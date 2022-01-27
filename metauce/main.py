# -*- coding: utf-8 -*-
from ast import While, arg
import datetime
from gc import collect
from lib2to3.pgen2 import driver
from re import L
import sys
import io
import os
import atexit
import time
from turtle import delay
from xmlrpc.client import Boolean

from httpx import options
from thelog import Log
from selenium import webdriver
import toolsFunc as Tool
import functools

from selenium.webdriver.common.keys import Keys
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.remote import webelement
from selenium.webdriver.common.action_chains import ActionChains
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.support import expected_conditions as EC

from apscheduler.schedulers.blocking import BlockingScheduler

url = "https://metauce.org/MetisGame"
url2 = "chrome://version"
totalHandler = []


# 一键收矿
class openUrl:

    def __init__(self, url: str):
        self._browser = None
        self._handler = None
        self._repairTime = {}
        self._url = url
        global totalHandler
        totalHandler.append(self)

    def closeBrowser(self):
        if self._browser:
            self._browser.close()
            self._browser = None

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

        browser.execute_script("window.open('');")
        newhandles = browser.window_handles

        for newOne in newhandles:
            if newOne not in oldHandles:
                self._handler = newOne
                break
        browser.switch_to.window(newOne)

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

    def openGameUrl(self):
        # 打开浏览器
        workPath = os.path.abspath('./res/chrome/chromedriver.exe')

        s = Service(workPath)
        options = self.get_debug_chrome_opetions()
        browser: webdriver = webdriver.Chrome(service=s, options=options)
        Log.debug(f"finded the browser!")
        self._browser = browser

        self.open_new_tab(browser)
        browser.get(self._url)
        Log.info(f"open url={self._url}, is ok!")

    # 到挖矿界面
    def touchMining(self):
        playKey = "//div/div[@class='main--collapse']/div[@class='warp']/div[@class='code']/button[1]"
        elment2: webelement = self.find_element_loop(By.XPATH, self._browser, playKey)
        if elment2:
            self.element_click(elment2)
            Log.debug(f"click the play button!")
        else:
            Log.debug(f"cannot find the play button!")
            self.closeBrowser()
            return False

        miningKey = "//div/div[@class='main--collapse']/div[@class='warp']/div[@class='cneter_warp']/div[@class='map']/p/span"
        mining: webelement = self.find_element_unit(By.XPATH, self._browser, miningKey)
        if mining:
            self.element_click(mining, 30, 20)
            Log.debug(f"click the mining button!")
        else:
            Log.debug(f"cannot find the mining button!")
            self.closeBrowser()
            return False
        return True

    def touchOneRemainBtn(self):
        radioKey = "//div/div/div/label[@class='el-radio']"
        radioEl: webelement = self.find_element_unit(By.XPATH, self._browser, radioKey)
        if radioEl:
            self.element_click(radioEl)
            Log.debug(f"click the radioEl button!")
        else:
            Log.debug(f"cannot find the radioEl button!")
            self.closeBrowser()
            return False
        return True

    def conformTransaction(self):
        confirmKey = "confirm-page-container-content"
        confirmBtnKey = "button.btn--rounded.btn-primary.page-container__footer-button"
        chainConfirm = "//span[contains(text(), 'Metis Stardust Testnet')]"
        chainName = self.find_element_loop(By.XPATH, self._browser, chainConfirm, 3)
        if not chainName:
            Log.error(f"chain is error! please check!")
            return

        while True:
            contentEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmKey, 3)
            if contentEl:
                btnEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmBtnKey, 3)
                if btnEl:
                    self.element_click(btnEl)
                    time.sleep(2)
                    Log.error("Has Confirm on Transaction!!")
            else:
                self.refreshPage()
                time.sleep(2)

    def refreshPage(self):
        try:
            self._browser.refresh()
            Log.debug('refreshPage: Ok')
        except Exception as e:
            Log.info('refreshPage: error!!')

    #修车
    def repairTruck(self):
        try:
            repairKey = '//*[contains(text(), "Repair truck ")]'
            repairEl = self.find_element_loop(By.XPATH, self._browser, repairKey, 1)
            if repairEl:
                if time.time() - self._repairTime.get(repairEl._id, 0) > 3600:
                    self.element_click(repairEl)
                    self._repairTime[repairEl._id] = time.time()
                    Log.info(f"find a repair truck! {repairEl._id}")
                    return True

        except Exception as ex:
            time.sleep(10)
            return True

        Log.info(f"repairTruck end!")
        return False

    #取下车
    def removeTruck(self):
        try:
            collectKey = "//div[@class='cneter_warp']/div[@class='collect']"
            collectEls = self.find_elements_loop(By.XPATH, self._browser, collectKey, 5)
            if collectEls:
                count = 1
                remainKey = ".//div/ul/li[4]/span[2]"
                removeKey = ".//div[@class='list_c']/div/div/p[@class='ones']"
                Log.info(f"removeTruck has {len(collectEls)} truck !")
                for one in collectEls:
                    remainEl = self.find_element(By.XPATH, one, remainKey)
                    removeEl = self.find_element(By.XPATH, one, removeKey)
                    Log.debug(f"try remove {count}")
                    count += 1
                    if remainEl and remainEl.text == "0" and removeEl:
                        self.element_click(removeEl)
                        Log.info(f" click Remove Truck {count} {removeEl._id} {one._id}")
                        time.sleep(0.2)
        except Exception as ex:
            pass

        Log.info(f"removeTruck end!")

    #补车
    def insertTruck(self, starLimit: int = 0):
        collectKey = "//div[@class='cneter_warp']/div[@class='collect']"
        collectEls = self.find_elements_loop(By.XPATH, self._browser, collectKey, 5)
        try:
            if collectEls:
                Log.info(f"insertTruck has {len(collectEls)} truck !")

                remainKey = ".//div/ul/li[4]/span[2]"
                carSelKey = f".//div[@class='right']/div[@class='list_data']/ul/li"
                for index in range(len(collectEls)):
                    one = collectEls[index]
                    remainEl = self.find_element(By.XPATH, one, remainKey)
                    if remainEl and remainEl.text != "0":
                        carselEls = self.find_elements(By.XPATH, one, carSelKey)

                        Log.debug(f"land {index} not zero remain, has {len(carselEls)} truck!")
                        if carselEls:
                            starKey = ".//div/p/i"
                            numCount = []
                            showNum = {}
                            showNum["1"] = 0
                            showNum["2"] = 0
                            showNum["3"] = 0
                            showNum["4"] = 0
                            showNum["5"] = 0
                            for carIdx in range(len(carselEls)):
                                car = carselEls[carIdx]
                                if not car.is_displayed():
                                    continue

                                starEls = self.find_elements(By.XPATH, car, starKey)
                                if starEls and len(starEls) > starLimit:
                                    data = {}
                                    data["carEl"] = car
                                    data["num"] = len(starEls)
                                    data["index"] = carIdx
                                    numCount.append(data)
                                    showNum[str(data['num'])] += 1

                            Log.debug(f"car info len:{len(numCount)}")
                            if numCount:

                                def compare(A, B):
                                    aNum = A.get('num', 0)
                                    bNum = B.get('num', 0)
                                    if aNum > bNum:
                                        return -1
                                    elif aNum < bNum:
                                        return 1
                                    return 0

                                numCount.sort(key=functools.cmp_to_key(compare))

                                Log.info(f"starTruck num => 5: {showNum['5']}, 4: {showNum['4']}, 3: {showNum['3']}, 2: {showNum['2']}, 1: {showNum['1']}")

                                theCar = numCount[0]['carEl']

                                Log.info(f"choose the Truck {theCar._id} {numCount[0]['index']} {numCount[0]['num']}")
                                theClickEl = self.find_element(By.XPATH, theCar, ".//div")
                                if theClickEl:
                                    self.element_click(theClickEl)
                                    addBtnKey = f".//div[@class='list_c']/div/div/p"
                                    addBtn = self.find_element_loop(By.XPATH, one, addBtnKey, 15)
                                    if addBtn:
                                        self.element_click(addBtn)
                                        Log.info(f" add Truck {theCar._id} {one._id}")
                                        return True
        except Exception as ex:
            time.sleep(10)
            return True

        Log.info(f"insertTruck end!")
        return False

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
                Log.info(f"click a wakuangbox {wakuangs1._id}!")
                continue

            count += 1
            Log.debug(f"no box!")
            if count > 20:
                timeStep = 30

    # 一次就搞定的
    def wakuang2(self):
        timeRecord = {}
        wakuangbox = "iconfont.icon--wakuangjiankong"
        while True:
            if self.repairTruck():
                time.sleep(3)
                continue

            try:
                wakuangs1 = self.find_elements_loop(By.CLASS_NAME, self._browser, wakuangbox, 3)
                if wakuangs1:
                    Log.info(f"find wakuangbox! num : {len(wakuangs1)}")
                    index = 0
                    for wa in wakuangs1:
                        index += 1
                        if time.time() - timeRecord.get(wa._id, 0) > 3600:
                            time.sleep(0.5)
                            self.element_click(wa)
                            Log.info(f"click wakuangbox! {index} {wa._id}")
                            timeRecord[wa._id] = time.time()

                    Log.info(f"click box once end! num : {len(wakuangs1)}")
                    time.sleep(60)
            except Exception as ex:
                time.sleep(60)

            else:
                time.sleep(120)


#取车
#收菜
#
def main():
    Tool.showParams()

    def removeTruck():
        Log.info('removeTruck job')
        handler = openUrl(url)
        handler.openGameUrl()
        handler.touchMining()
        time.sleep(20)
        handler.removeTruck()
        handler.closeBrowser()
        Log.info('removeTruck job end')

    def insertTruck(args):
        starLimit = 0
        if args:
            starLimit = args
        Log.info(f'insertTruck job! starLimit:{starLimit}')
        handler = openUrl(url)
        handler.openGameUrl()
        handler.touchMining()
        handler.touchOneRemainBtn()
        time.sleep(20)
        while True:
            if handler.insertTruck(starLimit):
                time.sleep(20)
                continue
            break
        handler.closeBrowser()
        Log.info('insertTruck job end')

    def mainFunc():
        Log.info('mainFunc job')

        handler = openUrl(url)
        handler.openGameUrl()
        handler.touchMining()
        handler.touchOneRemainBtn()
        handler.wakuang2()
        Log.info('mainFunc job end')

    def openMetaMask():
        handler = openUrl("chrome-extension://nkbihfbeogaeaoehlefnkodbefgpgknn/home.html")
        handler.openGameUrl()
        handler.conformTransaction()

    scheduler = BlockingScheduler()
    temp_date = datetime.datetime.now() + datetime.timedelta(seconds=5)
    temp_date1 = datetime.datetime.now() + datetime.timedelta(seconds=5)
    temp_date2 = datetime.datetime.now() + datetime.timedelta(seconds=15)
    temp_date3 = datetime.datetime.now() + datetime.timedelta(seconds=3)

    @atexit.register
    def clearUp():
        Log.error('clearUp')
        for oneHandler in totalHandler:
            oneHandler.closeBrowser()

    # scheduler.add_job(removeTruck, 'interval', seconds=60 * 60, id='removeJob', max_instances=5)
    # scheduler.add_job(insertTruck, 'interval', seconds=100 * 60, id='insertJob', max_instances=5)

    # scheduler.add_job(insertTruck, 'date', run_date=temp_date, max_instances=5, args=[3])
    scheduler.add_job(removeTruck, 'date', run_date=temp_date2, max_instances=5)
    # scheduler.add_job(mainFunc, 'date', run_date=temp_date1, max_instances=1)
    scheduler.add_job(openMetaMask, 'date', run_date=temp_date3, max_instances=1)

    scheduler.start()


if __name__ == "__main__":
    main()
