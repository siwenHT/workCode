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

import datetime
import json
import os
import re
import time
from distutils.util import strtobool
from json import tool
from random import Random, randint, random

from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until import ToolsFunc as Tool
from Until.Email import GEmail
from Until.MyLog import Log
from Until.WinSysytem import Win

from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotMsgSend import BotMsgSend
from DiscordBot.BotPullMsg import BotPullMsg
from DiscordBot.MsgAndQuestions import MsgInfo, Question


class AutoAnswer(object):

    def __init__(self):
        self._getIt = False
        self._myId = '897884992129105920'
        self._switchKey = "auto_answer_getit"
        self._questionNum = 4
        self._localtionTime = None
        self._nextPullTime = 6
        self._curQuestion = []
        self._sendDiscordOpen = False
        self._channelCfg = os.path.join(Win.GetWorkPath(), "Res/BotConfig/stepn-answer.json")
        self._historyFile = os.path.join(Win.GetWorkPath(), "Res/anwser/stepn-history.json")
        self._contentFile = os.path.join(Win.GetWorkPath(), "Res/anwser/content.txt")
        self._answerFile = os.path.join(Win.GetWorkPath(), "Res/anwser/answer.txt")
        self._configFile = os.path.join(Win.GetWorkPath(), "Res/anwser/switch.json")
        self.InitCfg()
        self.MsgRegeist()

    def InitCfg(self):
        self._botConfig = BotConfig(self._channelCfg)
        self._pullBot = BotPullMsg(self._botConfig)
        self.InitHistory()
        info = Tool.initJsonFromFileEx(self._configFile)
        self._getIt = info.get(self._switchKey)

    def InitHistory(self):
        info = Tool.initJsonFromFileEx(self._historyFile)
        self._lastTime = info.get('lastTime', 0)
        self._recodeList = info.get('history', {})

    def ResetData(self):
        self._curQuestion = []

    def RepaireQ(self):
        jsonData = Tool.initJsonFromFileEx(self._contentFile)
        self.GetQuestions(jsonData, True)
        self.CalAnswer()

    def RepaireA(self):
        jsonData = Tool.initJsonFromFileEx(self._answerFile)
        ans = self.GetAnswer(jsonData, True)
        if ans:
            self.PrepareRecord(ans)

    def GetAndFilterData(self, recFile, limit=50):
        bCon = self._pullBot.GetRemoteMessage(limit)
        Tool.WriteBinFile(recFile, bCon)
        strCon = bCon.decode('utf-8')
        JsonList = json.loads(strCon)
        return JsonList

    def GetQuestionContent(self):
        count = 0
        while True:
            JsonList = self.GetAndFilterData(self._contentFile, 50)
            self.GetQuestions(JsonList)

            if count > 10:
                break
            elif not self._curQuestion or len(self._curQuestion) < self._questionNum:
                time.sleep(self._nextPullTime)
                count += 1
            else:
                break

    def GetAnswerContent(self):
        count = 0
        while True:
            JsonList = self.GetAndFilterData(self._answerFile, 80)
            ans = self.GetAnswer(JsonList)

            if count > 20:
                break
            elif not ans:
                time.sleep(10)
                count += 1
            else:
                self.PrepareRecord(ans)
                return

    def GetQuestions(self, jsonData, isRepaire=False):
        oldQuestion = self._curQuestion or []
        questions = []

        checkFirstOk = False
        for msg in jsonData:
            tmp: MsgInfo = MsgInfo(msg)
            if not checkFirstOk:
                checkFirstOk = True
                if isRepaire:
                    firstMsgTime = tmp._time
                    self._localtionTime = datetime.datetime.fromtimestamp(firstMsgTime).replace(minute=0, second=0, microsecond=0).timestamp()

                if not tmp.MsgEnable(self._localtionTime):
                    self._nextPullTime = 30
                elif tmp._startSecond:
                    beginTime = tmp._time + tmp._startSecond + 3
                    self._nextPullTime = beginTime - datetime.datetime.utcnow().timestamp()

            if not tmp.MsgEnable(self._localtionTime):
                continue

            if tmp._isBot and tmp.IsQuestion():
                questions.append(tmp._myQuestion)

            if len(questions) == self._questionNum:
                break

        def takeSecond(elem):
            return elem._time

        questions.sort(key=takeSecond)
        Log.info(f"final question:{len(questions)}")
        if len(questions) > len(oldQuestion):
            self._curQuestion = questions

            strCon = json.dumps(jsonData)
            Tool.WriteFile(self._contentFile + ".bk", strCon)

    def GetAnswer(self, jsonData, isRepaire=False):
        rightId = None
        checkFirstOk = False
        for msg in jsonData:
            tmp = MsgInfo(msg)
            if not checkFirstOk:
                checkFirstOk = True
                if isRepaire:
                    firstMsgTime = tmp._time
                    self._localtionTime = datetime.datetime.fromtimestamp(firstMsgTime).replace(minute=0, second=0, microsecond=0).timestamp()

            if not tmp.MsgEnable(self._localtionTime):
                continue

            if tmp._authorId == self._myId:
                if self._sendAnswerTime:
                    Log.info(f" server revire my answer time cost: {tmp._time - self._curQuestion[0]._time}")

            if not rightId and tmp.IsBotAnswer():
                rightId = tmp._answerRightRoleId
            elif rightId and tmp._authorId == rightId:
                if self.TheTimeTheSameDay(tmp._time, self._curQuestion[0]._time):
                    if rightId == self._myId:
                        self._lastTime = self._localtionTime
                        GEmail.SendMsg('答题成功了', "stepn答题赢了 记得去填表")

                    ans = tmp._content.strip()
                    Log.info(f"final ans:{ans},role costTime:{tmp._time - self._curQuestion[0]._time}")
                    return ans
        Log.error(f"not find the right ans")

    def PrepareRecord(self, ans):
        if not self._curQuestion:
            return

        oldNum = len(self._recodeList)
        for i in range(len(self._curQuestion or {})):
            qu = self._curQuestion[i]
            qu.SetAnswer(ans[i])
            self._recodeList[qu._question] = qu._answer

        val = {}
        val['lastTime'] = self._lastTime
        val['history'] = self._recodeList

        newNum = len(self._recodeList)
        val = json.dumps(val)
        Tool.WriteFile(self._historyFile, val)
        Log.info(f"recode change: {oldNum} => {newNum}")

    def CalAnswer(self):
        if not self._curQuestion:
            return

        result = ['C', 'C', 'C', 'C']
        findCount = 0
        count = 0
        for qu in self._curQuestion:
            qu: Question = qu
            flg = qu._answer
            if not flg:
                ans = self._recodeList.get(qu._question)
                flg = qu.GetFlg(ans)

            if flg:
                findCount += 1
                result[count] = flg
                Log.info(f"find one question {qu._question} => {qu._calRet}")
            count += 1

        if findCount > 0:
            result = "".join(result)
            if randint(1, 10) < 6:
                result = result.lower()

            curTime = datetime.datetime.utcnow().timestamp()
            Log.info(f"final CalAnswer findNum: {findCount},ans: {result}, time: {curTime - self._curQuestion[0]._time}")

            ans = self.SendSwitch(result)
            if not ans or ans == '':
                return

            if self._getIt:
                time.sleep(4)
            else:
                time.sleep(randint(8, 10))
            self._sendAnswerTime = curTime
            if self._sendDiscordOpen:
                self._botConfig.SetMessage([ans])
                BotMsgSend(self._botConfig).send()

    # 获取时间基准.时间要在这个时间之后才进入分析范围
    def GetTimeLocation(self):
        self._localtionTime = datetime.datetime.utcnow().replace(minute=0, second=0, microsecond=0).timestamp()

    def TheTimeTheSameDay(self, times1, times2):
        t1_str = time.strftime("%Y-%m-%d", time.localtime(times1))
        t2_str = time.strftime("%Y-%m-%d", time.localtime(times2))
        return t1_str == t2_str

    def SendSwitch(self, ans):
        if self._lastTime:
            return ''

        if self._getIt:
            return ans

        if not self.RightTime() or not self.RandomSend():
            return ''

        return self.RandomAns(ans)

    def RightTime(self):
        localTime = datetime.datetime.now()
        if localTime.hour > 8 and localTime.hour < 23:
            return True

    def RandomSend(self):
        num = randint(1, 10)
        if num < 4:
            return True

    def RandomAns(self, ans):
        num = randint(1, 10)
        if num < 7:
            return ans
        else:
            cfg = ['A', "b", "C", 'd']
            num = len(ans)

            ret = ''
            for i in range(num):
                ret = ret + cfg[randint(0, 3)]

            return ret

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.reload_config:
                self.InitCfg()

        GEventHandler.RegedistEvent(EventType.reload_config, msgHandler)
