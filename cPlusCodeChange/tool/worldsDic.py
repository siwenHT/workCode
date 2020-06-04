#!python   
# -*- coding: utf-8 -*-

import os,sys  
import os.path
import sys
import demjson
import pickle
import re
import hashlib
import random
import binascii
import toolsFunc as tool
import unicodedata

worldCache = {}
keys = {}
normalValueType = {}
clsTag = ''

def WriteFile(filePath, all_the_text):    
    file_object = open(filePath,'wb+')    
    file_object.write(all_the_text)
    file_object.close()
    
def ReadFile(filePath):
    file_object = open(filePath, 'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text    

def initWorldArray(filePath):
    global worldCache
    if os.path.exists(filePath):
        worldCache = ReadFile(filePath)
        if len(worldCache) > 0:
            worldCache = demjson.decode(worldCache)
        else:
            worldCache = {}

    global keys
    keys = worldCache.keys()

def getCplusSuffix():
    cfg = ['Helper','Ctr', 'Control', 'Plane','Layer', 'Sence', 'View', 'Sprite', '', 'Baser', "Model", "MG", 'Tool', "Ins", "Map", "Node", "Op", "Manager", "Deal", "Handle", "Action",  "Label", 'Effect']
    return tool.random.choice(cfg)

def getObjectCSuffix():
    cfg = ['Helper','Warpper','Protocol', 'Manager', 'Extension', 'View', 'Tool', 'Controller', "Model", 'Factory', 'List', 'Listener', 'Notify', '', 'Observer', "Interfaces", 'Inner', 'Res', 'Choice']
    return tool.random.choice(cfg)

def randomWorldS(totalNum, ty):
    retS = []
    while(len(retS) < totalNum):
        randKey = ''
        if ty == "cplusClass":
            val = getTmpName(2, True, False)
            val = val[0].upper() + val[1:]
            randKey = clsTag + val + getCplusSuffix()
        elif ty == 'cplusAttr':
            num = random.randint(1, 100)
            num = 2 if (num > 60) else 3
            randKey = getTmpName(2, True, True)
        elif ty == 'cplusFunc':
            num = random.randint(1, 100)
            num = 4 if (num > 70) else 3
            randKey = getTmpName(num, False)
        elif ty == "ocClass":
            val = getTmpName(2, True, False)
            val = val[0].upper() + val[1:]
            randKey = clsTag + val + getObjectCSuffix()
        elif ty == 'ocAttr':
            num = random.randint(1, 100)
            num = 2 if (num > 60) else 3
            randKey = getTmpName(2, True, True)
        elif ty == 'ocFunc':
            num = random.randint(1, 100)
            num = 4 if (num > 70) else 3
            randKey = getTmpName(num, False)
        elif ty == 'ocString':
            cfg = ['.', '_']
            num = random.randint(1, 100)
            num = 1 if (num > 70) else 2
            randKey = getTmpName(num, False)
            num = random.randint(1, 100)
            line = (num > 85) and tool.random.choice(cfg) or ''
            randKey = line + randKey
        
        randKey = unicodedata.normalize('NFKD',randKey).encode('ascii','ignore')
        if not randKey in retS:
            retS.append(randKey)

    return retS

def getOneWorld():
    totalLen = len(keys)
    numRand = random.randint(1, totalLen)
    return keys[numRand - 1]

def getRandomTwoWorld():
    totalLen = len(keys)
    if random.randint(1, 50) < 15:
        numRand1 = random.randint(1, totalLen)
        numRand2 = random.randint(1, totalLen)
        return keys[numRand1 - 1] + keys[numRand2 - 1].capitalize()

    numRand = random.randint(1, totalLen)
    return keys[numRand - 1]
        
def getTmpName(num, addLine = False, addNum = True):
    ret = ""
    for i in range(num):
        tmpStr = getOneWorld()

        if len(ret) + len(tmpStr) > 25:
            break

        if i > 0:
            tmpStr = tmpStr.capitalize()
        
        if addLine and i > 0 and random.randint(1, 4) == 1:
            ret = ret + '_' + tmpStr
        else:
            ret = ret + tmpStr

        if len(ret) > 25:
            break

    if addNum and random.randint(1, 10) == 1:
        ret = ret + str(random.randint(1, 5))
    return ret

def getFuncName(num):
    return getTmpName(num, False)

def getFileFolderName(maxlayer = 3):
    ret = []

    # 默认都是3层， 最后在最后的文件下, 加随机.
    layer2Num = random.randint(3, 8)
    layer3Num = random.randint(3, 10)
    layer4Num = random.randint(1, 6)

    firstName = getOneWorld()
    ret.append(firstName)
    for i in range(layer2Num):
        secName = getOneWorld()
        ret.append(firstName + "/" + secName)
        for j in range(layer3Num):
            threeName = getRandomTwoWorld()
            ret.append(firstName + "/" + secName+ "/" + threeName)
            if random.randint(1, 20) <= 2:
                for k in range(layer4Num):
                    fourName = getRandomTwoWorld()
                    ret.append(firstName + "/" + secName+ "/" + threeName + "/" + fourName)

    print 'Folder:' + firstName + ", len" + str(len(ret))
    return ret

#删除所有注释
def clearnFiles(lanType, srcPath, dstPath):
    if lanType == "cplus":
        srcPath = tool.os.path.abspath(srcPath) 
        dstPath = tool.os.path.abspath(dstPath)
        for file in tool.os.listdir(srcPath):
            srcFile = tool.os.path.join(srcPath, file)
            dstFile = tool.os.path.join(dstPath, file)
            if tool.os.path.isfile(srcFile):
                f_content = tool.ReadFile(srcFile)
                tool.createDir(dstFile)
                # print "clearnFiles start:" + srcFile
                f_content = tool.delCplusNotes(f_content)
                tool.WriteFile(dstFile, f_content)
            elif tool.os.path.isdir(srcFile):
                clearnFiles(lanType, srcFile, dstFile)


def setClsHead(tag):
    global clsTag
    clsTag = tag

def clsHead():
    return clsTag

def init():
    destFile = './worldDic.txt'

    initWorldArray(destFile)