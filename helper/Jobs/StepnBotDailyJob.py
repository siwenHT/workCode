#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   StepnBotDailyJob.py
@Time    :   2022/03/11 12:44:55
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib
import time
from DiscordBot.AutoAnswerDaily import AutoAnswerDaily
from DiscordBot.BotMsgSend import BotMsgSend
from Jobs.BaseJob import BaseJob
from Until.MyLog import Log


class StepnBotDailyJob(BaseJob):

    def __init__(self):
        super().__init__()
        self.InitData()
        self.count = 0

    def InitData(self):
        self._autoAns = AutoAnswerDaily()

    def DoJob(self):
        try:
            #拉取问题， 计算答案
            if not self._autoAns.Enable():
                self.ReportJobVal(val=f"时间校验未通过")
                return

            self.ReportJobVal(val=f"开始计算答案")
            self._autoAns._sendDiscordOpen = True
            self._autoAns.ResetData()
            self._autoAns.InitHistory()
            self._autoAns.GetTimeLocation()
            self._autoAns.GetQuestionContent()
            #能计算出来的话，答题能顺利完成通知邮箱答题了
            self._autoAns.CalAnswer()
            self._autoAns.GetAnswerContent()
            self.count += 1
            self.ReportJobVal(val=f"任务完成 {self.count}")
            self._autoAns._sendDiscordOpen = False
        except Exception as ex:
            Log.exception(f"StepnBotDailyJob error")
            return