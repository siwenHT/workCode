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
import smtplib
from Until.MyLog import Log
from Until.WinSysytem import Win


class Email(object):

    def __init__(self):
        self.mail_host = 'smtp.163.com'
        self.mail_user = Win.MailUser()
        self.mail_pass = Win.MailPass()

        self.sender = Win.MailSender()
        self.receivers = Win.MailReceivers()

    def SendText(self, content):
        #设置email信息
        #邮件内容设置
        message = MIMEText(content, 'plain', 'utf-8')
        message['Subject'] = 'title'
        message['From'] = self.sender
        message['To'] = self.receivers[0]

        self.SendMsg(message)

    def SendMsg(self, msg):
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
        except smtplib.SMTPException as e:
            Log.exception('error')  #打印错误


GEmail = Email()