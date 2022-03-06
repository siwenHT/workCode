#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MetauceBotJob.py
@Time    :   2022/02/19 02:33:08
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import datetime
import time
from Jobs.BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Jobs.WebBaseJob import WebBaseJob
from Until.MyLog import Log
from Web.MetauceBot import MetauceBot


class MetauceBotJob(WebBaseJob):

    def __init__(self) -> None:
        super().__init__()

        self._starLimit = 3
        self._web = None
        self._web = MetauceBot(self._typeName)
        self._web.SetReportCallBack(lambda repVal: self.ReportJobVal(val=repVal))

    def DoJob(self, *args, **kwargs):
        while True:
            try:
                if self._isPause:
                    time.sleep(5)
                    continue

                self.CheckStop()
                self.mainFunc()
                if self._isPause:
                    time.sleep(5)
                    continue

                self.CheckStop()
                self.mainFunc()
                if self._isPause:
                    time.sleep(5)
                    continue

                self.CheckStop()
                self.insertTruck()
                if self._isPause:
                    time.sleep(5)
                    continue

                self.CheckStop()
                self.checkTokenVal()
                if self._isPause:
                    time.sleep(5)
                    continue

                self.CheckStop()
                self._web.touchMedalBtn()
                if self._isPause:
                    time.sleep(5)
                    continue

                self.CheckStop()
                self.removeTruck()
                if self._isPause:
                    time.sleep(5)
                    continue

                time.sleep(60 * 60)
            except Exception as ex:
                if self._isStop:
                    self._web.closeBrowser()
                    self.ReportJobVal(val=f"{self._jobName} exit")
                    return

                Log.exception(f"{self._jobName} error")
                self.DoJob(*args, **kwargs)

    def Stop(self):
        self._web.SetNeedStop(True)
        return super().Stop()

    def mainFunc(self):
        self.ReportJobVal(val="开始启动收矿")
        self._web.openGameUrl("https://metauce.org/MetisGame/#/Play")
        self._web.touchOneRemainBtn()

        self._web.wakuang()
        self._web.closeBrowser()

    def insertTruck(self):
        self.ReportJobVal(val="准备安装矿车")
        handler = self._web
        handler.openGameUrl("https://metauce.org/MetisGame/#/Play")
        handler.touchOneRemainBtn()
        time.sleep(20)
        self.ReportJobVal(val="安装矿车环境准备完毕")

        count = 0
        while True:
            if handler.insertTruck(self._starLimit):
                count += 1
                self.ReportJobVal(val="安装矿车 {count} 次")
                self.CheckStop()

                time.sleep(20)
                continue
            break
        handler.closeBrowser()

    def checkTokenVal(self):
        self.ReportJobVal(val="准备购买")
        handler = self._web
        handler.openGameUrl()
        handler.checkBuyTime()
        handler.closeBrowser()

    def removeTruck(self):
        self.ReportJobVal(val="准备移除车辆")
        handler = self._web
        handler.openGameUrl("https://metauce.org/MetisGame/#/Play")
        handler.touchDepletedBtn()
        handler.removeTruck()
        time.sleep(10)
        handler.closeBrowser()

    def Done(self, *args, **kwargs):
        return super().Done(*args, **kwargs)