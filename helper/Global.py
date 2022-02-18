#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   Global.py
@Time    :   2022/02/18 08:48:49
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
g_jobMG = None


def SetJobMG(jobMg):
    g_jobMG = jobMg


def GetJobMG():
    return g_jobMG
