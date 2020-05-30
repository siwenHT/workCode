#!python   
import os,sys  
import os.path
import sys
import demjson
import pickle
import re
import hashlib
import binascii
import time

from xml.etree import ElementTree  
from PIL import Image

format = 1
logFile = "iosResConverLog.txt"
logData = {}
srcRoot = "sg"
oldKeyFlg = '\\sg\\'
tmpFileDir = "pvrTmp"
TexturePackerPath = "./TexturePacker/bin/"

def removeTmpFile():
    global tmpFileDir
    tmpFileDir = os.path.abspath(tmpFileDir)
    cmd = "rmdir /s /q " + tmpFileDir 
    os.system(cmd)
    cmd = "md "+ tmpFileDir
    os.system(cmd)

def WriteFile(filePath,all_the_text):    
    file_object = open(filePath,'wb+')    
    file_object.write(all_the_text)
    file_object.close()
    
def ReadFile(filePath):
    file_object = open(filePath,'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text    

def showTime():
    return time.strftime("[%Y-%m-%d %X]  ", time.localtime())
    
def copyFile(sourceFile, targetFile):
    sourceFile = os.path.abspath(sourceFile)
    targetFile = os.path.abspath(targetFile)
    print("[copyFile] s d" + sourceFile + " --- " + targetFile)
    open(targetFile, "wb+").write(open(sourceFile, "rb+").read())

def jwkj_get_filePath_fileName_fileExt(filename):
    (filepath,tempfilename) = os.path.split(filename);
    (shotname,extension) = os.path.splitext(tempfilename);
    return filepath,shotname,extension
    
def createDir(path):
    path = os.path.dirname(path)
    path = path.replace("\\", "/")
    paths = path.split("/")
    tmpPath = ''
    for path in paths:
        tmpPath = tmpPath + path + "/";
        if not os.path.exists(tmpPath):
            os.mkdir(tmpPath)
            
def get_FileMd5(filePath):
    s_file = open(filePath, "rb")
    s_content = s_file.read()
    s_file.close()
    return (hashlib.md5(s_content).hexdigest()).strip()
    
def checkIsConver(srcPath):
    pos = srcPath.find(srcRoot)
    if pos == -1:
        return True
    md5Val = get_FileMd5(srcPath)
    key = srcPath[pos + len(srcRoot):]
    
    # key = key.replace(srcRoot, "")
    newMd5Val = str(md5Val)
    val = logData.get(key, "-1")
    if val <> newMd5Val:
        # print("-----------not has key:" + key + ":" + val + ":" + newMd5Val)
        logData[key] = newMd5Val
        return False
    # print("---------has key:" + key + ":" + val + ":" + newMd5Val)
    logData[key] = newMd5Val
    return True
            
def checkBitDepth(srcFile):
    im = Image.open(srcFile)
    bitDepth = 8
    if im.mode == "RGBA":
        bitDepth =  32
    
    # if bitDepth <> 32:
        # print 'bitDepth :' + im.mode + "|" + srcFile
    return bitDepth
    
# 1 (1-bit pixels, black and white, stored with one pixel per byte)
# L (8-bit pixels, black and white)
# P (8-bit pixels, mapped to any other mode using a colour palette)
# RGB (3x8-bit pixels, true colour)
# RGBA (4x8-bit pixels, true colour with transparency mask)
# CMYK (4x8-bit pixels, colour separation)
# YCbCr (3x8-bit pixels, colour video format)
# I (32-bit signed integer pixels)
# F (32-bit floating point pixels


    # s_file = open(srcFile, "rb")
    # data = s_file.read()
    # s_file.close()
    # pos = 7
    # allSize = len(data)
    # bitDepth = 8
    # # print("[checkBitDepth] srcFile allSize:" + srcFile + "|" +str(allSize))
    # pos = data.find('IHDR')
    # if pos > 0:
        # str2 = binascii.b2a_hex(data[pos+12:pos+13])
        # bitDepth = int(str2, 16)
    # # while (pos < allSize - 1):
        # # print("val" + data[0:pos])
        # # chunkLen = int(data[pos+1:pos+5])
        # # chunkType = str(data[pos+5:pos+9])
        # # if chunkType == 'IHDR':
            # # bitDepth = int(data[pos+13:pos+14])
        # # else:
            # # pos = pos + chunkLen
    # # if bitDepth == 32:
    # print 'bitDepth :' + str(bitDepth) + "|" + srcFile
    # return bitDepth
    
def checkIsPase(srcFile):
    pos = srcFile.find("\\particle\\")
    if pos > 0:
        return False
    pos = srcFile.find("\\.")
    if pos > 0:
        return False
    # obj = re.search( r'\\s_11\d\d\D', srcFile, re.M|re.I)
    # if obj:
        # print(srcFile + "____not to Pkm")
        # return False
    # if re.search( r'\\s_6100\d\d\D', srcFile, re.M|re.I):
        # print(srcFile + "____not to Pkm")
        # return False
        
    if srcFile.find(".plist") > 0:
        return True
        
    return False
    
def pvrFile(srcFile, destFile):
    destDir = os.path.dirname(destFile)
    # print("[pvrFile] destDir:" + destDir)
    createDir(destDir + "\\")
    
    filepath,shotname,extension = jwkj_get_filePath_fileName_fileExt(srcFile)
    # print("[pvrFile] filepath shotname extension:" + filepath + "|" + shotname  + "|" + extension)
    copyFile(srcFile, tmpFileDir + "/" + shotname + extension)
    
    plistFile = srcFile.replace(".png", ".plist")
    plistFileTar = tmpFileDir + "/" + shotname + ".plist"
    copyFile(plistFile, plistFileTar)
    
    cmd = "splitPlist.py {srcPath}".format(srcPath = tmpFileDir)
    # print("[pvrFile] cmd1:" +cmd)
    os.system(cmd)
    
    dir = tmpFileDir + "/" + shotname
    if format == 1:
        cmd = os.path.abspath(TexturePackerPath) + os.sep + "TexturePacker {0} --format cocos2d --force-squared --size-constraints NPOT --dither-fs-alpha --scale 1 --max-size 4096 --opt PVRTC4 --force-publish --texture-format pvr2ccz --data {1}/{2}.plist --sheet {1}/{2}.pvr.ccz".format(dir, tmpFileDir, shotname)
    elif format == 2:
        cmd = os.path.abspath(TexturePackerPath) + os.sep + "TexturePacker {0} --format cocos2d --force-squared --size-constraints NPOT --dither-fs-alpha --scale 1 --max-size 4096 --opt RGBA4444 --force-publish --texture-format pvr2ccz --data {1}/{2}.plist --sheet {1}/{2}.pvr.ccz".format(dir, tmpFileDir, shotname)
    elif format == 4:
        cmd = os.path.abspath(TexturePackerPath) + os.sep + "TexturePacker {0} --format cocos2d --force-squared --size-constraints NPOT --dither-fs-alpha --scale 1 --max-size 4096 --opt PVRTC2 --force-publish --texture-format pvr2ccz  --data {1}/{2}.plist --sheet {1}/{2}.pvr.ccz".format(dir, tmpFileDir, shotname)
    print("[pvrFile] cmd2:" +cmd)
    os.system(cmd)
    
    tmpPvrFile = tmpFileDir + "/" + shotname + ".pvr.ccz"
    # tmpPvrFile = tmpFileDir + "/" + shotname + ".png"
    tarPvrFile = destDir + "/" + shotname + ".png"
    copyFile(tmpPvrFile, tarPvrFile)
    
    tmpPlistFile = tmpFileDir + "/" + shotname + ".plist"
    tarPlistFile = destDir + "/" + shotname + ".plist"
    copyFile(tmpPlistFile , tarPlistFile)
    
    # removeTmpFile()
    
def allFileList(srcPath, dstPath):
    srcPath = os.path.abspath(srcPath)
    dstPath = os.path.abspath(dstPath)
    for file in os.listdir(srcPath):
        srcFile = os.path.join(srcPath,  file)
        dstFile = os.path.join(dstPath,  file)
        if os.path.isfile(srcFile):
            if checkIsPase(srcFile):
                srcFile = srcFile.replace("/",  "\\")
                dstFile = dstFile.replace("/",  "\\")
                srcFile = srcFile.replace(".plist", ".png")
                if os.path.exists(srcFile) and checkBitDepth(srcFile) == 32:
                    cczPath = dstFile.replace(".plist", ".png")
                    if not checkIsConver(srcFile) or not os.path.exists(cczPath) or not os.path.exists(dstFile):
                        print srcFile, ":", showTime()
                        pvrFile(srcFile, dstFile)
                            
                        logPushData = demjson.encode(logData)
                        WriteFile(logFile, logPushData)
                        # save_obj(logData, logFile)
        if os.path.isdir(srcFile):
            allFileList(srcFile, dstFile)
            
def checkSurplusFile(srcPath, dstPath):
    srcPath = os.path.abspath(srcPath)
    dstPath = os.path.abspath(dstPath)
    
    if not os.path.exists(dstPath):
        return
        
    for file in os.listdir(dstPath):
        srcFile = os.path.join(srcPath,  file)
        dstFile = os.path.join(dstPath,  file)
        # print("srcFile" + srcFile)
        if os.path.isfile(dstFile):
            # print("srcFile" + dstFile)
            srcFile = srcFile.replace(".png", ".plist")
            if not os.path.exists(srcFile):
                print("the file dest:" + dstFile + "is no use File")
                os.remove(dstFile)
        if os.path.isdir(dstFile):
            checkSurplusFile(srcFile, dstFile)
            
def main():
    currtenPath = os.getcwd()
       
    folder = 'sgIos'
    global logFile
    global format
    if len(sys.argv) >= 2:
        format =  int(sys.argv[1])
        
        if format == 1:
            logFile = "iosResConverLog_pvrtc4.txt"
            folder = 'sgIos_pvrtc4'
        elif format == 2:
            logFile = "iosResConverLog.txt"
        elif format == 4:
            logFile = "iosResConverLog_pvrtc2.txt"
            folder = 'sgIos_pvrtc2'
            
    if len(sys.argv) >= 3:
        global srcRoot
        srcRoot = sys.argv[2]
            
    srcRoot1 = "../"+ srcRoot +"/res/"
    srcRoot2 = "../"+ srcRoot +"/resNew/"
    
    desRoot1 = "../" + folder + "/res/"
    desRoot2 = "../" + folder + "/resNew/"
    removeTmpFile()
    
    srcRoot = os.path.abspath("../../"+ srcRoot +"/")
    srcRoot = srcRoot + '\\'
    srcRoot = srcRoot.replace('/', '\\')
    
    global logData
    if os.path.exists(logFile):
        logData = ReadFile(logFile)
        logData = demjson.decode(logData)
            
    allFileList(srcRoot1, desRoot1)
    checkSurplusFile(srcRoot1, desRoot1)
    checkSurplusFile(srcRoot2, desRoot2)
        
if __name__ == '__main__':  
    main()