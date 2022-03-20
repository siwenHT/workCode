#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   thelog.py
@Time    :   2022/02/14 23:22:07
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib

import logging
import logging.handlers


# 设置一下logging
class MyLog:

    def __init__(self) -> None:
        self.logger = logging.getLogger("logger")

        self.streamHandler = logging.StreamHandler()
        self.fileHandler = logging.FileHandler(filename="Res/log/test.log", mode='w')
        self.fileHandler1 = logging.FileHandler(filename="Res/log/test_info.log", mode='a')
        self.fileHandler2 = logging.FileHandler(filename="Res/log/test_info_detail.log", mode='a')

        self.logger.setLevel(logging.DEBUG)
        self.streamHandler.setLevel(logging.DEBUG)
        self.fileHandler.setLevel(logging.DEBUG)
        self.fileHandler1.setLevel(logging.INFO)
        self.fileHandler2.setLevel(logging.INFO)

        formatter = logging.Formatter("%(asctime)s %(levelname)s %(message)s")
        formatter2 = logging.Formatter("%(asctime)s %(filename)s[line:%(lineno)d] %(levelname)s %(message)s")

        self.streamHandler.setFormatter(formatter)
        self.fileHandler.setFormatter(formatter)
        self.fileHandler1.setFormatter(formatter)
        self.fileHandler2.setFormatter(formatter2)

        self.logger.addHandler(self.streamHandler)
        self.logger.addHandler(self.fileHandler)
        self.logger.addHandler(self.fileHandler1)
        self.logger.addHandler(self.fileHandler2)

    # def debug(self, msg, *args, **kwargs):
    #     self.logger.debug(msg, *args, **kwargs)

    # def info(self, msg, *args, **kwargs):
    #     self.logger.info(msg, *args, **kwargs)

    # def warning(self, msg, *args, **kwargs):
    #     self.logger.warning(msg, *args, **kwargs)

    # def error(self, msg, *args, **kwargs):
    #     self.logger.error(msg, *args, **kwargs)

    # def critical(self, msg, *args, **kwargs):
    #     self.logger.critical(msg, *args, **kwargs)

    # def exception(self, msg, *args, **kwargs):
    #     self.logger.exception(msg, *args, **kwargs)


TheLog = MyLog()
Log = TheLog.logger