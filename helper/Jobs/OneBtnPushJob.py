#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   OneBtnPushJob.py
@Time    :   2022/02/19 15:24:52
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import os, time
from xmlrpc.client import boolean
from Jobs.BaseJob import BaseJob
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotManager import BotManager
from DiscordBot.BotMsgSend import BotMsgSend
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from pickle import NONE
from Until.WinSysytem import Win


class OneBtnPushJob(BaseJob):

    def __init__(self, istest: boolean) -> None:
        super().__init__()
        self._filePath = os.path.join(Win.GetWorkPath(), "Res/pushForShare.json")
        self._isTest = istest

    def LoadConfig(self):
        self._config: BotConfig = BotConfig(self._filePath)

    def DoJob(self, *args, **kwargs):
        self.LoadConfig()
        self.ReportJobVal(val=f"加载完配置")

        config = self._config
        if self._isTest:
            self.ReportJobVal(val=f"目前是测试环境，只发送第一个渠道号")
            config._config["channel_id"] = config._config["channel_ids"][0]
            config._config["channel_ids"] = None

        time.sleep(0.5)
        time.time()
        self._curChannel = 0
        if config.ChannelIDs():
            while config.NextChannelID():
                now = time.time()
                if config.timeRecode == NONE or now - config.timeRecode > config.StepTime():
                    config.timeRecode = now
                    self._curChannel = config.NextChannelID()
                    self.ReportJobVal(val=f"{self._curChannel}")
                    self.SendMsgWithBotConfig(config)
                    config.StepNextChannel()

                    # 如果重新回到了原位, 则可以退出了
                    if config.GetCurrentIdx() == 0:
                        break
                else:
                    time.sleep(0.5)
        else:
            self._curChannel = config.ChannelID()
            self.ReportJobVal(val=f"{self._curChannel}")
            self.SendMsgWithBotConfig(config)
        self.ReportJobVal(val=f"发送完成")
        GEventHandler.Dispatch(EventType.stop_job, self._jobName)

    def SendMsgWithBotConfig(self, botConfig: BotConfig):
        sender = BotMsgSend(botConfig)
        if not sender.send() and self._curChannel != 0:
            Log.error(f"{self._jobName} error, channel id: {self._curChannel}")