#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   WebBaseJob.py
@Time    :   2022/03/03 20:12:21
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Jobs.BaseJob import BaseJob
from Until.MyLog import Log


class WebBaseJob(BaseJob):

    def __init__(self):
        super().__init__()
        self.webMsgRegeist()

    def webMsgRegeist(self):

        def msgHandler(eventType: EventType, *args, **kwargs):
            if eventType == EventType.reload_chrome:
                self.Pause()
                self.ReportJobVal(val=f"暂停")
            elif eventType == EventType.reload_chrome_over:
                self.Resume()
                self.ReportJobVal(val=f"恢复")

        GEventHandler.RegedistEvent(EventType.reload_chrome, msgHandler)
        GEventHandler.RegedistEvent(EventType.reload_chrome_over, msgHandler)
