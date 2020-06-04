#!python   
# -*- coding: utf-8 -*-

import sys
import os
import hashlib
import shutil
import random
import binascii
import struct
import toolsFunc3 as tool
import chardet
import paramiko
import getpass
import zipfile
import upFolderName
from toolsFunc3 import SSHTools
from toolsFunc3 import commondLine
import upFolderName

global sshCfg
global serverRoot

autoEnd = False
def pushPath(folder, name, serFolder, serName):
    print('准备推送的文件夹信息:',folder, name, serFolder, serName)

    if name == 1:
        name = upFolderName.checkPath(folder)
    try:
        serFolder = serFolder or folder
        serName = serName or name
        curTime = tool.datetime.datetime.now().strftime("_%Y-%m-%d_%H_%M_%S_%f")
        print (tool.showTime() + f" : {folder} {name}")
        
        ftpFolder = 'FtpFiles'
        localPath = folder + '/' + str(name)
        zipPath = ftpFolder + '/' + localPath + curTime +'.zip'
        tool.delFile(zipPath)
        if not os.path.exists(os.path.abspath(localPath)):
            print(f"准备上传的文件夹本地不存在! {localPath} \n\n\n")
            return

        tool.compress(localPath, zipPath)
        
        obj = SSHTools(sshCfg["user"], sshCfg['password'], sshCfg['port'], sshCfg['ips'])
        conFlg = getattr(obj, "connect")()
        if conFlg:
            serDir = serFolder + '/' + str(serName)
            serPath = f'{serverRoot}{ftpFolder}/{serDir}{curTime}.zip'
            desPath = f'{serverRoot}{serDir}'

            print ('serPath  : ' + serPath)
            print ('zipPath  : ' + os.path.abspath(zipPath))
            print ('desPath  : ' + desPath)

            #上传文件
            getattr(obj, "setDir")(os.path.abspath(zipPath), serPath)
            cmd = f'mkdir -p {ftpFolder}/{serFolder}'
            getattr(obj, 'cmd')(f'cd {serverRoot};{cmd}')
            getattr(obj, "put")()
            getattr(obj, 'cmd')(f'chmod -R a+r {serverRoot}{ftpFolder}/{serFolder}')
            getattr(obj, 'cmd')('chmod 777 ' + serPath)
            
            #下载md5文件
            clientMd5 = tool.md5sum(os.path.abspath(zipPath))
            ret,_ = getattr(obj, 'cmd')('md5sum ' + serPath)
            strRet = ''
            for i in ret:
                strRet = strRet + i

            #检查md5
            # strRet= strRet.encode('utf-8')
            if strRet.find(serPath) == -1 or strRet.find(clientMd5) == -1:
                getattr(obj, 'close')()
                print ('推送失败了, 再推送一次')
                pushPath(folder, name, serFolder, serName)
                return
            else:
                print ('MD5验证成功')
                    
            getattr(obj, 'cmd')(f'cd {serverRoot};mkdir -p {serDir}')
            getattr(obj, 'cmd')(f'chmod -R a+r {desPath}')
            cmd = f'unzip -o -q {serPath} -d {desPath}'
            outRet,errRet = getattr(obj, 'cmd')(cmd, False)
            if outRet or errRet:
                getattr(obj, 'close')()
                raise tool.CustomError(ErrorInfo = tool.showTime() + ' file unZip error! check Error by self!')
            else:
                print (tool.showTime() + ' file unZip OK.')
            getattr(obj, 'close')()

            print ('\n\n\n')
        else:
            return
    except tool.CustomError as e:
        print(e)
        os.system("pause")
    except Exception as e:
        tool.time.sleep(5)
        print ('处理时发生异常 2秒后重新在处理一次\n')
        pushPath(folder, name, serFolder, serName)

def main(params, gameCfg):
    global sshCfg
    global serverRoot
    #推送配置 推送服务器信息 推送选择
    pathDic = gameCfg['pushFolder']
    sshCfg = gameCfg['Ftpcfg']
    platforms = params['platforms']
    serverRoot = sshCfg['serverRoot']

    global tipLevel
    tipLevel = params['tipLevel']

    def pushVal(val, num = 0):
        valList = {}
        cfg = ['folder', 'name', 'serFolder', 'serName']
        flg = num > 0 and str(num) or ""
        for i in range(4):
            key = cfg[i] + flg
            if key in val:
                valList[i] = val[key]
            else:
                valList[i] = ""

        if valList[0] and valList[1]:
            pushPath(valList[0], valList[1], valList[2], valList[3])
    
    for val in pathDic:
        if val['platform'] in platforms:
            pushVal(val)
            pushVal(val, 1)
