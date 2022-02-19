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
    btn_base_click = 2  #点击基础tab按钮
    bot_btn_click = 3  #点击了聊天机器人tab按钮
    reload_config = 4  #重载全部配置
    pause_all_job = 5  #暂停所有任务  (目前只能暂停还未启动的,启动的任务不能控制)
    resume_all_job = 6  #恢复所有任务
    refresh_time_label = 7  #刷新时间
    reload_chrome = 8  #重启谷歌浏览器
    reload_job = 9  #重载某个任务
    refresh_job_cur_status = 10  #刷新任务当前进程
    need_reload_chrome_job = 11  #需要重启浏览器任务

    joblist_has_change = 12  #任务列表有变动

    End = 1000