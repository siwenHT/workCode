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
from xmlrpc.client import boolean
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from UI.BaseFrame import BaseFrame
import tkinter as tk
from Until import ToolsFunc as TOOL
from Until.Scheduler import TheScheduler


class MainFrame(BaseFrame):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self._isPause = True

        self.InitUI()
        self.MsgRegeist()

    def InitUI(self):
        frame1 = tk.Frame(self)
        self._baijinTime = tk.Label(frame1, text=f"北京时间:{TOOL.showTime()}")
        self._baijinTime.grid(column=0, row=0, sticky=tk.W, pady=3)
        self._utcTime = tk.Label(frame1, text=f"UTC时间:{TOOL.UtcTime()}")
        self._utcTime.grid(column=0, row=1, sticky=tk.W, pady=3)

        frame1.grid(column=0, row=0)

        frame2 = tk.Frame(self)
        btn = tk.Button(frame2, text="重置配置", command=self.ReloadConfig)
        btn.grid(column=0, row=0, sticky=tk.W, padx=5)
        btn = tk.Button(frame2, text="重启浏览器", command=self.ResetBrower)
        btn.grid(column=1, row=0, sticky=tk.W, padx=5)
        self._ctrlJob = tk.Button(frame2, text="暂停任务", command=self.CtrlJob, bg='green')
        self._ctrlJob.grid(column=2, row=0, sticky=tk.W, padx=5)
        btn = tk.Button(frame2, text="推送测试", command=lambda: self.OneKeyPush(True))
        btn.grid(column=0, row=1, sticky=tk.W, padx=5)
        btn = tk.Button(frame2, text="正式推送", command=lambda: self.OneKeyPush(False))
        btn.grid(column=1, row=1, sticky=tk.W, padx=5)
        frame2.grid(column=0, row=1, sticky=tk.W)

    def RefreshTimeLabel(self):
        self._baijinTime.config(text=f"北京时间:{TOOL.showTime()}")
        self._utcTime.config(text=f"UTC时间:{TOOL.UtcTime()}")

    def ReloadConfig(self):
        GEventHandler.Dispatch(EventType.reload_config)

    def ResetBrower(self):
        GEventHandler.Dispatch(EventType.reload_chrome)

    def CtrlJob(self):
        if self._isPause:
            GEventHandler.Dispatch(EventType.resume_all_job)
            self._isPause = False
            self._ctrlJob.config(text="暂停任务", bg='green')
        else:
            GEventHandler.Dispatch(EventType.pause_all_job)
            self._isPause = True
            self._ctrlJob.config(text="继续任务", bg='yellow')

    def OneKeyPush(self, istest: boolean):
        GEventHandler.Dispatch(EventType.btn_one_key_push_test if istest else EventType.btn_one_key_push)

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.refresh_time_label:
                self.RefreshTimeLabel()

        GEventHandler.RegedistEvent(EventType.refresh_time_label, msgHandler)
