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
import random, time
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler

id = 0


class BaseJob():

    def __init__(self):
        self._isStop = False
        self._isPause = False
        self._jobCurVal = '已构建'

        global id
        self._id = id
        id += 1
        self._typeName = type(self).__name__
        self._jobName = f"{self._typeName}[{id}]"

    def GetCurVal(self):
        return self._jobCurVal

    def ChangeStatus(self):
        self._isPause = not self._isPause
        val = '暂停' if self._isPause else "恢复"
        Log.info(f"{self._jobName} : {val}")

    def Pause(self):
        self._isPause = True

    def Resume(self):
        self._isPause = False

    def Stop(self):
        self._isStop = True

    def CheckStop(self):
        if self._isStop:
            raise RuntimeError('Job is stop')

    def CheckPause(self, inv: int = 1):
        if self._isPause:
            time.sleep(inv)

    def isPause(self):
        return self._isPause

    def Done(self, *args, **kwargs):
        try:
            if self._isPause:
                return

            self.DoJob(*args, **kwargs)
        except Exception as ex:
            Log.exception(f"Job:{self._jobName} error:")
            pass

    def JobEnd(self):
        GEventHandler.Dispatch(EventType.job_done_end, jobName=self._jobName)

    def ReportJobVal(self, *args, **kwargs):
        Log.info(f"job:{self._jobName}, report:{kwargs}")
        self._jobCurVal = kwargs.get('val', "")
        GEventHandler.Dispatch(EventType.refresh_job_cur_status, jobName=self._jobName, *args, **kwargs)

    def AddJob(self, jobParams):
        theParam = jobParams.get(self._typeName)
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
                if theParam.get("minutes"):
                    param['minute'] = theParam.get("minutes")
                else:
                    param['minute'] = random.randint(1, 59)

            TheScheduler.add_job(self.Done, **param)
            self._jobCurVal = '已加载任务'
        else:
            Log.error(f"Not find the {self._jobName} jobParam!")