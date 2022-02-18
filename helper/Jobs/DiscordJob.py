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
from time import time
from BaseJob import BaseJob
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotManager import BotManager
from DiscordBot.BotMsgSend import BotMsgSend
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from pickle import NONE


class DiscordJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._jobName = 'DiscordJob'
        self._botMG = BotManager()

    def DoJob(self, *args, **kwargs):

        now = time()
        for config in self._botMG._dataList:
            config: BotConfig = config
            if config.errorTime > config.ErrorLimite():
                continue

            if config.ChannelIDs():
                timeInv = config.TimeInterval() if (config.GetCurrentIdx() == 0) else config.StepTime()
                if config.NextChannelID():
                    if config.timeRecode == NONE or now - config.timeRecode > timeInv:
                        config.timeRecode = now
                        self.SendMsgWithBotConfig(config)
                        config.StepNextChannel()
            else:
                if config.timeRecode == NONE or now - config.timeRecode > config.TimeInterval():
                    config.timeRecode = now
                    self.SendMsgWithBotConfig(config)

    def SendMsgWithBotConfig(self, botConfig: BotConfig):
        sender = BotMsgSend(botConfig)
        sender.send()
        pass

    def AddJob(self):
        TheScheduler.add_job(self.Done, 'interval', seconds=0.1, id='botJob', max_instances=100, args=[self])
