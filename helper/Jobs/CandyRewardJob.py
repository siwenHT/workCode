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
import time
from tkinter import E
from Jobs.BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Jobs.WebBaseJob import WebBaseJob
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from Web.CandyReward import CandyReward


class CandyRewardJob(WebBaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        errCount = 0

        while True:
            try:
                web = CandyReward(self._typeName)
                self.ReportJobVal(val="准备开始领奖")
                web.openGameUrl()
                time.sleep(5)
                self.ReportJobVal(val="准备领奖")
                if web.clickReward():
                    web.closeBrowser()
                    self.ReportJobVal(val="领奖OK了")
                    return

                web.closeBrowser()
            except Exception as ex:
                Log.exception("CandyRewardJob error")

            if self._isStop:
                return

            self.CheckPause()

            if errCount < 10:
                time.sleep(60)
                errCount += 1
            else:
                break

    def Done(self, *args, **kwargs):
        return super().Done(*args, **kwargs)
