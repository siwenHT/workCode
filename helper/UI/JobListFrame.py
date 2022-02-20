#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   JobListFrame.py
@Time    :   2022/02/18 08:45:39
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib

from re import I
import string
import threading
from turtle import bgcolor
from Jobs.BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from UI.BaseFrame import BaseFrame
import Global
import tkinter as tk


class JobListFrame(BaseFrame):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self.Lock = threading.Lock()
        self.frame = None
        self._isRefreshIng = False

        self.InitUI()
        self.RefreshJobs()
        self.MsgRegeist()

    def InitUI(self):
        self._row = 0
        self.refreshBtn = self.CreateButton(text="刷新任务", command=self.RefreshJobs)
        self.refreshBtn.grid(column=0, row=self._row, sticky=tk.W + tk.N, pady=5)

    def RefreshJobs(self):
        self.Lock.acquire()
        self._isRefreshIng = True
        if self.frame:
            self.frame.destroy()
        self.Lock.release()

        self.frame = tk.Listbox(self, bg='green')
        self.frame.grid(column=0, row=1, pady=10)
        jobMG = Global.GetJobMG()
        self._joblist = jobMG.GetAllJobList()

        row = 0
        count = 0
        jobFrame = self.frame
        self.tkMiscs = {}
        for item in self._joblist:
            item: BaseJob = item
            col = 0

            statuBtn = tk.Button(jobFrame)
            statuBtn.config(text=("恢复" if item.isPause() else "暂停"), bg=('green' if item.isPause() else 'yellow'))
            statuBtn.config(command=lambda idx=count, curBtn=statuBtn: self.StatuBtn(idx, curBtn))
            statuBtn.grid(column=col, row=row, sticky=tk.W, padx=5, pady=5)
            col += 1

            btn = tk.Button(jobFrame, text='重载')
            btn.grid(column=col, row=row, sticky=tk.W, padx=5, pady=5)
            col += 1

            nameLab = tk.Label(jobFrame, text=item._jobName)
            nameLab.grid(column=col, row=row, sticky=tk.W, padx=5, pady=5)
            col += 1

            statuLab = tk.Label(jobFrame, text='运行状况...')
            statuLab.grid(column=col, row=row, sticky=tk.W, padx=5, pady=5)
            col += 1
            row += 1
            count += 1

            oneMiscs = {}
            oneMiscs["statuBtn"] = statuBtn
            oneMiscs["statuLab"] = statuLab
            oneMiscs["job"] = item
            self.tkMiscs[item._jobName] = oneMiscs

        self._isRefreshIng = False

    def GetIsRefreshIng(self):
        self.Lock.acquire()
        flg = self._isRefreshIng
        self.Lock.release()
        return flg

    def StatuBtn(self, count, statuBtn: tk.Button):
        if self.GetIsRefreshIng():
            return

        try:
            job = self._joblist[count]
            job.ChangeStatus()
            statuBtn.config(text=("恢复" if job.isPause() else "暂停"), bg=('green' if job.isPause() else 'yellow'))
        except Exception as ex:
            pass

    def ResfreshStatusLab(self, jobName="", val=""):
        if self.GetIsRefreshIng():
            return

        try:
            oneMiscs = self.tkMiscs.get(jobName)
            if oneMiscs and oneMiscs['statuLab']:
                oneMiscs['statuLab'].config(text=str(val))
        except Exception as ex:
            pass

    def ResfreshJobStop(self):
        if self.GetIsRefreshIng():
            return
        try:
            for oneMiscs in self.tkMiscs.values():
                job = oneMiscs["job"]
                oneMiscs["statuBtn"].config(text=("恢复" if job.isPause() else "暂停"), bg=('green' if job.isPause() else 'yellow'))
        except Exception as ex:
            pass

    def MsgRegeist(self):

        def msgHandler(eventType: EventType, *args, **kwargs):
            if eventType == EventType.refresh_job_cur_status:
                self.ResfreshStatusLab(*args, **kwargs)
            elif eventType == EventType.pause_all_job or eventType == EventType.resume_all_job:
                self.ResfreshJobStop()
            elif eventType == EventType.joblist_has_change:
                self.RefreshJobs()

        GEventHandler.RegedistEvent(EventType.refresh_job_cur_status, msgHandler)
        GEventHandler.RegedistEvent(EventType.pause_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.resume_all_job, msgHandler)
        GEventHandler.RegedistEvent(EventType.joblist_has_change, msgHandler)
