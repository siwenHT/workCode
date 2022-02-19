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
from this import d
import os
from BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.Scheduler import TheScheduler
from Until.WinSysytem import Win
from Until import ToolsFunc as TOOL

from Jobs.WindowJob import WindowJob
from Jobs.DiscordJob import DiscordJob
from Jobs.MeatMaskJob import MeatMaskJob
from Jobs.MetauceBotJob import MetauceBotJob
from Jobs.CandyRewardJob import CandyRewardJob
from Jobs.RefreshTimeLabel import RefreshTimeLabel
from Jobs.MetauceHelperJob import MetauceHelperJob


class JobManager():

    def __init__(self):
        self._jobs = []
        self.MsgRegeist()
        self.LoadJobConfig()

        self.jobNames = {}
        self.jobNames[type(WindowJob).__name__] = WindowJob
        self.jobNames[type(DiscordJob).__name__] = DiscordJob
        self.jobNames[type(CandyRewardJob).__name__] = CandyRewardJob
        self.jobNames[type(RefreshTimeLabel).__name__] = RefreshTimeLabel
        self.jobNames[type(MeatMaskJob).__name__] = MeatMaskJob
        self.jobNames[type(MetauceBotJob).__name__] = MetauceBotJob
        self.jobNames[type(MetauceHelperJob).__name__] = MetauceHelperJob

    '''加载任务参数'''

    def LoadJobConfig(self):
        filePath = os.path.join(Win.GetWorkPath(), "Res/JobConfig.json")
        self.jobParams = TOOL.initJsonFromFile(filePath)

    def GetAllJobList(self):
        return self._jobs

    def start(self):
        self._jobs.append(WindowJob())
        self._jobs.append(DiscordJob())
        self._jobs.append(RefreshTimeLabel())

        self._jobs.append(MeatMaskJob())
        self._jobs.append(CandyRewardJob())
        self._jobs.append(MetauceBotJob())
        self._jobs.append(MetauceHelperJob())

        for job in self._jobs:
            job.AddJob(self.jobParams)

        TheScheduler.start()

    def removeJob(self, jobName: str):
        for job in self._jobs:
            job: BaseJob = job
            if job._jobName == jobName:
                TheScheduler.remove_job(jobName)
                self._jobs.remove(job)

    def loadJob(self, jobName: str):
        self.removeJob(jobName)

        newJob = self.jobNames[jobName]()
        self._jobs.append(newJob)
        newJob.AddJob(self.jobParams)

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.pause_all_job:
                for job in self._jobs:
                    job.Pause()
            elif eventType == EventType.resume_all_job:
                for job in self._jobs:
                    job.Resume()
            elif eventType == EventType.reload_job:
                self.loadJob()
            elif eventType == EventType.need_reload_chrome_job:
                self.loadJob("MeatMaskJob")
                self.loadJob("MetauceBotJob")
                self.loadJob("CandyRewardJob")
                GEventHandler.Dispatch(EventType.joblist_has_change)

        GEventHandler.RegedistEvent(EventType.pause_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.resume_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.reload_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.need_reload_chrome_job, msgHandler)
