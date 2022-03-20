#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   Singleton.py
@Time    :   2022/03/20 21:06:31
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib
import threading


class Singleton(object):
    _instance_lock = threading.Lock()

    def __init__(self):
        pass

    def __new__(cls, *args, **kwargs):
        if not hasattr(Singleton, "_instance"):
            with Singleton._instance_lock:
                if not hasattr(Singleton, "_instance"):
                    Singleton._instance = object.__new__(cls)
        return Singleton._instance


# obj1 = Singleton()
# obj2 = Singleton()
# print(obj1, obj2)

# class classA(Singleton):

#     def __init__(self):
#         super().__init__()

# def task(arg):
#     obj = classA()
#     print(obj)

# for i in range(10):
#     t = threading.Thread(target=task, args=[
#         i,
#     ])
#     t.start()