#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   GmToChannelJob.py
@Time    :   2022/02/19 10:28:55
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import os, time
from Jobs.TwitterFellowJob import TwitterFellowJob
from DiscordBot.BotConfig import BotConfig
from DiscordBot.BotManager import BotManager
from DiscordBot.BotMsgSend import BotMsgSend
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Scheduler import TheScheduler
from pickle import NONE
from Until.WinSysytem import Win


class GmToChannelJob(TwitterFellowJob):

    def __init__(self) -> None:
        super().__init__()
        self._filePath = os.path.join(Win.GetWorkPath(), "Res/gm.json")