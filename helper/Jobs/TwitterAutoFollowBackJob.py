#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   TwitterAutoFollowBack.py
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
from Jobs.WebBaseJob import WebBaseJob
from Until.MyLog import Log
from Web.TwitterHandler import TwitterHandler
from selenium.webdriver.common.by import By


class TwitterAutoFollowBackJob(WebBaseJob):

    def __init__(self):
        super().__init__()
        self._web = TwitterHandler("https://twitter.com/TaoHong25462487/followers", self._typeName)
        self.ReportJobVal(val=f"加载任务")
        self.count = 0
        self.runCount = 0

    def DoJob(self, *args, **kwargs):
        try:
            self.runCount += 1
            followKey = "//span[text() = 'Follow']"
            key = ".css-1dbjc4n.r-x572qd.r-1d6w8o1.r-1867qdf.r-1phboty.r-rs99b7.r-1ifxtd0.r-1bro5k0.r-1udh08x"
            self._web.openGameUrl()
            while True:
                self.CheckStop()
                whoCanFollow = self._web.find_element(By.CSS_SELECTOR, self._web._browser, key)
                if whoCanFollow:
                    self._web.element_hide(whoCanFollow)

                followEl = self._web.find_element_loop(By.XPATH, self._web._browser, followKey)
                if followEl:
                    self._web.element_click(followEl)
                    self.count += 1
                    self.ReportJobVal(val=f'点击了关注 {self.count}')
                    time.sleep(1)
                else:
                    self.ReportJobVal(val=f'未发现关注者 {self.runCount}')
                    self._web.closeBrowser()
                    return
        except Exception as ex:
            Log.exception("TwitterAutoFollowBackJob error")
            self._web.closeBrowser()

    def Done(self, *args, **kwargs):
        return super().Done(*args, **kwargs)
