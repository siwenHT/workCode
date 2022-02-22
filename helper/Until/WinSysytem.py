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
import os, time
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until import ToolsFunc as TOOL
from Until.MyLog import Log


class WinSystem():

    def __init__(self) -> None:
        self._ensKey = '0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz._'
        self._configFilePath = os.path.join(self.GetWorkPath(), 'Res/Config.json')

        self.InitConfig()
        self.MsgRegeist()

    def InitConfig(self):
        self._commonConfig = TOOL.initJsonFromFile(self._configFilePath)

    def ReloadBrower(self):
        os.system("taskkill /f /im chrome.exe")
        os.system('cd /d C:/Program Files/Google/Chrome/Application && start chrome.exe --remote-debugging-port=9527 --"%1"')
        os.system('cd /d C:/Program Files (x86)/Google/Chrome/Application && start chrome.exe --remote-debugging-port=9527 --"%1"')
        time.sleep(3)
        GEventHandler.Dispatch(EventType.reload_chrome_over)

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

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.reload_config:
                self.InitConfig()
            elif eventType == EventType.reload_chrome:
                self.ReloadBrower()

        GEventHandler.RegedistEvent(EventType.reload_config, msgHandler)
        GEventHandler.RegedistEvent(EventType.reload_chrome, msgHandler)


Win = WinSystem()