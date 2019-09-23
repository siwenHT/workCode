#! /usr/bin/env python
# -*- coding: utf-8 -*-

import toolsFunc as tool
import subIosRes

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

def listFile(limitSize, oldpath, delPath = False):
    retList = {}
    oldpath = oldpath.replace('\\', '/')
    path = tool.os.path.abspath(oldpath)
    for root, _, files in tool.os.walk(path):
        for everyFile in files:
            srcFile = tool.os.path.join(path, root + "/" + everyFile)
            if srcFile.find('cocos/') > -1 or srcFile.find('cocos\\') > -1:
                continue
            fileSize = tool.get_FileSize(srcFile)
            # 随机一些lua 文件出来
            if (fileSize <= limitSize or srcFile.find('.pb') > -1) and srcFile.find('.mp3') == -1:
                srcFile = srcFile.replace('\\', '/')
                if delPath:
                    srcFile = srcFile.replace(oldpath, '')
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
        tmpSuf = '.zip'
        randomNum = tool.random.randint(1, 70)
        if 10 <= randomNum <= 20:
            tmpSuf = '.luac4'
        elif 30 <= randomNum <= 40:
            tmpSuf = '.data'
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

    print 'Max file in Zip ' + str(count) + ", zipFile num :" + str(len(retDic))+ ',zipcount' +str(zipCount)
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
    
    tool.WriteFile('delFileList.txt', tmpCont)

    totalLine = len(fileList)

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
    cmd = "E:/magicRpg/program/clientIos/Arts/texturepacker_Tool/czzFileDel/magic.exe -CCZPkm -s {srcFile} -d {dstPath} -ex {spaceNum}".format(srcFile = destFile, dstPath= destFile, spaceNum = 0)
    print("cmd:" +cmd)
    tool.os.system(cmd)

    s_file = open(destFile, "rb")
    s_content = s_file.read()
    
    # print srcFile + "--------" + dstFile
    subIosRes.spaceNum = 4
    subIosRes.needXxtea = True
    newContent = subIosRes.randomBit(s_content, destFile)
    open(destFile, "wb+").write(newContent)

def main():
    # 得到文件列表, 设置过滤值 50 * 1024.
    # 然后用随机，找到一个文件, 把文件所在目录作为生成合成文件目录.
    # 随机取文件, 直到文件接近设置值， 合并文件, 记录合并文件路径.
    # 所有文件都处理完毕后，保存合并记录到文件,准备读取.

    # 考虑更新问题.少量更新的话，查找合并表. 如果在合并表中, 找到合并文件, 把文件插入进去.
    channel = 'lmjy'
    limitSize = 30 * 1024
    tool.showParams()
    argvLen = len(tool.sys.argv)
    if argvLen >= 2:
        channel = tool.sys.argv[1]
    
    path = "E:/magicRpg/magic_ios/sg" + channel  + "/"
    relativePath = 'E:/magicRpg/program/clientIos/sg' + channel + '/'
    destFile = 'outAppendRes/' + channel + '/DeprecatedExtend_ex.lua'
    global delFileList
    delFileList = {}

    global cacheFile
    cacheFile = 'outAppendRes/' + channel +  '/resZipCfg.txt'

    global targetPath
    targetPath = path
    # if argvLen >= 2:
    #     path = tool.sys.argv[1]

    # if argvLen >= 3:
    #     limitSize = int(tool.sys.argv[2])

    # 小文件列表,{filePath:size, ...}
    smallFileList = listFile(limitSize, path)

    # 取原文件路径 [fileName, ...]
    oldFileList = listFile(1024 * 1024 * 1024, relativePath, True)

    # 随机合并文件 [zipFilePath : [fileName, ...]     ]
    combinFileDic = randomCombin(smallFileList, tool.random.randint(50 * 1024, 80 * 1024), path)

    saveCombinDicToFile(combinFileDic, oldFileList, path, destFile)

if __name__ == "__main__":
    main()
