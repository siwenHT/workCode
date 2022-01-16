# -*- coding: utf-8 -*-
import os,json

op_data_path_discord = os.getcwd()+"/discord_message.json"

class RunBetData:

    def __init__(self, configPath):
        self.config = self._get_json_data_discord(configPath)

    def _get_json_data_discord(self, configPath):
        '''读取json文件'''
        tmp_json = {}
        with open(op_data_path_discord, 'r', encoding='UTF-8') as f:
            tmp_json = json.load(f)
            f.close()
        return tmp_json

    def get_discord_message_random(self, index):
        data_json = self._get_json_data_discord()
        message_array =  data_json["bot"]
        return message_array[index]["message"]

    def get_discord_link(self):
        data_json = self._get_json_data_discord()
        message_array =  data_json["config"]
        return message_array["discord_link"]

    def get_discord_token(self):
        data_json = self._get_json_data_discord()
        message_array =  data_json["config"]
        return message_array["token"]

    def get_discord_channel_id(self):
        data_json = self._get_json_data_discord()
        message_array =  data_json["config"]
        return message_array["channel_id"]

    def get_discord_message_len(self):
        data_json = self._get_json_data_discord()
        message_array = data_json["bot"]
        return len(message_array)

    def get_discord_time_interval(self):
        data_json = self._get_json_data_discord()
        message_array = data_json["config"]
        return message_array["time_interval"]
