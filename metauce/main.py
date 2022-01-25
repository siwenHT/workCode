# -*- coding: utf-8 -*-
from gc import collect
from lib2to3.pgen2 import driver
from re import L
import sys
import io
import os

import time
from turtle import delay
from xmlrpc.client import Boolean

from httpx import options
from thelog import Log
from selenium import webdriver
import toolsFunc as Tool

from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.remote import webelement
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support.ui import WebDriverWait

url = "https://metauce.org/MetisGame"
url2 = "chrome://version"


# 一键收矿
class openUrl:

    def __init__(self):
        self._browser = None
        self._repairTime = {}
        pass

    def closeBrowser(self):
        if self._browser:
            self._browser.close()

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

    def open_new_tab(self, browser: webdriver):
        oldHandles = browser.window_handles
        browser.switch_to.window(oldHandles[-1])

        browser.execute_script("window.open('http://www.baidu.com');")
        handles = browser.window_handles
        browser.switch_to.window(handles[-1])

    def get_debug_chrome_opetions(self):
        options = webdriver.ChromeOptions()
        options.add_experimental_option("debuggerAddress", "127.0.0.1:9527")
        options.add_argument('blink-settings=imagesEnabled=false')  # 不加载图片, 提升速度
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

    def start(self, oneTime: Boolean = False):
        # 打开浏览器
        workPath = os.path.abspath('./res/chrome/chromedriver.exe')

        s = Service(workPath)
        # options = self.get_chrome_options()
        options = self.get_debug_chrome_opetions()
        browser: webdriver = webdriver.Chrome(service=s, options=options)
        Log.debug(f"finded the browser!")
        self._browser = browser

        self.open_new_tab(browser)
        # 打开网址.这个是同步的, 没完全打开不会返回
        browser.get(url)
        Log.debug(f"open url={url}, is ok!")

        # 链接钱包
        # elment: webelement = browser.find_element_by_class_name("address_token")

        time.sleep(1)
        # 点击play
        playKey = "//div/div[@class='main--collapse']/div[@class='warp']/div[@class='code']/button[1]"
        elment2: webelement = self.find_element_loop(By.XPATH, browser, playKey)
        if elment2:
            Log.debug(f"finded the play button!")
            self.element_click(elment2)
            Log.debug(f"click the play button!")
        else:
            Log.debug(f"cannot find the play button!")
            self.closeBrowser()
            return

        # 点击挖矿
        time.sleep(1)
        miningKey = "//div/div[@class='main--collapse']/div[@class='warp']/div[@class='cneter_warp']/div[@class='map']/p/span"
        mining: webelement = self.find_element_unit(By.XPATH, browser, miningKey)
        if mining:
            Log.debug(f"finded the mining button!")
            self.element_click(mining, 30, 20)
            Log.debug(f"click the mining button!")
        else:
            Log.debug(f"cannot find the mining button!")
            self.closeBrowser()
            return

        self.removeTruck()

        time.sleep(1)
        radioKey = "//div/div/div/label[@class='el-radio']"
        radioEl: webelement = self.find_element_unit(By.XPATH, browser, radioKey)
        if radioEl:
            Log.debug(f"finded the radioEl button!")
            self.element_click(radioEl)
            Log.debug(f"click the radioEl button!")
        else:
            Log.debug(f"cannot find the radioEl button!")
            self.closeBrowser()
            return

        # self.insertTruck()

        # 点击所有收获
        if True or oneTime:
            self.wakuang2(browser)
        else:
            self.wakuang(browser)

    #修车
    def repairTruck(self):
        repairKey = '//*[contains(text(), "Repair truck ")]'
        repairEl = self.find_element_loop(By.XPATH, self._browser, repairKey, 1)
        if repairEl:
            if time.time() - self._repairTime.get(repairEl._id, 0) > 60:
                self.element_click(repairEl)
                self._repairTime[repairEl._id] = time.time()
                Log.debug(f"find a repair truck!")
                return True

        Log.debug(f"repairTruck end!")
        return False

    #取下车
    def removeTruck(self):
        collectKey = "//div[@class='cneter_warp']/div[@class='collect']"
        collectEls = self.find_elements_loop(By.XPATH, self._browser, collectKey, 5)
        if collectEls:
            index = 1
            count = 1
            remainKey = ".//div/ul/li[4]/span[2]"
            removeKey = ".//div[@class='list_c']/div/div/p[@class='ones']"
            Log.debug(f"removeTruck has {len(collectEls)} truck !")
            for one in collectEls:
                remainEl = self.find_element(By.XPATH, one, remainKey)
                removeEl = self.find_element(By.XPATH, one, removeKey)
                Log.debug(f"try remove {count}")
                count += 1
                if remainEl and remainEl.text == "0" and removeEl:
                    self.element_click(removeEl)
                    Log.debug(f" click Remove Truck {index} {removeEl._id} {remainEl._id} {one._id}")
                    index += 1
                    time.sleep(0.2)

        Log.debug(f"removeTruck end!")

    #补车
    def insertTruck(self):
        collectKey = "//div[@class='cneter_warp']/div[@class='collect']"
        collectEls = self.find_elements_loop(By.XPATH, self._browser, collectKey, 5)
        if collectEls:
            remainKey = ".//div/ul/li[4]/span[2]"
            carSelKey = ".//div[@class='right']/div[@class='list_data']/ul/li[1]"
            Log.debug(f"insertTruck has {len(collectEls)} truck !")
            for index in range(len(collectEls)):
                one = collectEls[index]
                remainEl = self.find_element(By.XPATH, one, remainKey)
                carSelEl = self.find_element(By.XPATH, one, carSelKey)
                if remainEl and remainEl.text != "0" and carSelEl:
                    # self.element_click(carSelEl)
                    carSelEl.click()
                    addBtnKey = f"//div[@class='cneter_warp']/div[@class='collect'][{index + 1}]//div[@class='list_c']/div/div/p"
                    addBtn = self.find_element_loop(By.XPATH, self._browser, addBtnKey, 15)
                    if addBtn:
                        self.element_click(addBtn)
                        Log.debug(f" add Truck {index} {carSelEl._id} {remainEl._id} {one._id} {addBtn._id}")
                        time.sleep(0.2)

        Log.debug(f"removeTruck end!")

    # 等待下一次点击挖矿
    def wakuang(self, browser: webdriver):
        count = 0
        timeStep = 0.5
        wakuangbox = "iconfont.icon--wakuangjiankong"
        loadingKey = "loading-mask"
        while True:
            time.sleep(timeStep)

            # 在转圈圈就先停一下
            loadingEl = self.find_element_loop(By.CLASS_NAME, browser, loadingKey, 0.5)
            if loadingEl:
                continue

            if self.repairTruck():
                continue

            wakuangs1 = self.find_element_loop(By.CLASS_NAME, browser, wakuangbox, 0.5)
            if wakuangs1:
                count = 0
                timeStep = 0.5
                self.element_click(wakuangs1)
                Log.debug(f"click a wakuangbox!")
                continue

            count += 1
            Log.debug(f"no box!")
            if count > 20:
                timeStep = 30

    # 一次就搞定的
    def wakuang2(self, browser: webdriver):
        timeRecord = {}
        wakuangbox = "iconfont.icon--wakuangjiankong"
        while True:
            if self.repairTruck():
                time.sleep(3)
                continue

            wakuangs1 = self.find_elements_loop(By.CLASS_NAME, browser, wakuangbox, 3)
            if wakuangs1:
                Log.debug(f"find wakuangbox! num : {len(wakuangs1)}")
                index = 0
                for wa in wakuangs1:
                    index += 1
                    if time.time() - timeRecord.get(wa._id, 0) > 60:
                        time.sleep(0.5)
                        self.element_click(wa)
                        Log.debug(f"click wakuangbox! {index} {wa._id}")
                        timeRecord[wa._id] = time.time()

                Log.debug(f"click box once end! num : {len(wakuangs1)}")
                time.sleep(60)

            else:
                time.sleep(30)


#取车
#收菜
#
def main():
    Tool.showParams()

    handler = openUrl()
    if len(sys.argv) > 1:
        handler.start(True)
    else:
        handler.start()


if __name__ == "__main__":
    main()
