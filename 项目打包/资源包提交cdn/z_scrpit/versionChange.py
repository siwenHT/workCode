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
import logging
import paramiko
import getpass
import zipfile
import upFolderName
import refreshUrl
import pushFolder
import json
import tkinter
import tkinter.messagebox

from toolsFunc3 import SSHTools
from toolsFunc3 import commondLine

#根据文件夹更新url的版本号
codeList = []

def preShowInfo(urlItemCfg, isTmp = True):
    folder = urlItemCfg['folder']
    nowFileNum = upFolderName.checkPath(folder, True)
    if arrow == 'down':
        nowFileNum = upFolderName.checkPath(folder, True, True)

    upFilePath = folder + '/' + str(nowFileNum)
    if os.path.exists(upFilePath):
        for webUrl in urlItemCfg['urls']:
            if isTmp:
                webUrl = webUrl.replace('.cfg', '_tmp.cfg')
            url, version = refreshUrl.checkVersion(webUrl, True)
            if url == '404':
                print(f'{url=} is not find!')
                continue
            
            #更新文件夹
            pos = tool.findLastStr(url, '/')
            oldFolderPath = url[0:pos]
            # oldFolderName = url[pos+1:]
            newFolder = oldFolderPath + '/' + str(nowFileNum)

            #更新版本号
            strVersion = upFolderName.getVersionFromFileNum(nowFileNum)

            filePath = webUrl.replace(hostUrl, serverRoot)
            upInfo = {  
                        'webUrl':webUrl, 
                        'oldUrl':url, 
                        'newUrl':newFolder, 
                        'oldVersion':version, 
                        'newVersion':strVersion, 
                        'filePath':filePath,
                    }
            codeList.append(upInfo)
    else:
        print('upfile not exists ' + upFilePath)

def showPreRes():
    global codeList
    for val in codeList:
        print('---------------------------------------------------------------------------------------')
        print(val['webUrl'] +' 将发生以下改变')
        print('下载对应文件夹:')
        print('old:' + val['oldUrl'])
        print('new:' + val['newUrl'])
        print('version:' + ' old=' + val['oldVersion'] + ', new=' + val['newVersion'])

    if codeList:
        print('---------------------------------------------------------------------------------------')

        if tipLevel > 1:
            if tkinter.messagebox.askokcancel('提示', '查看改变信息是否正常!'):
                begin()
        else:
            begin()

def begin(idxs = None):
    if not idxs:
        idxs = range(len(codeList))
    
    upVersionByCodeIdx(idxs)

def upVersionByCodeIdx(idxs):
    if not idxs:
        return

    try:
        codeLen = len(codeList)
        obj = SSHTools(cdnCfg['user'], cdnCfg['password'], cdnCfg['port'], cdnCfg['ips'])
        conFlg = getattr(obj, "connect")()
        if conFlg and idxs:
            for i in range(codeLen):
                if i in idxs:
                    itemInfo = codeList[i]
                    
                    fileContent = {'code':0, 'result':{'url': itemInfo['newUrl'],  'version':itemInfo['newVersion']}}
                    fileContent = json.dumps(fileContent)
                    tool.WriteFile('tmp.cfg', fileContent)
                    getattr(obj, 'setDir')(os.path.abspath('tmp.cfg'), itemInfo['filePath'])
                    getattr(obj, "put")()
                    tool.delFile('tmp.cfg')
                    ret, _ = getattr(obj, 'cmd')('cat ' + itemInfo['filePath'])
                    strRet = ''
                    for i in ret:
                        strRet = strRet + i

                    if strRet and strRet.find(fileContent) == -1:
                        print("文件推送失败了.请重新推送. file:" + itemInfo['filePath'])
                    else:
                        print(itemInfo['filePath'] + ':' + strRet)

            getattr(obj, 'close')()
    except Exception as e:
        tool.time.sleep(5)
        print ('推送版本变更异常, 2秒后重新在处理一次\n')
        upVersionByCodeIdx(idxs)

def main(argvs, gameCfg):
    urlCfg = gameCfg['version']
    platforms = argvs['platforms']
    debug = argvs['debug']

    global cdnCfg
    cdnCfg = gameCfg['Ftpcfg']

    global tipLevel
    tipLevel = argvs['tipLevel']

    sshCfg = gameCfg['Ftpcfg']
    global hostUrl
    global serverRoot
    hostUrl = sshCfg['hostUrl']
    serverRoot = sshCfg['serverRoot']

    global arrow
    arrow = argvs['arrow']

    for val in urlCfg:
        if val['platform'] in platforms:
            preShowInfo(val, debug)
        
    showPreRes()