#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   WinSysytem.py
@Time    :   2022/02/15 08:22:51
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import os
from Until import ToolsFunc as TOOL
from Until.MyLog import Log


class WinSystem():

    def __init__(self) -> None:
        self._ensKey = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz._'
        self._configFilePath = os.path.join(self.GetWorkPath(), 'Res/Config.json')

        self.InitConfig()

    def InitConfig(self):
        self._commonConfig = TOOL.initJsonFromFile(self._configFilePath)

    def ReloadBrower(self):
        os.system("taskkill /f /im chrome.exe")
        os.system('chrome.exe --remote-debugging-port=9527 --"%1"')
        pass

    def GetWorkPath(self):
        return os.getcwd()

    def DiscordToken(self):
        retList = self._commonConfig.get("discord_token", "")
        return self.SimpDesc(retList)

    def HttpIp(self):
        return self._commonConfig.get("http_ip", "127.0.0.1")

    def HttpPort(self):
        return self._commonConfig.get("http_port", "")

    def DiscordSwitch(self):
        return self._commonConfig.get("discord_switch", [])

    def SimpEnc(self, input: str):
        ret = []
        for i in range(len(input)):
            index = self._ensKey.index(input[i])
            if index >= 0:
                ret.append(index)
            else:
                Log.error(f"not find the key {input[i]}")

        return ret

    def SimpDesc(self, input: list):
        retStr = ''
        for idx in input:
            retStr = retStr + self._ensKey[idx]

        return retStr


Win = WinSystem()