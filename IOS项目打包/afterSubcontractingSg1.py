#! /usr/bin/env python
# -*- coding: utf-8 -*-
import sys
import os
import hashlib
import shutil

def readLineFile(file):
    dir = {}
    file_object = open(file, 'r')
    for line in open(file):
        line = line.strip()
        if line.find("|") == -1:
            # print("line:" + line + " ��һ��������")
            continue
        lines = line.split("|")
        fileName = lines[0]
        md5Val = lines[1]
        dir[fileName] = md5Val
        # print("key:"+fileName+",val"+md5Val)
    file_object.close()
    print("�ļ���"+ file + " ==== ��ȡ���ļ�����" + str(len(dir)) )
    return dir
    
def createDir(path):
    path = os.path.dirname(path)
    path = path.replace("\\", "/")
    paths = path.split("/")
    tmpPath = ''
    for path in paths:
        tmpPath = tmpPath + path + "/";
        if not os.path.exists(tmpPath):
            os.mkdir(tmpPath)    

def ReadFile(filePath):
    file_object = open(filePath,'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

def WriteFile(filePath,all_the_text):    
    file_object = open(filePath,'wb')    
    file_object.write(all_the_text)
    file_object.close()
    
def WriteFileAddModel(filePath,all_the_text):    
    file_object = open(filePath,'ab+')    
    file_object.write(all_the_text)
    file_object.close()
    
def BakFile(filePath,all_the_text):
    file_bak = filePath[:len(filePath)-3] + 'bak'   
    WriteFile(file_bak,all_the_text)

def md5sum(filename):
    fd = open(filename,"r")
    fcont = fd.r
    fd.close()
    fmd5 = hashlib.md5(fcont)
    return fmd5

def RemoveFile(sourcePath, fileNme):
    fileNme = fileNme.strip()
    t_path = os.path.join(sourcePath,fileNme).strip()
    if os.path.isfile(t_path):
        os.remove(t_path)
    
def generateAfterSubContentRes(packagedFileList,sourcePath):
    md5List = []
    file_object = open(packagedFileList,'r')
    for line in open(packagedFileList):
        line = line.strip()
        t_path = os.path.join(sourcePath,line).strip()
        if os.path.isfile(t_path):
            os.remove(t_path)
    file_object.close()
    
def cmpDicForNew(dicNew, dicOld, srcPath, destPath, errFile):
    totalNum = 0 
    errorInfo = ''
    print("=========================================================")
    for key,value in dict.items(dicNew):
        # print(value)
        if (not dicOld.get(key)):
            createDir(destPath + "/" + key)
            shutil.copyfile(srcPath + "/" + key, destPath + "/" + key)
            totalNum = totalNum + 1
        if dicOld.get(key) and (dicOld.get(key) != value):
            createDir(destPath + "/" + key)
            shutil.copyfile(srcPath + "/" + key, destPath + "/" + key)
            totalNum = totalNum + 1
            errStr = "���޸����ļ�, q_update����û������." + key
            errorInfo = errorInfo + errStr + '\n'
            print errStr
    print("=========================================================")
    print("�����ļ�����" + destPath + ", �ļ���ĿΪ��" + str(totalNum))
    
    if errorInfo:
        errorInfo = '\n File floor error! \n' + errorInfo
        WriteFileAddModel(errFile, errorInfo)
    
                

def main():
    sourcePath = "../sg1/"
    packagedFileList = "packagedFileList.txt"
    md5FileNew = "subContent/filelist_sub.txt"
    md5FileOld = "subContentOld/filelist_sub.txt"
    if len(sys.argv) >= 2:
        md5FileOld = "subContentOld/" + sys.argv[1]
            
    srcPath = "subContent"
    destPath = "subContentAssert"
    if not os.path.exists(md5FileNew):
        print("�µ� filelist_sub ������,�޷����ɷְ������ļ�")
        return
    if not os.path.exists(md5FileOld):
        print("�ɵ� filelist_sub ������,�޷����ɷְ������ļ�")
        return
    generateAfterSubContentRes(packagedFileList,sourcePath)
    RemoveFile(sourcePath, "status.cfg")
    shutil.rmtree(destPath, True)
    
    errorFile = "subPackageError.txt"
    cmpDicForNew(readLineFile(md5FileNew), readLineFile(md5FileOld), srcPath, destPath, errorFile)
    
    print "ɾ��sg1�зְ�����, �������µķְ������ļ���"

if __name__=="__main__":
    main()




