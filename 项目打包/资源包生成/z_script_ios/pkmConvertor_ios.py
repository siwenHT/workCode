#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os.path
import sys
import demjson
import pickle
import re
import hashlib
import time

expPath = "czzFileDel"
toolPath = "../Arts/texturepacker_Tool/MaliTextureCompressionTool_v4.3.0/bin"
keyFlg = '\\sg\\'
logFile = "z_script_ios/iosResConverLog_etc2_sg.txt"
srcRoot1 = "/res/"
srcRoot2 = "/resNew/"

desRoot1 = "../etc2_sg/res/"
desRoot2 = "../etc2_sg/resNew/"
logData = {}
spaceNum = 0

oldDir = ""

def save_obj(obj, name ):
    with open(name, 'wb') as f:
        pickle.dump(obj, f, pickle.HIGHEST_PROTOCOL)
        
def load_obj(name ):
    with open(name, 'rb') as f:
        return pickle.load(f)
        
def ReadFile(filePath):
    file_object = open(filePath,'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

def WriteFile(filePath,all_the_text):    
    file_object = open(filePath,'wb+')    
    file_object.write(all_the_text)
    file_object.close()
    
def removeFilePath(filePath):
    for root, dirs, files in os.walk(filePath, topdown=False):
        for name in files:
            os.remove(os.path.join(root, name))
        for name in dirs:
            os.rmdir(os.path.join(root, name))
            
def get_FileModifyTime(filePath):
    filePath = unicode(filePath, 'utf8')
    t = os.path.getmtime(filePath)
    return t
    
def get_FileMd5(filePath):
    s_file = open(filePath, "rb")
    s_content = s_file.read()
    return (hashlib.md5(s_content).hexdigest()).strip()

def showTime():
    return time.strftime("[%Y-%m-%d %X]  ", time.localtime())
    
def get_FileName(filePath):
    pos = filePath.rfind("\\")
    return filePath[pos+1:]
            
def cczFile(srcPath, outPath):
    cmd = os.path.abspath(expPath) + "\magic.exe -CCZPkm -s {srcFile} -d {dstPath} -ex {spaceNum}".format(srcFile = srcPath, dstPath= outPath, spaceNum = spaceNum)
    print("cmd:" +cmd)
    os.system(cmd)
    
def pkmFile(srcPath, outPath):
    global toolPath
    toolPath = os.path.abspath(toolPath)
    cmd0 = "cd " + toolPath
    cmd1 = toolPath + "\etcpack.exe {srcFile} {dstPath} -c etc2 -s fast -ext PNG -f RGBA".format(srcFile = srcPath, dstPath= outPath)
    cmd = cmd0 + " && " + cmd1 + " && cd " + oldDir
    # print("cmd:" +cmd)
    os.system(cmd)

def checkIsConver(srcPath):
    pos = srcPath.find(keyFlg)
    if pos == -1:
        return True
    md5Val = get_FileMd5(srcPath)
    key = srcPath[pos + len(keyFlg):]
    
    newMd5Val = str(md5Val)
    val = logData.get(key, "-1")
    if val <> newMd5Val:
        # print("-----------not has key:" + key + ":" + val + ":" + newMd5Val)
        logData[key] = newMd5Val
        return False
    # print("---------has key:" + key + ":" + val + ":" + newMd5Val)
    logData[key] = newMd5Val
    return True
    
def checkIsPase(srcFile):
    pos = srcFile.find("\\particle\\")
    if pos > 0:
        return False
    pos = srcFile.find("\\.")
    if pos > 0:
        return False
    obj = re.search( r'\\s_11\d\d\D', srcFile, re.M|re.I)
    if obj:
        print(srcFile + "____not to Pkm")
        return False

    if srcFile.find(".plist") > 0:
        return True
    return False

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
                if os.path.exists(srcFile):
                    cczPath = dstFile.replace(".plist", ".png")
                    if not checkIsConver(srcFile) or not os.path.exists(cczPath):
                        pkmDir = os.path.dirname(dstFile)
                        pkmFile(srcFile, pkmDir)
                        if not os.path.exists(pkmDir):
                            os.makedirs(pkmDir + "/")
                        pkmPath = cczPath.replace(".png", ".pkm")
                        print srcFile, ":", showTime()
                        print("srcFile" + srcFile + "-------" + pkmDir + "....." + cczPath)
                        cczFile(pkmPath, cczPath)                            
                        if os.path.exists(pkmPath):
                            os.remove(pkmPath)
                        logPushData = demjson.encode(logData)
                        WriteFile(logFile, logPushData)
                        # save_obj(logData, logFile)
        if os.path.isdir(srcFile):
            allFileList(srcFile, dstFile)
            
def checkSurplusFile(srcPath, dstPath):
    srcPath = os.path.abspath(srcPath)
    dstPath = os.path.abspath(dstPath)
    for file in os.listdir(dstPath):
        srcFile = os.path.join(srcPath,  file)
        dstFile = os.path.join(dstPath,  file)
        # print("srcFile" + srcFile)
        if os.path.isfile(dstFile):
            # print("srcFile" + dstFile)
            srcFile = srcFile.replace(".png", ".plist")
            if not os.path.exists(srcFile):
                print("the file dest:" + dstFile + "  is 多余文件 将被移除")
                os.remove(dstFile)
        if os.path.isdir(dstFile):
            checkSurplusFile(srcFile, dstFile)
        
def main():
    global oldDir
    oldDir = os.getcwd()
    global logData
    global spaceNum
    global keyFlg
    global logFile
    global desRoot1
    
    sourcePath = 'sg_waiwang'
    if len(sys.argv) >= 3:
        sourcePath = sys.argv[2]
        keyFlg = '\\' + sourcePath + '\\'
        logFile = logFile.replace('sg', sourcePath)
        desRoot1 = desRoot1.replace('sg', sourcePath)
    
    if os.path.exists(logFile):
        logData = ReadFile(logFile)
        logData = demjson.decode(logData)            
    if len(sys.argv) >= 2:
        spaceNum =  int(sys.argv[1])

    global srcRoot1
    global srcRoot2
    
    srcRoot1 = ".." + keyFlg + "/res/"
    srcRoot2 = ".." + keyFlg + "/resNew/"
        
    allFileList(srcRoot1, desRoot1)
    checkSurplusFile(srcRoot1, desRoot1)
    # allFileList(srcRoot2, desRoot2)
    
if __name__=="__main__":
    main()