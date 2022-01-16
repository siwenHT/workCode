# -*- coding: utf-8 -*-
from datetime import datetime
import os,json
from pickle import NONE
import time, os
from http.client import HTTPSConnection
from sys import stderr
from json import dumps
from ConfigManager import ConfigManager as configMG
from runBetData import RunBetData
from thelog import Log
from apscheduler.schedulers.blocking import BlockingScheduler

'''发送消息'''
class messageAuto:

    def __init__(self, CMG : configMG) -> None:
        self.CMG:configMG = CMG

        self.token = self.CMG.token()
    
    
    def prepare_head(self, config: RunBetData):
        header_data = {
            "content-type": "application/json",
            "user-agent": "discordapp.com",
            "host": "discordapp.com",
        }
        header_data['authorization'] = self.token
        header_data['referer'] = config.getChannelName()

        return header_data

    def go_message(self, config: RunBetData):
        headerData = self.prepare_head(config)
        channelId = config.get_discord_channel_id()
        content = config.get_discore_ramdom_message()
        linkName = config.getChannelName()

        self.send_message(headerData, channelId, content, linkName)

    def send_message(self, header, channel_id, message_content, linkName):
        try:
            message_data = {
                "content": message_content,
                "tts": "false",
            }
            conn = HTTPSConnection('127.0.0.1', 7891)
            conn.set_tunnel("discordapp.com", 443)
            conn.request("POST", f"/api/v6/channels/{channel_id}/messages", dumps(message_data), header)
            resp = conn.getresponse()

            if 199 < resp.status < 300:
                Log.debug(f"succ! link: {linkName}, channel:{channel_id} content:{str(message_data)}")
                pass

            else:
                Log.error(f"fail! code: {resp.status}, reason : {resp.reason}")
                pass

            resp.close()

        except Exception as ex:
            Log.exception("Exception occurred")

    def start(self):
        # self.go_message(self.CMG.dataList[0])
        # pass
        def func():
            now = time.time()
            for config in self.CMG.dataList:
                timeInv = config.get_discord_time_interval()
                if config.timeRecode == NONE or now - config.timeRecode > timeInv:
                    config.timeRecode = now
                    self.go_message(config)

        #创建调度器：BlockingScheduler
        scheduler = BlockingScheduler()
        #添加任务,时间间隔2S
        scheduler.add_job(func, 'interval', seconds=1, id='job')

        scheduler.start()