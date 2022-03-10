#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MainView.py
@Time    :   2022/02/14 23:22:24
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import tkinter as tk
from tkinter import ttk
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from UI.JobListFrame import JobListFrame
from UI.MainFrame import MainFrame
from UI.DiscordFrame import DiscordFrame


class MainWindow():

    def __init__(self) -> None:
        self._width = 480
        self._height = 680

        self.InitUI()
        self.baseView()
        self.MsgRegeist()
        self._window.mainloop()

    def InitUI(self):
        window = tk.Tk()
        window.title('helper')
        window.configure(bg='gray')
        window.geometry(f'{self._width}x{self._height}+100+100')

        self._window = window
        # self.NewTitle()

    def NewTitle(self):

        root = self._window

        def move_window(event):
            root.geometry('+{0}+{1}'.format(event.x_root, event.y_root))

        root.overrideredirect(True)  # turns off title bar, geometry
        root.geometry('400x100+200+200')  # set new geometry

        # make a frame for the title bar
        title_bar = tk.Frame(root, bg='white', relief='raised', bd=2)

        # put a close button on the title bar
        close_button = tk.Button(title_bar, text='X', command=root.destroy)

        # a canvas for the main area of the window
        window = tk.Canvas(root, bg='black')

        # pack the widgets
        title_bar.pack(expand=1, fill=tk.X)
        close_button.pack(side=tk.RIGHT)
        window.pack(expand=1, fill=tk.BOTH)

        # bind title bar motion to the move window function
        title_bar.bind('<B1-Motion>', move_window)

    def baseView(self):
        pad = 5
        menuHeight = 100
        bottomHeight = self._height * 2 - menuHeight - 10
        align_mode = 'nswe'

        tabControl = ttk.Notebook(self._window, width=100)  # Create Tab Control

        tab1 = ttk.Frame(tabControl)  # Create a tab
        tabControl.add(tab1, text='基础')  # Add the tab

        tab2 = ttk.Frame(tabControl)  # Add a second tab
        tabControl.add(tab2, text='Bot')  # Make second tab visible

        tab3 = ttk.Frame(tabControl)  # Add a second tab
        tabControl.add(tab3, text='jobList')  # Make second tab visible

        tabControl.pack(expand=1, fill="both")  # Pack to make visible

        # self._menuFrame = MainMenuFrame(self._window, bg='green')
        self._mainFrame = MainFrame(tab1, bg='green')
        self._mainFrame.grid(column=0, row=0)

        self._jobListFrame = JobListFrame(tab3)
        self._jobListFrame.grid(column=0, row=0)

        # self._mainFrame.InitUI()
        # self._BotFrame = DiscordFrame(self._window, width=self._width * 2, height=bottomHeight, bg='orange')

        # self._menuFrame.place(x=0, y=0, relwidth=self._width * 2, relheight=menuHeight)
        # self._BotFrame.place(x=0, y=bottomHeight, relwidth=self._width * 2, relheight=bottomHeight)
        # self._menuFrame.grid(column=0, row=0, padx=pad, pady=pad, sticky=align_mode)
        # self._BotFrame.grid(column=0, rowspan=7, row=1, padx=pad, pady=pad, sticky=align_mode)
        # self._mainFrame.grid(column=0, rowspan=1, row=2, padx=pad, pady=pad, sticky=align_mode)

        # self.DefineLayout(self._window, cols=1, rows=3)

    def DefineLayout(self, obj, cols=1, rows=1):

        def method(trg, col, row):
            for c in range(cols):
                trg.columnconfigure(c, weight=1)
            for r in range(rows):
                trg.rowconfigure(r, weight=1)

        if type(obj) == list:
            [method(trg, cols, rows) for trg in obj]
        else:
            trg = obj
            method(trg, cols, rows)

    def MsgRegeist(self):
        pass
        # def msgHandler(eventType: EventType):
        #     if eventType == EventType.btn_base_click:
        #         self._mainFrame.grid(column=0, rowspan=7, row=1)
        #         self._BotFrame.grid(column=0, rowspan=1, row=2)
        #     elif eventType == EventType.bot_btn_click:
        #         self._BotFrame.grid(column=0, rowspan=7, row=1)
        #         self._mainFrame.grid(column=0, rowspan=1, row=2)

        # GEventHandler.RegedistEvent(EventType.btn_base_click, msgHandler)
        # GEventHandler.RegedistEvent(EventType.bot_btn_click, msgHandler)
