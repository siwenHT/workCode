#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   DiscordJob.py
@Time    :   2022/02/15 08:41:35
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import BaseJob

class DiscordJob(BaseJob):

    def __init__(self) -> None:
        super().__init__()
        self._jobName = 'DiscordJob'

    def doJob(self):
        pass