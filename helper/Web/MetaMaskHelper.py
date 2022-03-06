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
from ast import While
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

    def __init__(self, jobName=''):
        super().__init__("chrome-extension://nkbihfbeogaeaoehlefnkodbefgpgknn/home.html", jobName)
        self.ConfirmAccountCount = 0

    def ConfirmChangeNet(self):
        confirmKey = "//div[@class='confirmation-footer__actions']/button[text()='Switch network' or text()='切换网络' ]"
        confirmEl = self.find_element_loop(By.XPATH, self._browser, confirmKey, 1)
        if confirmEl:
            changeTargetKey = "//div/div/span[contains(text(), 'Testnet')]"
            targetEl = self.find_element_loop(By.XPATH, self._browser, changeTargetKey, 1)
            if not targetEl:
                time.sleep(5)

            self.ReportVal(f"切换了主网")
            self.element_click(confirmEl)
            time.sleep(1)
            self.CheckChainName()

    def ConfirmAccount(self, accountidx: int = 1):
        accountListKey = "//div[@class='choose-account-list']"
        accountListEl = self.find_element_loop(By.XPATH, self._browser, accountListKey, 1)
        if accountListEl:
            clickNum = 0
            while True:
                if clickNum > 10:
                    break

                unselKey = "//div[@class='choose-account-list']/div/div/input"
                unselEl = self.find_element_loop(By.XPATH, self._browser, unselKey, 2)
                if unselEl:
                    self.element_click(unselEl)
                    clickNum += 1

                inputKey = "check-box.choose-account-list__header-check-box.far.fa-square"
                noSelKey = f"//div[@class='choose-account-list']/div/div/input[@class='{inputKey}']"
                noSelEl = self.find_element_loop(By.XPATH, self._browser, unselKey, 2)
                if noSelEl:
                    break

            unselKey = "//div[@class='choose-account-list']/div/div/input"
            unselEl = self.find_element_loop(By.XPATH, self._browser, unselKey, 2)
            if unselEl:
                self.element_click(unselEl)

            selKey = f"//div[@class='choose-account-list']/div[2]/div/div[{accountidx}]/div"
            selEl = self.find_element_loop(By.XPATH, self._browser, selKey, 2)
            if selEl:
                self.element_click(selEl)

            okKey = "//div[@class='permissions-connect-choose-account__bottom-buttons']/button[2]"
            okEl = self.find_element_loop(By.XPATH, self._browser, okKey, 1)
            if okEl and okEl.is_enabled():
                self.element_click(okEl)
                self.ReportVal(f"确认使用了账号{accountidx}")
            elif self.ConfirmAccountCount >= 3:
                Log.error("ConfirmAccount fail")
            else:
                self.ConfirmAccountCount += 1
                self.ConfirmAccount(accountidx)

    def UnlockConfirm(self):
        unlockKey = "unlock-page__container"
        inputKey = "MuiInputBase-input.MuiInput-input"
        OKKey = "button.btn--rounded.btn-default"
        unlockEl = self.find_element_loop(By.CLASS_NAME, self._browser, unlockKey, 1)
        if unlockEl:
            input = self.find_element_loop(By.CLASS_NAME, self._browser, inputKey, 1)
            if input:
                input.send_keys("Myhxlin170")
                OKKeyEl = self.find_element_loop(By.CLASS_NAME, self._browser, OKKey, 1)
                if OKKeyEl:
                    self.element_click(OKKeyEl)
            else:
                Log.error(f"not find the {inputKey}")

    def CheckChainName(self):
        self._timeSleep = 1
        chainNameKey = "//div[@class='app-header__network-component-wrapper']/div/span"
        chainNameEl = self.find_element_loop(By.XPATH, self._browser, chainNameKey, 1)
        if chainNameEl:
            chainNameText = chainNameEl.text
            Log.info(f"chain is {chainNameText}")

            self.ReportVal(f"检查链名:{chainNameText}...")
            if chainNameText.find("Testnet") == -1 and chainNameText.find("testnet") == -1:
                self._timeSleep = 5

    def ConfirmTransaction(self):
        confirmKey = "confirm-page-container-content"
        confirmBtnKey = "button.btn--rounded.btn-primary.page-container__footer-button"
        dangerousKey = "actionable-message.actionable-message--danger"
        cancelBtnKey = "button.btn--rounded.btn-secondary.page-container__footer-button"

        contentEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmKey, 1)
        if contentEl:
            dangerousEl = self.find_element_loop(By.CLASS_NAME, self._browser, dangerousKey, 1)
            btnEl = self.find_element_loop(By.CLASS_NAME, self._browser, confirmBtnKey, 1)
            cancelEl = self.find_element_loop(By.CLASS_NAME, self._browser, cancelBtnKey, 1)
            if dangerousEl:
                Log.info("the transaction has error!!")
                if cancelEl:
                    self.element_click(cancelEl)
                    Log.info("Has cancel on Transaction!!")
            else:
                time.sleep(self._timeSleep)
                if btnEl and btnEl.is_enabled():
                    self.ReportVal(f"确认交易")
                    self.element_click(btnEl)
                    Log.info("Has Confirm on Transaction!!")
                else:
                    if cancelEl:
                        self.element_click(cancelEl)
                        Log.info("Has cancel on Transaction!!")

    def ConfirmApproveAction(self):
        approveContentKey = "//div[@class='confirm-approve-content']"
        approveContentEl = self.find_element_loop(By.XPATH, self._browser, approveContentKey, 1)
        if approveContentEl:
            approveCancelKey = "//div[@class='page-container__footer']/footer/button[1]"
            approveOkKey = "//div[@class='page-container__footer']/footer/button[2]"

            cancelEl = self.find_element_loop(By.XPATH, self._browser, approveCancelKey, 1)
            okEl = self.find_element_loop(By.XPATH, self._browser, approveOkKey, 1)
            if okEl and okEl.is_enabled():
                self.element_click(okEl)
                self.ReportVal(f"授权成功")
            else:
                if cancelEl:
                    self.element_click(cancelEl)
                    self.ReportVal(f"授权失败")

    def ConfirmSignature(self):
        signCancelKey = "//div[@class='request-signature__footer']/button[1]"
        signOkKey = "//div[@class='request-signature__footer']/button[2]"

        cancelEl = self.find_element_loop(By.XPATH, self._browser, signCancelKey, 1)
        okEl = self.find_element_loop(By.XPATH, self._browser, signOkKey, 1)
        if okEl and okEl.is_enabled():
            self.element_click(okEl)
            self.ReportVal(f"签名成功")
        else:
            if cancelEl:
                self.element_click(cancelEl)
                self.ReportVal(f"签名失败")