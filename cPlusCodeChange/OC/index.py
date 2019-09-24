#!python   
# -*- coding: utf-8 -*-
import analysisFile as ANS
import createFile   as CRT
from define import globalDef as ins
from tool import toolsFunc as tool

cacheFile = 'changeTextIos.txt'

def ansFiles(path):
    path = tool.os.path.abspath(path)
    for root,_,files in tool.os.walk(path):
        for everyFile in files:
            if '.h' in everyFile:
                srcFile = tool.os.path.join(path, root + "/" + everyFile)
                ANS.analysis(srcFile)

def clearnFiles(lanType, srcPath, dstPath):
    if lanType == "cplus":
        srcPath = tool.os.path.abspath(srcPath) 
        dstPath = tool.os.path.abspath(dstPath)
        for file in tool.os.listdir(srcPath):
            srcFile = tool.os.path.join(srcPath, file)
            dstFile = tool.os.path.join(dstPath, file)
            if tool.os.path.isfile(srcFile):
                f_content = tool.ReadFile(srcFile)
                tool.createDir(dstFile)
                # print "clearnFiles start:" + srcFile
                f_content = tool.delCplusNotes(f_content)
                tool.WriteFile(dstFile, f_content)
            elif tool.os.path.isdir(srcFile):
                clearnFiles(lanType, srcFile, dstFile)

#oc文件混淆的主文件
def myMain():
    resFile = 'res/iosFile'
    ansFiles(resFile)

    


