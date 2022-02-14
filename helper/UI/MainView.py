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

class MainView():
    def __init__(self, jobManager: JobManager) -> None:
        self.data = {}
        self.data.jobManager = jobManager
        pass

    def InitUI(self):
        pass

    def baseView(self):
        pass

    def botView(self):
        pass
