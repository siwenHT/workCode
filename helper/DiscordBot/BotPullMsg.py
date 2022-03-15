#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BotPullMsg.py
@Time    :   2022/03/11 12:52:13
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib
import time
from http.client import HTTPSConnection
from json import dumps
from DiscordBot.BotConfig import BotConfig
from Until.MyLog import Log
from Until.WinSysytem import Win


### 获取频道的历史消息
class BotPullMsg(object):

    def __init__(self, botConfig: BotConfig):
        self._botConfig = botConfig
        self._getTime = 0
        self._invTime = 0.5

    def Header(self):
        headers = {}
        headers['content-type'] = "application/json"
        headers['authorization'] = Win.DiscordToken()

        return headers

    def GetRemoteMessage(self, limmit=50):

        if time.time() - self._getTime <= self._invTime:
            Log.info(f"BotPullMsg time inv not enough! {time.time() - self._getTime} => {self._invTime}")
            return

        try:
            showName = self._botConfig.ShowName()
            channel = self._botConfig.ChannelID()
            header = self.Header()
            httpIp = Win.HttpIp()
            httpPort = Win.HttpPort()

            self._getTime = time.time()
            conn = HTTPSConnection(httpIp, int(httpPort))
            conn.set_tunnel("discordapp.com", 443)
            conn.request("GET", f"/api/v6/channels/{channel}/messages?limit={limmit}", None, header)
            resp = conn.getresponse()

            if 199 < resp.status < 300:
                data = resp.read()
                Log.debug(f"succ! name: {showName}, GetRemoteMess")
                self._botConfig.errorTime = 0
                resp.close()
                return data
            else:
                Log.info(f"fail! name: {showName}, code: {resp.status}, reason : {resp.reason}")
                self._botConfig.errorTime += 1
                resp.close()
                return ""

        except Exception as ex:
            self._botConfig.errorTime += 1
            Log.exception("Exception occurred")
            return ""