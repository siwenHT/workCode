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
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from UI.BaseFrame import BaseFrame
import tkinter as tk
from Until import ToolsFunc as TOOL


class MainFrame(BaseFrame):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self._isStop = False

    def InitUI(self):
        self.txt = tk.Label(self, text=f"北京时间:{TOOL.showTime()}")
        self.txt.grid(column=0, row=0, sticky=tk.W)
        btn = self.CreateButton(text="重置配置", command=self.ReloadConfig)
        btn.grid(column=0, row=1, sticky=tk.W + tk.N)
        btn = self.CreateButton(text="暂停任务", command=self.StopJob)
        btn.grid(column=1, row=1, sticky=tk.W + tk.N)
        btn = self.CreateButton(text="暂停任务", command=self.StopJob)
        btn.grid(column=1, row=1, sticky=tk.W + tk.N)
        pass

    def ReloadConfig(self):
        GEventHandler.Dispatch(EventType.reload_config)

    def StopJob(self):
        if self._isStop:
            GEventHandler.Dispatch(EventType.resume_all_job)
            self._isStop = False
        else:
            GEventHandler.Dispatch(EventType.pause_all_job)
            self._isStop = True
