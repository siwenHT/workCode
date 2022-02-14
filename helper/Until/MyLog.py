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
        self.fileHandler = logging.FileHandler(filename="test.log", mode='a')

        self.logger.setLevel(logging.DEBUG)
        self.streamHandler.setLevel(logging.DEBUG)
        self.fileHandler.setLevel(logging.DEBUG)

        formatter = logging.Formatter(
            "%(asctime)s %(name)s %(levelname)s %(message)s")
        self.streamHandler.setFormatter(formatter)
        self.fileHandler.setFormatter(formatter)

        self.logger.addHandler(self.streamHandler)
        self.logger.addHandler(self.fileHandler)

    def debug(self, msg, *args, **kwargs):
        self.logger.debug(msg, *args, **kwargs)

    def info(self, msg, *args, **kwargs):
        self.logger.info(msg, *args, **kwargs)

    def warning(self, msg, *args, **kwargs):
        self.logger.warning(msg, *args, **kwargs)

    def error(self, msg, *args, **kwargs):
        self.logger.error(msg, *args, **kwargs)

    def critical(self, msg, *args, **kwargs):
        self.logger.critical(msg, *args, **kwargs)

    def exception(self, msg, *args, **kwargs):
        self.logger.exception(msg, *args, **kwargs)


Log = MyLog()