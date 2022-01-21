# -*- coding: utf-8 -*-
from re import L
import sys
import io
import os

import time
from thelog import Log
from selenium import webdriver
#一键收矿


url = "https://metauce.org/MetisGame"


def find_element(dir, key):
    pass

def do():
    #打开浏览器
    workPath = os.path.abspath('./res/chrome')
    browser = webdriver.Chrome(workPath)
    
    #打开网址
    browser.get(url)

    #等待网页打开
    time.sleep(10)

    #链接钱包
    browser.find_element_by_class_name("address_token")

    pass

#点击菜单第一个
#点击play
#点击挖矿
#点击所有收获
#等待下一次点击挖矿


def main():
    do()


if __name__ == "__main__":
    main()