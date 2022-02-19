#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   RefreshTimeLabel.py
@Time    :   2022/02/18 08:33:21
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.Scheduler import TheScheduler


class RefreshTimeLabel(BaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        GEventHandler.Dispatch(EventType.refresh_time_label)

    def AddJob(self, jobParams):
        TheScheduler.add_job(self.Done, 'interval', seconds=1, max_instances=1)
