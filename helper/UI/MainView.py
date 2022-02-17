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
import JobManager
import tkinter as tk


class MainView():

    def __init__(self, jobManager: JobManager) -> None:
        self._jobManager: JobManager = jobManager

        self.InitUI()

    def InitUI(self):
        window = tk.Tk()
        window.title('helper')
        window.geometry('600x800')
        window.mainloop()

        self._window = window

    def baseView(self):
        tk.Frame(self._window,)
        pass

    def botView(self):
        pass
