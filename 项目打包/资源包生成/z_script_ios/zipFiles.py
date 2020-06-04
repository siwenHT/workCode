#! /usr/bin/env python
# -*- coding: utf-8 -*-


import os
import sys
workPath = os.getcwd()
print workPath + '/outAppendRes'
sys.path.append(workPath + '/outAppendRes')
import toolsFunc as tool
import subIosRes
import worldsDic as wd

impurityFileList = []
outZipNum = 0
standSufCfg = []
prefixDic = None

def initFilePrefix():
    global prefixDic
    prefixDic = [
                 '.png', 
                 '.jpg', 
                 '.plist', 
                 '.txt', 
                 '.json',
                 '.lua4',
                 '.lua',
                 '.lua8',
                ]

def tmpWriteFile():
    listStr = [1024, 1024 * 1024, 1024 * 1024 *1024]

    tool.delFolders(tool.os.path.abspath('hexBin.bin'))
    with open('hexBin.bin', 'wb')as fp:
        fp.write('PK')
        for x in listStr:
            a = tool.struct.pack('L', x)
            fp.write(a)
            fp.write('|')
    
    print('done')

def getSufCfg():
    ret = []
    sufCfg = ['.zip', '.cfg', '.data', '.rar', '.gzip']
    ret.append(tool.random.choice(sufCfg))
    ret.append(tool.random.choice(sufCfg))
    return ret

def listFile(limitSize, oldpath, delPath = False, isRandom = False):
    global outZipNum
    retList = {}
    oldpath = oldpath.replace('\\', '/')
    path = tool.os.path.abspath(oldpath)
    linuxPath = path.replace("\\", "/")
    for root, _, files in tool.os.walk(path):
        for everyFile in files:
            srcFile = tool.os.path.join(path, root + "/" + everyFile)
            if srcFile.find('cocos/') > -1 or srcFile.find('cocos\\') > -1:
                continue
            fileSize = tool.get_FileSize(srcFile)
            isOK = False
            if isRandom:
                tmpNum = tool.random.randint(1, 200)
                if fileSize >= 100 * 1024 and tmpNum >= 50 and tmpNum <= 75:
                    isOK = True
            # 随机一些lua 文件出来
            if (fileSize <= limitSize or srcFile.find('.pb') > -1 or isOK) and srcFile.find('.mp3') == -1:
                if isRandom and False:
                    tmpStrFile = srcFile.replace("\\", "/").replace(linuxPath + "/", '')
                    if tmpStrFile in impurityFileList and tool.random.randint(0, 20) == 2 and srcFile.find('.pb') == -1 and 5 * 1024 <= fileSize <= 10 * 1024:
                        print srcFile + ' is Out Zip.'
                        outZipNum = outZipNum + 1
                        continue

                srcFile = srcFile.replace('\\', '/')
                if delPath:
                    srcFile = srcFile.replace(linuxPath + "/", '')
                retList[srcFile] = fileSize

    return retList

def combinFiles(fileList, targetFile, fileSizeList):
    totalNum = len(fileList)

    s_content = '' + tool.struct.pack('H', totalNum)
    fContent = ''
    fSize = 0
    for tmpFile in fileList:
        fSize += fileSizeList[tmpFile]
        s_content += tool.struct.pack('L', fSize)
        fContent += tool.ReadFile(tmpFile)
        # print 'del file', tmpFile
        tool.defFile(tmpFile)
        delFileList[tmpFile] = targetFile
        
    s_content += fContent
    subIosRes.spaceNum = 4
    subIosRes.needXxtea = True
    newContent = subIosRes.randomBit(s_content, targetFile)

    #很有可能文件被删除了, 导致文件夹不存在.（如果文件夹下文件都不见了. 则文件可能没有创建出来）
    if not tool.os.path.exists(tool.os.path.dirname(targetFile)):
        tool.createDir(targetFile)
        print "zip Path not Exist , Be careful", targetFile
    tool.WriteFile(r"%s" % targetFile, newContent)

def randomCombin(fileList, combinSize, path):
    if not fileList:
        return {}
    retDic = {}
    listFile = fileList.keys()

    count = 0
    # 把已经缓存下来的, 先zip掉
    if tool.os.path.exists(cacheFile):
        ret = {}
        def func(lineStr):
            lineStrs = lineStr.split('|')
            zipName = path + lineStrs[0]
            ret[zipName] = []
            for i in range(len(lineStrs) - 1):
                fileName = path + lineStrs[i + 1]

                #预处理文件删除的情况
                if fileName in listFile:
                    listFile.remove(fileName)
                    ret[zipName].append(fileName)
                else:
                    print "file not exists in listFile" , fileName

            if ret[zipName]:
                combinFiles(ret[zipName], zipName, fileList)
            else:
                del ret[zipName]
        tool.ReadLineFile(cacheFile, func)
        print 'oldZipFile num :' + str(len(ret))
        retDic = ret

    #随机取文件
    zipCount = 0
    leftNum = len(listFile)
    while leftNum > 0:
        taskList = []
        totalSize = 0
        fileNum = 0
        combinSize = tool.random.randint(30 * 1024, 80 * 1024)
        while True:
            leftNum = len(listFile)
            # print str(leftNum) + 'leftNum'
            chooseNum = tool.random.randint(1, leftNum) - 1
            filePath = listFile[chooseNum]
            del listFile[chooseNum]
            chooseSize = fileList[filePath]
            totalSize += chooseSize
            taskList.append(filePath)
            fileNum += 1
            if totalSize > combinSize or leftNum <= 1:
                break
        
        tmpNum = tool.random.randint(0, len(taskList) - 1)
        tmpFilePath = taskList[tmpNum]

        tmpSuf = tool.random.choice(standSufCfg)
        tmpFilePath = tool.changeFileSuf(tmpFilePath, tmpSuf)

        # lua8
        while tmpFilePath in retDic:
            tmpNum = tool.random.randint(0, len(taskList) - 1)
            tmpFilePath = taskList[tmpNum]
            tmpFilePath = tool.changeFileSuf(tmpFilePath, tmpSuf)

        if tmpFilePath in retDic:
            print tmpFilePath + retDic[tmpFilePath]
        
        retDic[tmpFilePath] = taskList
        zipCount += 1

        combinFiles(taskList, tmpFilePath, fileList)

        if count < fileNum:
            count = fileNum

        if len(listFile) == 0:
            break

    print 'Max file in Zip ' + str(count) + ", zipFile num :" + str(len(retDic))+ ',zipcount :' + str(zipCount) + ',outZipNum :' + str(outZipNum) + ",fileList len :" + str(len(fileList))
    return retDic

def saveCombinDicToFile(combinFileDic, oldFileList, path, destFile):
    tool.delFolders(tool.os.path.abspath(destFile))
    path = path.replace('\\', '/')
    fileList = {}
    fContent = ''
    for zipFile, val in combinFileDic.items():
        zipCellContent = ''
        for idx in range(len(val)):
            sourceFile = val[idx]
            sourceFile = sourceFile.replace('\\', '/')
            sourceFile = sourceFile.replace(path, '')
            zipFile = zipFile.replace('\\', '/')
            zipFile = zipFile.replace(path, '')
            if sourceFile in oldFileList:
                fileList[sourceFile] = {'file':zipFile, 'num':idx + 1}
            zipCellContent += '|' + sourceFile
        zipCellContent = zipFile + zipCellContent + '\r\n'
        fContent += zipCellContent 

    tmpCont = ''    
    for fileName,  oldzipFile in delFileList.items():
        fileName = fileName.replace('\\', '/')
        fileName = fileName.replace(path, '')
        zipFile = oldzipFile.replace('\\', '/')
        zipFile = zipFile.replace(path, '')
        tmpCont += fileName + '|' + zipFile + '\r\n'

        if fContent.find(fileName) == -1:
            print fileName + ' bai shan chu l ...........' + zipFile
        if oldzipFile not in combinFileDic:
            print fileName + '%'+ zipFile
    
    # tool.WriteFile('delFileList.txt', tmpCont)

    totalLine = len(fileList)
    tool.createDir(cacheFile)
    tool.WriteFile(cacheFile, fContent)
    sContent = '' + tool.struct.pack('H', totalLine)

    for key, val in fileList.items():
        zipFile = val['file']
        idx = val['num']
        fileName = key
        sContent += tool.struct.pack('H', len(fileName))
        sContent += fileName
        sContent += tool.struct.pack('H', len(zipFile))
        sContent += zipFile
        sContent += tool.struct.pack('H', idx)

    destFile = tool.os.path.abspath(destFile)
    tool.WriteFile(destFile, sContent)
    cmd = os.getcwd() + "/czzFileDel/magic.exe -CCZPkm -s {srcFile} -d {dstPath} -ex {spaceNum}".format(srcFile = destFile, dstPath= destFile, spaceNum = 0)
    print("cmd:" +cmd)
    tool.os.system(cmd)

    s_file = open(destFile, "rb")
    s_content = s_file.read()
    
    # print srcFile + "--------" + dstFile
    subIosRes.spaceNum = 4
    subIosRes.needXxtea = True
    newContent = subIosRes.randomBit(s_content, destFile)
    print("s_content:" + str(len(s_content)) + ",newContent:" + str(len(newContent)) + ",sContent:" + str(len(sContent)))
    open(destFile, "wb+").write(newContent)

def splitFiles(oldFilePath, combinFilesList, splitFile, splitHexFile, fodlerInfo):
    limitSize = tool.random.randint(200 * 1024, 300 * 1024)
    targetFileList = {}
    curFodlerInfo = {}
    fileNumRecord = {}
    if combinFilesList:
        combinKeys = combinFilesList.keys()
    else:
        combinKeys = []

    for i in range(500):
        curFodlerInfo[i] = []

    oldFilePath = oldFilePath.replace('\\', '/')
    newpath = tool.os.path.abspath(oldFilePath)
    linuxPath = newpath.replace("\\", "/")
    for root, _, files in tool.os.walk(newpath):

        # 获取大文件
        for everyFile in files:
            srcFile = root + "\\" + everyFile
            if srcFile.find('cocos/') > -1 or srcFile.find('cocos\\') > -1:
                continue
            fileSize = tool.get_FileSize(srcFile)
            # 随机一些lua 文件出来
            if fileSize >= limitSize and srcFile.find('.ttf') == -1 and tool.random.randint(1, 2) == 2:
                srcFile = srcFile.replace('\\', '/')
                if srcFile not in combinKeys:
                    srcFile = srcFile.replace(linuxPath + "/", '')
                    targetFileList[srcFile] = fileSize
                else:
                    print srcFile , ' is in combinZipFiles'

        #获取当前文件夹目录结构
        fileNum = len(files)
        if fileNum > 0:
            linuxRoot = root.replace('\\', '/')
            if root.find('cocos') > -1:
                continue
            RelativePath = linuxRoot.replace(linuxPath + '/', '')
            
            fileNumRecord[RelativePath] = fileNum
            if not curFodlerInfo.has_key(fileNum):
                curFodlerInfo[fileNum] = []
            curFodlerInfo[fileNum].append(RelativePath)
    
    newTxtContent = ''
    for fileRelName, fileSize in targetFileList.items():
        pos = tool.findLastStr(fileRelName, '/')
        #一级目录不处理
        if pos > -1:

            RelativePath = fileRelName[:pos]
            realFileName = fileRelName[pos + 1:]
            #保存一下记录
            splitFileRecode = []
            targetFileList[fileRelName] = splitFileRecode

            #分成几个文件决策
            splitNum = 2
            if fileSize >= 500 * 1024:
                splitNum = tool.random.randint(2, 5)

            avgSize = int(tool.math.floor(fileSize / splitNum))
            tmpSize1 = int(tool.math.floor(avgSize * 2 / 3))
            tmpSize2 = int(tool.math.floor(avgSize * 4 / 3))
            fileContent = tool.ReadFile(linuxPath + '/' + fileRelName)

            newTxtContent += fileRelName + '['+ str(fileSize) + ']' + ' : '

            splitSize = 0
            for i in range(splitNum):
                if fileSize == splitSize:
                    break
                
                tmpSize = tool.random.randint(tmpSize1, tmpSize2)
                if splitSize + tmpSize >= fileSize:
                    tmpSize = fileSize - splitSize
                    splitSize = fileSize
                elif fileSize - splitSize - tmpSize < 30 * 1024:
                    tmpSize = fileSize - splitSize
                    splitSize = fileSize
                elif i == splitNum -1:
                    tmpSize = fileSize - splitSize
                    splitSize = fileSize
                else:
                    splitSize += tmpSize

                splitContent = fileContent[:tmpSize]
                splitContent = tool.struct.pack('L', tmpSize) + splitContent
                fileContent = fileContent[tmpSize:]

                #选择放入文件
                for i in range(499):
                    if len(curFodlerInfo[i + 1]) > 0 and RelativePath not in curFodlerInfo[i + 1]:
                        tmpFileFodler = curFodlerInfo[i +  1].pop()
                        curFodlerInfo[i + 2].append(tmpFileFodler)
                        fileNumRecord[tmpFileFodler] += 1
                        tmpSuf = tool.random.choice(prefixDic)
                        
                        newFileName = ''
                        newFilePath = ''
                        while True:
                            newFileName = tool.unicodeToAscii( wd.getTmpName( tool.random.randint(2, 4) ) )
                            newFilePath = linuxPath + '/' + tmpFileFodler + '/' + newFileName + tmpSuf
                            if not tool.os.path.exists(newFilePath):
                                break

                        tool.WriteFile(newFilePath, splitContent)

                        newTxtContent += tmpFileFodler + '/' + newFileName + tmpSuf + '[' + str(tmpSize) + ']'
                        splitFileRecode.append(tmpFileFodler + '/' + newFileName + tmpSuf)
                        break
            
            newTxtContent += '\r\n'
            
            #删除掉原文件
            curFodlerInfo[fileNumRecord[RelativePath]].remove(RelativePath)
            fileNumRecord[RelativePath] -= 1
            curFodlerInfo[fileNumRecord[RelativePath]].append(RelativePath)

            tool.defFile(linuxPath + '/' + fileRelName)
        else:
            print 'targetFileList error!', fileRelName

    #保存删除记录到文件
    txtContent = ''
    hexContent = '' + tool.struct.pack('H', len(targetFileList))
    for fileRelName, fileInfo in targetFileList.items():
        if isinstance(fileInfo, list):
            hexContent += tool.struct.pack('H', len(fileRelName))
            hexContent += fileRelName
            txtContent += fileRelName + '|'

            hexContent += tool.struct.pack('H', len(fileInfo))
            for tmpFile in fileInfo:
                hexContent += tool.struct.pack('H', len(tmpFile))
                hexContent += tmpFile
                txtContent += tmpFile + '#'
            txtContent += '\r\n'
        else:
            print fileRelName + ' splitInfo error! '

        
    tool.WriteFile(splitFile, newTxtContent)
    tool.WriteFile(splitHexFile, hexContent)

    destFile = splitHexFile
    cmd = os.getcwd() + "/czzFileDel/magic.exe -CCZPkm -s {srcFile} -d {dstPath} -ex {spaceNum}".format(srcFile = destFile, dstPath= destFile, spaceNum = 0)
    print("cmd 1:" +cmd)
    tool.os.system(cmd)

    s_file = open(destFile, "rb")
    s_content = s_file.read()
    
    # print srcFile + "--------" + dstFile
    subIosRes.spaceNum = 4
    subIosRes.needXxtea = True
    newContent = subIosRes.randomBit(s_content, destFile)
    print("s_content:" + str(len(s_content)) + ",newContent:" + str(len(newContent)) + ",hexContent:" + str(len(hexContent)))
    open(destFile, "wb+").write(newContent)

    #把文件分布统计到文件中
    con = ''
    for key, info in curFodlerInfo.items():
        if info:
            con += str(key) + "  :  "
            for one in info:
                con += one + ","
            con += '\r\n'
    
    tool.WriteFile(fodlerInfo, con)

def main():
    # 得到文件列表, 设置过滤值 50 * 1024.
    # 然后用随机，找到一个文件, 把文件所在目录作为生成合成文件目录.
    # 随机取文件, 直到文件接近设置值， 合并文件, 记录合并文件路径.
    # 所有文件都处理完毕后，保存合并记录到文件,准备读取.

    # 考虑更新问题.少量更新的话，查找合并表. 如果在合并表中, 找到合并文件, 把文件插入进去.
    print os.getcwd()
    initFilePrefix()
    channel = 'hdmy'
    limitSize = tool.random.randint(25, 50) * 1024
    tool.showParams()
    argvLen = len(tool.sys.argv)
    if argvLen >= 2:
        channel = tool.sys.argv[1]
    
    global standSufCfg
    standSufCfg = getSufCfg()
    path = "E:/magicRpg/magic_ios/sg" + channel  + "/"
    relativePath = '../sg' + channel + '/'
    destFile = 'outAppendRes/' + channel + '/DeprecatedExtend_ex.lua'
    global delFileList
    delFileList = {}

    global cacheFile
    cacheFile = 'outAppendRes/' + channel +  '/resZipCfg.txt'

    impurityPath = 'outAppendRes/target' + channel

    splitFilePath = 'outAppendRes/' + channel +  '/resSplit.txt'
    splitHexFilePath = 'outAppendRes/' + channel +  '/resSplitHex.txt'
    fodlerInfo = 'outAppendRes/' + channel +  '/resFodlerInfo.txt'
    wd.init()

    global targetPath
    targetPath = path
    # if argvLen >= 2:
    #     path = tool.sys.argv[1]

    # if argvLen >= 3:
    #     limitSize = int(tool.sys.argv[2])
    global impurityFileList
    impurityFileList = listFile(1024 * 1024 * 1024, impurityPath, True)
    print(impurityPath, len(impurityFileList))

    # 小文件列表,{filePath:size, ...}
    smallFileList = listFile(limitSize, path, False, True)
    print (path, len(smallFileList))

    # 取原文件路径 [fileName, ...]
    oldFileList = listFile(1024 * 1024 * 1024, relativePath, True)
    print (relativePath, len(oldFileList))

    # 随机合并文件 [zipFilePath : [fileName, ...]     ]
    combinFileDic = randomCombin(smallFileList, tool.random.randint(50 * 1024, 80 * 1024), path)

    saveCombinDicToFile(combinFileDic, oldFileList, path, destFile)

    splitFiles(path, combinFileDic, splitFilePath, splitHexFilePath, fodlerInfo)
    #添加文件拆分逻辑

    #得到当前文件夹下所有文件的状态
    # 一个字典保存每个文件夹下的文件名 
    #｛'fileFodler':｝
    # 一个数组保存对应文件个数的文件路径
    #{1:{},2:{},3:{}}

    # 选择大文件拆分,  拆分完成后，记录拆分信息，记录文件夹变更信息。 删除原文件

    # 将所有记录保存下来. 给下一次打包做准备.


if __name__ == "__main__":
    main()
