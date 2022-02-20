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
                time.sleep(1)
                self.CheckChainName()

    def UnlockConfirm(self):
        unlockKey = "unlock-page__container"
        inputKey = "MuiInputBase-input.MuiInput-input"
        OKKey = "button.btn--rounded.btn-default"
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

    def CheckChainName(self):
        self._timeSleep = 1
        chainNameKey = "//div[@class='app-header__network-component-wrapper']/div/span"
        chainNameEl = self.find_element_loop(By.XPATH, self._browser, chainNameKey)
        if chainNameEl:
            chainNameText = chainNameEl.text
            Log.info(f"chain is {chainNameText}")

            self.ReportVal(f"检查链名:{chainNameText}...")
            if chainNameText.find("Testnet") == -1 and chainNameText.find("testnet") == -1:
                self._timeSleep = 3

    def ConfirmTransaction(self):
        confirmKey = "confirm-page-container-content"
        confirmBtnKey = "button.btn--rounded.btn-primary.page-container__footer-button"
        dangerousKey = "actionable-message.actionable-message--danger"
        cancelBtnKey = "button.btn--rounded.btn-secondary.page-container__footer-button"

        contentEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmKey, 3)
        if contentEl:
            self.ReportVal(f"确认交易")
            dangerousEl = self.find_element_loop(By.CLASS_NAME, self._browser, dangerousKey, 1)
            btnEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmBtnKey, 3)
            cancelEl = self.find_element_loop(By.CLASS_NAME, self._browser, cancelBtnKey, 3)
            if dangerousEl:
                Log.info("the transaction has error!!")
                if cancelEl:
                    self.element_click(cancelEl)
                    Log.info("Has cancel on Transaction!!")
            else:
                time.sleep(self._timeSleep)
                if btnEl and btnEl.is_enabled():
                    self.element_click(btnEl)
                    Log.info("Has Confirm on Transaction!!")
                else:
                    if cancelEl:
                        self.element_click(cancelEl)
                        Log.info("Has cancel on Transaction!!")
        else:
            self.refreshPage()
