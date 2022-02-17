#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   EventType.py
@Time    :   2022/02/15 20:13:14
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib

from enum import Enum, unique


@unique
class EventType(Enum):
    Begin = 1
    btn_base_click = 2
    bot_btn_click = 3
    reload_config = 4
    pause_all_job = 5
    resume_all_job = 5

    End = 1000