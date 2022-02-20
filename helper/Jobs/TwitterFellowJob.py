#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   TwitterFellowJob.py
@Time    :   2022/02/20 00:02:24
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   推特互关
'''

# here put the import lib
import os, time
from Jobs.BaseJob import BaseJob
from Until.MyLog import Log
from Until.WinSysytem import Win
from Until import ToolsFunc as TOOL
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotMsgSend import BotMsgSend
from pickle import NONE


class TwitterFellowJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._filePath = os.path.join(Win.GetWorkPath(), "Res/twitterFellow.json")

    def LoadConfig(self):
        self._config: BotConfig = BotConfig(self._filePath)

    def DoJob(self, *args, **kwargs):
        self.LoadConfig()
        self.ReportJobVal(val=f"加载完配置")

        config = self._config
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

    def SendMsgWithBotConfig(self, botConfig: BotConfig):
        sender = BotMsgSend(botConfig)
        if not sender.send() and self._curChannel != 0:
            Log.error(f"{self._jobName} error, channel id: {self._curChannel}")