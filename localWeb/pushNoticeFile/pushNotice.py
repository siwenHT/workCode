# -*- coding:utf-8 -*-
import os
import sys
import pushNoticeFile.toolsFunc3 as tool
from pushNoticeFile.toolsFunc3 import SSHTools
from .models import Game, NoticeCfg, NoticeLog

isDebug = False
def refreshUrl(fileUrl, SecretKey, SecretId):
    cmd = 'python pushNoticeFile/QcloudCdnTools_V2.py RefreshCdnUrl -u {id} -p {key} --urls-from {u}'.format(id = SecretId, key = SecretKey, u = fileUrl)
    # print("url:" + fileUrl)

    if not isDebug:
        os.system(cmd)

def refreshUrls(urlList, SecretKey, SecretId):
    content = ''
    for url in urlList:
        content += url + '\n'
    
    print(content)
    filePath = 'tmpUrls.txt'
    tool.WriteFile(filePath, content)
    refreshUrl(filePath, SecretKey, SecretId)
    tool.delFile(filePath)

def pushFiles(text, fileList, sshInfo):
    if not fileList:
        return

    print(fileList)
    count = 1
    filePath = 'noticeTmp.txt'
    tool.WriteFile(filePath, text)
    try:
        obj = SSHTools(sshInfo.user, sshInfo.psw, sshInfo.port, sshInfo.ip)
        conFlg = getattr(obj, "connect")()
        if conFlg :
            for itemInfo in fileList:
                tmpFile = itemInfo.replace(sshInfo.server_root, '')
                pos = tool.findLastStr(tmpFile, '/')
                tmpFile = tmpFile[:pos]

                getattr(obj, 'cmd')(f'cd {sshInfo.server_root};mkdir -p {tmpFile}')
                getattr(obj, 'cmd')(f'chmod -R a+r {sshInfo.server_root}{tmpFile}')
                getattr(obj, 'cmd')('chmod 777 ' + itemInfo)

                getattr(obj, 'setDir')(os.path.abspath(filePath), itemInfo)
                getattr(obj, "put")()
                ret, _ = getattr(obj, 'cmd')('cat ' + itemInfo)
                strRet = ''
                for i in ret:
                    strRet = strRet + i

                if strRet and strRet.find(text) == -1:
                    print("文件推送失败了.请重新推送. file:" + itemInfo)
                else:
                    print(itemInfo + ':' + strRet)

            getattr(obj, 'close')()
    except Exception as e:
        print ("e：", e)
        tool.time.sleep(5)
        print ('推送公告异常, 2秒后重新在处理一次\n')
        pushFiles(text, fileList, sshInfo)
        count = count + 1
        if count > 3:
            tool.delFile(filePath)
            return e

    tool.delFile(filePath)

def pushNoticeFunc(text, tmpNoticeCfg):
    urlList = {}
    fileLists = {}

    sshInfo = tmpNoticeCfg.ssh
    cdnInfo = tmpNoticeCfg.cdn
    for game in tmpNoticeCfg.game_set.all():
        if game.notice_url:
            urlList[game.notice_url] = 1

            filePath = game.notice_url.replace(sshInfo.host_url, sshInfo.server_root + 'tmp/')
            fileLists[filePath] = 1
            break

    # 把文件写入文件服务器
    # 把公告下所有游戏的链接收集起来全部刷新
    e = pushFiles(text, fileLists.keys(), sshInfo)
    if not e:
        refreshUrls(urlList.keys(), cdnInfo.secret_key, cdnInfo.secret_id)
        
    return e