#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BotMsgSend.py
@Time    :   2022/02/15 01:33:21
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import BotConfig


class BotMsgSend():
    def __init__(self, botConfig: BotConfig) -> None:
        self.data = {}
        self.data.botConfig = botConfig