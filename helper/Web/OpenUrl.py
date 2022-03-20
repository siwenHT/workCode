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
from selenium.common.exceptions import WebDriverException
from selenium.common import exceptions
from selenium.common.exceptions import NoSuchWindowException

from Web.Browser import Browser


class OpenUrl:

    def __init__(self, url: str = '', jobName: str = ''):
        self._browser = None
        self._handler = None
        self._url = url
        self._reportCallBack = None
        self._needStop = False
        self._jobName = jobName

    def resetBroser(self):
        self._browser = None
        self._handler = None

    def SetReportCallBack(self, func):
        if isfunction(func):
            self._reportCallBack = func

    def ReportVal(self, val: str):
        if self._reportCallBack:
            self._reportCallBack(val)

    def SetNeedStop(self, val):
        self._needStop = val

    def closeBrowser(self):
        try:
            if self._browser and self._handler:
                self._browser.switch_to.window(self._handler)
                if self._browser.current_window_handle == self._handler:
                    self._browser.close()

                self._browser = None
                self._handler = None
        except Exception as ex:
            pass

    '''刷新网页'''

    def refreshPage(self):
        try:
            self._browser.refresh()
        except exceptions.NoSuchWindowException as ex:
            self.resetBroser()
            raise RuntimeError(f'{self._jobName} window is lost')
        except Exception as ex:
            raise RuntimeError(f"{self._jobName} refreshPage error")

    def Back(self):
        try:
            self._browser.back()
        except exceptions.NoSuchWindowException as ex:
            self.resetBroser()
            raise RuntimeError(f'{self._jobName} window is lost')
        except Exception as ex:
            raise RuntimeError(f"{self._jobName} Back error")

    def find_element_unit(self, by: str, browser: webdriver, key: str, timeOut: int = 10, timeStep: int = 0.5):
        while True:
            retElement = self.find_element_loop(by, browser, key, timeOut, timeStep)
            if retElement:
                return retElement

    def find_elements_unit(self, by: str, browser: webdriver, key: str, num: int = 1, timeOut: int = 10, timeStep: int = 0.5):
        while True:
            retElement = self.find_elements_loop(by, browser, key, num, 10, timeOut, timeStep)
            if retElement:
                return retElement

    def find_elements_loop(self, by: str, browser: webdriver, key: str, num: int = 1, timeOut: int = 10, timeStep: int = 1):
        count = 1
        while True:
            retElements = self.find_elements(by, browser, key)
            if count > timeOut:
                Log.debug(f"not find elements {key}")
                return retElements
            elif retElements and len(retElements) > num:
                return retElements
            else:
                time.sleep(timeStep)
                count = count + timeStep

    def find_element_loop(self, by: str, browser: webdriver, key: str, timeOut: int = 10, timeStep: int = 1):
        count = 1
        while True:
            retElement = self.find_element(by, browser, key)
            if count > timeOut:
                Log.debug(f"not find element {key}")
                return retElement
            elif retElement:
                return retElement
            else:
                time.sleep(timeStep)
                count = count + timeStep

    def find_elements(self, by: str, browser: webdriver, key: str):
        retElement = None
        try:
            retElement = browser.find_elements(by, key)
        except Exception as ex:
            pass

        return retElement

    def find_element(self, by: str, browser: webdriver, key: str):
        retElement = None
        try:
            retElement = browser.find_element(by, key)
        except Exception as ex:
            pass

        return retElement

    def element_click(self, element, offsetX: int = 5, offsetY: int = 5, delay: int = 3):
        try:
            # element.click()
            # ActionChains(self._browser).move_to_element_with_offset(element, offsetX, offsetY).perform()
            self._browser.execute_script("arguments[0].click();", element)
        except Exception as ex:
            try:
                ActionChains(self._browser).move_to_element_with_offset(element, offsetX, offsetY).click(element).perform()
            except Exception as ex:
                pass

    def element_hide(self, element):
        try:
            self._browser.execute_script("arguments[0].style.display='none';", element)
        except Exception as ex:
            pass

    def openGameUrl(self, url: str = ''):
        try:
            if not self._browser:
                self._browser = Browser().GetBrowser()

            self._handler = Browser().OpenNewTab(self._browser)

            if url and url != '':
                self._url = url
            self._browser.get(self._url)

            Log.info(f"{self._jobName} open url={self._url}, is ok!")
        except NoSuchWindowException as ex1:
            Log.exception(f"{self._jobName} openGameUrl error")
            self.resetBroser()
            raise RuntimeError(f'{self._jobName} browser handler error!')
        except Exception as ex2:
            Log.exception(f"{self._jobName} openGameUrl error")
            self.resetBroser()
            raise RuntimeError(f'{self._jobName} some error!')
