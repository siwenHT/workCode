# -*- coding: utf-8 -*-
import logging
import logging.handlers


# 设置一下logging
class singleLog:

    def __init__(self) -> None:
        self.logger = logging.getLogger("logger")

        self.streamHandler = logging.StreamHandler()
        self.fileHandler = logging.FileHandler(filename="test.log", mode='w')

        self.logger.setLevel(logging.DEBUG)
        self.streamHandler.setLevel(logging.DEBUG)
        self.fileHandler.setLevel(logging.DEBUG)

        formatter = logging.Formatter("%(asctime)s %(name)s %(levelname)s %(message)s")
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


Log = singleLog()