#! /usr/bin/env python
# -*- coding: utf-8 -*-
import os
import hashlib
import shutil

def ReadFile(filePath):
    file_object = open(filePath,'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

def WriteFile(filePath,all_the_text):    
    file_object = open(filePath,'wb')    
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
    
def copyFilesAndMD5(packagedFileList,sourcePath,targetPath,md5_file_name):
    md5List = []
    floorSize = {}
    floor = 2
    file_object = open(packagedFileList,'r')
    tmpTargetPath = targetPath
    for line in open(packagedFileList):
        tmpTargetPath = targetPath
        line = line.strip()
        otherFload = ""
        if line.find("status.cfg") != -1 or line.find("mapDownRes.cfg") != -1:
            continue
        if line.find("|") != -1:
            lines = line.split("|")
            line = lines[0]
            floor = int(lines[1])
            # print("lines[2]:" + lines[2])
            if lines[2] != "1":
                otherFload = str(lines[2])
                tmpTargetPath = "subContent/sg" + otherFload + "/"
                # print("tmpTargetPath:" + tmpTargetPath)
        s_path = os.path.join(sourcePath, line).strip()
        t_path = os.path.join(tmpTargetPath, line).strip()
        t_path_dir = os.path.dirname(t_path).strip()
        if os.path.isfile(s_path):
            if not os.path.exists(t_path_dir):
                os.makedirs(t_path_dir)
            s_file = open(s_path, "rb")
            s_content = s_file.read()
            s_size = os.path.getsize(s_path)
            open(t_path, "wb").write(s_content)
            fmd5 = (hashlib.md5(s_content).hexdigest()).strip()
            md5_str = "{0}|{1}|{2}".format("sg" + otherFload +"/"+line,fmd5,s_size)
            md5List.append(md5_str+os.linesep)
            if not floorSize.get(floor):
                floorSize[floor] = 0
            floorSize[floor] = floorSize[floor] + s_size
        else:
            print("分包配置的文件不存在:%s" % s_path)
    file_object.close()
    file_md5 = open(md5_file_name,'wb+')
    file_md5.writelines(md5List)
    file_md5.close()
    print("===========================================================")
    totalM = 0
    for key,value in dict.items(floorSize):
        # print("key :" + str(key) + ",value:" + str(value))
        print("第 " + str(key) + " 个分包: " + str('%.3f' % (value / 1024/ 1024)) + "M" )
        totalM = totalM + (value / 1024/ 1024)
    print("分包总大小为：" + str('%.3f' % totalM))
    print("===========================================================")
    
def main():
    sourcePath = "../sg1/"
    targetPath = "subContent/sg/"
    packagedFileList = "packagedFileList2.txt"
    md5_file_name = "subContent/filelist_sub.txt"
    shutil.rmtree("subContent",True)
    print("===========================================================")
    copyFilesAndMD5(packagedFileList,sourcePath,targetPath,md5_file_name)
    print "subctonet and md5 ok"

if __name__=="__main__":
    main()




