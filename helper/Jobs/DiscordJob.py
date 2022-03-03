#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   DiscordJob.py
@Time    :   2022/02/15 08:41:35
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import os, time
from Jobs.BaseJob import BaseJob
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotManager import BotManager
from DiscordBot.BotMsgSend import BotMsgSend
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from pickle import NONE


class DiscordJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._botMG = BotManager()

    def DoJob(self, *args, **kwargs):

        now = time.time()
        for config in self._botMG._dataList:
            config: BotConfig = config
            if config.errorTime > config.ErrorLimite():
                continue

            if self._isStop:
                return

            if self._isPause:
                continue

            if config.ChannelIDs():
                timeInv = config.TimeInterval() if (config.GetCurrentIdx() == 0) else config.StepTime()
                if config.NextChannelID():
                    if config.timeRecode == NONE or now - config.timeRecode > timeInv:
                        config.timeRecode = now
                        self.ReportJobVal(val=config.ShowName())
                        self.SendMsgWithBotConfig(config)
                        config.StepNextChannel()
            else:
                if config.timeRecode == NONE or now - config.timeRecode > config.TimeInterval():
                    config.timeRecode = now
                    self.ReportJobVal(val=config.ShowName())
                    self.SendMsgWithBotConfig(config)

    def AddJob(self, jobParams):
        self._botMG.LoadBotConfigs()
        return super().AddJob(jobParams)

    def SendMsgWithBotConfig(self, botConfig: BotConfig):
        sender = BotMsgSend(botConfig)
        sender.send()

    def Done(self, *args, **kwargs):
        return super().Done(*args, **kwargs)
