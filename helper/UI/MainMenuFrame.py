#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MainMenuFrame.py
@Time    :   2022/02/17 15:06:13
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib
from distutils import command
import tkinter as tk
from turtle import width
from Event.EventMsgHandler import EventMsgHandler, GEventHandler
from Event.EventType import EventType

from UI.BaseFrame import BaseFrame


class MainMenuFrame(BaseFrame):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)
        self.InitUI()

    def InitUI(self):
        pad = 10
        menuHeight = 100
        align_mode = 'nswe'
        self._baseBtn = self.CreateButton(text="基础", command=self.OnBaseBtnClick)
        self._botBtn = self.CreateButton(text="Bot", command=self.OnBotBtnClick)

        self._baseBtn.grid(column=0, row=0, padx=pad, pady=pad, sticky=align_mode)
        self._botBtn.grid(column=1, row=0, padx=pad, pady=pad, sticky=align_mode)

        self.DefineLayout(self, cols=2, rows=1)
        pass

    def OnBaseBtnClick(self):
        GEventHandler.Dispatch(EventType.btn_base_click)

    def OnBotBtnClick(self):
        GEventHandler.Dispatch(EventType.bot_btn_click)