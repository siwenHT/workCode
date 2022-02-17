#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   JobManager.py
@Time    :   2022/02/15 01:26:21
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   任务管理器
'''

# here put the import lib
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Jobs.WindowJob import WindowJob
from Until.Scheduler import TheScheduler
from Jobs.DiscordJob import DiscordJob


class JobManager():

    def __init__(self) -> None:
        self._jobs = []
        self.MsgRegeist()

    def pause(self):
        pass

    def pasueByType(self, type):
        pass

    def start(self):
        # self._jobs.append(DiscordJob())
        self._jobs.append(WindowJob())

        for job in self._jobs:
            job.AddJob()

        TheScheduler.start()
        pass

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.pause_all_job:
                for job in self._jobs:
                    job.Pause()
            elif eventType == EventType.resume_all_job:
                for job in self._jobs:
                    job.Resume()

        GEventHandler.RegedistEvent(EventType.pause_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.resume_all_job, msgHandler)
