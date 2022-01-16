import os
import pdb
from thelog import Log
from runBetData import RunBetData
from ConfigManager import ConfigManager as configMG
from messageAuto import messageAuto

# 配置文件路径
def configPath():
    return os.getcwd() + "/config"

def main():
    Log.warning('==========@begin')
    CMG = configMG(configPath(), "baseConfig.json")
    CMG.showList()
    
    auto = messageAuto(CMG)
    auto.start()
    Log.warning('@end')

    # total_count = op_data.get_discord_message_len()
    # index = 0
    # while True:

    #     try :
    #         message_data = {
    #             "content": op_data.get_discord_message_random(index),
    #             "tts": "false",
    #         }
    #         message_current = op_data.get_discord_message_random(index)
    #         index = (index + 1) % total_count
    #         send_message(get_connection(), op_data.get_discord_channel_id(), dumps(message_data), message_current)
    #         time.sleep(op_data.get_discord_time_interval())
    #     except Exception as ex:
    #         print(str(ex))

if __name__ == '__main__':
    main()