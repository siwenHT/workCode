#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   OpenUrl.py
@Time    :   2022/02/19 02:06:27
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from multiprocessing import Event
import os, time
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Global import *
from Until.MyLog import Log
from inspect import isfunction
from selenium import webdriver
from selenium.webdriver.remote import webelement
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.service import Service
from Web.OpenUrl import OpenUrl


class TwitterLimite():

    def __init__(self):
        pass


class TwitterHandler(OpenUrl):

    def __init__(self, url: str = ''):
        super().__init__(url)
        self.minuteLimmite = 11
