#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   CandyRewardJob.py
@Time    :   2022/02/19 02:47:22
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import datetime
from time import time
from tkinter import E
from BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from Web.CandyReward import CandyReward


class CandyRewardJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        errCount = 0

        while True:
            try:
                web = CandyReward()
                self.ReportJobVal(val="准备打开网页")
                web.openGameUrl()
                self.ReportJobVal(val="打开完成")
                time.sleep(5)
                self.ReportJobVal(val="准备点击领奖")
                if web.clickReward():
                    web.closeBrowser()
                    self.ReportJobVal(val="领奖OK了")
                    return
            except Exception as ex:
                pass

            if errCount < 10:
                time.sleep(60)
                errCount += 1
            else:
                break

    # def AddJob(self, jobParams):
    #     TheScheduler.add_job(self.Done, trigger='cron', hour='10', max_instances=1)
