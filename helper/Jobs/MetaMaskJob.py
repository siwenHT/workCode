#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MetaMaskJob.py
@Time    :   2022/02/19 16:50:58
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

import datetime
import time
# here put the import lib
from ast import While

from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Jobs.WebBaseJob import WebBaseJob
from Until.MyLog import Log
from Web.MetaMaskHelper import MeatMaskHelper

from Jobs.BaseJob import BaseJob


class MetaMaskJob(WebBaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._web = MeatMaskHelper(self._typeName)
        self._web.SetReportCallBack(lambda repVal: self.ReportJobVal(val=repVal))

    def DoJob(self, *args, **kwargs):
        try:
            self.CheckStop()
            self.ReportJobVal(val=f"metamask load")
            self.CheckStop()
            self._web.openGameUrl()
            self.CheckStop()
            self._web.UnlockConfirm()
            self.CheckStop()
            self._web.CheckChainName()
            while True:
                if self._isPause:
                    time.sleep(5)
                    continue

                self.CheckStop()
                time.sleep(0.2)
                self._web.ConfirmChangeNet()
                self._web.ConfirmAccount()
                self._web.ConfirmTransaction()
                self._web.ConfirmApproveAction()
                self._web.SollowBottom()
                self._web.ConfirmOk()
                self._web.refreshPage()

        except Exception as ex:
            if self._isStop:
                self.ReportJobVal(val=f"{self._jobName} exit")
                return

            time.sleep(5)
            self._web.resetBroser()
            Log.exception("MetaMaskJob error:")
            self.DoJob()

    def Done(self, *args, **kwargs):
        return super().Done(*args, **kwargs)