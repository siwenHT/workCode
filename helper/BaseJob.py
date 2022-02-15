#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BaseJob.py
@Time    :   2022/02/15 01:23:50
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from Until.MyLog import Log
from Until.Scheduler import TheScheduler


class BaseJob():

    def __init__(self) -> None:
        self._isStop = False
        self._jobName = ''

    def Pause(self):
        self._isStop = True

    def Resume(self):
        self._isStop = False

    def Done(self, *args, **kwargs):
        try:
            self.DoJob(*args, **kwargs)
        except Exception as ex:
            Log.exception(f"Job:{self._jobName} error:")
            pass

    # def AddJob(self, *args, **kwargs):
    #     TheScheduler.add_job(self.Done, args=[self], *args, **kwargs)