import time, os
from http.client import HTTPSConnection
from sys import stderr
from json import dumps
from time import sleep
from runBetData import RunBetData
op_data = RunBetData()
header_data = {
    "content-type": "application/json",
    "user-agent": "discordapp.com",
    "authorization": op_data.get_discord_token(),
    "host": "discordapp.com",
    "referer": op_data.get_discord_link()
}


def configPath():
    return os.getcwd()+"/config"

def get_connection():
    return HTTPSConnection("discordapp.com", 443)


def send_message(conn, channel_id, message_data, message_title):
    try:
        conn.request("POST", f"/api/v6/channels/{channel_id}/messages", message_data, header_data)
        resp = conn.getresponse()

        if 199 < resp.status < 300:
            print("发送成功~~~~" + str(message_title))
            pass

        else:
            stderr.write(f"HTTP recibido {resp.status}: {resp.reason}\n")
            pass

    except Exception as ex:
        print(str(ex))


def main():
    total_count = op_data.get_discord_message_len()
    index = 0
    while True:

        try :
            message_data = {
                "content": op_data.get_discord_message_random(index),
                "tts": "false",
            }
            message_current = op_data.get_discord_message_random(index)
            index = (index + 1) % total_count
            send_message(get_connection(), op_data.get_discord_channel_id(), dumps(message_data), message_current)
            time.sleep(op_data.get_discord_time_interval())
        except Exception as ex:
            print(str(ex))



if __name__ == '__main__':
    while True:
        main()
        sleep(3600)  # every 1 hour = 3600