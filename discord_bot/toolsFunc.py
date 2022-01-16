#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   toolsFunc.py
@Time    :   2020/12/23 11:08:19
@Author  :   hongtao 
@Desc    :   None
'''

# here put the import lib
import os
import random
import re
import sys
import shutil
import time
import struct
import unicodedata
import datetime
import selenium


def ReadFile(filePath):
    file_object = open(filePath, 'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text


def ReadLineFile(filePath, callBack):
    if not os.path.exists(filePath):
        return
    file_object = open(filePath, 'r')
    for line in open(filePath):
        line = line.strip()
        callBack(line)
    file_object.close()


def getFile_path_name_suf(filename):
    (filepath, tempfilename) = os.path.split(filename)
    (shotname, extension) = os.path.splitext(tempfilename)
    return filepath, shotname, extension


def get_FileSize(filePath):
    filePath = unicode(filePath, 'utf8')
    fsize = os.path.getsize(filePath)
    return fsize


def randomList(allNum, num):
    ret = []
    while (len(ret) < num):
        randNum = random.randint(1, allNum)
        if not (randNum - 1) in ret:
            ret.append(randNum - 1)
    return ret


def showParams():
    print("========================================================")
    argvLen = len(sys.argv)
    for index in range(argvLen):
        print("agrv" + str(index) + ":" + str(sys.argv[index]))

    print("========================================================")


# 检测文字是否符合规则
def checkStrIsOk(strInfo):
    if len(strInfo) == 1:
        return False

    for i in range(len(strInfo)):
        symbol = strInfo[i]
        if i == 0 and symbol.isdigit():
            return False
        if not symbol.isalnum() and symbol != '_':
            return False
    return True


def createDir(path):
    path = os.path.dirname(path)
    path = path.replace("\\", "/")
    if not os.path.exists(path):
        paths = path.split("/")
        tmpPath = ''
        for path in paths:
            tmpPath = tmpPath + path + "/"
            if not os.path.exists(tmpPath):
                os.mkdir(tmpPath)


def WriteFile(filePath, all_the_text):
    if type(all_the_text) == str:
        all_the_text = all_the_text.encode('utf-8')

    file_object = open(filePath, 'wb')
    file_object.write(all_the_text)
    file_object.close()


def BakFile(filePath, all_the_text):
    file_bak = filePath[:len(filePath) - 3] + 'bak'
    WriteFile(file_bak, all_the_text)


def ListFile(path):
    path = os.path.abspath(path)

    fileList = []
    for file in os.listdir(path):
        fileList.append(os.path.join(path, file))

    return fileList


def find_last(string, str):
    last_position = -1
    while True:
        position = string.find(str, last_position + 1)
        if position == -1:
            return last_position
        last_position = position


def getRandomChar(num, key1=33, key2=125):
    ret = ""
    count = 1
    while (count <= num):
        ret = ret + chr(random.randint(key1, key2))
        count = count + 1

    return ret


def unicodeToAscii(tmpStr):
    if isinstance(tmpStr, unicode):
        return unicodedata.normalize('NFKD', tmpStr).encode('ascii', 'ignore')
    return tmpStr


def getResRandomChar(key1=33, key2=125):
    start = getRandomChar(1, key1, key2)

    startAscii = ord(start)
    if startAscii == 49:
        return start + getRandomStr(3)
    elif 50 <= startAscii <= 90:
        return start + getRandomStr(23)
    elif 91 <= startAscii <= 116:
        return start + getRandomStr(42)
    elif 117 <= startAscii <= 125:
        return start + getRandomStr(37)
    else:
        return start + getRandomStr(35)


def showTime():
    return datetime.datetime.now().strftime('[%Y-%m-%d %H:%M:%S  %f]')


def getRandomStr(num, key1=1, key2=255):
    ret = ""
    count = 1
    while (count <= num):
        ret = ret + unichr(random.randint(key1, key2))
        count = count + 1

    ret = to_bytes(ret)
    ret = ret[0:num]
    return ret


def to_bytes(bytes_or_str):
    if isinstance(bytes_or_str, unicode):
        return bytes_or_str.encode('utf-8')
    return bytes_or_str


def to_str(bytes_or_str):
    if isinstance(bytes_or_str, str):
        return bytes_or_str.decode('utf-8')
    return bytes_or_str


def find_ex(con, symbol):
    pos = con.find(symbol)
    if pos > -1:
        return pos + len(symbol)

    return pos


def copyFiles(sourceDir, targetDir, callBack):
    if sourceDir.find(".svn") > 0:
        return

    for file in os.listdir(sourceDir):
        sourceFile = os.path.join(sourceDir, file)
        targetFile = os.path.join(targetDir, file)
        if os.path.isfile(sourceFile):
            if not os.path.exists(targetDir):
                os.makedirs(targetDir)
            callBack()

        if os.path.isdir(sourceFile):
            copyFiles(sourceFile, targetFile, callBack)


def delEmptyFolder(path):
    for root, dirs, files in os.walk(path):
        if not dirs and not files:
            os.rmdir(root)
            print("del Folder :" + root)


#找到字符串中最后出现的字符
def findLastStr(content, symbol, beginOffset=0, endOffset=-1):
    if endOffset == -1:
        endOffset = len(content) - 1

    posCheck = beginOffset
    oldPosCheck = -1
    while True:
        posCheck = content.find(symbol, posCheck)
        if posCheck > endOffset:
            return oldPosCheck

        if posCheck > -1:
            oldPosCheck = posCheck
            posCheck = posCheck + len(symbol)
        else:
            return oldPosCheck
    return oldPosCheck


def matchSymbol(content, symbolBegin, symbolEnd, beginOffset=0, endOffset=-1):
    if endOffset == -1:
        endOffset = len(content) - 1

    if symbolBegin == symbolEnd:
        print('toolsFunc.matchSymbol params error!  info: symbolBegin.' + symbolBegin + ' --- symbolEnd.' + symbolEnd)
        return -1, -1
    if endOffset != -1 and beginOffset >= endOffset:
        print('toolsFunc.matchSymbol params error!  info: beginOffset.' + str(beginOffset) + ' --- endOffset.' + str(endOffset))
        return -1, -1

    posCheck = beginOffset
    bNum = 0
    while True:
        pTmpBegin = content.find(symbolBegin, posCheck)
        pTmpEnd = content.find(symbolEnd, posCheck)
        if pTmpBegin > -1 and pTmpEnd > -1:
            if pTmpBegin < pTmpEnd:
                bNum += 1
                posCheck = pTmpBegin + len(symbolBegin)
            elif pTmpBegin > pTmpEnd:
                bNum -= 1
                posCheck = pTmpEnd + len(symbolEnd)
        elif pTmpBegin == -1 and pTmpEnd > -1:
            bNum -= 1
            posCheck = pTmpEnd + len(symbolBegin)
        elif pTmpBegin > -1 and pTmpEnd == -1:
            return -1, -1
        elif pTmpBegin == -1 and pTmpEnd == -1:
            return -1, -1

        if bNum == 0:
            return pTmpEnd, content.find(symbolBegin, beginOffset) + len(symbolBegin)

    return -1, -1


def getNameFromStr(content, pBegin, pEnd):
    tmpRet = content[pBegin:pEnd]
    tmpRet = tmpRet.strip()
    if tmpRet.find('\n') > -1:
        print('tool.getNameForStr is error find \\n.info:' + tmpRet)
    if tmpRet.find(',') > -1:
        return tmpRet.split(',')
    return tmpRet


def getEndPosByEndList(content, pBegin=0, pEndSymbol=None):
    pRet, _ = getEndPosByEndList_ex(content, pBegin, pEndSymbol)
    return pRet


def getEndPosByEndList_ex(content, pBegin=0, pEndSymbol=None):
    if not pEndSymbol:
        pEndSymbol = ['\n', '\r\n']

    pRet = len(content)
    endChar = ''
    for endSy in pEndSymbol:
        pFind = content.find(endSy, pBegin)
        if pFind > -1:
            if pRet > pFind:
                pRet = pFind
                endChar = endSy

    return pRet, endChar


#删除C++注释
def delCplusNotes(content):
    flg1 = '/*'
    flg2 = '*/'

    flg3 = '//'
    while True:
        pChar1 = content.find(flg1)
        if pChar1 > -1:
            pChar2 = content.find(flg2, pChar1)
            if pChar2 == -1:
                print('error ! can not find */ in ' + content)
            else:
                headContent = content[0:pChar1]
                subContent = content[pChar2 + len(flg2):]
                content = headContent + subContent
        else:
            break

    pCheckPos = 0
    while True:
        pChar1 = content.find(flg3, pCheckPos)
        if pChar1 > -1:
            pLinePos = findLastStr(content, '\r\n', 0, pChar1)
            if pLinePos == -1:
                pLinePos = findLastStr(content, '\n', 0, pChar1)
            if pLinePos == -1:
                pLinePos = 0
            retList = [i.start() for i in re.finditer('\"', content[pLinePos:pChar1])]
            if (len(retList) % 2) != 0:
                pCheckPos = pChar1 + len(flg3)
                continue
            pChar2 = getEndPosByEndList(content, pChar1)
            headContent = content[0:pChar1]
            subContent = content[pChar2:]
            content = headContent + subContent
        else:
            break

    content = content.replace('\r\n', '\n')
    content = content.replace('\t\n', '\n')
    content = content.replace('\n\n\n\n\n\n\n\n', '\n')
    content = content.replace('\n\n\n\n\n\n\n', '\n')
    content = content.replace('\n\n\n\n\n\n', '\n')
    content = content.replace('\n\n\n\n\n', '\n')
    content = content.replace('\n\n\n\n', '\n')
    content = content.replace('\n\n\n', '\n')
    content = content.replace('\n\n', '\n')

    return content


def delFolders(destPath):
    shutil.rmtree(destPath, True)


def delFile(filePath):
    if not os.path.exists(filePath):
        return

    if os.path.isfile(filePath):
        os.remove(filePath)
    else:
        delFolders(filePath)


def changeFileSuf(fileName, newSuf):
    pos = fileName.find('.')
    if pos == -1:
        return fileName + newSuf
    else:
        if newSuf.find('.') > -1:
            return fileName[0:pos] + newSuf
        else:
            return fileName[0:pos] + '.' + newSuf


def waitInputIdx(minIdx=None, maxIdx=None, strLine='please input idx:>>'):
    while True:
        try:
            idx = input(strLine)
            idx = int(idx)
            if minIdx and maxIdx:
                if idx >= minIdx and idx <= maxIdx:
                    return idx
                else:
                    print(f'idx need {minIdx} <= value <= {maxIdx}, try again:>>')
            else:
                return idx

        except Exception:
            # print e.message
            return ''


def showList(valList):
    for k in range(len(valList)):
        print(f"  {k} : {valList[k]}")


def parse_json_str(jsonStr: str):
    pos = 0
    bPos = 0
    flg = '/'
    isMathModel = False

    while (True):
        pos = jsonStr.find(flg, pos)
        if pos > -1:
            if isMathModel:
                jsonStr = jsonStr[:bPos - 1] + jsonStr[pos + len(flg):]
                pos = bPos
                isMathModel = False
                flg = '/'
                continue

            lineBeginPos = jsonStr.rfind('\n', 0, pos)
            lineStr = jsonStr[lineBeginPos:pos]
            num = len(re.findall('"', lineStr))

            if num % 2 == 0:
                if jsonStr[pos + 1] == '*':
                    flg = '*/'
                    isMathModel = True
                    bPos = pos
                    continue
                elif jsonStr[pos + 1] == "/":
                    lineEndpos = jsonStr.find('\n', pos)
                    jsonStr = jsonStr[:pos - 1] + jsonStr[lineEndpos - 1:]
                    continue

            pos = pos + 1
        else:
            break

    return jsonStr
