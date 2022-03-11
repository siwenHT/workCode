#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   StepnBotJob.py
@Time    :   2022/03/11 12:44:55
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib
from DiscordBot.AutoAnswer import AutoAnswer
from Jobs.BaseJob import BaseJob
from Until.MyLog import Log


class StepnBotJob(BaseJob):

    def __init__(self):
        super().__init__()
        self.InitData()

    def InitData(self):
        self._autoAns = AutoAnswer()

    def DoJob(self):
        try:
            #拉取问题， 计算答案
            self._autoAns.GetRemoteMsg()

            #能计算出来的话，答题

            #答题能顺利完成通知邮箱答题了

            #等待3分钟拉取最近的记录, 解析答案

        except Exception as ex:
            Log.exception(f"StepnBotJob error")
            return