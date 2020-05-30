#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
import hashlib
import shutil
import random
import binascii
import struct
import toolsFunc3 as tool
from toolsFunc3 import commondLine

def compareMd5(md51, md52, savePath):
    addList = []
    delList = []
    changeList = []
    md5key1 = md51.keys()
    md5key2 = md52.keys()
    for key, val in md51.items():
        if key not in md5key2:
            addList.append(key)
        elif key in md5key2:
            if val != md52[key]:
                changeList.append(key)
    
    for key, val in md52.items():
        if key not in md5key1:
            delList.append(key)

    tool.createDir(savePath)

    content = ''
    if delList:
        content = content + "DEL FILE............" + '\n'
        delList.sort()
        for file in delList:
            content = content + file + '\n'
        content = content + '\n\n\n'

    if addList:
        content = content + "ADD FILE............" + '\n'
        addList.sort()
        for file in addList:
            content = content + file + '\n'
        content = content + '\n\n\n'

    if changeList:
        content = content + "CHANGE FILE............" + '\n'
        changeList.sort()
        for file in changeList:
            content = content + file + '\n'
        
        print(content)
    else:
        print('update no change file')

    tool.WriteFile(savePath, content)

def display_path(path):
    path_new = path.replace("\\", "/")
    m = path_new[-1]
    if m.strip() == "/":
        path_new = path_new[:-1]
    return path_new

def md5Path(path):
    md5List = {}
    path = path.replace("\\", "/")
    for parent, _, filenames in os.walk(path):
        for file in filenames:
            if file.find("filelist.txt") != -1:
                continue
            s_path = os.path.join(parent,file)
            if os.path.isfile(s_path):
                if not os.path.exists(parent):
                    os.makedirs(parent)
                s_file = open(s_path, "rb")
                s_content = s_file.read()
                fmd5 = (hashlib.md5(s_content).hexdigest()).strip()
                s_path = s_path.replace("\\", "/")
                s_path = s_path.replace(path + '/', "")

                md5List[s_path] = fmd5
    
    return md5List

# 检查文件夹下最新的2个文件夹的文件对比
def checkPath(path):
    dirDic = []
    path = os.path.abspath(path)
    print ("\ncheckFileUpdate is checking " + path)
    for files in os.listdir(path):
        srcFile = os.path.join(path, files)
        if os.path.isdir(srcFile):
            dirDic.append({"dirName":files , "date": os.path.getmtime(srcFile)})
        
    if len(dirDic) < 2:
        print('not two folder')
        return

    def takeSecond(elem):
        return elem["date"]
        
    dirDic.sort( key=takeSecond,reverse = True)
    # print dirDic
    
    path1 = os.path.join(path, dirDic[0]["dirName"])
    path2 = os.path.join(path, dirDic[1]["dirName"])
    print(f'compare folder:{path1=} {path2=}\n\n')
    
    md5Dic1 = md5Path(path1)
    md5Dic2 = md5Path(path2)
    compareMd5(md5Dic1, md5Dic2, os.path.join(path, "modify.txt"))

def main(argv = None):
    filePaths = 'update/1_mzy_lmjy_version'
    
    commond = commondLine(argv)
    comLen = len(commond)

    if comLen > 1:
        filePaths = commond[1]

    checkPath(filePaths)

    # os.system("pause")

if __name__ == '__main__':  
    main() 