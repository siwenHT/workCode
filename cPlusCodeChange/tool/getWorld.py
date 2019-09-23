#!python   
# -*- coding: utf-8 -*-
# from __future__ import unicode_literals

import os,sys  
import os.path
import sys
import pickle
import demjson
import numpy as np
import toolsFunc as tool

worldCache = {}
exWorld = {}

def save_obj(obj, name ):
    with open(name, 'wb') as f:
        pickle.dump(obj, f, pickle.HIGHEST_PROTOCOL)
        
def load_obj(name):
    with open(name, 'rb') as f:
        return pickle.load(f)

def writeJsonFile(obj, fileName):
    logPushData = demjson.encode(obj)
    WriteFile(fileName, logPushData)

def ReadFile(filePath):
    file_object = open(filePath,'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

def WriteFile(filePath,all_the_text):    
    file_object = open(filePath,'wb+')    
    file_object.write(all_the_text)
    file_object.close()    

def show_params(params):
    lenIdx = len(params)
    if lenIdx <= 0:
        return

    for index in range(lenIdx):
        print "argv" + str(index) + ":" + str(sys.argv[index])

def initWorldArray(filePath, exFile):
    global worldCache
    if os.path.exists(filePath):
        worldCache = ReadFile(filePath)
        if len(worldCache) > 0:
            worldCache = demjson.decode(worldCache)
        else:
            worldCache = {}
    
    global exWorld
    if os.path.exists(exFile):
        ret = []
        def func(linStr):
            linStr = linStr.strip()
            ret.append(linStr)
        tool.ReadLineFile(exFile, func)
        exWorld = ret

def isEnglishWorld(singleChar):
    intVal = ord(singleChar)
    if (97 <= intVal <= 122) or (65 <= intVal <= 90):
        return True
    
    return False

def getWorldFromTxt(srcFile, destFile):
    if not os.path.exists(srcFile):
        print '源文件不存在'
        return
    
    sContent = ReadFile(srcFile)
    sContent = sContent.decode("gbk")

    tmpWorldCatch = {}
    pos = 0
    tmpPos = pos
    slen = len(sContent)
    while (pos < slen):
        curChr = sContent[pos]
        tmpPos = sContent.find(' ', pos)
        if tmpPos == -1:
            break
    
        if isEnglishWorld(curChr):
            shortStr = sContent[pos: tmpPos]
            isOk = True
            for i in range(len(shortStr)):
                if not isEnglishWorld(shortStr[i]):
                    isOk = False

            if isOk and len(shortStr) > 3:
                shortStr = shortStr.lower()
                shortStr = shortStr.encode("utf-8")
                tmpWorldCatch[shortStr] = 1
        pos = tmpPos + 1
    
    for key in tmpWorldCatch:
        if key and key not in worldCache:
            worldCache[key] = 1

    for key in worldCache.keys():
        if key in exWorld:
            del worldCache[key]
            print 'remove :' + key 

    writeJsonFile(worldCache, destFile)

def main():
    print "sys encode:" + sys.getdefaultencoding()

    print os.getcwd()
    os.chdir('./res')
    srcFile = '../res/world.txt'
    destFile = '../res/worldDic.txt'
    exFile = '../res/expWorld.txt'

    argvLen = len(sys.argv)
    show_params(sys.argv)
    if argvLen >= 2:
        srcFile = sys.argv[1]

    if argvLen >= 3:
        destFile = sys.argv[2]

    initWorldArray(destFile, exFile)
    getWorldFromTxt(srcFile, destFile)
    print u"获取字符串成功"
    global worldCache
    print "len:" + str(len(worldCache))
    os.system('pause')

if __name__ == '__main__':  
    main()