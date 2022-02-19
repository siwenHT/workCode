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
import threading

g_jobMG = None
GLock = threading.Lock()


def SetJobMG(jobMg):
    global g_jobMG
    g_jobMG = jobMg


def GetJobMG():
    return g_jobMG


def GetGlock():
    return GLock