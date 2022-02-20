#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   main.py
@Time    :   2022/02/14 23:17:25
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import os
from Until import ToolsFunc as TOOL
from Until.MyLog import Log
from UI.MainWindow import MainWindow
from Until.Scheduler import TheScheduler
from Until.WinSysytem import Win
from Jobs.JobManager import JobManager
from Global import *


def main():
    TOOL.showParams()

    # key = ""
    # retList = Win.SimpEnc(key)
    # print(retList)
    # retStr = Win.DiscordToken()
    # if retStr == key:
    #     a = 1

    Win.ReloadBrower()
    #加载所有配置任务
    JobMG = JobManager()
    SetJobMG(JobMG)
    JobMG.start()


if __name__ == "__main__":
    main()
