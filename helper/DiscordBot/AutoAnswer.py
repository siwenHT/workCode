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
        self.ParseMsg(msg)

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
        if self._content.find('Chicken Dinner') != -1:
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


class AutoAnswer(object):

    def __init__(self):
        self._myId = '897884992129105920'
        self._questionNum = 4
        self._localtionTime = None
        self._nextPullTime = 6
        self._curQuestion = []
        self._channelCfg = os.path.join(Win.GetWorkPath(), "Res/BotConfig/stepn-answer.json")
        self._historyFile = os.path.join(Win.GetWorkPath(), "Res/log/stepn-history.json")
        self._contentFile = os.path.join(Win.GetWorkPath(), "Res/log/content.txt")
        self._answerFile = os.path.join(Win.GetWorkPath(), "Res/log/answer.txt")

        self.InitCfg()
        self.MsgRegeist()

    def InitCfg(self):
        self._botConfig = BotConfig(self._channelCfg)
        self._pullBot = BotPullMsg(self._botConfig)
        self.InitHistory()

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
                    Log.info(f" server revire my answer time cost: {tmp._time - self._sendAnswerTime}")

            if not rightId and tmp.IsBotAnswer():
                rightId = tmp._answerRightRoleId
            elif rightId and tmp._authorId == rightId:
                if self.TheTimeTheSameDay(tmp._time, self._curQuestion[0]._time):
                    if rightId == self._myId:
                        self._lastTime = self._localtionTime

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

            self._botConfig.SetMessage([result])
            curTime = datetime.datetime.utcnow().timestamp()
            Log.info(f"final CalAnswer findNum: {findCount},ans: {result}, time: {curTime - self._curQuestion[0]._time}")
            if self._lastTime:
                return result

            time.sleep(10)
            self._sendAnswerTime = curTime
            BotMsgSend(self._botConfig).send()
            return result

        return ''

    # 获取时间基准.时间要在这个时间之后才进入分析范围
    def GetTimeLocation(self):
        self._localtionTime = datetime.datetime.utcnow().replace(minute=0, second=0, microsecond=0).timestamp()

    def TheTimeTheSameDay(self, times1, times2):
        t1_str = time.strftime("%Y-%m-%d", time.localtime(times1))
        t2_str = time.strftime("%Y-%m-%d", time.localtime(times2))
        return t1_str == t2_str

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.reload_config:
                self.InitCfg()

        GEventHandler.RegedistEvent(EventType.reload_config, msgHandler)