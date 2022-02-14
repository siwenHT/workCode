#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   Scheduler.py
@Time    :   2022/02/15 01:11:57
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from apscheduler.schedulers.blocking import BlockingScheduler


class Scheduler(BlockingScheduler):

    def __init__(self, gconfig=..., **options):
        super().__init__(gconfig, **options)

    

TheScheduler = Scheduler()