#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   EventMsgHandler.py
@Time    :   2022/02/15 20:14:04
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   消息管理器
'''

# here put the import lib

from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler


class EventMsgHandler():

    def __init__(self):
        self.callBacks = {}
        self.delayCall = []
        TheScheduler.add_job(self._dealy_call, trigger="interval", seconds=0.1, id='EventMsgHandler')

    def _dealy_call(self):
        for item in self.delayCall:
            self.Dispatch(item["eventType"], *item["args"], **item["kwargs"])

    def RegedistEvent(self, eventType: EventType, callBack, caller: object = None):
        if not self.callBacks.get(eventType, None):
            self.callBacks[eventType] = []

        callInfo = {}
        callInfo["callFunc"] = callBack
        callInfo["caller"] = caller
        self.callBacks[eventType].append(callInfo)

    def UnRegedistEvent(self, eventType: EventType, callBack):
        if eventType:
            eventList = self.callBacks.get(eventType, None)
            if eventList:
                eventList = [item for item in eventList if (item.get("callFunc") != callBack)]
                self.callBacks[eventType] = eventList
        else:
            for eventType, eventList in self.callBacks:
                eventList = [item for item in eventList if (item.get("callFunc") != callBack)]
                self.callBacks[eventType] = eventList

    def Dispatch(self, eventType: EventType, *args, **kwargs):
        try:
            if eventType:
                eventList = self.callBacks.get(eventType, None)
                if eventList:
                    for callInfo in eventList:
                        if callInfo.get("caller"):
                            callInfo.get("callFunc")(eventType, callInfo.get("caller"), *args, **kwargs)
                        else:
                            callInfo.get("callFunc")(eventType, *args, **kwargs)
        except Exception as ex:
            Log.exception("Dispatch error:")

    def DelayDispatch(self, eventType: EventType, *args, **kwargs):
        item = {}
        item["eventType"] = eventType
        item["args"] = args
        item["kwargs"] = kwargs
        self.delayCall.append(item)


GEventHandler = EventMsgHandler()
