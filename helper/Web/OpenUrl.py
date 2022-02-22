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


class OpenUrl:

    def __init__(self, url: str):
        self._browser = None
        self._handler = None
        self._url = url
        self._reportCallBack = None
        self._needStop = False

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
                self._browser.close()
                self._browser = None
                self._handler = None
        except Exception as ex:
            pass

    '''打开新标签'''

    def open_new_tab(self, browser: webdriver):
        oldHandles = browser.window_handles

        browser.execute_script("window.open('');")
        newhandles = browser.window_handles

        for newOne in newhandles:
            if newOne not in oldHandles:
                self._handler = newOne
                break
        browser.switch_to.window(self._handler)

    '''刷新网页'''

    def refreshPage(self):
        self._browser.refresh()

    def get_debug_chrome_opetions(self):
        options = webdriver.ChromeOptions()
        options.add_experimental_option("debuggerAddress", "127.0.0.1:9527")
        options.add_argument('blink-settings=imagesEnabled=false')  # 不加载图片, 提升速度
        options.add_argument('--headless')
        return options

    def get_chrome_options(self):
        options = webdriver.ChromeOptions()
        prefs = {}

        # 设置这两个参数就可以避免密码提示框的弹出
        prefs["credentials_enable_service"] = False
        prefs["profile.password_manager_enabled"] = False

        options.add_experimental_option("prefs", prefs)
        options.add_experimental_option("excludeSwitches", ['disable-automation'])
        options.add_experimental_option('excludeSwitches', ['enable-logging'])

        options.add_argument('--enable-background-networking')
        options.add_argument('--disable-infobars')  # 禁止策略化
        options.add_argument('--no-sandbox')  # 解决DevToolsActivePort文件不存在的报错
        options.add_argument('window-size=1920x3000')  # 指定浏览器分辨率
        options.add_argument('--disable-gpu')  # 谷歌文档提到需要加上这个属性来规避bug
        # options.add_argument('--incognito') # 隐身模式（无痕模式）
        # options.add_argument('--disable-javascript') # 禁用javascript
        options.add_argument('--start-maximized')  # 最大化运行（全屏窗口）,不设置，取元素会报错
        options.add_argument('--disable-infobars')  # 禁用浏览器正在被自动化程序控制的提示
        options.add_argument('--hide-scrollbars')  # 隐藏滚动条, 应对一些特殊页面
        options.add_argument('blink-settings=imagesEnabled=false')  # 不加载图片, 提升速度
        # options.add_argument('--headless') # 浏览器不提供可视化页面. linux下如果系统不支持可视化不加这条会启动失败
        options.binary_location = r"C:\Program Files\Google\Chrome\Application\chrome.exe"  # 手动指定使用的浏览器位置
        options.add_argument("--user-data-dir=" + r"C:\Users\hongtao\AppData\Local\Google\Chrome\User Data")

        return options

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

    def find_the_browser(self):
        if not self._browser:
            workPath = os.path.abspath('./res/chrome/chromedriver.exe')
            s = Service(workPath)
            options = self.get_debug_chrome_opetions()
            browser: webdriver = webdriver.Chrome(service=s, options=options)
            Log.debug(f"finded the browser!")
            self._browser = browser

    def openGameUrl(self, url: str = ''):
        try:
            self.find_the_browser()
            self.open_new_tab(self._browser)
            if url and url != '':
                self._url = url

            self._browser.get(self._url)
            Log.info(f"open url={self._url}, is ok!")
        except Exception as ex:
            Log.exception("openGameUrl error")
            GEventHandler.Dispatch(EventType.reload_chrome)
            RuntimeError('Job is stop')
