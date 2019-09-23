#!python   
# -*- coding: utf-8 -*-

# from __future__ import unicode_literals
import os
import os,sys  
import os.path
import sys
import demjson
import pickle
import re
import hashlib
import random
import binascii
import zlib
import math
import base64
import worldsDic as wd
import struct
from aesEncode import MyCrypt
import unicodedata
import chardet

from xml.etree import ElementTree  
from PIL import Image
sys.path.append('E:/magicRpg/program/clientIos/luaecode/')
import subIosRes
import toolsFunc as tool

suffixDic = 0
prefixDic = 0
xmlHead = '<?xml version="1.0" encoding="UTF-8"?>\n\
<!DOCTYPE plist PUBLIC "-//Apple Computer//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">\n\
<plist version="1.0">\n\
    <dict>\n\
        <key>frames</key>\n\
        <dict>'
xmlBody = '\n            <key>{0}</key>\n\
            <dict>\n\
                <key>rep</key>\n\
                <string>{1}</string>\n\
            </dict>'
xmlEnd = '\n        </dict>\n\
    </dict>\n\
</plist>'

# def getReplacePathList_ex(pathDic, isAdd):
#     outList = []
#     fileNameRep = {}
#     fileList = []
#     if isAdd:
#         fileNameRep = readLineFile(target + '\\..\\rep_FileName.txt')

#     for key, dirs, files in os.walk(pathDic):
#         # 列出所有文件夹
#         key = key.replace('\\', '/')
#         if key.find('/cocos') == -1 and key.find('\\cocos') == -1:
#             outList.append(key)
#         if key.find('cocos2dx') != -1:
#             outList.append(key)

#         for everyDir in dirs:
#             newDir = key + '/'+ everyDir
#             newDir = newDir.replace('\\', '/')
#             if newDir.find('/cocos') == -1 and newDir.find('\\cocos') == -1:
#                 outList.append(newDir)
#             if newDir.find('cocos2dx') != -1:
#                 outList.append(newDir)

#         #取出所有文件，并把每个文件名改变
#         recode = []
#         for everyFile in files:
#             pos = everyFile.find('.')
#             if pos == -1:
#                 print 'this file no suf' + key + '/' + everyFile
#                 continue
#             tmpFileName = everyFile[0:pos]
#             if not tmpFileName:
#                 continue

#             if key.find('/cocos') == -1 and key.find('\\cocos') == -1:
#                 fileList.append(key + '/' + everyFile)

#             if key.find('cocos2dx') != -1:
#                 fileList.append(key + '/' + everyFile)

#             if tmpFileName in fileNameRep:
#                 continue

#             tmpRepName = wd.getTmpName(random.randint(2, 4))
#             while tmpRepName in recode:
#                 tmpRepName = wd.getTmpName(random.randint(2, 4))
#             fileNameRep[tmpFileName] = tmpRepName
#             recode.append(tmpRepName)

#             # print tmpFileName + "====" + base64.b64encode(tmpFileName)

#     createRepFileName_ex(fileNameRep)

#     keyList = {}
#     if isAdd:
#         keyList = readLineFile(target + '\\..\\rep_resPath.txt', 'repStr')
#         tmpOutList = readLineFile(target + '\\..\\rep_hasCheckFodler.txt')
#         writeListToFile(outList, target + '\\..\\rep_hasCheckFodler.txt')
#         for key in tmpOutList:
#             if key in outList:
#                 outList.remove(key)
#     else:
#         writeListToFile(outList, target + '\\..\\rep_hasCheckFodler.txt')
    
#     #获取一级目录
#     firstLevF = []
#     worldS = wd.randomWorldS(len(outList) + 100)
#     for val in outList:
#         val = val.replace(pathDic, '')
#         tmpStr = val.replace('\\', '/')
#         strList = tmpStr.split('/')
#         for val in strList:
#             if val and val not in keyList:
#                 newName = worldS.pop()
#                 while newName in outList:
#                     newName = worldS.pop()
#                 keyList[val] = {'repStr':newName, 'count': 0}

#         if len(strList) == 2:
#             tmpStr = keyList[strList[1]]['repStr']
#             if not tmpStr in firstLevF:
#                 firstLevF.append(keyList[strList[1]]['repStr'])
    
#     fodlerNum = random.randint(6,  9)
#     for i in range(fodlerNum):
#         if len(firstLevF) < i + 1:
#             fName = worldS.pop()
#             while fName in firstLevF:
#                 fName = worldS.pop()
#             firstLevF.append(fName)

    
#     #4级换三级。3级换2级4级 1/3。2/3
#     #1/3。2/3替换一级目录。不换就直接换 1级目录
#     for dirs in outList:
#         dirs = dirs.replace(pathDic, '')
#         dirs = dirs.replace('\\', '/')
#         dirStrs = dirs.split('/')
#         isChangeRoot = random.randint(1, 100) > 50
#         if isChangeRoot:
#             if dirs.count('/') == 3:
#                 oldVal = dirStrs[1]
#                 newP = ''
#                 newVal = firstLevF[random.randint(0, fodlerNum - 1)]
#                 while newVal == oldVal:
#                     newVal = firstLevF[random.randint(0, fodlerNum - 1)]
#                 cPathVal = random.randint(1, 100)

#                 #缩短路径
#                 if 25 < cPathVal < 50:
#                     newP = keyList[dirStrs[3]]['repStr']
#                 elif 49 < cPathVal < 60:
#                     newP = keyList[dirStrs[2]]['repStr'] + '/' + keyList[dirStrs[3]]['repStr'] + '/' + worldS.pop()
#                 else:
#                     newP = keyList[dirStrs[2]]['repStr'] + '/' + keyList[dirStrs[3]]['repStr']
                
#                 keyList[dirs[1:]] = {'repStr':newVal + '/' + newP, 'count':1}
#                 continue
#             if dirs.count('/') == 2:
#                 oldVal = dirStrs[1]
#                 newVal = firstLevF[random.randint(0, fodlerNum - 1)]
#                 while newVal == oldVal:
#                     newVal = firstLevF[random.randint(0, fodlerNum - 1)]
#                 newP = keyList[dirStrs[2]]['repStr']
                
#                 keyList[dirs[1:]] = {'repStr':newVal + '/' + newP, 'count':1}
#                 continue

#     # 获取所有资源更名之后的列表
#     fileRepList = {}
#     for fileName in fileList:
#         fileName = fileName.replace(pathDic, '')
#         fileName = fileName.replace('\\', '/')
#         if fileName[0] == '/':
#             fileName = fileName[1:]
#         tmpBack = getRealFileName(fileName, keyList, fileNameRep)
#         fileRepList[fileName] = tmpBack
#         # adchar = chardet.detect(tmpBack)
#         if isinstance(tmpBack, unicode):
#             fileRepList[fileName] = unicodedata.normalize('NFKD', tmpBack).encode('ascii','ignore')

#     saveResFullChange(fileRepList)

#     # print count
#     return keyList

# def getRealFileName(oldFileName, repFodlerName, repFileName):
#     if oldFileName.find('cocos/') != -1 or oldFileName.find('cocos\\') != -1:
#         return oldFileName

#     resPath = ''
#     oldFileName = oldFileName.replace(resPath, '')
#     tmpRetPath = ''
#     pos = find_last(oldFileName, '/')
#     if pos != -1:
#         tmpStr = oldFileName[0:pos]
#         find = tmpStr in repFodlerName
#         while not find:
#             pos = find_last(tmpStr, '/')
#             if pos == -1:
#                 break
#             tmpStr = tmpStr[0:pos]
#             find = tmpStr in repFodlerName
        
#         if not find:
#             print 'not find key in replaceList:' + oldFileName
#             return resPath + oldFileName
#         else:
#             tmpRetPath = repFodlerName[tmpStr]['repStr'] + '/'
#             tmpStr = oldFileName[pos + 1:]
#             pos = tmpStr.find('/')
#             while pos != -1:
#                 key = tmpStr[0:pos]
#                 val = key
#                 if key in repFodlerName:
#                     val = repFodlerName[key]['repStr']
#                 else:
#                     print 'not find key in repFodlerName key:' + key
#                 tmpRetPath += val + '/'
#                 tmpStr = tmpStr[pos + 1:]
#                 pos = tmpStr.find('/')
#             pointPos = tmpStr.find('.')
#             if pointPos > -1:
#                 tmpFileName1 = tmpStr[0:pointPos]
#                 tmpFileName2 = tmpStr[pointPos:]
#                 if tmpFileName1 in repFileName:
#                     tmpFileName1 = repFileName[tmpFileName1]
#                 else:
#                     print 'δ�ҵ��ļ���:' + tmpFileName1
#                 tmpRetPath += tmpFileName1 + tmpFileName2
#             else:
#                 tmpRetPath += tmpStr
#             return resPath + tmpRetPath
#     else:
#         pointPos = oldFileName.find('.')
#         if pointPos > -1:
#             tmpFileName1 = oldFileName[0:pointPos]
#             tmpFileName2 = oldFileName[pointPos:]

#             # if tmpFileName2 == '.pb':
#             #     tmpFileName2 = '.lua'
#             if tmpFileName1 in repFileName:
#                 tmpFileName1 = repFileName[tmpFileName1]
#             else:
#                 print 'δ�ҵ��ļ���:' + tmpFileName1
#             return resPath + tmpFileName1 + tmpFileName2
#         else:
#             return resPath + oldFileName

#     return ''    

def removeFilePath(filePath):
    for root, dirs, files in os.walk(filePath, topdown=False):
        for name in files:
            os.remove(os.path.join(root, name))
        for name in dirs:
            print os.path.join(root, name)
            os.rmdir(os.path.join(root, name))

def WriteFile(filePath, all_the_text):    
    file_object = open(filePath,'wb+')    
    file_object.write(all_the_text)
    file_object.close()
    
def ReadFile(filePath):
    file_object = open(filePath, 'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

def readLineFile(file, key = None):
    dir = {}
    if not os.path.exists(file):
        return dir
    file_object = open(file, 'r')
    for line in open(file):
        line = line.strip()
        if line.find("|") == -1:
            # print("line:" + line + " 这一行有问题")
            continue
        lines = line.split("|")
        oldVal = lines[0]
        if key:
            dir[oldVal] = {key: lines[1], 'count' : 0}
        else:
            dir[oldVal] =  lines[1]

        # print("key:"+oldPath+",val:"+newPath)
    file_object.close()
    # print("文件："+ file + " ==== 读取到替换数目：" + str(len(dir)) )
    return dir
    
def createDir(path):
    path = os.path.dirname(path)
    path = path.replace("\\", "/")
    paths = path.split("/")
    tmpPath = ''
    for path in paths:
        tmpPath = tmpPath + path + "/"
        if not os.path.exists(tmpPath):
            os.mkdir(tmpPath)
            
def get_FileMd5(filePath):
    s_file = open(filePath, "rb")
    s_content = s_file.read()
    s_file.close()
    return (hashlib.md5(s_content).hexdigest()).strip()

def getDirList(path):
    retList = []
    for root, dirs, files in os.walk(path):
        for everyDir in dirs:
            newPath = root + '\\' + everyDir
            newPath = newPath.replace(path + '\\', '')
            newPath = newPath.replace('\\', '/')
            if newPath.find('/') > -1:
                retList.append(newPath)

    return retList

def randomList(allNum, num):
    ret = []
    while(len(ret) < num):
        randNum = random.randint(1, allNum)
        if not (randNum - 1) in ret:
            ret.append(randNum - 1)
    return ret

def matchStringMin(str1, str2):
    ret = ''
    count = 0
    for x in str1:
        if str2[count] == x:
            ret = ret + x
            count = count + 1
        else:
            return ret
    return ret

def getFileNameSuffix(fileName):
    fileName = fileName.replace("\\", '/')
    if fileName.find('.') > -1:
        pos = fileName.find('.')
        pos1 = 0
        while(pos > -1):
            pos1 = pos1 + pos + 1
            if pos1 + 1 < len(fileName):
                lastStr = fileName[pos1:]
                pos = lastStr.find('.')
            else:
                break
            
        # print fileName + "|" + fileName[pos1:]
        return fileName[pos1 - 1:]
    return ''


def getRandomChar(num, key1 = 33, key2 = 125):
    ret = ""
    count = 1
    while (count <= num):
        ret = ret + chr(random.randint(key1, key2))
        count = count + 1

    return ret

def initFilePrefix():
    global prefixDic
    prefixDic = {'.png':'CCZp', 
                 '.jpg':'CCZp', 
                 '.plist':'WSZRx', 
                 '.pvr':'CCZp', 
                 '.txt':'WSZRx', 
                 '.json':'WSZRx',
                 '.xml':'WSZRx',
                 '.lua4':'xxteaSign',
                 '.lua':'xxteaSign',
                 '.pkm':'CCZp',
                 '.pvr.czz':'CCZp',
                 '.lua8':'xxteaSign',
                 '.czz':'CCZp',
                 '.cfg':'xxteaSign',
                 '.mp3':'CCZp',
                 '.pb':'xxteaSign',
                 '.wav':'CCZp',
                 '.tmx':'CCZp',
                 '.ttf':'CCZp',
                 '.fsh':'CCZp',
    }

def initFileSuffix():
    global suffixDic
    suffixDic = {1:['.png'], 
                 2:['.jpg'], 
                 3:['.plist', '.png'], 
                 4:['.pvr'], 
                 5:['.txt'], 
                 6:['.json'],
                 7:['.xml'],
                 8:['.lua4'],
                 9:['.pkm','.plist'],
                 10:['.pvr.czz', '.plist'],
                 11:['.lua8'],}


def getFileSuffix():
    idx = random.randint(1, len(suffixDic))
    return suffixDic[idx]

def getFileNum():
    return random.randint(2000, 2600)

def getFileLength():
    return random.randint(512 * 1, 1024 * 20)

def createFileContent(fileFullpath, count, size = None):
    fileFullpath = tool.unicodeToAscii(fileFullpath)

    if fileFullpath.find('.pb') > -1 or fileFullpath.find('.gitignore') > -1 or fileFullpath.find('.ttf') > -1 or fileFullpath.find('.fsh') > -1:
        return False
    if os.path.exists(fileFullpath.replace(target, matchFolder)):
        print 'createFileContent error ! file is exist'
        return False
    suf = getFileNameSuffix(fileFullpath)
    fileLength = getFileLength()
    if size:
        if size > 30 * 1024:
            size = 20 * 1024
        fileLength = int(size / 3)
        fileLength = random.randint(fileLength, fileLength * 4)

    content = getRandomChar(fileLength, 1, 125)
    content = tool.unicodeToAscii(content)
    # content = tool.to_str(content)
    crypt =  MyCrypt("swcfiwksjcnrmcjw")
    content = crypt.myencrypt(content)
    content = zlib.compress(content)

    contentSize =  len(content)
    endContent = content[random.randint(18, 50):random.randint(contentSize - 60, contentSize)]
    midContent = getRandomChar(random.randint(2, 8), 1, 125)
    suf = suf.encode('ascii','ignore')
    content = prefixDic[suf] + midContent + endContent
    print 'file' + str(count) + ':' + fileFullpath + "====" + str(len(content) / 1024) + "KB"
    WriteFile(fileFullpath, content)
    return True

def getReplacePathList(pathDic):
    outList = []
    for key, value in pathDic.items():
        if value['files'] > 15 or value['dirs'] > 5:
            outList.append(key)

    for idx1 in range(len(outList)):
        for idx2 in range(len(outList)):
            if idx1 != idx2:
                str1 = outList[idx1]
                str2 = outList[idx2]
                if str1 != str2 and str1.find(str2) > -1:
                    outList[idx2] = '1'

    repList = list(set(outList))

    tmpLen = len(repList)
    for idx in range(tmpLen):
        if repList[tmpLen - idx - 1] == '1':
            del repList[tmpLen - idx - 1]

    return repList

def getReplacePathList_ex_ex(pathDic, isAdd):
    # 做到文件散布, 需要把文件统计出来, 做平均分布
    # 剔除掉4级目录, 只留3级以下目录 *
    # 根据文件体积, 做分组
    # 然后每组随机到文件夹下. 避免文件夹下文件名重复
    # 统计文件夹文件数据, 准备做杂质文件
    groupSize = [50 * 1024, 1024 * 1024 * 1024]
    groups = {}
    fullResFileRep = {}
    oldFileList = []
    if isAdd:
        ret = {}
        def func(lineStr):
            lineStrs = lineStr.split('|')
            ret[lineStrs[0]] = lineStrs[1]
        tool.ReadLineFile(repFullFileNameCache1, func)
        fullResFileRep = ret

    tmpPath = pathDic.replace('\\', '/')
    for root, _, files in os.walk(pathDic):
        for everyFile in files:
            if everyFile[0] == '.':
                continue

            # 取资源路径
            fullFileName = root + '/' + everyFile
            fileName = fullFileName.replace('\\', '/')
            fileName = fileName.replace(tmpPath, '')
            if fileName[0] == '/':
                fileName = fileName[1:]

            if fileName in fullResFileRep:
                continue

            if fileName.find('cocos') == -1:
                oldFileList.append(fileName)
            elif fileName.find('cocos2dx') != -1 and fileName.find('cocos/cocos2d') == -1:
                oldFileList.append(fileName)

            # 文件按大小分组
            if fileName in oldFileList:
                fileSize = tool.get_FileSize(fullFileName)
                for size in groupSize:
                    if fileSize <= size:
                        sizeKey = str(size)
                        if sizeKey not in groups:
                            groups[sizeKey] = []
                        groups[sizeKey].append(fileName)
                        break
            
    # 获取所有文件夹数量
    oldPathList = {}
    oldSplitPath = {}
    if isAdd:
        ret = {}
        def func1(lineStr):
            lineStrs = lineStr.split('|')
            ret[lineStrs[0]] = lineStrs[1]
        tool.ReadLineFile(repSplitPathCache, func1)
        oldSplitPath = ret

    for fileName in oldFileList:
        # 不在根目录下放文件
        if fileName.find('/') >-1:
            splitPath = fileName.split('/')
            tmpPath = ''
            if len(splitPath) > 4 and not isAdd:
                continue
            for path in splitPath:
                if path.find('.') != -1:
                    continue

                if tmpPath:
                    tmpPath += '/' + path
                else:
                    tmpPath += path
                
                if tmpPath not in oldPathList:
                    oldPathList[tmpPath] = {'files':[]}
                
                if path:
                    if path not in oldSplitPath:
                        oldSplitPath[path] = 1
    
    # 路径换名字
    worldS = wd.randomWorldS(len(oldSplitPath) * 2)
    for path in oldSplitPath:
        if oldSplitPath[path] == 1:
            newPathName = tool.unicodeToAscii(worldS.pop())
            while newPathName in oldSplitPath:
                newPathName = worldS.pop()
            oldSplitPath[path] = newPathName

    # 分组投放所有文件进文件夹
    for _,tmpGroup in groups.items():
        keys = oldPathList.keys()
        avgNum = int(len(tmpGroup) / len(keys))
        if avgNum < 1:
            avgNum = 1
        for groupItem in tmpGroup:
            if groupItem in fullResFileRep:
                continue

            fodlerIdx = random.randrange(len(keys))
            _, _, suf = tool.getFile_path_name_suf(groupItem)

            newPath = keys[fodlerIdx]
            filesList = oldPathList[newPath]['files']

            # 新文件名
            newFileName = tool.unicodeToAscii( wd.getTmpName( random.randint(2, 4) ) )
            while newFileName in filesList:
                newFileName = wd.getTmpName(random.randint(2, 4))
            filesList.append( newFileName )
            
            if len(filesList) >= avgNum and random.randint(1, 100) > 50:
                # fullFodler.append(keys[fodlerIdx])
                if len(keys) > 1:
                    keys.remove(newPath)
                    # print  newPath + ' fodler is full ... num : ' + str(len(filesList))

            #记录文件更名信息
            newFullFile = getRepPath(newPath, oldSplitPath) + '/' + newFileName + getRepSuf(suf)
            newFullFile = tool.unicodeToAscii(newFullFile)
            fullResFileRep[groupItem] = newFullFile
    
    saveResFullChange(fullResFileRep)
    creatRepaceList_ex(oldSplitPath)
    return oldPathList, oldSplitPath

#获取文件后缀修改后的值
def getRepSuf(oldSuf):
    return oldSuf

#根据原路径获得改名后的新路径            
def getRepPath(oldPath, oldSplitPath):
    ret = ''
    oldPaths = oldPath.split('/')
    for val in oldPaths:
        if val and val in oldSplitPath:
            val = oldSplitPath[val]
        
        if ret:
            ret += '/' + val
        else:
            ret = val

    return ret

# 保存所有资源 改变前后的值到文件, 供游戏启动读取
def saveResFullChange(resPathList):
    totalNum = len(resPathList)
    sContent = ''
    fContent = '' + struct.pack('H', totalNum)
    for oldFile, newFile in resPathList.items():
        fContent += struct.pack('H', len(oldFile))
        fContent += oldFile
        fContent += struct.pack('H', len(newFile))
        fContent += newFile
        sContent += oldFile + '|' +newFile + '\r\n'
    targetFile = repFullFileNameCache2
    WriteFile(targetFile, fContent)
    WriteFile(repFullFileNameCache1, sContent)

    cmd = "E:/magicRpg/program/clientIos/Arts/texturepacker_Tool/czzFileDel/magic.exe -CCZPkm -s {srcFile} -d {dstPath} -ex {spaceNum}".format(srcFile = targetFile, dstPath= targetFile, spaceNum = 0)
    print("cmd:" +cmd)
    os.system(cmd)
    
    s_file = open(targetFile, "rb")
    s_content = s_file.read()
    
    # print srcFile + "--------" + dstFile
    subIosRes.spaceNum = 4
    subIosRes.needXxtea = True
    subIosRes.specSpace = '1111'
    newContent = subIosRes.randomBit(s_content, targetFile)
    open(targetFile, "wb+").write(newContent)

def find_last(string,str):
    last_position = -1
    while True:
        position = string.find(str, last_position+1)
        if position == -1:
            return last_position
        last_position = position

def writeListToFile(tmpList, fileName):
    outStr = ''
    for key in tmpList:
        if key:
            outStr += key + "|1" +'\r\n'
    WriteFile(fileName, outStr)

# def createRepFileName_ex(repList):
#     outStr = ''
#     # outStr2 = xmlHead
#     # dictItem = xmlBody

#     for key in repList:
#         if key:
#             outStr += key + "|" + repList[key] +'\r\n'
#             # outStr2 += dictItem.format(key, repList[key])
#     WriteFile(target + '\\..\\rep_FileName.txt', outStr)

#     # outStr2 += xmlEnd
#     # WriteFile(target + '\\..\\initFile.lua', outStr2)

def creatRepaceList_ex(repList):
    outStr = ''

    for key, val in repList.items():
        if key:
            outStr += key + '|' + val + '\r\n'

    WriteFile(repSplitPathCache, outStr)

def getMatchFolderInfo(matchFile):
    if not os.path.exists(matchFile):
        print u'需要匹配的文件夹不存在'
    
    pathDic = {}
    for root,dirs,files in os.walk(matchFile):
        if root.find('cocos') > -1:
            continue

        key = root.replace(matchFile, "")
        pathDic[key] = {'dirs':len(dirs), 'files':len(files), 'suf':{}}

        nameType = None
        suffix = None
        ignoTime = int(len(files) / 10) + 1
        
        for everyFile in files:
            if nameType == None:
                nameType = everyFile
            else:
                tmpNameType = matchStringMin(nameType, everyFile)
                if ignoTime > 0 and tmpNameType != nameType:
                    ignoTime = ignoTime - 1
                    if len(tmpNameType) > 0  and len(tmpNameType) < len(nameType):
                        nameType = tmpNameType
                else:
                    nameType = tmpNameType

            fileSize = os.path.getsize(root + '/' + everyFile)
            suffix = getFileNameSuffix(everyFile)
            if suffix != '':
                val = pathDic[key]['suf'].get(suffix, "-1")
                if val == '-1':
                    pathDic[key]['suf'][suffix] = {'num':1,'size':fileSize}
                else:
                    pathDic[key]['suf'][suffix]['num'] += 1
                    pathDic[key]['suf'][suffix]['size'] += fileSize

        if len(files) > 1:
            pathDic[key]['nameTy'] = nameType
        else:
            pathDic[key]['nameTy'] = ''
        
        #命名规则不再需要返照源. 源的名字都随机换掉了
        pathDic[key]['nameTy'] = ''

        if nameType != '' and len(files) > 0:
            if len(files[-1]) > len(nameType):
                nextNum = ord(files[-1][len(nameType)])
                if 49 <= nextNum <=57:
                    nextNum = 1
                else:
                    nextNum = 2

                pathDic[key]['nextChr'] = nextNum
            else:
                pathDic[key]['nextChr'] = 3
        else:
            pathDic[key]['nextChr'] = 3

    for key in pathDic:
        suff = pathDic[key]['suf']
        for val in suff:
            suff[val]['ave'] = int(suff[val]['size'] / suff[val]['num'])
    # print pathDic
    return pathDic

def creatMatchFiles(dstPath, oldDic, totalFileNum, pathRepList):
    count = 0
    for key, info in oldDic.items():
        dirNum = info['dirs']
        fileNum = info['files'] 
        nameBegin = info['nameTy']
        nextChr = info['nextChr']

        suf = info['suf'] #{}
        sufLen = len(suf)

        dirNum = math.ceil(float(dirNum) / 2 * 1)
        fileNum = math.ceil(float(fileNum) / 5 * 3)
        dirNum = int(dirNum)
        fileNum = int(fileNum)

        # key = key.replace('\\', '/')
        # keys = key.split('/')

        createDir(dstPath + key + "/")
        for _ in range(dirNum):
            tmpFoldername = wd.getRandomTwoWorld()
            filePath = dstPath + key + "/" + tmpFoldername
            createDir(filePath + "/")
            
            randNum = random.randint(1, 5)
            tmpSuffix = getFileSuffix()
            for _ in range(randNum):
                tmpFileName = wd.getTmpName(random.randint(2, 4))
                for everySuf in tmpSuffix:
                    fileAllPath = filePath + "/" + tmpFileName + everySuf
                    if createFileContent(fileAllPath, count):
                        count = count + 1
                        if count > totalFileNum:
                            return count
        
        for _ in range(fileNum):
            tmpFileName = wd.getTmpName(random.randint(1, 2))
            tmpNameBegin = nameBegin
            if nextChr == 1:
                tmpNameBegin = nameBegin + chr(random.randint(49, 57))
            elif nextChr == 2:
                tmpNameBegin = nameBegin + chr(random.randint(65, 90) + random.randint(0,  1) * 32)
            fileAllPath = dstPath + key + "/" + tmpNameBegin + tmpFileName
            randSuf = random.randint(0, sufLen - 1)
            tmpSuffix = suf.keys()[randSuf]
            tmpSize = suf[tmpSuffix]['ave']
            fileAllPath = fileAllPath + tmpSuffix
            if createFileContent(fileAllPath, count, tmpSize):
                count = count + 1
                if count > totalFileNum:
                    return count

    return count

def creatMatchFiles_ex(dstPath, oldPathList, totalFileNum, pathRepList):
    count = 0
    for oldPath, info in oldPathList.items():
        fileList = info['files']
        fileNum = len(fileList)
        fileNum = random.randint( int(fileNum / 4), int(fileNum / 2))

        # 10分之1的几率添加一个路径
        newPath = getRepPath(oldPath, pathRepList)
        dirPath = newPath
        dirNum = 0
        pathLayers = len(oldPath.split('/'))
        if pathLayers > 1:
            randNum = random.randint(1, 100)

            worldS = wd.randomWorldS(1)
            while worldS[0] in pathRepList:
                worldS = wd.randomWorldS(1)
            # 加一个下一级目录
            if 20 <= randNum <= 29:
                dirNum = 1
                dirPath += '/' + worldS[0] 
            # 加一个同级目录
            elif 50 <= randNum <= 60:
                dirNum = 1
                dirPath = dirPath[0:tool.find_last(dirPath, '/')]
                dirPath += '/' + worldS[0]

        # 添加新目录
        if dirNum > 0:
            createDir(dstPath + '/' + dirPath + "/")
            for _ in range(dirNum):
                filePath = dstPath + '/' + dirPath
                createDir(filePath + "/")
                
                randNum = random.randint(1, 5)
                tmpSuffix = getFileSuffix()
                for _ in range(randNum):
                    tmpFileName = wd.getTmpName(random.randint(2, 4))
                    for everySuf in tmpSuffix:
                        fileAllPath = filePath + "/" + tmpFileName + everySuf
                        if createFileContent(fileAllPath, count):
                            count = count + 1
                            if count > totalFileNum:
                                return count
        
        createDir(dstPath + '/' + newPath + "/")
        for _ in range(fileNum):
            tmpFileName = wd.getTmpName(random.randint(2, 4))
            fileAllPath = dstPath + '/' + newPath + '/' + tmpFileName
            tmpSuffix = getFileSuffix()
            randSuf = random.randrange(len(tmpSuffix))
            tmpSuffix = tmpSuffix[randSuf]
            fileAllPath = fileAllPath + tmpSuffix
            if createFileContent(fileAllPath, count):
                count = count + 1
                if count > totalFileNum:
                    return count
                
    return count


def createFiles(dstPath, hasCount, totalFileNum):
    count = hasCount
    while (count < totalFileNum) :
        tmpFolderPath = wd.getFileFolderName()

        for filePath in tmpFolderPath:
            filePath = dstPath + "/" + filePath 
            createDir(filePath + "/")
        
            randNum = random.randint(3, 12)
            tmpSuffix = getFileSuffix()
            for _ in range(randNum):
                tmpFileName = wd.getTmpName(random.randint(2, 4))
                for everySuf in tmpSuffix:
                    fileAllPath = filePath + "/" + tmpFileName + everySuf
                    if createFileContent(fileAllPath, count):
                        count = count + 1
                    if count > totalFileNum:
                        return

def main():
    print __file__ + ' working in ' + os.getcwd()
    os.chdir(os.path.dirname(__file__))
    print __file__ + ' working in ' + os.getcwd()

    channel = 'hajy'
    global target
    target = '.\\target' + channel
    
    global repFullFileNameCache1 
    repFullFileNameCache1 = channel + '/rep_resFullPathName.txt'

    global repFullFileNameCache2
    repFullFileNameCache2 = channel + '/initFile_ex.lua'

    global repSplitPathCache
    repSplitPathCache = channel + '/rep_resPath.txt'

    global matchFolder
    matchFolder = '../../sg1'
    wd.init()

    isAdd = False
    pathRepList, oldSplitPath = getReplacePathList_ex_ex(matchFolder, isAdd)

    # return
    if isAdd:
        return

    initFileSuffix()
    initFilePrefix()

    removeFilePath(target)
    totalFileNum = getFileNum()
    hasCreateCount = creatMatchFiles_ex(target, pathRepList, totalFileNum, oldSplitPath)
    createFiles(target,  hasCreateCount, totalFileNum)

    print u'生成完成'

if __name__ == '__main__':  
    main()