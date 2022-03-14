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
from Jobs.WebBaseJob import WebBaseJob
from Until.Email import GEmail
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from Web.CandyReward import CandyReward
from Web.OpenUrl import OpenUrl
from selenium.webdriver.common.by import By


class ChiKorokoJob(WebBaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._count = 0

    def DoJob(self, *args, **kwargs):
        errCount = 0

        self.ReportJobVal(val="准备领取NFT")
        while True:
            try:
                if self._isStop:
                    return
                web = OpenUrl('', self._typeName)
                web.openGameUrl("https://expo.chikoroko.art/")
                time.sleep(5)
                self.ReportJobVal(val="准备点击")
                btnEl = web.find_element_loop(By.XPATH, web._browser, "//span[contains(text(), 'Collect now')]")
                if btnEl:
                    # web.element_click(btnEl)
                    # roleKey = "//div[@class='recaptcha-checkbox-border']"
                    # newBtnel = web.find_element_loop(By.XPATH, web._browser, roleKey)
                    # if roleKey:
                    #     web.element_click(newBtnel)

                    # newBtnel = web.find_element_loop(By.XPATH, web._browser, "//button[@class='button-wrapper']")
                    # if newBtnel:
                    #     web.element_click(btnEl)

                    self._count += 1
                    self.ReportJobVal(val=f"有新的领奖 :{self._count}")
                    GEmail.SendText("有新的领奖, 请注意前往领取")
                    time.sleep(3)
                else:
                    collectedKey = "//span[contains(text(), 'Collected')]"
                    if web.find_element(By.XPATH, web._browser, collectedKey):
                        self.ReportJobVal(val=f"已经领完了")
                        web.closeBrowser()
                        return

                web.closeBrowser()
            except Exception as ex:
                Log.exception("ChiKorokoJob error")

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
