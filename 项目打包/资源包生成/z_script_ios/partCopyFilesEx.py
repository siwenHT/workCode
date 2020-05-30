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

copyNum = 0

def copyFiles(srcPath, destPath, logTy):
    for fileName in os.listdir(srcPath):
        srcFile = os.path.join(srcPath, fileName)
        dstFile = os.path.join(destPath, fileName)
        srcFile = srcFile.replace("\\", "/")
        dstFile = dstFile.replace("\\", "/")
        if os.path.isfile(srcFile):
            if not os.path.exists(dstFile):
                t_path_dir = os.path.dirname(dstFile).strip()
                if not os.path.exists(t_path_dir):
                    tool.createDir(t_path_dir + "/")
                tool.WriteFile(dstFile, tool.ReadFile(srcFile) )
                global copyNum
                copyNum = copyNum + 1
                if logTy == 2:
                    print u"拷贝了文件：" , dstFile
            else:
                if logTy == 1:
                    print u"文件已经存在了：" , dstFile

        if os.path.isdir(srcFile):
            copyFiles(srcFile, dstFile, logTy)

def main():
    #向一个文件夹下拷贝文件, 如果目标文件夹下文件存在, 则不再拷贝
    destPath = '../sg1'
    srcPath = '../sg_waiwang'

    argvLen = len(sys.argv)
    tool.showParams()

    if argvLen >= 3:
        srcPath = sys.argv[1]
        destPath = sys.argv[2]

    logTy = 0
    if argvLen >= 4:
        logTy = int(sys.argv[3])
    
    srcPath = os.path.abspath(srcPath)
    destPath = os.path.abspath(destPath)
    copyFiles(srcPath, destPath, logTy)
    print u"@@@@@@@@@copyNum:" + str(copyNum)

if __name__=="__main__":
    main()
