#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BaseJob.py
@Time    :   2022/02/15 01:23:50
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib


class BaseJob():

    def __init__(self) -> None:
        self._isStop = False
        pass
    
    def pause(self):
        self._isStop = True

    def resume(self):
        self._isStop = False
        