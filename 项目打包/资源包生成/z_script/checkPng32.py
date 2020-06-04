#! /usr/bin/env python
# -*- coding: utf-8 -*-

import os.path
import sys
import demjson
import pickle
import re
import shutil
import hashlib

from xml.etree import ElementTree  
from PIL import Image

def show_params(params):
    lenIdx = len(params)
    allStr = str(lenIdx) + ":"
    for index in range(lenIdx):
        print "argv" + str(index) + ":" + str(sys.argv[index])
        
def save_obj(obj, name ):
    with open(name, 'wb') as f:
        pickle.dump(obj, f, pickle.HIGHEST_PROTOCOL)
        
def load_obj(name ):
    with open(name, 'rb') as f:
        return pickle.load(f)
        
def ReadFile(filePath):
    file_object = open(filePath,'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

def WriteFile(filePath,all_the_text):    
    file_object = open(filePath,'wb+')    
    file_object.write(all_the_text)
    file_object.close()
    
def removeFilePath(filePath):
    for root, dirs, files in os.walk(filePath, topdown=False):
        for name in files:
            os.remove(os.path.join(root, name))
        for name in dirs:
            os.rmdir(os.path.join(root, name))
            
def get_FileModifyTime(filePath):
    filePath = unicode(filePath, 'utf8')
    t = os.path.getmtime(filePath)
    return t
    
def get_FileMd5(filePath):
    s_file = open(filePath, "rb")
    s_content = s_file.read()
    s_file.close()
    return (hashlib.md5(s_content).hexdigest()).strip()
    
def get_FileName(filePath):
    pos = filePath.rfind("\\")
    return filePath[pos+1:]
   
def checkBitDepth(srcFile):
    im = Image.open(srcFile)
    bitDepth = 8
    if im.mode == "RGBA":
        bitDepth =  32
    
    # if bitDepth <> 32:
        # print 'bitDepth :' + im.mode + "|" + srcFile
    return bitDepth

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
    
def allFileList(srcPath, dict):
    srcPath = os.path.abspath(srcPath)
    for file in os.listdir(srcPath):
        srcFile = os.path.join(srcPath,  file)
        if os.path.isfile(srcFile):
            print(srcFile)
            if srcFile.find('.png') > -1 :
                if checkBitDepth(srcFile) != 32:
                    dict.append(srcFile)

                    tmpSrcFile = srcFile.replace('\\', '/')
                    tmpSrcFile = tmpSrcFile.replace(srcRoot, '')
                    newFile = os.path.join(destFile, tmpSrcFile)
                    # print(srcFile, newFile)
                    createDir(newFile)
                    shutil.copy2(srcFile, newFile)
                
        if os.path.isdir(srcFile):
            allFileList(srcFile, dict)
        
def main():
    show_params(sys.argv)
    global srcRoot
    srcRoot = 'G:/magicRpg/program/client_haiwai/sg/resNew/'    

    global destFile
    destFile = "G:/magicRpg/program/client/luaecode/z_script/resNew/"

    dict = []
    allFileList(srcRoot, dict)
    for key in dict:
        print key
    os.system("pause")
    
if __name__=="__main__":
    main()