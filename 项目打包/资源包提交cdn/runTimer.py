#!python   
# -*- coding: utf-8 -*-
import time
import os
from apscheduler.schedulers.blocking import BlockingScheduler

def job():
    print("job runing ")
    # path = os.path.abspath('oneKeyPushVersion.bat')
    # print(path)
    os.system('python3 .\z_scrpit\z_beginPreparePackage.py -t game1 -p 3 --version -r')
    # os.system('python checkVersion.py 1')
    
if __name__ == '__main__':
    # BlockingScheduler：在进程中运行单个任务，调度器是唯一运行的东西
    scheduler = BlockingScheduler()
    # 采用阻塞的方式
    
    # 采用date的方式，在特定时间只执行一次
    timeStr = '2019-11-22 18:05:00'
    print timeStr,"will update!!!"
    scheduler.add_job(job, 'date', run_date=timeStr)

    scheduler.start() 
    
    os.system('pause')