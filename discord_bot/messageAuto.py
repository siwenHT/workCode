# -*- coding: utf-8 -*-
from datetime import datetime
import os, json
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

    def __init__(self, CMG: configMG) -> None:
        self.CMG: configMG = CMG

        self.token = self.CMG.token()

    def prepare_head(self, config: RunBetData):
        header_data = {
            "content-type": "application/json",
            "user-agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/97.0.4692.71 Safari/537.36",
            "host": "discordapp.com",
            "origin": "https://discord.com",
            "accept-language":"zh-CN,zh;q=0.9,en-US;q=0.8,en;q=0.7",
        }
        header_data['authorization'] = self.token
        # header_data['referer'] = config.get_channel_link()

        return header_data

    def go_message(self, config: RunBetData):
        headerData = self.prepare_head(config)
        channelId = config.get_discord_channel_id()
        content = config.get_discore_ramdom_message()
        showName = config.get_show_name()

        self.send_message(headerData, channelId, content, showName, config)

    def send_message(self, header, channel_id, message_content, showName, config):
        try:
            message_data = {
                "content": message_content,
                "tts": "false",
            }
            conn = HTTPSConnection('127.0.0.1', 7890)
            conn.set_tunnel("discordapp.com", 443)
            conn.request("POST", f"/api/v6/channels/{channel_id}/messages", dumps(message_data), header)
            resp = conn.getresponse()

            if 199 < resp.status < 300:
                Log.debug(f"succ! link: {showName}, content:{str(message_data)}")
                config.errorTime = 0
            else:
                Log.error(f"fail! link: {showName}, code: {resp.status}, reason : {resp.reason}")
                config.errorTime = config.errorTime + 1

            resp.close()

        except Exception as ex:
            config.errorTime = config.errorTime + 1
            Log.exception("Exception occurred")

    def start(self):
        # self.go_message(self.CMG.dataList[0])
        # pass
        def func():
            now = time.time()
            for config in self.CMG.dataList:
                timeInv = config.get_discord_time_interval()
                if config.errorTime > config.getErrorLimite():
                    continue

                if config.timeRecode == NONE or now - config.timeRecode > timeInv:
                    config.timeRecode = now
                    self.go_message(config)


        #创建调度器：BlockingScheduler
        scheduler = BlockingScheduler()
        #添加任务,时间间隔2S
        scheduler.add_job(func, 'interval', seconds=0.2, id='job', max_instances=100)

        scheduler.start()