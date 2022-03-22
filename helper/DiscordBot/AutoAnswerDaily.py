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
import json
from json import tool
import os, time, datetime, re
from random import randint, random

import pytz
from DiscordBot.AutoAnswer import AutoAnswer
from DiscordBot.BotMsgSend import BotMsgSend
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until import ToolsFunc as Tool
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotPullMsg import BotPullMsg
from Until.Email import GEmail
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from Until.WinSysytem import Win
from DiscordBot.MsgAndQuestions import MsgInfo, Question


class AutoAnswerDaily(AutoAnswer):

    def __init__(self):
        super().__init__()
        self._className = 'AutoAnswerDaily'
        self._questionNum = 10
        self._curAnswer = {}
        self._switchKey = "auto_answer_daily_getit"
        self._channelCfg = os.path.join(Win.GetWorkPath(), "Res/BotConfig/stepn-answer-daily.json")
        self._historyFile = os.path.join(Win.GetWorkPath(), "Res/anwser/stepn-history.json")
        self._contentFile = os.path.join(Win.GetWorkPath(), "Res/anwser/content_daily.txt")
        self._answerFile = os.path.join(Win.GetWorkPath(), "Res/anwser/answer_daily.txt")

        self.InitCfg()
        self.MsgRegeist()

    def ResetData(self):
        self._curQuestion = []
        self._curAnswer = {}

    # def RepaireQ(self):
    #     jsonData = Tool.initJsonFromFileEx(self._contentFile)
    #     self.GetQuestions(jsonData, True)
    #     self.CalAnswer()

    def RepaireA(self):
        jsonData = Tool.initJsonFromFileEx(self._answerFile + ".allbk")
        ans = self.GetAnswer(jsonData, True)
        if ans and ans != 'Over':
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
            JsonList = self.GetAndFilterData(self._answerFile, 10)
            ans = self.GetAnswer(JsonList)

            if count > 30:
                break
            elif not ans:
                if len(self._curAnswer) < 20:
                    time.sleep(0.8)
                else:
                    time.sleep(30)
                count += 1
            else:
                time.sleep(5 * 60)
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
                    self._nextPullTime = 15
                elif tmp._startSecond:
                    beginTime = tmp._time + tmp._startSecond + 4
                    self._nextPullTime = beginTime - datetime.datetime.utcnow().timestamp()

            if not tmp.MsgEnable(self._localtionTime):
                continue

            if tmp._isBot and tmp.IsQuestion():
                questions.append(tmp._myQuestion)
                self._nextPullTime = 0.8

            if len(questions) == self._questionNum:
                break

        def takeSecond(elem):
            return elem._time

        questions.sort(key=takeSecond)
        Log.info(f"{self._className} final question:{len(questions)}")
        if len(questions) > len(oldQuestion):
            self._curQuestion = questions

            strCon = json.dumps(jsonData)
            Tool.WriteFile(self._contentFile + "daily.bk", strCon)

    def GetAnswer(self, jsonData, isRepaire=False):
        rightId = None
        checkFirstOk = False
        # 先将所有的答案都存一下，因为答案会被删除掉
        for msg in jsonData:
            tmp = MsgInfo(msg)
            if not checkFirstOk and not self._localtionTime:
                checkFirstOk = True
                if isRepaire:
                    firstMsgTime = tmp._time
                    self._localtionTime = datetime.datetime.fromtimestamp(firstMsgTime).replace(minute=0, second=0, microsecond=0).timestamp()

            if not tmp.MsgEnable(self._localtionTime):
                continue

            if tmp._authorId == self._myId:
                if self._sendAnswerTime:
                    Log.info(f"{self._className} server revire my answer time cost: {tmp._time - self._curQuestion[0]._time}")

            if not rightId and tmp.IsBotAnswer():
                rightId = tmp._answerRightRoleId

            if not tmp._isBot:
                self._curAnswer[tmp._msgId] = tmp

        #如果bot标记了中奖者,在所有答案中查找中奖者的发言。可能会找不到
        if rightId:
            try:
                ret = []
                for msg in self._curAnswer.values():
                    ret.append(msg.getRecode())
                Tool.WriteFile(self._answerFile + '.allbk', json.dumps(ret))
            except Exception as ex:
                pass

            for msg in self._curAnswer:
                if not tmp.MsgEnable(self._localtionTime):
                    continue

                if rightId == tmp._authorId:
                    if rightId == self._myId:
                        GEmail.SendMsg("SETPN 答题领NFT 赢了", "一定要记得填表")

                    ans = tmp._content.strip()
                    Log.info(f"{self._className} final ans:{ans},role costTime:{tmp._time - self._curQuestion[0]._time}")
                    return ans

            Log.error(f"not find the right ans")
            return 'Over'

        Log.error(f"not find the right ans")

    def CalAnswer(self):
        if not self._curQuestion:
            return

        result = ['C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C', 'C']
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

            delayTime = randint(15, 20)
            if self._getIt:
                delayTime = 4

            def callBack(self):
                self._sendAnswerTime = curTime
                if self._sendDiscordOpen:
                    self._botConfig.SetMessage([ans])
                    BotMsgSend(self._botConfig).send()

            TheScheduler.delay_call(callBack, delayTime, self)

    def Enable(self):
        tz = pytz.timezone('Australia/Sydney')
        syDneyTime = datetime.datetime.now(tz)
        weekDay = syDneyTime.weekday()
        cfg = {'0': 3, '1': 6, '2': 9, '3': 12, '4': 15, '5': 18, "6": 21}
        hour = cfg[str(weekDay)]
        if syDneyTime.hour == hour:
            return True

        return False

    def SendSwitch(self, ans):
        if self._getIt:
            return ans

        return self.RandomAns(ans)

    def RandomAns(self, ans):
        cfg = ['A', "b", "C", 'd']
        num = len(ans)

        ret = ''
        for i in range(num):
            ret = ret + cfg[randint(0, 3)]

        return ret