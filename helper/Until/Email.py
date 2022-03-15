#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   email.py
@Time    :   2022/03/10 18:37:36
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib
from email.mime.text import MIMEText
from random import randint
import smtplib
from Event.EventMsgHandler import GEventHandler
from Event.EventType import EventType
from Until.MyLog import Log
from Until.WinSysytem import Win
from Until import ToolsFunc as Tool


class Email(object):

    def __init__(self):
        self.emailCount = 0
        self.InitCfg()
        self.MsgRegeist()

    def InitCfg(self):
        self.mail_host = 'smtp.163.com'
        self.mail_user = Win.MailUser()
        self.mail_pass = Win.MailPass()

        self.sender = Win.MailSender()
        self.receivers = Win.MailReceivers()

    def SendMsg(self, title, content):
        self.SendText(content, title)

    def SendText(self, content, title='title'):
        randomVal = ""
        for i in range(randint(10, 20)):
            randomVal = randomVal + str(randint(0, 9))

        content = f"{Tool.showTime()}  {content} ... {randomVal}  ,邮件上限:{self.emailCount}"
        message = MIMEText(content, 'plain', 'utf-8')
        message['Subject'] = title
        message['From'] = self.sender
        message['To'] = self.receivers[0]

        self.Send(message)

    def Send(self, msg):

        if self.emailCount > 50:
            Log.error("邮件达到上限了")
            return

        #登录并发送邮件
        try:
            smtpObj = smtplib.SMTP()
            #连接到服务器
            smtpObj.connect(self.mail_host, 25)
            #登录到服务器
            smtpObj.login(self.mail_user, self.mail_pass)
            #发送
            smtpObj.sendmail(self.sender, self.receivers, msg.as_string())
            #退出
            smtpObj.quit()
            Log.info('success')
            self.emailCount = self.emailCount + 1
        except smtplib.SMTPException as e:
            Log.exception('error')  #打印错误

    def MsgRegeist(self):

        def msgHandler(eventType: EventType):
            if eventType == EventType.reload_config:
                self.InitCfg()

        GEventHandler.RegedistEvent(EventType.reload_config, msgHandler)


GEmail = Email()