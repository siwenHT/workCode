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
from UI.MainView import MainView
from Until.Scheduler import TheScheduler
import JobManager

def main():
    TOOL.showParams()

    #加载所有配置任务
    JobMG = JobManager()

    #加载界面
    thisView = MainView(JobMG)

    TheScheduler.start()

if __name__ == "__main__":
    main()
