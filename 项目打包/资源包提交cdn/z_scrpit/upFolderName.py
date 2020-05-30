#! /usr/bin/env python
# -*- coding: utf-8 -*-
import os
import toolsFunc3 as tool
from toolsFunc3 import commondLine

#检查目录下文件夹的命名. 获取最新的文件夹 (选倒数第二个)
def checkPath(path, noShowFileList = False, isDown = False):
    dirList = []
    path = os.path.abspath(path)
    path = path.replace("\\", "/")
    strFile = ''
    for file in os.listdir(path):
        allPath = os.path.join(path,  file)
        if os.path.isdir(allPath):
            strFile = strFile  + file + '   '
            dirList.append(file)
    
    if not noShowFileList:
        print ('------------------------------------------------------------------------------------------------')
        print ('path: ' + path)
        print (strFile)

    fileNum = 0
    listLen = len(dirList)
    for i in range(listLen):
        if dirList[listLen - i - 1].isdigit():
            if isDown:
                isDown = False
            else:
                fileNum = int(dirList[listLen - i - 1])
                break
        
        
    return fileNum

def checkPathUplv1(nowNum):
    return nowNum + 1

def checkPathUplv2(nowNum):
    strNum = str(nowNum)
    strNum1 = strNum[0:1]
    strNum2 = strNum[1:4]

    return int(strNum1) * 1000000 + (int(strNum2) + 1) * 1000 + 0

def getVersionFromFileNum(fileNum):
    strNum = str(fileNum)
    strNum1 = strNum[0:1]
    strNum2 = strNum[1:4]
    strNum3 = strNum[4:7]
    return str(int(strNum1)) + '.' + str(int(strNum2)) + '.' + str(int(strNum3))

def main(argv = None):
    filePath = ''
    
    commond = commondLine(argv)
    comLen = len(commond)

    # tool.showParams()
    upType = 2
    if comLen >= 2:
        filePath = commond[1]

    if comLen >= 3:
        upType = int(commond[2])
    
    fileNum = checkPath(filePath, upType == 2 or upType == 3 or upType == 4)
    if upType == 1:
        fileNum = checkPathUplv1(fileNum)
    if upType == 2:
        fileNum = checkPathUplv2(fileNum)

    if upType == 4:
        return checkPathUplv1(fileNum), checkPathUplv2(fileNum), fileNum
    
    return fileNum
    # exit(fileNum)
    # os.system("pause")

if __name__ == '__main__':  
    main() 