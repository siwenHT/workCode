#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   CandyReward.py
@Time    :   2022/02/19 02:27:45
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
from Global import *
from Until.MyLog import Log
from Web.OpenUrl import OpenUrl

import os, time
import functools
from selenium import webdriver
from selenium.webdriver.remote import webelement
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common.by import By


class CandyReward(OpenUrl):

    def __init__(self, jobName=''):
        super().__init__('https://www.coingecko.com/account/candy?locale=zh', jobName)

    def clickReward(self):
        try:
            key = "//div[@class='row']/div/form"
            element = self.find_element_loop(By.XPATH, self._browser, key)
            if element:
                element.submit()
                return True
            else:
                okEl = self.find_element_loop(By.CSS_SELECTOR, self._browser, "#next-daily-reward-countdown-timer")
                if okEl:
                    self.ReportVal(val=f'已经领取过了')
                    return True
        except Exception as ex:
            pass

        return False
