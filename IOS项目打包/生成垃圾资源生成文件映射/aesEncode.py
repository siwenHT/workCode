#!python   
# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from Crypto.Cipher import AES
from binascii import b2a_hex,a2b_hex

class MyCrypt():
    def __init__(self, key):
        self.key = key.encode('utf-8')
        self.mode = AES.MODE_CBC
    def myencrypt(self, text):
        text = text.encode('utf-8')
        length = 16
        count = len(text)
        # print count
        if count < length:
            add = length - count
            text= text + ('\0' * add).encode('utf-8')
        elif count > length:
            add = (length -(count % length))
            text= text + ('\0' * add).encode('utf-8')
        # print len(text)
        cryptor = AES.new(self.key, self.mode, b'0000000000000000')
        self.ciphertext = cryptor.encrypt(text)
        return b2a_hex(self.ciphertext)

    def mydecrypt(self, text):
        cryptor = AES.new(self.key, self.mode, b'0000000000000000')
        plain_text = cryptor.decrypt(a2b_hex(text))
        return plain_text.rstrip('\0')
            
# if __name__ == '__main__':
#     mycrypt = MyCrypt('abcdefghjklmnopq')
#     e = mycrypt.myencrypt('hello,world!')
#     d = mycrypt.mydecrypt(e)