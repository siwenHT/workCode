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


class Question(object):

    def __init__(self, msg={}):
        self._question = None
        self._choose = []
        self._answer = None
        self._done = False
        self._Time = None
        self._msgId = None

    def ParseMsg(self, msg):
        self._question = msg.get('title')

        fields = msg.get('fields')
        for ans in fields:
            ans = {}
            ans

    def ParseOneAns(self):
        pass


class MsgInfo(object):

    def __init__(self, msg={}):
        self._isBot = False
        self._myQuestion = None
        self._content = ""
        self._authorId = ""
        self._msgId = ""
        self._time = 0
        self._userName = ''
        self._stepnQuestionBotId = '927771714241310731'
        self.ParseMsg(msg)

    def ParseMsg(self, msg):
        author = msg.get('author')
        if author:
            self._authorId = author.get('id')
            self._userName = author.get('username')
            self._isBot = (self._authorId == self._stepnQuestionBotId)
        self._msgId = msg.get('id')
        self._content = msg.get('content')
        self._time = self.TimestampToInt(msg.get('timestamp'))
        self.QuestionCheck()

    def QuestionCheck(self, msg):
        embeds = msg.get('embeds')
        if embeds and embeds.get('type') == 'rich':
            self._myQuestion = Question(embeds)

    def IsQuestion(self):
        return self._myQuestion != None

    def TimestampToInt(self, strTime):
        if not strTime:
            return 0

        #2022-03-09T19:31:09.960000+00:00
        ret = re.search(r'([0-9]+)-([0-9]+)-([0-9]+)T([0-9]+):([0-9]+):([0-9]+)\.([0-9]+)', strTime)
        if ret:
            y = int(ret.group(1))
            m = int(ret.group(2))
            d = int(ret.group(3))

            h = int(ret.group(4))
            min = int(ret.group(5))
            sec = int(ret.group(6))

            mic = int(ret.group(7))

            # Log.debug(f"{y}-{m}-{d} {h}:{min}:{sec} {mic} == {strTime}")
            return datetime.datetime.now().replace(year=y, month=m, day=d, hour=h, minute=h, second=sec, microsecond=mic).timestamp()

        return 0

    def MsgEnable(self, lTime):
        return True or (self._time > lTime)


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
        self._recodeList = Tool.initJsonFromFileEx(self._historyFile)

    def GetRemoteMsg(self, limit=50):
        self.GetTimeLocation()
        data = self._pullBot.GetRemoteMessage(limit)
        Tool.WriteFile(self._tempFile, data.decode('utf-8'))
        jsonData = Tool.parse_json_str(data.decode('utf-8'))

    def TestGetQ(self):
        self.GetTimeLocation()
        jsonData = Tool.initJsonFromFileEx(os.path.join(Win.GetWorkPath(), "Res/log/contentq.txt"))
        self.GetQuestions(jsonData)

    def TestGetA(self):
        pass

    def GetQuestions(self, jsonData):

        curQ = None
        findStart = False
        for msg in jsonData:
            tmp = MsgInfo(msg)
            if not tmp.MsgEnable(self._localtionTime):
                continue

            # if tmp._isQuestionStart != -1:
            #     findStart = True
            #     continue

            if tmp._isBot:
                Log.debug(f"bot: {msg}")

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