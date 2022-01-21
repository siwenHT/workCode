import os
import pdb
from thelog import Log
from runBetData import RunBetData
from ConfigManager import ConfigManager as configMG
from messageAuto import messageAuto


# 配置文件路径
# pip freeze > requirements.txt
def configPath():
    return os.getcwd() + "/config"


def main():
    Log.warning('==========@begin')
    CMG = configMG(configPath(), "baseConfig.json")
    CMG.showList()

    auto = messageAuto(CMG)
    auto.start()
    Log.warning('@end')


if __name__ == '__main__':
    main()