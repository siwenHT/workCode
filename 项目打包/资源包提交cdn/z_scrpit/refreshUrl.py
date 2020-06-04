#!python   
# -*- coding: utf-8 -*-

import os,sys  
import os.path
import sys
import pickle
import demjson
import numpy as np
import json
import requests
import tkinter
import tkinter.messagebox
import toolsFunc3 as tool
from toolsFunc3 import commondLine
from toolsFunc3 import SSHTools

def checkVersion(url, noShowPrint = None):
    req_url = url
    Form_Data = {}

    translate_result = requests.get(req_url, Form_Data)
    # print translate_result.status_code
    if translate_result.status_code == 200:
        if not noShowPrint:
            print('url    :' + url)
        # print translate_result._content
        
        jsonInfo = json.loads(translate_result._content)
        if not noShowPrint:
            print ('filedir:' + jsonInfo[u'result'][u'url'])
            print ('verison:' + jsonInfo[u'result'][u'version'])
            print ("==================================================================================================")
        
        return jsonInfo[u'result'][u'url'], jsonInfo[u'result'][u'version']
    else:
        if not noShowPrint:
            print ('url    :' + url)
            print ('code   :' + str(translate_result.status_code))
            print ("==================================================================================================")
        return '404', ''

def getServerFiles(urls):
    try:
        serverUrlInfo = {}
        obj = SSHTools(sshCfg['user'], sshCfg['password'], sshCfg['port'], sshCfg['ips'])
        conFlg = getattr(obj, "connect")()
        if conFlg and urls:
            for oldUrl in urls:
                url = oldUrl.replace(hostUrl, serverRoot)

                ret, _ = getattr(obj, 'cmd')(f'cat {url}')
                strRet = ''
                for i in ret:
                    strRet = strRet + i

                if strRet.find('No such file or directory') > -1:
                    serverUrlInfo[oldUrl] = '404'
                else:
                    jsonInfo = json.loads(strRet)
                    tmpUrl = jsonInfo[u'result'][u'url']
                    tmpVer = jsonInfo[u'result'][u'version']
                    serverUrlInfo[oldUrl] = [tmpUrl, tmpVer]
                    
            getattr(obj, 'close')()
            return serverUrlInfo
    except Exception as e:
        tool.time.sleep(5)
        print ('获取服务器文件信息异常, 5秒后重新在处理一次\n')
        getServerFiles(urls)

        
def checkNoctice(url, noShowPrint = None):
    req_url = url
    Form_Data = {}

    translate_result = requests.get(req_url, Form_Data)
    # print translate_result.status_code
    if translate_result.status_code == 200:
        if not noShowPrint:
            print ('url    :' + url)
        # print translate_result._content
        
        jsonInfo = translate_result._content.decode('utf-8')
        if not noShowPrint:
            print ('content:')
            print (jsonInfo)
            print ("==================================================================================================")
        
        return ''
    else:
        if not noShowPrint:
            print ('url    :' + url)
            print ('code   :' + str(translate_result.status_code))
            print ("==================================================================================================")
        return '404', ''
    
def refreshUrl(fileUrl):
    cmd = 'python QcloudCdnTools_V2.py RefreshCdnUrl -u {id} -p {key} --urls-from {u}'.format(id = SecretId, key = SecretKey, u = fileUrl)
    print("url:" + fileUrl)
    os.system(cmd)
    
def refreshDir(url):
    cmd = 'python QcloudCdnTools_V2.py RefreshCdnDir -u {id} -p {key} --dirs {u}'.format(id = SecretId, key = SecretKey, u = url)
    # print("cmd:" +cmd)
    os.system(cmd)

def refreshCheck(urlList, isVersion = True):
    count = 1
    time = 10
    if urlList :
        urlCount = len(urlList)
        serFileList = {}
        if isVersion:
            serFileList = getServerFiles(urlList)

        while True:
            tool.time.sleep(time)
            
            needWait = False
            for i in range(urlCount):
                url = urlList[i]
                if url != "1":
                    if isVersion:
                        cdnUrl, cdnVer = checkVersion(url, True)
                        if cdnUrl == '404' or serFileList[url] == "404":
                            urlList[i] = '1'
                        else:
                            if cdnUrl == serFileList[url][0] and cdnVer == serFileList[url][1]:
                                urlList[i] = '1'
                            else:
                                needWait = True
                    else:
                        time = 30
                        checkNoctice(url)
            
            if not needWait:
                tkinter.messagebox.askokcancel('提示', 'cdn链接刷新完成了!')
                return
            else:
                for url in urlList:
                    if url != '1':
                        print (f'{url=} is not ok!')

            print (f'第 {count} 次查询完毕 \n')
            count = count + 1
            
def refreshGameVersionCfg(cfg):
    urlList = []
    tmpFile = './urlsFile.txt'
    content = ''
    for val in cfg:
        if val['platform'] in platforms:
            for url in val['urls']:
                if debug:
                    url = url.replace(".cfg", '_tmp.cfg')
                # totalUrl.append(url)
                content += url + '\n'
                urlList.append(url)
    
    tool.WriteFile(tmpFile, content[:-1])
    print ("刷新url:")
    print (content[:-1])

    refreshUrl(tmpFile)
    tool.delFile(tmpFile)

    refreshCheck(urlList)

def showVersion(cfg):
    for val in cfg:
        if val['platform'] in platforms:
            for url in val['urls']:
                if debug:
                    url = url.replace(".cfg", '_tmp.cfg')
                
                checkVersion(url)

def main(params, gameCfg):
    global cdnCfg
    global SecretId
    global SecretKey
    cdnCfg = gameCfg['cdnCfg']
    SecretId = cdnCfg['SecretId']
    SecretKey = cdnCfg['SecretKey']

    global hostUrl
    global serverRoot
    global sshCfg
    sshCfg = gameCfg['Ftpcfg']
    hostUrl = sshCfg['hostUrl']
    serverRoot = sshCfg['serverRoot']

    global debug
    debug = params['debug']

    isShow = params['show']

    global platforms
    platforms = params['platforms']
    isNotice = params['notice']

    if not isNotice:
        cfg = gameCfg['version']
        if not isShow:
            refreshGameVersionCfg(cfg)
        else:
            showVersion(cfg)
