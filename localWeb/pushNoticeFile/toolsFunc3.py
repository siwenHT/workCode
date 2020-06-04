# -*- coding: utf-8 -*-

import os
import sys
import random
import re
import shutil
import time
import struct
import unicodedata
import datetime
import hashlib
import zipfile
import paramiko

def ReadFile(filePath):
    file_object = open(filePath, 'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

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

def WriteFile(filePath,all_the_text):
    if not isinstance(all_the_text, bytes):
        if isinstance(all_the_text, str):
            all_the_text = all_the_text.encode('utf-8')
    file_object = open(filePath,'wb')    
    file_object.write(all_the_text)
    file_object.close()

def delFolders(destPath):
    shutil.rmtree(destPath, True)

def copyFile(src, dest):
    if not os.path.exists(src):
        print (f'{src=} is not exist')
        return
    
    if os.path.isfile(src):
        createDir(dest)
        shutil.copy2(src, dest)
    else:
        createDir(dest)
        shutil.copytree(src, dest, symlinks=False, ignore=None)

def delFile(filePath):
    if not os.path.exists(filePath):
        return

    if os.path.isfile(filePath):
        os.remove(filePath)
    else:
        delFolders(filePath)

#找到字符串中最后出现的字符
def findLastStr(content, symbol, beginOffset = 0, endOffset = -1):
    if endOffset == -1:
        endOffset = len(content) - 1
    
    posCheck = beginOffset
    oldPosCheck = -1
    while True:
        posCheck = content.find(symbol, posCheck)
        if posCheck > endOffset:
            return oldPosCheck

        if posCheck > -1:
            oldPosCheck = posCheck
            posCheck = posCheck + len(symbol)
        else:
            return oldPosCheck
    return oldPosCheck

class commondLine:
    def __init__(self, argv = None):
        if argv:
            self.argv = argv
            self.argv.insert(0, '')
        else:
            self.argv = sys.argv[:]
        self.len  = len(self.argv)

    def __getitem__(self, item):
        return self.argv[item]

    def __len__(self):
        return self.len

    def __str__(self):
        return str(self.argv)

def waitInput(strLine = 'please input:>>'):
    try:
        idx = input(strLine)
        idx = idx.replace('\r', '')
        return idx
    except Exception as e:
        # print e.message
        return ''

def waitInputIdx(minIdx = None, maxIdx = None, strLine = 'please input idx:>>'):
    while True:
        try:
            idx = input(strLine)
            idx = int(idx)
            if minIdx and maxIdx:
                if idx >= minIdx and idx <= maxIdx:
                    return idx
                else:
                    print (f'idx need {minIdx} <= value <= {maxIdx}, try again:>>')
            else:
                return idx

        except Exception:
            # print e.message
            return ''
        
def showTime():
    return datetime.datetime.now().strftime("[%Y-%m-%d_%H_%M_%S_%f]")


def progress_bar(transferred, toBeTransferred, suffix=''):
    bar_len = 100
    filled_len = int(round(bar_len * transferred / float(toBeTransferred)))
    percentNum = 100.0 * transferred / float(toBeTransferred)
    percents = '%.1f' % percentNum
    bar = '%s' % '=' * filled_len + '-' * (bar_len - filled_len)
    sys.stdout.write('[%s] %s%s %s %s \r' % (bar, percents, '%', suffix, str(round(transferred/1024/1024)) + 'M/' + str(round(toBeTransferred/1024/1024)) + 'M' ) )
    sys.stdout.flush()
    if transferred >= toBeTransferred:
        print("")

class SSHTools(object):
    def __init__(self, user, password, port, ips):
        self.user = user
        self.password = password
        self.port = port
        self.ip = ips

    def connect(self):
        try:
            self.ssh = paramiko.SSHClient()
            self.ssh.load_system_host_keys()
            self.ssh.set_missing_host_key_policy(paramiko.AutoAddPolicy())
            privatekeyfile = os.path.expanduser('~/.ssh/id_rsa')
            mykey = paramiko.RSAKey.from_private_key_file(privatekeyfile)
            self.ssh.connect(self.ip, 22, self.user, pkey=mykey, timeout=50)
            # print("has connect remote server", self.ip)
            return True

        except Exception as e:
            print (e)
            print ("connect remote server fail!")
            return False

    def cmd(self, strCmd, notShow = True):
        _, stdout, stderr = self.ssh.exec_command(strCmd)

        ret = stdout.readlines()
        errRet = stderr.readlines()
        if not notShow:
            print ('CMD:>>' + strCmd)
            for i in ret:
                print (i)
            
            for i in errRet:
                print (i)
        return ret, errRet

    def setDir(self, srcFile, destFile):
        self.local_file_abs = srcFile
        self.remote_file_abs = destFile

    def put(self):
        sftp = paramiko.SFTPClient.from_transport(self.ssh.get_transport())
        sftp = self.ssh.open_sftp()
        sftp.put(self.local_file_abs,self.remote_file_abs, progress_bar)
        sftp.close()
        print (self.local_file_abs , " put file to remote server ok.")

    def get(self):
        sftp = paramiko.SFTPClient.from_transport(self.ssh.get_transport())
        sftp = self.ssh.open_sftp()
        sftp.get(self.remote_file_abs,self.local_file_abs, progress_bar)
        sftp.close()

    def close(self):
        self.ssh.close()
        print("connect shutdown")

class CustomError(Exception):
    def __init__(self,ErrorInfo):
        super(CustomError, self).__init__(self) #初始化父类
        self.errorinfo=ErrorInfo
    def __str__(self):
        return self.errorinfo

def compress(get_files_path, set_files_path):
    createDir(set_files_path)
    f = zipfile.ZipFile(set_files_path , 'w', zipfile.ZIP_DEFLATED )
    for dirpath, _, filenames in os.walk( get_files_path ):      
        fpath = dirpath.replace(get_files_path,'') 
        fpath = fpath and fpath + os.sep or ''
        for filename in filenames: 
            f.write(os.path.join(dirpath,filename), fpath+filename)
    f.close()
    print (showTime() + ":" + set_files_path + " file compress ok!")

def md5sum(filename):
    fd = open(filename,"rb")
    fcont = fd.read()
    fd.close()
    fmd5 = (hashlib.md5(fcont).hexdigest()).strip()
    return fmd5     