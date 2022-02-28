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
from Until.MyLog import Log
from Web.TwitterHandler import TwitterHandler
from selenium.webdriver.common.by import By


class TwitterAutoFollowBackJob(BaseJob):

    def __init__(self):
        super().__init__()
        self._web = TwitterHandler("https://twitter.com/TaoHong25462487/followers")
        self.ReportJobVal(val=f"加载任务")

    def DoJob(self, *args, **kwargs):
        try:
            followKey = "//div[@class='css-1dbjc4n']/div/div/div/div/div/div/div/div/div/div[starts-with(@aria-label,'Follow ')]"
            self._web.openGameUrl()
            while True:
                followEl = self._web.find_element_loop(By.XPATH, self._web._browser, followKey)
                if followEl:
                    self.ReportJobVal(val=f'点击了关注')
                    self._web.element_click(followEl)
                    time.sleep(1)

                else:
                    self.JobEnd()
                    return
        except Exception as ex:
            Log.exception("error")
            self.JobEnd()

    def Done(self, *args, **kwargs):
        return super().Done(*args, **kwargs)
