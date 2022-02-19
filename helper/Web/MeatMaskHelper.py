#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   MeatMaskHelper.py
@Time    :   2022/02/19 02:25:41
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


class MeatMaskHelper(OpenUrl):

    def __init__(self):
        super().__init__("chrome-extension://nkbihfbeogaeaoehlefnkodbefgpgknn/home.html")

    def ConfirmChangeNet(self):
        changeKey = "//h3[contains(text(), 'Allow this site to switch the network?')]"
        unlockEl = self.find_element(By.XPATH, self._browser, changeKey)
        if unlockEl:
            changeTargetKey = "//div/div/span[contains(text(), 'Testnet')]"
            targetEl = self.find_element(By.XPATH, self._browser, changeTargetKey)
            if not targetEl:
                time.sleep(3)

            confirmKey = "//div[@class='confirmation-footer__actions']/button[text()='Switch network']"
            confirmEl = self.find_element(By.XPATH, self._browser, confirmKey)
            if confirmEl:
                self.element_click(confirmEl)
                return True

    def ConfirmTransaction(self):
        unlockKey = "unlock-page__container"
        inputKey = "MuiInputBase-input.MuiInput-input"
        OKKey = "button.btn--rounded.btn-default"
        confirmKey = "confirm-page-container-content"
        confirmBtnKey = "button.btn--rounded.btn-primary.page-container__footer-button"
        chainConfirm = "//span[contains(text(), 'Metis Stardust Testnet')]"
        dangerousKey = "actionable-message.actionable-message--danger"
        cancelBtnKey = "button.btn--rounded.btn-secondary.page-container__footer-button"
        unlockEl = self.find_element_loop(By.CLASS_NAME, self._browser, unlockKey)
        if unlockEl:
            input = self.find_element_loop(By.CLASS_NAME, self._browser, inputKey)
            if input:
                input.send_keys("Myhxlin170")
                OKKeyEl = self.find_element_loop(By.CLASS_NAME, self._browser, OKKey)
                if OKKeyEl:
                    self.element_click(OKKeyEl)
                    time.sleep(3)
            else:
                Log.error(f"not find the {inputKey}")

        name = self.find_element_loop(By.XPATH, self._browser, "//span")
        if name:
            Log.info(f"{name.text}")
        chainNameKey = "//div[@class='app-header__network-component-wrapper']/div/span"
        chainNameEl = self.find_element_loop(By.XPATH, self._browser, chainNameKey)
        if chainNameEl:
            Log.error(f"chain is {chainNameEl.text}")

        timeSleep = 1
        chainName = self.find_element_loop(By.XPATH, self._browser, chainConfirm, 3)
        if not chainName:
            timeSleep = 3
            # chainNameKey = "//div[@class='app-header__network-component-wrapper']/div/span"
            # chainNameEl = self.find_element_loop(By.XPATH, self._browser, chainNameKey)
            # if chainNameEl:
            #     Log.error(f"chain is {chainNameEl.text}! please check!")
            # else:
            #     Log.error(f"chain is error! please check!")
            # return

        while True:
            if self.ConfirmChangeNet():
                time.sleep(2)

            contentEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmKey, 3)
            if contentEl:
                dangerousEl = self.find_element_loop(By.CLASS_NAME, self._browser, dangerousKey, 1)
                btnEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmBtnKey, 3)
                cancelEl = self.find_element_loop(By.CLASS_NAME, self._browser, cancelBtnKey, 3)
                if dangerousEl:
                    Log.info("the transaction has error!!")
                    if cancelEl:
                        self.element_click(cancelEl)
                        time.sleep(timeSleep)
                        Log.info("Has cancel on Transaction!!")
                else:
                    time.sleep(timeSleep)
                    if btnEl and btnEl.is_enabled():
                        self.element_click(btnEl)
                        time.sleep(1)
                        Log.info("Has Confirm on Transaction!!")
                    else:
                        if cancelEl:
                            self.element_click(cancelEl)
                            time.sleep(1)
                            Log.info("Has cancel on Transaction!!")
            else:
                self.refreshPage()
                time.sleep(1)
