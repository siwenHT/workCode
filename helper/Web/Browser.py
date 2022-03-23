#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   Browser.py
@Time    :   2022/03/20 21:03:50
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib

import os, time, threading
from socket import timeout
from selenium import webdriver
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.Singleton import Singleton
from selenium.webdriver.chrome.service import Service
from selenium.common.exceptions import WebDriverException


class Browser(Singleton):

    def __init__(self):
        if not hasattr(self, "_lock"):
            self._lock = threading.Lock()
            self._lock2 = threading.Lock()
            self._openErrorNum = 0
            self._findBrowserErrorNum = 0
            self._workPath = os.path.abspath('./res/chrome/chromedriver_99.exe')

    def GetBrowser(self):
        browser = None
        self._lock.acquire()
        while True:
            try:
                Log.debug(f"begin find the browser!")
                s = Service(self._workPath)
                options = self.get_debug_chrome_opetions()
                browser: webdriver = webdriver.Chrome(service=s, options=options)
                Log.debug(f"finded the browser!")
                self._findBrowserErrorNum = 0
                break
            except Exception as ex:
                Log.info(f"Browser GetBrowser {type(ex).__name__}")
                if self._findBrowserErrorNum >= 3:
                    self._findBrowserErrorNum = 0
                    Log.exception(f"Browser GetBrowser error time max!")
                    break

                GEventHandler.DelayDispatch(EventType.reload_chrome)
                time.sleep(5)
                self._findBrowserErrorNum = self._findBrowserErrorNum + 1

        self._lock.release()
        return browser

    def OpenNewTab(self, theBrowser):
        newHandler = None
        self._lock2.acquire()
        while True:
            try:
                oldHandles = theBrowser.window_handles

                theBrowser.execute_script("window.open('');")
                newhandles = theBrowser.window_handles

                for newOne in newhandles:
                    if newOne not in oldHandles:
                        newHandler = newOne
                        break

                if not newHandler:
                    newHandler = oldHandles[1]
                    # raise RuntimeError(f'OpenNewTab window is miss {theBrowser.title}')

                theBrowser.switch_to.window(newHandler)
                self._openErrorNum = 0
                break
            except Exception as ex:
                self._openErrorNum = self._openErrorNum + 1
                Log.exception(f"Browser OpenNewTab WebDriverException {self._openErrorNum}")
                if self._openErrorNum > 3:
                    self._openErrorNum = 0
                    break

                time.sleep(2)

        self._lock2.release()
        if newHandler:
            return newHandler
        else:
            raise RuntimeError(f'OpenNewTab window is miss')

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