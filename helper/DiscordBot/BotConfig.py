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
        self.config: json = self.get_discord_config(self.filePath)
        self.timeRecode = NONE
        self.errorTime = 0

    def get_discord_config(self, filePath):
        fileCon = Tool.ReadFile(filePath)
        fileCon = Tool.parse_json_str(fileCon.decode('utf-8'))
        return json.loads(fileCon)

    def get_discord_message_index(self, index):
        mlen = self.get_discord_message_len()
        if index > 0 and index < mlen:
            return self.config['mes'][index]

        return ""

    def get_discore_ramdom_message(self):
        return choice(self.config['mes'])

    def get_discord_channel_id(self):
        return self.config["channel_id"]

    def get_discord_message_len(self):
        return len(self.config['mes'])

    def get_discord_time_interval(self):
        return self.config["time_interval"]

    def get_channel_link(self):
        return self.config['discord_link']

    def get_show_name(self):
        return self.config.get("discord_name", "未配置")

    def getErrorLimite(self):
        return self.config.get("errorTimes", 10)
