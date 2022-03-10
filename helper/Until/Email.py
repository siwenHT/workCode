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
from WinSysytem import Win


class Email(object):

    def __init__(self):
        self.mail_host = 'smtp.163.com'
        self.mail_user = Win.MailUser()
        self.mail_pass = Win.MailPass()

        #邮件发送方邮箱地址
        self.sender = Win.MailSender()
        #邮件接受方邮箱地址，注意需要[]包裹，这意味着你可以写多个邮件地址群发
        self.receivers = Win.MailReceivers()


#设置email信息
#邮件内容设置
message = MIMEText('content', 'plain', 'utf-8')
#邮件主题
message['Subject'] = 'title'
#发送方信息
message['From'] = sender
#接受方信息
message['To'] = receivers[0]

#登录并发送邮件
try:
    smtpObj = smtplib.SMTP()
    #连接到服务器
    smtpObj.connect(mail_host, 25)
    #登录到服务器
    smtpObj.login(mail_user, mail_pass)
    #发送
    smtpObj.sendmail(sender, receivers, message.as_string())
    #退出
    smtpObj.quit()
    print('success')
except smtplib.SMTPException as e:
    print('error', e)  #打印错误

GEmail = Email()