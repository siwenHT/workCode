#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   ChiKorokoJob.py
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
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from Web.CandyReward import CandyReward
from Web.OpenUrl import OpenUrl
from selenium.webdriver.common.by import By


class ChiKorokoJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._count = 0

    def DoJob(self, *args, **kwargs):
        errCount = 0

        while True:
            try:
                if self._isStop:
                    return
                web = OpenUrl()
                self.ReportJobVal(val="准备打开网页")
                web.openGameUrl("https://expo.chikoroko.art/")
                self.ReportJobVal(val="打开完成")
                time.sleep(5)
                self.ReportJobVal(val="准备点击领奖")
                btnEl = web.find_element_loop(By.XPATH, web._browser, "//span[@class='mobile-toy-info']/button")
                if btnEl:
                    web.element_click(btnEl)
                    self._count += 1
                    self.ReportJobVal(val=f"领奖OK了 :{self._count}")
                    web.closeBrowser()
                    return

                web.closeBrowser()
            except Exception as ex:
                Log.exception("ChiKorokoJob error")
                pass

            if self._isStop:
                return

            if errCount < 10:
                time.sleep(60)
                errCount += 1
            else:
                break

    def Done(self, *args, **kwargs):
        return super().Done(*args, **kwargs)
