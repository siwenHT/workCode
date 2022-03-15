#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MsgAndQuestions.py
@Time    :   2022/03/16 00:40:47
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from distutils.util import strtobool
import json
from json import tool
import os, time, datetime, re
from random import randint, random
from DiscordBot.BotMsgSend import BotMsgSend
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until import ToolsFunc as Tool
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotPullMsg import BotPullMsg
from Until.MyLog import Log
from Until.WinSysytem import Win


class Question(object):

    def __init__(self, msg={}, time=0):
        self._question = None
        self._chooses = []
        self._answer = None
        self._done = False
        self._time = time
        self._msgId = None
        self._calRet = 0

        self.ParseMsg(msg)

    def __str__(self):
        ret = f"{self._time} {self._question} "
        for ans in self._chooses:
            ret += f"{ans['con']}"

        return ret

    def ParseMsg(self, msg):
        self._question = msg.get('title').strip()

        fields = msg.get('fields')
        for oneAns in fields:
            name = oneAns.get("name")
            ret = re.match(r'\s*([a-zA-Z])\s*\.(.*)', name)
            if ret:
                ans = {}
                ans['flg'] = ret.group(1)
                ans['con'] = ret.group(2).strip()
                ans['idx'] = self.FlgToIdx(ret.group(1))
                self._chooses.append(ans)
            else:
                Log.error(f"name ani error")
        self.IsCalNum(self._question)

        def takeSecond(elem):
            return elem['idx']

        self._chooses.sort(key=takeSecond)
        # Log.debug(self._chooses)

    def FlgToIdx(self, flg):
        cfg = {'a': 1, 'A': 1, 'b': 2, 'B': 2, 'c': 3, 'C': 3, 'd': 4, 'D': 4, 'e': 5, 'E': 5, 'f': 6, 'F': 6}
        return cfg[flg]

    def IsCalNum(self, question):
        totalStr = question.replace(' ', '')
        ret = re.match(r'([0-9\+\-\*\/\%]+)=\?', totalStr)
        if ret:
            self._calRet = eval(ret.group(1))
            self.GetFlg(self._calRet)
            Log.debug(f"question:{self._question} = {self._calRet}  {self._answer}")

    def GetFlg(self, ans):
        self._calRet = ans
        for choose in self._chooses:
            if choose['con'] == str(ans):
                self._answer = choose['flg']
                return self._answer

    def SetAnswer(self, flg):
        self._answer = self._chooses[self.FlgToIdx(flg) - 1]['con']


class MsgInfo(object):

    def __init__(self, msg={}):
        self._isBot = False
        self._myQuestion = None
        self._answerRightRoleId = None
        self._content = ""
        self._authorId = ""
        self._startSecond = 0
        self._msgId = ""
        self._time = 0
        self._userName = ''
        self._ogreData = msg
        self.ParseMsg(msg)

    def __str__(self):
        return str(self._ogreData)

    def ParseMsg(self, msg):
        author = msg.get('author')
        if author:
            self._authorId = author.get('id')
            self._userName = author.get('username')
            self._isBot = author.get('bot')
        self._msgId = msg.get('id')
        self._content = msg.get('content')
        self._time = self.TimestampToInt(msg.get('timestamp'))
        self.QuestionCheck(msg)
        self.AnswerCheck()
        self.QuestionStartCheck()

    def QuestionStartCheck(self):
        if self._content.find('Question starts in') > -1:
            ret = re.search(r'Question starts in ([0-9]+) seconds', self._content)
            if ret:
                self._startSecond = int(ret.group(1))

    def QuestionCheck(self, msg):
        embeds = msg.get('embeds')
        if embeds and embeds[0].get('type') == 'rich' and embeds[0].get('title'):
            self._myQuestion = Question(embeds[0], self._time)

    def IsQuestion(self):
        return self._myQuestion != None

    def AnswerCheck(self):
        if self._content.find('Chicken Dinner') != -1 or self._content.find('Master of Day') != -1:
            ret = re.search(r'<@([0-9]+)> for', self._content)
            if ret:
                self._answerRightRoleId = ret.group(1)

    def IsBotAnswer(self):
        return self._answerRightRoleId != None

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
            return datetime.datetime.now().replace(year=y, month=m, day=d, hour=h, minute=min, second=sec, microsecond=mic).timestamp()

        return 0

    def MsgEnable(self, lTime):
        return (self._time > lTime)