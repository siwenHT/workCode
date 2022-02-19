#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MetauceHelperJob.py
@Time    :   2022/02/19 16:52:37
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   挖矿伴生程序
'''

# here put the import lib
import datetime
from time import time
from BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Web.MetauceBot import MetauceBot
from Web.OpenUrl import OpenUrl
from Until.WinSysytem import Win


class MetauceHelperJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        self.ReportJobVal(val="开始检查浏览器网页标题")
        web = OpenUrl("")
        web.find_the_browser()

        count = 0
        num = len(web._browser.window_handles)
        self.ReportJobVal(val=f"浏览器网页数目 {num}")
        for one in web._browser.window_handles:
            checkTime = 0
            while True:
                web._browser.switch_to.window(one)
                time.sleep(1)

                if checkTime > 5:
                    break
                elif web.current_window_handle != one:
                    checkTime += 1
                else:
                    break

            flg = web._browser.title.find("Metauce")
            if flg > -1:
                count = count + 1

        self.ReportJobVal(val=f"找到的数目为: {count}")
        if count > 2:
            Win.ReloadBrower()
            time.sleep(3)
            self.ReportJobVal(val=f"重启了浏览器")
            GEventHandler.Dispatch(EventType.need_reload_chrome_job)
