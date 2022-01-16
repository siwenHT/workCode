# -*- coding: utf-8 -*-
import os,json
import toolsFunc as Tool
import runBetData as Data

from discord_bot.runBetData import RunBetData

'''解析配置文件夹'''
class parseConfigPath:

    def __init__(self, configRoot):
        self.configRoot = configRoot
        self.dataList = []
        self.loadConfig()

        lastChr = self.configRoot[-1]
        if lastChr != '\\' and lastChr != '/':
            self.configRoot = self.configRoot[0:-1] + "/"

    def loadConfig(self):
        fileList = Tool.ListFile(self.configRoot)

        for filePath in fileList:
            fileCon = Tool.ReadFile(filePath)
            fileCon = Tool.parse_json_str(fileCon.decode('utf-8'))
            retJson = json.loads(fileCon)

            if retJson["enable"] :
                oneData = RunBetData(retJson)
                self.dataList.append(oneData) 

        


