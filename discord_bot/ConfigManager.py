# -*- coding: utf-8 -*-
import os,json
import toolsFunc as Tool
from runBetData import RunBetData
from thelog import Log

'''解析配置文件夹'''
class ConfigManager:

    def __init__(self, configRoot, baseJsonFile):
        self.configRoot = configRoot
        self.dataList:RunBetData = []
        self.baseJson:dict = {}
        self.baseConfig(baseJsonFile)
        self.loadConfig()

        lastChr = self.configRoot[-1]
        if lastChr != '\\' and lastChr != '/':
            self.configRoot = self.configRoot[0:-1] + "/"

    def loadConfig(self):
        fileList = Tool.ListFile(self.configRoot)

        for filePath in fileList:
            fileCon = Tool.ReadFile(filePath)
            fileCon = Tool.parse_json_str(fileCon.decode('utf-8'))
            retJson:dict = json.loads(fileCon)

            if retJson.get("enable", 0) == 1 :
                oneData = RunBetData(retJson)
                self.dataList.append(oneData) 

    def baseConfig(self, baseJsonFile):
        fileCon = Tool.ReadFile(baseJsonFile)
        fileCon = Tool.parse_json_str(fileCon.decode('utf-8'))
        self.baseJson:dict = json.loads(fileCon)

    def token(self):
        return self.baseJson.get("token", "empty")

    def showList(self):
        for data in self.dataList:
            Log.debug(f'channel: {data.getChannelName()}')
        
    def getList(self):
        return self.dataList


