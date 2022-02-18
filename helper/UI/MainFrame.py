#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MainFrame.py
@Time    :   2022/02/17 15:12:32
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib
from distutils import command
from turtle import color
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from UI.BaseFrame import BaseFrame
import tkinter as tk
from Until import ToolsFunc as TOOL
from Until.Scheduler import TheScheduler


class MainFrame(BaseFrame):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self._isStop = False

        self.InitUI()
        self.MsgRegeist()

    def InitUI(self):
        row = 0
        self._baijinTime = tk.Label(self, text=f"北京时间:{TOOL.showTime()}")
        self._baijinTime.grid(column=0, row=row, sticky=tk.W)

        row += 1
        self._utcTime = tk.Label(self, text=f"UTC时间:{TOOL.UtcTime()}")
        self._utcTime.grid(column=0, row=row, sticky=tk.W)

        row += 1
        btn = self.CreateButton(text="重置配置", command=self.ReloadConfig)
        btn.grid(column=0, row=row, sticky=tk.W + tk.N)

        self._ctrlJob = self.CreateButton(text="暂停任务", command=self.CtrlJob, bg='green')
        self._ctrlJob.grid(column=1, row=row, sticky=tk.W + tk.N)

    def RefreshTimeLabel(self):
        self._baijinTime.config(text=f"北京时间:{TOOL.showTime()}")
        self._utcTime.config(text=f"UTC时间:{TOOL.UtcTime()}")

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.refrest_time_label:
                self.RefreshTimeLabel()

        GEventHandler.RegedistEvent(EventType.refrest_time_label, msgHandler)

    def ReloadConfig(self):
        GEventHandler.Dispatch(EventType.reload_config)

    def CtrlJob(self):
        if self._isStop:
            GEventHandler.Dispatch(EventType.resume_all_job)
            self._isStop = False
            self._ctrlJob.config(text="暂停任务", bg='green')
        else:
            GEventHandler.Dispatch(EventType.pause_all_job)
            self._isStop = True
            self._ctrlJob.config(text="继续任务", bg='yellow')
