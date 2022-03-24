#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BotMsgSend.py
@Time    :   2022/02/15 01:33:21
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from http.client import HTTPSConnection
from json import dumps
from DiscordBot.BotConfig import BotConfig
from Until.MyLog import Log
from Until.WinSysytem import Win


class BotMsgSend():

    def __init__(self, botConfig: BotConfig) -> None:
        self._botConfig: BotConfig = botConfig

    def ParaseHead(self):
        headerData = {
            "content-type": "application/json",
            # "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36",
            # "host": "discordapp.com",
            # "origin": "https://discord.com",
            # "accept-language": "zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7",
        }

        headerData['authorization'] = Win.DiscordToken()
        return headerData

    def send(self):
        try:
            message_data = {}
            message_data["content"] = self._botConfig.RandomMessage()
            message_data["tts"] = "false"

            header = self.ParaseHead()
            showName = self._botConfig.ShowName()
            channel = self._botConfig.GetTmpChannelID() or self._botConfig.NextChannelID() or self._botConfig.ChannelID()
            httpIp = Win.HttpIp()
            httpPort = Win.HttpPort()
            conn = HTTPSConnection(httpIp, int(httpPort))
            conn.set_tunnel("discordapp.com", 443)
            conn.request("POST", f"/api/v6/channels/{channel}/messages", dumps(message_data), header)
            resp = conn.getresponse()

            if 199 < resp.status < 300:
                data = resp.read()
                resp.close()
                Log.debug(f"succ! link: {showName}")
                self._botConfig.errorTime = 0

                if data == b"":
                    data = b"{}"
                return data
            else:
                Log.error(f"fail! link: {showName}, code: {resp.status}, reason : {resp.reason}")
                self._botConfig.errorTime += 1
                resp.close()
                return False

        except Exception as ex:
            self._botConfig.errorTime += 1
            Log.exception("Exception occurred")
            return False
