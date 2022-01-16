# -*- coding: utf-8 -*-
import os,json
from pickle import NONE
from random import choice

# 配置
class RunBetData:
    def __init__(self, jsonDict):
        self.config:json = jsonDict
        self.timeRecode = NONE

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

    def getChannelName(self):
        return self.config['discord_link']
