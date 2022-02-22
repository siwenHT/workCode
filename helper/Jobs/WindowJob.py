#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   WindowJob.py
@Time    :   2022/02/15 08:41:35
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import os, time
import datetime
from Jobs.BaseJob import BaseJob
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from UI.MainWindow import MainWindow


class WindowJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._isPause = False

    def DoJob(self, *args, **kwargs):
        self._window = MainWindow()
        self.ReportJobVal(val=f"窗口已开")
        pass

    def AddJob(self, jobParams):
        temp_date3 = datetime.datetime.now() + datetime.timedelta(seconds=1)
        Log.info(f"job: {self._jobName} is Add!")
        self._job = TheScheduler.add_job(self.Done, 'date', run_date=temp_date3, max_instances=1, id='WindowJob')
