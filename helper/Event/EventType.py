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

    End = 1000