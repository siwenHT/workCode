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


class EventMsgHandler():

    def __init__(self) -> None:
        self.callBacks = {}
        pass

    def RegedistEvent(self, eventType: EventType, callBack: function, caller: object = None):
        if not self.callBacks.get(eventType, None):
            self.callBacks[eventType] = []

        callInfo = {}
        callInfo.callFunc = callBack
        callInfo.caller = caller
        self.callBacks[eventType].append(callInfo)

    def UnRegedistEvent(self, eventType: EventType, callBack: function):
        if eventType:
            eventList = self.callBacks.get(eventType, None)
            if eventList:
                eventList = [item for item in eventList if (item.callBack != callBack)]
                self.callBacks[eventType] = eventList
        else:
            for eventType, eventList in self.callBacks:
                eventList = [item for item in eventList if (item.callBack != callBack)]
                self.callBacks[eventType] = eventList

    def Dispatch(self, eventType: EventType, *args, **kwargs):
        if eventType:
            eventList = self.callBacks.get(eventType, None)
            if eventList:
                for callInfo in eventList:
                    if callInfo.caller:
                        callInfo.callFunc(callInfo.caller, *args, **kwargs)
                    else:
                        callInfo.callFunc(*args, **kwargs)
