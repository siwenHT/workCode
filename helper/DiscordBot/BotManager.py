#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BotManager.py
@Time    :   2022/02/15 01:22:51
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   聊天机器人配置管理
'''

# here put the import lib
from BaseJob import BaseJob

# discord 聊天管理
class BotManager(BaseJob):

    def __init__(self) -> None:
        pass

    def LoadBaseConfig():
        pass

    def LoadBotConfigs():
        pass

    


# # 配置文件路径
# # pip freeze > requirements.txt
# def configPath():
#     return os.getcwd() + "/config"


# def main():
#     Log.warning('==========@begin')
#     CMG = configMG(configPath(), "baseConfig.json")
#     CMG.showList()

#     auto = messageAuto(CMG)
#     auto.start()
#     Log.warning('@end')