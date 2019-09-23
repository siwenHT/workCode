#!python   
# -*- coding: utf-8 -*-
# from __future__ import unicode_literals

import os,sys  
import os.path
import sys
import pickle
import demjson
import numpy as np
import json
import requests
requests.packages.urllib3.disable_warnings()

worldCache = {}

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
    

def checkWorld(world):
    req_url = 'https://fanyi.baidu.com/transapi'
    Form_Data = {"query": world, 'from':'en', 'to' : 'zh', 'transtype':'realtime'}

    translate_result = requests.post(req_url, Form_Data)
    result = translate_result.json() #转化为json格式
    result = result["data"][0]["dst"]
    cmpStr = world.upper() + u''
    cmpStr = cmpStr.decode('utf-8')
    if result.upper() == cmpStr:
        return False
    print cmpStr.lower() + '============' + result.upper()
    return True

def initWorldArray(filePath):
    global worldCache
    if os.path.exists(filePath):
        worldCache = ReadFile(filePath)
        if len(worldCache) > 0:
            worldCache = demjson.decode(worldCache)
        else:
            worldCache = {}

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
    sContent = sContent.decode("gb2312")

    tmpWorldDic = {}
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
                shortStr = shortStr.lower()
                tmpWorldDic[shortStr] = 1                    
        pos = tmpPos + 1

    for key in tmpWorldDic:
        if not key in worldCache:
            worldCache[key] = 1
    
    writeJsonFile(worldCache, destFile)

def main():
    print "sys encode:" + sys.getdefaultencoding()

    srcFile = './world.txt'
    destFile = './worldDic.txt'
    argvLen = len(sys.argv)
    show_params(sys.argv)
    if argvLen >= 2:
        srcFile = sys.argv[1]

    if argvLen >= 3:
        destFile = sys.argv[2]

    initWorldArray(destFile)
    getWorldFromTxt(srcFile, destFile)
    print u"获取字符串成功"
    print "len:" + str(len(worldCache))

if __name__ == '__main__':  
    main()