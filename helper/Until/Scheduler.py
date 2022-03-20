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
import datetime
from Until.MyLog import Log
from apscheduler.schedulers.blocking import BlockingScheduler


class Scheduler(BlockingScheduler):

    def __init__(self, *args, **options):
        self._delayCount = 0
        super().__init__(*args, **options)

    def remove_job(self, job_id, jobstore=None):
        if self.get_job(job_id):
            super().remove_job(job_id, jobstore)

    def add_job(self, *args, **kwargs):
        id = kwargs.get('id')
        if id and id.find('dealy_call_') == -1:
            Log.info(f"job: {id} is Add!")
        return super().add_job(*args, **kwargs)

    def delay_call(self, callBack, second, *args, **kwargs):

        def call():
            callBack(*args, **kwargs)

        id = f'dealy_call_{self._delayCount}'
        self._delayCount = self._delayCount + 1
        run_date = datetime.datetime.now() + datetime.timedelta(seconds=second)
        self.add_job(call, trigger="date", run_date=run_date, id=id)
        return id

    def delay_call_loop(self, callBack, second, *args, **kwargs):

        def call():
            callBack(*args, **kwargs)

        id = f'dealy_call_{self._delayCount}'
        self._delayCount = self._delayCount + 1
        self.add_job(call, trigger="interval", seconds=second, id=id)
        return id

    def stop_delay_call(self, id):
        if self.get_job(id):
            self.remove_job(id)

    def test_callBack(self):

        def delay_call(param1=None, param2=None):
            Log.debug(f'test_callBack delay_call call {param1} {param2}')

        self.delay_call(delay_call, 5, 'param1', 'param2')

        count = 1
        loopId = None

        def delay_call_loop(param1=None, param2=None):
            nonlocal count
            Log.debug(f'test_callBack delay_call_loop call {param1} {param2}')
            count = count + 1

            if count > 5:
                self.stop_delay_call(loopId)

        loopId = self.delay_call_loop(delay_call_loop, 3, 'param1', 'param2')


TheScheduler = Scheduler(timezone='Asia/Shanghai')