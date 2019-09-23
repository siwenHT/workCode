#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
import hashlib
import shutil
import random
import binascii
import struct
import toolsFunc as tool
import chardet

spaceNum = 4
specSpace = ''
changePngEndBuff = False
chanegJpgEndBuff = False
changeMap3Info = False
needXxtea = False
updateFile = ''
updateFileList = {}
resFullRep = {}
count = 0
copyNum = 0
showRepError = True

def readLineFile(file):
    dir = {}
    file_object = open(file, 'r')
    for line in open(file):
        line = line.strip()
        if line.find("|") == -1:
            continue
        lines = line.split("|")
        oldPath = lines[0]
        dir[oldPath] = {'newPath': lines[1]}

    file_object.close()
    return dir

def md5sum(filename):
    fd = open(filename,"r")
    fcont = fd.r
    fd.close()
    fmd5 = hashlib.md5(fcont)
    return fmd5

def initUpdateFileList():
    if updateFile != '0':
        global updateFileList
        updateFileList = readLineFile(updateFile)
    
def initRepList():
    global resFullRep
    ret = {}
    def func(lineStr):
        lineStr = lineStr.strip()
        lineStrs = lineStr.split('|')
        ret[lineStrs[0]] = lineStrs[1]

    tool.ReadLineFile('outAppendRes/rep_resFullPathName.txt' , func)
    resFullRep = ret
    
def checkNeedCopy(fileName):
    if updateFileList:
        for key,_ in updateFileList.items():
            key = key[3:]
            if fileName.find(key) > -1:
                return True
            if fileName.find("filelist.txt") > -1:
                return True
    else:
        if fileName.find(".gitignore") > -1:
            return False
        return True

    return False

def randEndBuff(fileName, content):
    if changePngEndBuff and fileName.find(".png") > -1:
        pngEndPos = content.find("IEND")
        if content.find("IHDR") > -1 and pngEndPos > -1:
            space = tool.getRandomChar(spaceNum)
            return content[0: pngEndPos + 8] + space
    
    if chanegJpgEndBuff and fileName.find('.jpg') > -1:
        jpgEndPos = content.find(b"\xff\xd9")
        if content.find(b'\xff\xd8') > -1 and content.find("JFIF") > -1 and jpgEndPos > -1:
            space = tool.getRandomChar(spaceNum)
            return content[0: jpgEndPos + 2] + space
        
        if content.find('Adobe Photoshop CS6 (Windows)') > -1:
            content = content.replace('Adobe Photoshop CS6 (Windows)', tool.getRandomChar(29))
            content = content.replace('Adobe Photoshop CS5 (Windows)', tool.getRandomChar(29))
            return content
    
    if changeMap3Info and fileName.find('.mp3') > -1:
        pos = content.find('TAG')
        if content.find('TAG') > -1:
            space = tool.getRandomChar(spaceNum)
            return content[0:pos+3] + space + content[pos+3+spaceNum:]

    return content
    
def randomBit(content, srcFile):
    notXxtea = False
    if spaceNum == 0:
        return content

    #这个地方去掉了粒子系统的配置文件
    # if srcFile.find("particle") > -1:
    #     return content
    if len(content) > 4 and content[0] == 'C' and content[1] == 'C' and content[2] == 'Z' and content[3] == '!':
        str2 = binascii.b2a_hex(content[6:8])
        # print "[randomBit] srcFile" + srcFile + "|" + str2
        version = int(str2, 16)
        if version == 199:
            subContent = content[16 + spaceNum:]
            headContent = content[0:16]
            if spaceNum > 0:
                if specSpace == '':
                    space = tool.getResRandomChar()
                else:
                    space = specSpace
                content = headContent + space + subContent
                # return headContent + space + subContent

        if version == 2 or version == 0:
            if spaceNum > 0:
                subContent = content[16:]
                headContent1 = content[0:6]
                headContent2 = content[8:16]
                newVersion = str(b"\x00\xc7")
                space = ""
                if specSpace == '':
                    space = tool.getResRandomChar()
                else:
                    space = specSpace
                content = headContent1 + newVersion + headContent2 + space + subContent
                # return headContent1 + newVersion + headContent2 + space + subContent

        # notXxtea = True
    
    tmpStr = len(content) > 4  and content[0:4] or ''
    if tmpStr == "WSZR":
        subContent = content[4:]
        tmpStr = content[4:4+spaceNum]
        if tmpStr == "1111":
            subContent = content[4+spaceNum:]
        
        space = ''
        headContent = "WSZR"
        if specSpace == '':
            space = tool.getResRandomChar()
        else:
            space = specSpace
        
        content = headContent + space + subContent
        # return headContent + space + subContent
    
    signment = "Signal"
    tmpStr = content[0:len(signment)]
    if tmpStr == signment:
        subContent = content[len(signment):]
        tmpStr = content[len(signment):len(signment)+spaceNum]
        if tmpStr == "1111":
            subContent = content[len(signment) + spaceNum:]
    
        if specSpace == '':
            space = tool.getResRandomChar()
            return signment + space + subContent
        else:
            return signment + specSpace + subContent
    
    content = randEndBuff(srcFile, content)
    # notXxtea = True
    if not notXxtea and srcFile.find('.mp3') == -1 \
        and needXxtea \
        and srcFile.find('.ttf') == -1 and srcFile.find('.fsh') == -1 \
        and srcFile.find('.wav') == -1:
        content = tool.EncodeContent(content, 'ZYA14ageb8642F58', signment, spaceNum, specSpace)
        
    return content

def getRealFileName(oldFileName):
    # if oldFileName.find('adChannel.png') > -1:
    #     return oldFileName.replace('adChannel.png', 'info.png')
    if not isChangePath:
        return oldFileName
    if oldFileName.find('cocos/') != -1 or oldFileName.find('cocos\\') != -1:
        return oldFileName
    resPath = os.path.abspath(targetPath)
    resPath = resPath.replace("\\", "/")
    resPath = resPath + '/'
    oldFileName = oldFileName.replace( resPath, '')
    if oldFileName in resFullRep:
        return resPath + resFullRep[oldFileName]
    else:
        if showRepError:
            print resPath + oldFileName + ' canot find repName!!!'
        
    return resPath + oldFileName
    
def copyFiles(sourcePath, targetPath):
    srcPath = os.path.abspath(sourcePath)
    dstPath = os.path.abspath(targetPath)
    for file in os.listdir(srcPath):
        srcFile = os.path.join(srcPath, file)
        dstFile = os.path.join(dstPath, file)
        srcFile = srcFile.replace("\\", "/")
        dstFile = dstFile.replace("\\", "/")
        if os.path.isfile(srcFile):
            if not checkNeedCopy(srcFile):
                continue

            dstFile = getRealFileName(dstFile)
            t_path_dir = os.path.dirname(dstFile).strip()
            if not os.path.exists(t_path_dir):
                tool.createDir(t_path_dir + '/')
            s_file = open(srcFile, "rb")
            s_content = s_file.read()
            
            # print srcFile + "--------" + dstFile
            newContent = randomBit(s_content, srcFile)
            try:
                open(dstFile, "wb").write(newContent)
                global copyNum
                copyNum = copyNum + 1
            except Exception as e:
                print srcFile + "--------" + dstFile
                print 'str(Exception):\t', str(Exception)
                print 'str(e):\t\t', str(e)
                print 'repr(e):\t', repr(e)
                print 'e.message:\t', e.message
                # print 'traceback.print_exc():'; traceback.print_exc()
                # print 'traceback.format_exc():\n%s' % traceback.format_exc()

            
        if os.path.isdir(srcFile):
            copyFiles(srcFile, dstFile)
    
            
def main():
    global sourcePath
    global targetPath
    sourcePath = "../sg1/"
    targetPath = "../sgtest/"
    global isChangePath
    isChangePath = True
    
    print "========================================================"
    argvLen = len(sys.argv)
    for index in range(argvLen):
        print "agrv" + str(index) + ":" + str(sys.argv[index])
        
    print "========================================================"

    if argvLen >= 2:
        sourcePath = sys.argv[1]
        
    if argvLen >= 3:
        targetPath = sys.argv[2]
        
    if argvLen >= 4:
        global specSpace
        if sys.argv[3] != "0":
            specSpace = sys.argv[3]        
        
    if argvLen >= 5:
        if sys.argv[4] == '1':
            isChangePath = False
       
    if argvLen >= 6:
        global spaceNum
        spaceNum = int(sys.argv[5])
        
    if argvLen >= 7:
        pngJpgDelFlg = int(sys.argv[6])
        global changePngEndBuff
        global chanegJpgEndBuff
        global changeMap3Info
        if pngJpgDelFlg == 0:
            changePngEndBuff = False
            chanegJpgEndBuff = False
        if pngJpgDelFlg == 1:
            changePngEndBuff = True
            chanegJpgEndBuff = False
        if pngJpgDelFlg == 2:
            changePngEndBuff = False
            chanegJpgEndBuff = True
        if pngJpgDelFlg == 3:
            changePngEndBuff = True
            chanegJpgEndBuff = True
            changeMap3Info = True

    if argvLen >= 8:
        if sys.argv[7] == '1':
            global needXxtea
            needXxtea = True
    
    if argvLen >= 9:
        global updateFile
        updateFile = sys.argv[8]
        initUpdateFileList()

    if argvLen >= 10:
        global showRepError
        if sys.argv[9] == '0':
            showRepError = False

    if isChangePath:
        initRepList()
    # print "拷贝到文件:" + targetPath
    global copyNum
    copyNum = 0
    copyFiles(sourcePath, targetPath)
    print "@@@@@@@@@copyNum:" + str(copyNum)

if __name__=="__main__":
    main()
