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
import datetime
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler


class BaseJob():

    def __init__(self) -> None:
        self._isStop = False
        self._jobName = type(self).__name__

    def ChangeStatus(self):
        self._isStop = not self._isStop
        val = '暂停' if self._isStop else "恢复"
        Log.info(f"{self._jobName} : {val}")

    def Pause(self):
        self._isStop = True

    def Resume(self):
        self._isStop = False

    def isStop(self):
        return self._isStop

    def Done(self, *args, **kwargs):
        try:
            if self._isStop:
                return

            self.DoJob(*args, **kwargs)
        except Exception as ex:
            Log.exception(f"Job:{self._jobName} error:")
            pass

    def ReportJobVal(self, *args, **kwargs):
        Log.info(f"job:{self._jobName}, report:{kwargs}")
        GEventHandler.Dispatch(EventType.refresh_job_cur_status, jobName=self._jobName, *args, **kwargs)

    def AddJob(self, jobParams):
        theParam = jobParams.get(self._jobName)
        if theParam:
            trigger = theParam.get("trigger")

            run_date = None
            if theParam.get('time'):
                run_date = datetime.datetime.now()
                if theParam.get('time') != "now":
                    run_date = datetime.datetime.now() + datetime.timedelta(seconds=theParam.get('time'))

            param = {}
            param['trigger'] = theParam.get("trigger")
            param['max_instances'] = theParam.get("max_instances") or 1
            param['id'] = self._jobName
            if trigger == "date":
                param['run_date'] = run_date
            elif trigger == "interval":
                param['seconds'] = theParam.get("second")
            elif trigger == "cron":
                param['hour'] = theParam.get('hour')

            TheScheduler.add_job(self.Done, **param)
        else:
            Log.error(f"Not find the {self._jobName} jobParam!")