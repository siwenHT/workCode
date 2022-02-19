#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   OneBtnPushJob.py
@Time    :   2022/02/19 15:24:52
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from time import time
from BaseJob import BaseJob
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotManager import BotManager
from DiscordBot.BotMsgSend import BotMsgSend
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from pickle import NONE


class OneBtnPushJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        pass

    def AddJob(self):
        pass
