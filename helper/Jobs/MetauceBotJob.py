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
from time import time
from BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Web.MetauceBot import MetauceBot


class MetauceBotJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        while True:
            try:
                self.mainFunc()
                self.insertTruck()
                self.checkTokenVal()
                self.removeTruck()

                time.sleep(60 * 60)
            except Exception as ex:
                pass

    def mainFunc(self):
        self.ReportJobVal(val="开始启动收矿")
        handler = MetauceBot()
        handler.openGameUrl()
        handler.touchMining()
        handler.touchOneRemainBtn()
        handler.wakuang()
        handler.closeBrowser()
        self.ReportJobVal(val="收矿作业完成")

    def insertTruck(self):
        starLimit = 3
        self.ReportJobVal(val="准备安装矿车")
        handler = MetauceBot()
        handler.openGameUrl()
        handler.touchMining()
        handler.touchOneRemainBtn()
        time.sleep(20)
        self.ReportJobVal(val="安装矿车环境准备完毕")

        count = 0
        while True:
            if handler.insertTruck(starLimit):
                count += 1
                self.ReportJobVal(val="安装矿车 {count} 次")

                time.sleep(20)
                continue
            break
        handler.closeBrowser()
        self.ReportJobVal(val="安装矿车完成 安装了{count}台车")

    def checkTokenVal(self):
        self.ReportJobVal(val="准备购买")
        handler = MetauceBot()
        handler.openGameUrl()
        handler.touchMining()
        handler.touchOneRemainBtn()
        self.ReportJobVal(val="准备中...")
        handler.checkBuyTime()
        self.ReportJobVal(val="购买完成")

    def removeTruck(self):
        self.ReportJobVal(val="准备移除车辆")
        handler = MetauceBot()
        handler.openGameUrl()
        handler.touchMining()
        handler.touchDepletedBtn()
        handler.removeTruck()
        time.sleep(10)
        handler.closeBrowser()
        self.ReportJobVal(val="移除车辆完成")
