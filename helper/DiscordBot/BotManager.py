#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BotManager.py
@Time    :   2022/02/15 01:22:51
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   聊天机器人管理
'''

# here put the import lib

import os
from DiscordBot.BotConfig import BotConfig
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.Scheduler import TheScheduler
from Until.WinSysytem import Win
from Until import ToolsFunc as Tool


class BotManager():

    def __init__(self) -> None:
        self._configPath = os.path.join(Win.GetWorkPath(), 'Res/BotConfig')
        self.LoadBotConfigs()
        self.MsgRegeist()

    def LoadBotConfigs(self):
        self._dataList = []
        fileList = Tool.ListFile(self._configPath)

        switch = Win.DiscordSwitch()
        for filePath in fileList:
            (filepath, shotname, extension) = Tool.getFile_path_name_suf(filePath)
            if switch.get(shotname, 0) == 1:
                oneData = BotConfig(filePath)
                self._dataList.append(oneData)

    def GetList(self):
        return self._dataList

    def ChangeBotConfigSetByUI(self):
        pass

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.reload_config:
                self.InitConfig()

        GEventHandler.RegedistEvent(EventType.reload_config, msgHandler)
