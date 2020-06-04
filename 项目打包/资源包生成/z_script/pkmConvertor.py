#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os.path
import sys
import demjson
import pickle
import re
import hashlib

expPath = "czzFileDel"
toolPath = "../Arts/texturepacker_Tool/MaliTextureCompressionTool_v4.3.0/bin"
logFile = "z_script/z_converLog"
srcRoot1 = "/res/"
srcRoot2 = "/resNew/"
desRoot1 = "../sgAndroid/res/"
desRoot2 = "../sgAndroid/resNew/"
keyFlg = "\\sg\\"
logData = {}
oldDir = ""

def show_params(params):
    lenIdx = len(params)
    for index in range(lenIdx):
        print "argv" + str(index) + ":" + str(sys.argv[index])
        
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
    s_file.close()
    return (hashlib.md5(s_content).hexdigest()).strip()
    
def get_FileName(filePath):
    pos = filePath.rfind("\\")
    return filePath[pos+1:]
            
def cczFile(srcPath, outPath):
    cmd = os.path.abspath(expPath) + "\magic.exe -CCZPkm -s {srcFile} -d {dstPath} -ex {spaceNum}".format(srcFile = srcPath, dstPath= outPath, spaceNum = 0)
    print("cmd:" +cmd)
    os.system(cmd)
    
def pkmFile(srcPath, outPath):
    global toolPath
    toolPath = os.path.abspath(toolPath)
    cmd0 = "cd " + toolPath
    cmd1 = toolPath + "\etcpack.exe {srcFile} {dstPath} -c etc1 -s fast -aa -ext PNG".format(srcFile = srcPath, dstPath= outPath)
    cmd = cmd0 + " && " + cmd1 + " && cd " + oldDir
    # print("cmd:" +cmd)
    os.system(cmd)

def checkIsConver(srcPath):
    pos = srcPath.find(keyFlg)
    if pos == 0:
        return True
    md5Val = get_FileMd5(srcPath)
    key = srcPath[pos + len(keyFlg):]
    
    oldKey = key
    newMd5Val = str(md5Val)
    val = logData.get(key, "-1")
    if val <> newMd5Val:
        # print("-----------not has key:" + oldKey + ":" + val + ":" + newMd5Val)
        logData[key] = newMd5Val
        return False
    # print("----- ----has key:" + oldKey + ":" + val + ":" + newMd5Val)
    logData[key] = newMd5Val
    return True
    
def checkIsPase(srcFile):
    pos = srcFile.find(keyFlg)
    if pos == 0:
        return False
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
                            os.makedirs(pkmDir)
                        pkmPath = cczPath.replace(".png", ".pkm")
                        # print("srcFile" + srcFile + "-------" + pkmDir + "....." + cczPath)
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
                print("the file dest:" + dstFile + "  is 多出来的残余文件，将被删除")
                os.remove(dstFile)
        if os.path.isdir(dstFile):
            checkSurplusFile(srcFile, dstFile)
        
def main():
    global logData
    global keyFlg
    global srcRoot1
    global srcRoot2
    global oldDir
    global logFile
    global desRoot1

    oldDir = os.getcwd()

    show_params(sys.argv)
    paramsLen = len(sys.argv)
    
    # 按工程路径来, 工程路径位置为统一位置. py文件位置可以随便移动.保证能调用到就可以了.
    # 这个也按做游戏的思路来, 游戏也是统一的资源路径, 所有脚本文件,都是基于统一位置来搜索资源的
    # 相对来说,c++的文件引用关系就复杂一点
    # 默认调用位置为  client/luaecode
            
    if paramsLen >= 2:
        keyFlg = '\\' + sys.argv[1] + '\\'
        logFile = logFile + '_' + sys.argv[1] + ".txt"
        desRoot1 = desRoot1.replace("sgAndroid", "sgAndroid" + "_" + sys.argv[1])

    if os.path.exists(logFile):
        logData = ReadFile(logFile)
        logData = demjson.decode(logData)
        
    srcRoot1 = '..' + keyFlg + srcRoot1
    srcRoot2 = '..' + keyFlg + srcRoot2
    allFileList(srcRoot1, desRoot1)
    checkSurplusFile(srcRoot1, desRoot1)
    
if __name__=="__main__":
    main()