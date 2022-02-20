#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MeatMaskJob.py
@Time    :   2022/02/19 16:50:58
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from ast import While
import datetime
import time
from Jobs.BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Web.MeatMaskHelper import MeatMaskHelper


class MeatMaskJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        try:
            self.ReportJobVal(val=f"metamask load")
            self._web = MeatMaskHelper()
            self._web.SetReportCallBack(lambda repVal: self.ReportJobVal(val=repVal))
            self._web.openGameUrl()
            self._web.UnlockConfirm()
            self._web.CheckChainName()
            while True:
                if self._isPause:
                    time.sleep(5)
                    continue

                if self._isStop:
                    self.ReportJobVal(val=f"{self._jobName} exit")
                    return

                self._web.ConfirmChangeNet()
                self._web.ConfirmTransaction()
                time.sleep(0.5)

        except Exception as ex:
            self.DoJob()
