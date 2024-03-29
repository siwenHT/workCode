#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
import hashlib
import shutil
import random
import binascii
import struct
import toolsFunc as tool
import chardet
import subIosRes
import time
import thread

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
    for key,_ in subPackageDic.items():
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
                    size = len(content)
                    tool.createDir(filePath)
                    content = subIosRes.randomBit(content, filePath)
                    if floor > 1:
                        otherFload = info[3]
                        srcFile = info[4]
                        fmd5 = (hashlib.md5(content).hexdigest()).strip()
                        # tool.WriteFile(newFilePath, content)
                        md5_str = "sg{0}|{1}|{2}".format(otherFload + "/" + srcFile, fmd5, size)
                        newMd5List.append(md5_str + os.linesep)

                    setFloorLine(floor, size)                    
                    # print tool.showTime() + " " + filePath
                    tool.WriteFile(filePath, content)
                    writeFileRecode[filePath] = 1
                else:
                    time.sleep(2)
            else:
                print tool.showTime() + "thread end  ... " + str(idx)
                break
        except:
            writeList.append(info)


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
                        # tool.createDir(newFilePath)
                        # content = subIosRes.randomBit(content, newFilePath)
                        # fmd5 = (hashlib.md5(content).hexdigest()).strip()
                        # # tool.WriteFile(newFilePath, content)
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
                    # content = subIosRes.randomBit(content, newFilePath)
                    # # tool.WriteFile(newFilePath, content)
                    # setFloorLine(1, size)

                    writeFileRecode[newFilePath] = 0
                    writeList.append([newFilePath, allSrcPath, 1])
                # else:
                    # print 'main file is exist:', newFilePath
        
def main():
    #向一个文件夹下拷贝文件, 如果目标文件夹下文件存在, 则不再拷贝
    
    soucePath = 'sg_waiwang'
    srcPath = ['../sgCommon', '../sgIos', '../' + soucePath ]

    subIosRes.spaceNum = 4
    subIosRes.specSpace = '1111'

    argvLen = len(sys.argv)
    tool.showParams()
    print tool.showTime() + " start ...."

    if argvLen >= 2:
        srcPath[1] = sys.argv[1]
        
    if argvLen >= 3:
        soucePath = sys.argv[2]
        srcPath[2] = '../' + soucePath

    print srcPath
    shutil.rmtree("subContent",True)
    subDic = initSubDicWithFile('packagedFileList2.txt')
    for path in srcPath:
        copyFiles(path, subDic, '../sg1', 'subContent/sg')

    print tool.showTime() + "....."

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
        for _,val in writeFileRecode.items():
            if val == 0:
                find = True
                break

        if not find:
            break
        else:
            # print tool.showTime() + "main is wait for writeEnd" + str(count)
            count = count + 1
            time.sleep(1)

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

