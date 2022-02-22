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
import os, time
from xmlrpc.client import boolean
from Jobs.BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.Scheduler import TheScheduler
from Until.WinSysytem import Win
from Until import ToolsFunc as TOOL
from Until.MyLog import Log

from Jobs.WindowJob import WindowJob
from Jobs.DiscordJob import DiscordJob
from Jobs.MeatMaskJob import MeatMaskJob
from Jobs.MetauceBotJob import MetauceBotJob
from Jobs.CandyRewardJob import CandyRewardJob
from Jobs.RefreshTimeLabel import RefreshTimeLabel
from Jobs.MetauceHelperJob import MetauceHelperJob
from Jobs.TwitterFellowJob import TwitterFellowJob
from Jobs.GmToChannelJob import GmToChannelJob
from Jobs.OneBtnPushJob import OneBtnPushJob


class JobManager():

    def __init__(self):
        self._jobInitStart = False
        self._jobs = []
        self.MsgRegeist()
        self.LoadJobConfig()

        self.jobNames = {}
        self.jobNames["WindowJob"] = WindowJob
        self.jobNames["DiscordJob"] = DiscordJob
        self.jobNames["CandyRewardJob"] = CandyRewardJob
        self.jobNames["RefreshTimeLabel"] = RefreshTimeLabel
        self.jobNames["MeatMaskJob"] = MeatMaskJob
        self.jobNames["MetauceBotJob"] = MetauceBotJob
        self.jobNames["MetauceHelperJob"] = MetauceHelperJob
        self.jobNames["TwitterFellowJob"] = TwitterFellowJob
        self.jobNames["GmToChannelJob"] = GmToChannelJob
        self.jobNames["OneBtnPushJob"] = OneBtnPushJob

    '''加载任务参数'''

    def LoadJobConfig(self):
        filePath = os.path.join(Win.GetWorkPath(), "Res/JobConfig.json")
        self.jobParams = TOOL.initJsonFromFile(filePath)

    def GetAllJobList(self):
        return self._jobs

    def start(self):
        self._jobs.append(WindowJob())
        self._jobs.append(RefreshTimeLabel())

        for job in self._jobs:
            job.AddJob(self.jobParams)

        TheScheduler.start()

    '''按配置开启任务'''

    def StartJobByInitConfig(self):
        if self._jobInitStart:
            initJobs = self.jobParams.get("initJobs")
            for jobName in initJobs:
                self.loadJob(jobName)

    def RestartJobWhoExist(self, jobTypeName: str):
        job = self.FindTheJob(jobTypeName)
        if job:
            self.loadJob(jobTypeName)

    '''任务是否存在'''

    def FindTheJob(self, jobTypeName: str):
        for job in self._jobs:
            job: BaseJob = job
            if job._typeName == jobTypeName:
                return job

    def removeJob(self, jobTypeName: str):
        job = self.FindTheJob()
        if job:
            Log.info(f"remove job {job._jobName}")
            job.Stop()
            TheScheduler.remove_job(job._jobName)
            self._jobs.remove(job)

    def loadJob(self, jobTypeName: str, *args, **kwargs):
        self.removeJob(jobTypeName)

        newJob = self.jobNames[jobTypeName](*args, **kwargs)
        self._jobs.append(newJob)
        newJob.AddJob(self.jobParams)

    def OneKeyPush(self, isTest: boolean):
        self.loadJob("OneBtnPushJob", isTest)

    def ChromRestartOver(self):
        self.RestartJobWhoExist('MeatMaskJob')
        self.RestartJobWhoExist('MetauceBotJob')
        self.RestartJobWhoExist('CandyRewardJob')
        GEventHandler.Dispatch(EventType.joblist_has_change)

    def MsgRegeist(self):

        def msgHandler(eventType: EventType, *args, **kwargs):
            if eventType == EventType.pause_all_job:
                for job in self._jobs:
                    job.Pause()
            elif eventType == EventType.resume_all_job:
                for job in self._jobs:
                    job.Resume()
            elif eventType == EventType.reload_job:
                self.loadJob()
            elif eventType == EventType.reload_chrome_over:
                self.ChromRestartOver()
            elif eventType == EventType.btn_one_key_push:
                self.OneKeyPush(False)
            elif eventType == EventType.btn_one_key_push_test:
                self.OneKeyPush(True)
            elif eventType == EventType.stop_job:
                self.removeJob(args[0])
            elif eventType == EventType.start_job_by_jobinit:
                self.StartJobByInitConfig()

        GEventHandler.RegedistEvent(EventType.pause_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.resume_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.reload_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.reload_chrome_over, msgHandler)
        GEventHandler.RegedistEvent(EventType.btn_one_key_push, msgHandler)
        GEventHandler.RegedistEvent(EventType.btn_one_key_push_test, msgHandler)
        GEventHandler.RegedistEvent(EventType.stop_job, msgHandler)