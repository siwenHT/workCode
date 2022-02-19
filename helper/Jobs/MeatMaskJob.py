#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MeatMaskJob.py
@Time    :   2022/02/19 16:50:58
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import datetime
from time import time
from BaseJob import BaseJob
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Web.MeatMaskHelper import MeatMaskHelper


class MeatMaskJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()

    def DoJob(self, *args, **kwargs):
        web = MeatMaskHelper()
        web.ConfirmChangeNet()
        web.ConfirmTransaction()
