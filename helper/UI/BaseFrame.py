#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   BaseFrame.py
@Time    :   2022/02/17 15:06:13
@Author  :   hongtao
@Version :   1.0
@Contact :   hongtao353@gmail.com
'''

# here put the import lib
import tkinter as tk


class BaseFrame(tk.Frame):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)

    def CreateButton(self, *args, **kwargs):
        bt_1 = tk.Button(self, *args, **kwargs)
        return bt_1

    def DefineLayout(self, obj, cols=1, rows=1):

        def method(trg, col, row):
            for c in range(cols):
                trg.columnconfigure(c, weight=1)
            for r in range(rows):
                trg.rowconfigure(r, weight=1)

        if type(obj) == list:
            [method(trg, cols, rows) for trg in obj]
        else:
            trg = obj
            method(trg, cols, rows)
