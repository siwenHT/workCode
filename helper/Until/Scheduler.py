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

from Until.MyLog import Log


class Scheduler(BlockingScheduler):

    def __init__(self, *args, **options):
        super().__init__(*args, **options)

    def remove_job(self, job_id, jobstore=None):
        if self.get_job(job_id):
            super().remove_job(job_id, jobstore)

    def add_job(self, *args, **kwargs):
        Log.info(f"job: {kwargs['id']} is Add!")
        return super().add_job(*args, **kwargs)


TheScheduler = Scheduler(timezone='Asia/Shanghai')