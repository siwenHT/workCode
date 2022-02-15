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


class WinSystem():

    def __init__(self) -> None:
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
        return self._commonConfig.get("discord_token", "")

    def HttpIp(self):
        return self._commonConfig.get("http_ip", "127.0.0.1")

    def HttpPort(self):
        return self._commonConfig.get("http_port", "")

    def DiscordSwitch(self):
        return self._commonConfig.get("discord_switch", [])


Win = WinSystem()