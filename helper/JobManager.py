#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   JobManager.py
@Time    :   2022/02/15 01:26:21
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   任务管理器
'''

# here put the import lib
from Until.Scheduler import TheScheduler
from Jobs.DiscordJob import DiscordJob


class JobManager():

    def __init__(self) -> None:
        self._jobs = []
        pass

    def pause(self):
        pass

    def pasueByType(self, type):
        pass

    def start(self):
        self._jobs.append(DiscordJob())

        for job in self._jobs:
            job.AddJob()

        TheScheduler.start()
        pass
