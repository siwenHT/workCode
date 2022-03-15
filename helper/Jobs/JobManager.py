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
from Jobs.StepnBotDailyJob import StepnBotDailyJob
from Until.Scheduler import TheScheduler
from Until.WinSysytem import Win
from Until import ToolsFunc as TOOL
from Until.MyLog import Log

from Jobs.WindowJob import WindowJob
from Jobs.DiscordJob import DiscordJob
from Jobs.MetaMaskJob import MetaMaskJob
from Jobs.ChiKorokoJob import ChiKorokoJob
from Jobs.OneBtnPushJob import OneBtnPushJob
from Jobs.MetauceBotJob import MetauceBotJob
from Jobs.GmToChannelJob import GmToChannelJob
from Jobs.CandyRewardJob import CandyRewardJob
from Jobs.RefreshTimeLabel import RefreshTimeLabel
from Jobs.MetauceHelperJob import MetauceHelperJob
from Jobs.TwitterFellowJob import TwitterFellowJob
from Jobs.StepnBotJob import StepnBotJob
from Jobs.TwitterAutoFollowBackJob import TwitterAutoFollowBackJob


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
        self.jobNames["TwitterFellowJob"] = TwitterFellowJob
        self.jobNames["GmToChannelJob"] = GmToChannelJob
        self.jobNames["ChiKorokoJob"] = ChiKorokoJob
        self.jobNames["StepnBotJob"] = StepnBotJob
        self.jobNames["StepnBotDailyJob"] = StepnBotDailyJob
        self.jobNames["TwitterAutoFollowBackJob"] = TwitterAutoFollowBackJob

        self.jobNames["OneBtnPushJob"] = OneBtnPushJob
        self.jobNames["MetaMaskJob"] = MetaMaskJob
        self.jobNames["MetauceBotJob"] = MetauceBotJob
        self.jobNames["MetauceHelperJob"] = MetauceHelperJob

    '''加载任务参数'''

    def LoadJobConfig(self):
        try:
            filePath = os.path.join(Win.GetWorkPath(), "Res/JobConfig.json")
            self.jobParams = TOOL.initJsonFromFile(filePath)
        except Exception as ex:
            Log.exception("error")

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
        if not self._jobInitStart:
            initJobs = self.jobParams.get("initJobs")
            for jobName in initJobs:
                self.loadJob(jobName)
            self._jobInitStart = True
            GEventHandler.Dispatch(EventType.joblist_has_change)

    def RestartJobWhoExist(self, jobTypeName: str):
        job = self.FindTheJob(jobTypeName)
        if job:
            self.loadJob(jobTypeName)

    '''任务是否存在'''

    def FindTheJob(self, jobTypeName: str):
        retJob = None
        for job in self._jobs:
            job: BaseJob = job
            if job._typeName == jobTypeName:
                retJob = job
        return retJob

    def removeJob(self, jobTypeName: str):
        job = self.FindTheJob(jobTypeName)
        if job:
            Log.info(f"remove job {job._jobName}")
            job.Stop()
            TheScheduler.remove_job(job._jobName)
            self._jobs.remove(job)

    def loadJob(self, jobTypeName: str, *args, **kwargs):
        self.removeJob(jobTypeName)

        self.LoadJobConfig()
        newJob = self.jobNames[jobTypeName](*args, **kwargs)
        self._jobs.append(newJob)
        newJob.AddJob(self.jobParams)

    def OneKeyPush(self, isTest: boolean):
        self.loadJob("OneBtnPushJob", isTest)

    def ChromRestartOver(self):
        # self.RestartJobWhoExist('MetaMaskJob')
        # self.RestartJobWhoExist('MetauceBotJob')
        # self.RestartJobWhoExist('CandyRewardJob')
        # self.RestartJobWhoExist('ChiKorokoJob')

        GEventHandler.DelayDispatch(EventType.joblist_has_change)

    def CheckJobIsEnd(self, *args, **kwargs):
        jobName = kwargs.get("jobName")
        if jobName:
            job = TheScheduler.get_job(jobName)
            if not job:
                self.removeJob(jobTypeName=jobName)
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
                self.loadJob(args[0])
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
            elif eventType == EventType.job_done_end:
                self.CheckJobIsEnd(*args, **kwargs)

        GEventHandler.RegedistEvent(EventType.pause_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.resume_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.reload_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.reload_chrome_over, msgHandler)
        GEventHandler.RegedistEvent(EventType.btn_one_key_push, msgHandler)
        GEventHandler.RegedistEvent(EventType.btn_one_key_push_test, msgHandler)
        GEventHandler.RegedistEvent(EventType.stop_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.start_job_by_jobinit, msgHandler)
        GEventHandler.RegedistEvent(EventType.job_done_end, msgHandler)
