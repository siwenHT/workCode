from asyncio.log import logger
import time, os
from selenium import webdriver
from selenium.common.exceptions import SessionNotCreatedException  #导入NoSuchElementException
from selenium.webdriver.chrome.service import Service
from websockets import serve
from download_driver import auto_download_chromedrive
import log


class MySelenium(object):

    def __init__(self):
        self.basic_url = "https://www.baidu.com/"
        self.executable_path = r"./chromedriver_win32/chromedriver.exe"
        self.workPath = "./chromeWorkPath"
        self.browser = None

    @property
    def start_driver(self):
        try:
            option = webdriver.ChromeOptions()
            workpath = os.path.join(os.getcwd(), self.workPath)
            option.add_argument(f'--user-data-dir={workpath}')
            option.add_argument("profile-directory=Profile 1")
            workPath = os.path.abspath(self.executable_path)
            s = Service(workPath)
            option.add_experimental_option('excludeSwitches', ['enable-automation'])
            # option.add_argument('--headless')
            self.browser = webdriver.Chrome(service=s, options=option)
            self.browser.maximize_window()
        except SessionNotCreatedException:
            print("Chrome version unmatch. ")
            return None
        except Exception as ex:
            logger.exception("11")
            self.close()

        return 1

    def request_url(self, url):
        if self.browser:
            self.browser.get(url)

    def getReward(self):
        pass

    def close(self):
        if self.browser:
            self.browser.close()


if __name__ == '__main__':
    start_time = time.time()

    ms = MySelenium()
    if not ms.start_driver:
        chrome = auto_download_chromedrive()
        chrome.start()
        ms.start_driver
        ms.request_url(ms.basic_url)
        #ms.close()

    test_time = time.strftime("%H:%M:%S", time.gmtime(time.time() - start_time))
    print(test_time)
