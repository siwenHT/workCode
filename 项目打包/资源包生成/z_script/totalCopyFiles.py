#! /usr/bin/env python
# -*- coding: utf-8 -*-
from numba import jit
import sys
import os
import hashlib
import shutil
import random
import binascii
import struct
import toolsFunc as tool
import chardet
import time
import thread
import logging
from multiprocessing import Process

#各分包文件个数
floorNumDic = {}
#各分包大小
floorSizeDic = {}
#新的分包文件列表
newMd5List = []
#已经写入中的文件
writeFileRecode = {}
#已经写完
bWriteOk = False
#
writeList = []

#记录数据里面添加一条记录
def setFloorLine(floor, size):
    if not floorSizeDic.get(floor):
        floorSizeDic[floor] = []
    floorSizeDic[floor].append(size)

    if not floorNumDic.get(floor):
        floorNumDic[floor] = []
    floorNumDic[floor].append(1)

#打印结果
def showFloorInfo():
    mainM = 0
    totalM = 0
    content = ''
    for floor, sizeList in floorSizeDic.items():
        size = 0
        for val in sizeList:
            size = size + val
        lineStr = 'idx:'+ str(floor) + ', size : ' + str('%.3f' % (size / 1024/ 1024)) + "M" + ", fileNum:" + str(len(floorNumDic[floor]))
        content = content + lineStr + '\n'
        print lineStr
        if floor > 1:
            totalM = totalM + (size / 1024 / 1024)
        else:
            mainM = (size / 1024 / 1024)

    mainSize = "main package size:" + str('%.3f' % mainM)
    subPackageSize = "sub package TotalSize:" + str('%.3f' % totalM)
    content = content + mainSize + '\n'
    content = content + subPackageSize + '\n'
    print mainSize
    print subPackageSize
    print "==========================================================="

    fileNum = 0
    for floor, valList in floorNumDic.items():
        fileNum = fileNum + len(valList)
    print "writeFileRecode num:", len(writeFileRecode), ",AllFileNum:", fileNum
    return content

#打印异常
def showSubInfo(subPackageDic):
    errorInfo = 'sub package file not exit....... \n'
    begin = 0
    items = subPackageDic.items()
    items.sort()
    for key,_ in items:
        if 'hasCopy' not in subPackageDic[key]:
            if begin == 0:
                print "==========================================================="
                begin = 1
            print "sub package file no exists:%s" % key
            errorInfo = errorInfo + key + '\n'
    if begin == 1:
        print "==========================================================="
        return errorInfo

    return ''

#根据分包文件列表, 生成字典
def initSubDicWithFile(packagedFileList):
    ret = {}
    if os.path.exists(packagedFileList):
        file_object = open(packagedFileList, 'r')
        for line in open(packagedFileList):
            line = line.strip()
            #不放入分包的文件在这里过滤
            if line.find("status.cfg") != -1 or line.find("mapDownRes.cfg") != -1:
                continue
            floor = 2
            if line.find('|') != -1:
                lines = line.split('|')
                line = lines[0]
                floor = int(lines[1])
                folderNum = int(lines[2])
                ret[line] = {'floor':floor, 'folderNum':folderNum}
            else:
                print 'line error:', line
        file_object.close()

    return ret

def processWriteFile(idx):
    # print tool.showTime() + " " + filePath
    while True:
        info = []
        try:
            if writeList:
                info = writeList.pop()
                if info:
                    filePath = info[0]
                    srcFilePath = info[1]
                    floor = info[2]

                    content = tool.ReadFile(srcFilePath)
                    size = len(content) #os.path.getsize(srcFilePath)
                    tool.createDir(filePath)
                    if floor > 1:
                        otherFload = info[3]
                        srcFile = info[4]
                        fmd5 = (hashlib.md5(content).hexdigest()).strip()
                        md5_str = "sg{0}|{1}|{2}".format(otherFload + "/" + srcFile, fmd5, size)
                        newMd5List.append(md5_str + os.linesep)
                    
                    setFloorLine(floor, size)
                    # print tool.showTime() + " " + filePath
                    tool.WriteFile(filePath, content)
                    writeFileRecode[filePath] = 1
                else:
                    print(idx + " sleep 1 min")
                    time.sleep(1)
            else:
                print tool.showTime() + "thread end  ... " + str(idx)
                break
        except BaseException as e:
            # logging.exception(e)
            writeList.append(info)
            # time.sleep(0.5)

#从源文件夹想目标文件夹拷贝文件
def copyFiles(oldSrcPath, subPackageDic, oldMainPackageDir, oldSubPackageDir):
    srcPath = tool.os.path.abspath(oldSrcPath)
    subPackageDir = tool.os.path.abspath(oldSubPackageDir)
    mainPackageDir = tool.os.path.abspath(oldMainPackageDir)

    srcPath = srcPath.replace('\\', '/')
    subPackageDir = subPackageDir.replace('\\', '/')
    mainPackageDir = mainPackageDir.replace('\\', '/')
    for root, _, files in tool.os.walk(srcPath):
        for everyFile in files:
            srcFile = root + "/" + everyFile
            allSrcPath = srcFile
            srcFile = srcFile.replace('\\', '/')
            srcFile = srcFile.replace(srcPath + '/', '')

            # print tool.showTime() + " " + srcFile
            #如果在分包文件列表中
            if srcFile in subPackageDic:
                if 'hasCopy' not in subPackageDic[srcFile]:
                    itemInfo = subPackageDic[srcFile]
                    floor = itemInfo['floor']
                    folderNum = itemInfo['folderNum']

                    otherFload = ''
                    newSubPackageDir = subPackageDir
                    if folderNum > 1:
                        newSubPackageDir = subPackageDir + str(folderNum)
                        otherFload = str(folderNum)
                    newSubDir = newSubPackageDir + '/'
                    newFilePath = newSubDir + srcFile

                    if not newFilePath in writeFileRecode:  #tool.os.path.exists(newFilePath):
                        subPackageDic[srcFile]['hasCopy'] = 1

                        # content = tool.ReadFile(allSrcPath)
                        # size = os.path.getsize(allSrcPath)
                        # fmd5 = (hashlib.md5(content).hexdigest()).strip()
                        # tool.createDir(newFilePath)
                        # tool.WriteFile(newFilePath, content)

                        # md5_str = "sg{0}|{1}|{2}".format(otherFload + "/" + srcFile, fmd5, size)
                        # newMd5List.append(md5_str + os.linesep)
                        # setFloorLine(floor, size)
                        
                        writeFileRecode[newFilePath] = 0
                        writeList.append([newFilePath, allSrcPath, floor, otherFload, srcFile])
                    # else:
                        # print 'sub file is exist:', newFilePath
            else:
                #文件在主包
                newFilePath = mainPackageDir + '/' + srcFile
                if not newFilePath in writeFileRecode: #tool.os.path.exists(newFilePath):
                    # content = tool.ReadFile(allSrcPath)
                    # size = os.path.getsize(allSrcPath)
                    # tool.createDir(newFilePath)
                    # tool.WriteFile(newFilePath, content)
                    # setFloorLine(1, size)

                    writeFileRecode[newFilePath] = 0
                    # writeList.append([newFilePath, content])
                    writeList.append([newFilePath, allSrcPath, 1])
                # else:
                    # print 'main file is exist:', newFilePath
        
def main():
    #向一个文件夹下拷贝文件, 如果目标文件夹下文件存在, 则不再拷贝
    print (os.getcwd())

    soucePath = 'sg_waiwang'
    argvLen = len(sys.argv)
    if argvLen > 1:
        soucePath = sys.argv[1]

    srcPath = ['../sgCommon', '../sgAndroid', '../' + soucePath]

    srcPath[1] = srcPath[1] + "_" + soucePath
    
    tool.showParams()
    print srcPath
    print tool.showTime() + " start ...."

    shutil.rmtree("subContent",True)
    subDic = initSubDicWithFile('packagedFileList2.txt')
    for path in srcPath:
        copyFiles(path, subDic, '../sg1', 'subContent/sg')

    print "............................"

    thread.start_new_thread(processWriteFile, ("Thread-1",))
    thread.start_new_thread(processWriteFile, ("Thread-2",))
    thread.start_new_thread(processWriteFile, ("Thread-3",))
    thread.start_new_thread(processWriteFile, ("Thread-4",))
    thread.start_new_thread(processWriteFile, ("Thread-5",))
    thread.start_new_thread(processWriteFile, ("Thread-6",))
    thread.start_new_thread(processWriteFile, ("Thread-7",))
    thread.start_new_thread(processWriteFile, ("Thread-8",))
    thread.start_new_thread(processWriteFile, ("Thread-9",))
    thread.start_new_thread(processWriteFile, ("Thread-10",))
    thread.start_new_thread(processWriteFile, ("Thread-11",))
    thread.start_new_thread(processWriteFile, ("Thread-12",))
    thread.start_new_thread(processWriteFile, ("Thread-13",))
    thread.start_new_thread(processWriteFile, ("Thread-14",))
    thread.start_new_thread(processWriteFile, ("Thread-15",))

        
    count = 0
    while True:
        find = False
        listFile = []
        for key,val in writeFileRecode.items():
            if val == 0:
                find = True
                listFile.append(key)
                # break

        if not find:
            break
        else:
            # print tool.showTime() + "main is wait for writeEnd" + str(count)
            count = count + 1
            time.sleep(1)
    
    if newMd5List:
        newMd5List.sort()
        file_md5 = open('subContent/filelist_sub.txt','wb+')
        file_md5.writelines(newMd5List)
        file_md5.close()

    sizeInfo = showFloorInfo()
    if sizeInfo:
        tool.WriteFile("sizeInfo.txt", sizeInfo)
    errorInfo = showSubInfo(subDic)
    if errorInfo:
        tool.WriteFile("subPackageError.txt", errorInfo)
    # os.system("pause")
    print tool.showTime() + " end ...."

if __name__=="__main__":
    main()

