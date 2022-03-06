#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MetauceBot.py
@Time    :   2022/02/19 02:15:50
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


class MetauceBot(OpenUrl):

    def __init__(self, jobName=''):
        super().__init__("https://metauce.org/MetisGame", jobName)
        self._wakuangRun = 0
        self._repairTime = {}
        self._mintFee = 125
        self._minLanNum = 5
        self._metalNum = 0

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

    '''点击查看挖矿情况'''

    def touchOneRemainBtn(self):
        self.refreshPage()
        time.sleep(10)
        radioKey = "//div/div/div[@class='el-radio-group']/label[2]"
        radioEl: webelement = self.find_element_unit(By.XPATH, self._browser, radioKey)
        if radioEl:
            self.element_click(radioEl)
            Log.debug(f"click the radioEl button!")
        else:
            Log.debug(f"cannot find the radioEl button!")
            self.closeBrowser()
            return False
        return True

    '''点击已经已经完成挖矿的土地'''

    def touchDepletedBtn(self):
        self.refreshPage()
        time.sleep(10)
        radioKey = "//div/div/div[@class='el-radio-group']/label[3]"
        radioEl: webelement = self.find_element_unit(By.XPATH, self._browser, radioKey)
        if radioEl:
            self.element_click(radioEl)
            Log.debug(f"click the radioEl button!")
        else:
            Log.debug(f"cannot find the radioEl button!")
            self.closeBrowser()
            return False
        return True

    '''检查能不能构建激活码'''

    def touchMedalBtn(self):
        try:
            self.ReportVal(f"构建新徽章{self._metalNum}...")
            self.closeBrowser()
            self.openGameUrl("https://metauce.org/MetisGame/#/Medal")

            btnKey = "//div[@class='cneter_warp']/ul/li[1]/button"
            btnEl: webelement = self.find_element_unit(By.XPATH, self._browser, btnKey)
            if btnEl:
                if btnEl.is_enabled():
                    self.element_click(btnEl)
                    Log.debug(f"click the medal button!")
                else:
                    Log.debug(f"canNot click the medal button!")
            else:
                Log.debug(f"cannot find the medal button!")
                self.closeBrowser()
        except Exception as ex:
            Log.exception("touchMedalBtn error")
            pass

    '''查看够不够买东西'''

    def checkBuyTime(self):
        self.ReportVal(f"开始花钱...")
        try:
            time.sleep(10)
            tokenNum = "address_token.address_token_p"
            tokenEl = self.find_element_loop(By.CLASS_NAME, self._browser, tokenNum)
            if tokenEl:
                test: str = tokenEl.text
                test = test.replace("Claim ", "")
                test = test.replace(" MINES", "")
                tokenVal = float(test)
                Log.info(f"tokenVal: {tokenVal}")
                if tokenVal > self._mintFee:
                    collectKey = "//div[@class='cneter_warp']/div[@class='collect']"
                    collectEls = self.find_elements_loop(By.XPATH, self._browser, collectKey, 1)
                    if collectEls:
                        Log.info(f"land current num: {len(collectEls)}")

                    if not collectEls or len(collectEls) < self._minLanNum:
                        val = 0 if not collectEls else len(collectEls)
                        val = (self._minLanNum - val) * self._mintFee
                        val = val if tokenVal > val else tokenVal
                        self.minitTruckOrLand(int(val / self._mintFee), 1)
                        # self.checkBuyTime()
                    else:
                        self.minitTruckOrLand(int((tokenVal - 250) / self._mintFee), 2)
        except Exception as ex:
            pass

        self.ReportVal(f"花钱完事了...")

    def minitTruckOrLand(self, times, type):
        Log.info(f"minitTruckOrLand {times} {type}")
        if times == 0:
            return

        try:
            flg = 'land' if (type == 1) else "truck"
            self.closeBrowser()
            self.openGameUrl("https://metauce.org/MetisGame/#/Map" if (type == 1) else "https://metauce.org/MetisGame/#/Car")

            key = "//div[@class='cneter_warp']/div[@class='header_search']/button/span"
            tBtn = self.find_element_loop(By.XPATH, self._browser, key)
            if tBtn:
                for i in range(times):
                    self.element_click(tBtn)
                    Log.info(f"miniting a {flg}!")
                    time.sleep(12)

                    if self._needStop:
                        return
        except Exception as ex:
            pass

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

        # Log.info(f"repairTruck end!")
        return False

    #取下车
    def removeTruck(self):
        try:
            self.ReportVal(f"开始取车了...")
            collectKey = "//div[@class='cneter_warp']/div[@class='collect']"
            collectEls = self.find_elements_loop(By.XPATH, self._browser, collectKey, 5)
            if collectEls:
                count = 0
                remainKey = ".//div/ul/li[4]/span[2]"
                removeKey = ".//div[@class='list_c']/div/div/p[@class='ones']"
                Log.info(f"removeTruck has {len(collectEls)} truck !")
                for one in collectEls:
                    if self._needStop:
                        return

                    count += 1
                    carlistKey = ".//div/div[@class='list_data']"
                    carlistEl = self.find_element_loop(By.XPATH, one, carlistKey)
                    if carlistEl:
                        self.element_hide(one)
                    else:
                        remainEl = self.find_element(By.XPATH, one, remainKey)
                        removeEl = self.find_element(By.XPATH, one, removeKey)
                        Log.debug(f"try remove {count}")
                        self.ReportVal(f"取第{count}块地")
                        if remainEl and remainEl.text == "0" and removeEl:
                            self.element_click(removeEl)
                            Log.info(f" click Remove Truck {count} {removeEl._id} {one._id}")
                            time.sleep(0.2)
        except Exception as ex:
            Log.exception("removeTruck error:")
            pass

        self.ReportVal(f"取车完成...")

    #安装卡车
    def insertTruck(self, starLimit: int = 0):
        self.ReportVal(f"开始安装卡车...")
        collectKey = "//div[@class='cneter_warp']/div[@class='collect']"
        collectEls = self.find_elements_loop(By.XPATH, self._browser, collectKey, 5)
        try:
            if collectEls:
                Log.info(f"insertTruck has {len(collectEls)} truck !")

                remainKey = ".//div/ul/li[4]/span[2]"
                minedKey = f".//div/ul/li[3]"
                carSelKey = f".//div[@class='right']/div[@class='list_data']/ul/li"
                for index in range(len(collectEls)):
                    one = collectEls[index]
                    remainEl = self.find_element(By.XPATH, one, remainKey)
                    minedEl = self.find_element(By.XPATH, one, minedKey)
                    if remainEl and remainEl.text != "0" and minedEl and minedEl.text == 'Mined : 0 MINES':
                        fVal = float(remainEl.text)
                        if fVal < 0:
                            continue
                        carselEls = self.find_elements(By.XPATH, one, carSelKey)

                        if self._needStop:
                            return

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
                                if starEls and len(starEls) >= starLimit:
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

                                self.ReportVal(f"开始第{index}块地,补车...")
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

        self.ReportVal(f"补车完成...")
        return False

    def wakuang(self):
        timeRecord = {}
        wakuangbox = "iconfont.icon--wakuangjiankong"
        while True:
            self.ReportVal(f"开始第{self._wakuangRun}轮挖矿...")
            if self._needStop:
                return

            if self.repairTruck():
                time.sleep(3)
                continue

            try:
                time.sleep(10)
                flg = False
                # selAllKey = "//div[@class='header_search']/label/span/span"
                # collectAllKey = "//div[@class='header_search']/button"
                # selAllEl = self.find_element_loop(By.XPATH, self._browser, selAllKey)
                # if selAllEl:
                #     self.element_click(selAllEl)
                #     time.sleep(10)
                #     collectAllEl = self.find_element_loop(By.XPATH, self._browser, collectAllKey)
                #     if collectAllEl:
                #         self.element_click(collectAllEl)
                #         Log.info(f"one time collect all!")
                #         time.sleep(5)
                #         flg = True

                if not flg:
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
                        time.sleep(10)
            except Exception as ex:
                time.sleep(10)

            else:
                time.sleep(20)

            self.ReportVal(f"第{self._wakuangRun}轮挖矿完成...")
            self._wakuangRun += 1
            return
