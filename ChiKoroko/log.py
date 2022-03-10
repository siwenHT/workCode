from asyncio.log import logger
import logging

streamHandler = logging.StreamHandler()
fileHandler = logging.FileHandler(filename="log/test.log", mode='w')
fileHandler1 = logging.FileHandler(filename="log/test_error.log", mode='w')

logger.setLevel(logging.DEBUG)
streamHandler.setLevel(logging.DEBUG)
fileHandler.setLevel(logging.DEBUG)
fileHandler1.setLevel(logging.INFO)

formatter = logging.Formatter("%(asctime)s %(name)s %(levelname)s %(message)s")
streamHandler.setFormatter(formatter)
fileHandler.setFormatter(formatter)
fileHandler1.setFormatter(formatter)

logger.addHandler(streamHandler)
logger.addHandler(fileHandler)
logger.addHandler(fileHandler1)