#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BotConfig.py
@Time    :   2022/02/15 01:15:40
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   机器人配置
'''

# here put the import lib
import os, json
from pickle import NONE
from Until import ToolsFunc as Tool
from random import choice


class BotConfig():

    def __init__(self, filePath) -> None:
        self.filePath = filePath
        self.timeRecode = NONE
        self.errorTime = 0
        self._idx = 0

        self.InitCfg()

    def InitCfg(self):
        self._config: json = Tool.initJsonFromFile(self.filePath)

    def RandomMessage(self):
        return choice(self._config['mes'])

    def SetMessage(self, mes):
        self._config['mes'] = mes

    def ChannelID(self):
        return self._config.get("channel_id", "")

    def TimeInterval(self):
        return self._config["time_interval"]

    def ChannelLink(self):
        return self._config.get('discord_link', "未配置")

    def ShowName(self):
        return self._config.get("discord_name", "未配置")

    def ErrorLimite(self):
        return self._config.get("errorTimes", 10)

    def ChannelIDs(self):
        return self._config.get("channel_ids", None)

    def StepTime(self):
        return self._config.get("stepTime", 2)

    def NextChannelID(self):
        channelIds = self.ChannelIDs()
        if channelIds:
            if self._idx < len(channelIds):
                return channelIds[self._idx]
            else:
                return None
        else:
            return None

    def GetTmpChannelID(self):
        return self._config.get("tempChannel_id")

    def StepNextChannel(self):
        self._idx += 1
        if self.ChannelIDs() and self._idx >= len(self.ChannelIDs()):
            self._idx = 0

    def GetCurrentIdx(self):
        return self._idx
