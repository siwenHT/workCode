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

worldCache = {}
keys = {}
def randomWorldS(num):
    ret = []
    allNum = len(keys)
    while(len(ret) < num):
        randNum = random.randint(1, allNum)
        if not (randNum - 1) in ret:
            ret.append(randNum - 1)

    retS = []
    for idx in ret:
        retS.append(keys[idx])

    return retS

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
        
def getTmpName(num, addLine = False):
    ret = ""
    for i in range(num):
        tmpStr = getOneWorld()

        if len(ret) + len(tmpStr) > 25:
            break

        if i > 0:
            tmpStr = tmpStr.capitalize()
        
        if i > 0 and random.randint(1, 4) == 1:
            ret = ret + '_' + tmpStr
        else:
            ret = ret + tmpStr

        if len(ret) > 25:
            break

    if random.randint(1, 10) == 1:
        ret = ret + str(random.randint(1, 5))
    return ret

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

def init():
    print __file__ + ' working in ' + os.getcwd()
    destFile = './worldDic.txt'

    initWorldArray(destFile)
    
