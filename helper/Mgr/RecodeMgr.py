#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   RecodeMgr.py
@Time    :   2022/03/16 21:05:26
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib


class RecodeMgr():

    def __init__(self):
        self._data = {}
        pass

    def SetJobSucc(self, _typeName):
        ret = self.GetTypeInfo(_typeName)
        ret['succ'] += 1

    def SetJobFail(self, _typeName, res=''):
        ret = self.GetTypeInfo(_typeName)
        ret['fail'] += 1
        if res and res != '':
            ret['failRes'].append(res)

    def GetTypeInfo(self, _typeName):
        if not self._data.get(_typeName):
            self._data[_typeName] = {'succ': 0, 'fail': 0, "failRes": []}

        return self._data[_typeName]

    def ShowHtmlString(self):
        pass
