#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   UpLevelJob.py
@Time    :   2022/03/21 10:11:29
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import os, json
from DiscordBot.BotMsgSend import BotMsgSend
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.WinSysytem import Win
from Jobs.BaseJob import BaseJob
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotDeleteMsg import BotDeleteMsg


class UpLevelJob(BaseJob):

    def __init__(self):
        super().__init__()
        self._channelCfg = os.path.join(Win.GetWorkPath(), "Res/BotConfig/uplevel.json")
        self.InitCfg()
        self.MsgRegeist()

    def InitCfg(self):
        self._botConfig = BotConfig(self._channelCfg)

    def DoJob(self):
        try:
            recData = BotMsgSend(self._botConfig).send()
            jsonData = recData.decode('utf-8')
            JsonList = json.loads(jsonData)
            id = JsonList.get('id')

            BotDeleteMsg(self._botConfig).DelMsg(id)
        except Exception as ex:
            pass

    def AddJob(self, jobParams):
        self.InitCfg()
        return super().AddJob(jobParams)

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.reload_config:
                self.InitCfg()

        GEventHandler.RegedistEvent(EventType.reload_config, msgHandler)