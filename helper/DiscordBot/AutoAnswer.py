#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   AutoAnswer.py
@Time    :   2022/03/11 14:21:22
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib

from distutils.util import strtobool
import os, time, datetime, re
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until import ToolsFunc as Tool
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotPullMsg import BotPullMsg
from Until.MyLog import Log
from Until.WinSysytem import Win


class MsgInfo(object):

    def __init__(self, msg={}):
        self._isBot = False
        self._isQuestionStart = -1
        self._content = ""
        self._authorId = ""
        self._msgId = ""
        self._time = 0
        self._userName = ''
        self._stepnQuestionBotId = '927771714241310731'
        self.ParseMsg(msg)

    def ParseMsg(self, msg):
        author = msg.get('auther')
        if author:
            self._authorId = author.get('id')
            self._userName = author.get('username')
            self._isBot = (self._authorId == self._stepnQuestionBotId)
        self._msgId = msg.get('id')
        self._content = msg.get('content')
        self._time = self.TimestampToInt(msg.get('timestamp'))

        self._isQuestionStart = self.QuestionIdx()

    def QuestionStartIdx(self):
        if self._content.find("Question starts in") != -1:
            if self._content.find('30'):
                return 1
            elif self._content.find('15'):
                return 2
            elif self._content.find('10'):
                return 3
            elif self._content.find('5'):
                return 4

        return -1

    def TimestampToInt(self, strTime):
        if not strTime:
            return 0

        #2022-03-09T19:31:09.960000+00:00
        ret = re.search(r'([0-9]+)-([0-9]+)-([0-9]+)T([0-9]+):([0-9]+):([0-9]+)\.', strTime)
        if ret:
            y = ret.group(1)
            m = ret.group(2)
            d = ret.group(3)

            h = ret.group(4)
            min = ret.group(5)
            sec = ret.group(6)

            Log.debug(f"{y}-{m}-{d} {h}:{min}:{sec} == {strTime}")
            return datetime.datetime.now().replace(year=y, month=m, day=d, hour=h, minute=h, second=sec, microsecond=0).timestamp()

        return 0

    def MsgEnable(self, lTime):
        return self._time > lTime


class question(object):

    def __init__(self, msg={}):
        self._question = None
        self._choose = []
        self._answer = None
        self._done = False
        self._Time = None
        self._msgId = None

    def ParseMsg(self, msg):
        pass


class AutoAnswer(object):

    def __init__(self):
        self._channelCfg = os.path.join(Win.GetWorkPath(), "Res/BotConfig/stepn-answer.json")
        self._historyFile = os.path.join(Win.GetWorkPath(), "Res/log/stepn-history.json")
        self._tempFile = os.path.join(Win.GetWorkPath(), "Res/log/tempData.json")
        self._stepnQuestionBotId = '927771714241310731'
        self.InitCfg()
        self.MsgRegeist()

    def InitCfg(self):
        self._botConfig = BotConfig(self._channelCfg)
        self._pullBot = BotPullMsg(self._botConfig)
        self._recodeList = Tool.initJsonFromFile(self._historyFile)

    def GetRemoteMsg(self, limit=50):
        self.GetTimeLocation()
        data = self._pullBot.GetRemoteMessage(limit)
        Tool.WriteFile(self._tempFile, data.decode('utf-8'))
        jsonData = Tool.parse_json_str(data.decode('utf-8'))

    def TestGetQ(self):
        jsonData = Tool.initJsonFromFile(os.path.join(Win.GetWorkPath()))
        self.GetQuestions(jsonData)
        pass

    def TestGetA(self):
        pass

    def GetQuestions(self, jsonData):
        items = jsonData.items()

        curQ = None
        findStart = False
        for msg in items:
            tmp = MsgInfo(msg)
            if not tmp.MsgEnable():
                continue

            if tmp._isQuestionStart:
                findStart = True
                continue

            if findStart:
                if not curQ:
                    curQ = question(msg)

    def GetAnswer(self, jsonData):
        pass

    # 获取时间基准.时间要在这个时间之后才进入分析范围
    def GetTimeLocation(self):
        self._localtionTime = datetime.datetime.now().replace(minute=0, second=0, microsecond=0).timestamp()

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.reload_config:
                self.InitCfg()

        GEventHandler.RegedistEvent(EventType.reload_config, msgHandler)