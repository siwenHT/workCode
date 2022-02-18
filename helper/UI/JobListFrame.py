#!/usr/bin/env python
# -*- encoding: utf-8 -*-
'''
@File    :   JobListFrame.py
@Time    :   2022/02/18 08:45:39
@Author  :   hongtao
@Contact :   hongtao353@gmail.com
@Desc    :   None
'''

# here put the import lib

from UI.BaseFrame import BaseFrame
import Global
from JobManager import JobManager

class JobListFrame(BaseFrame):

    def __init__(self, *args, **kwargs) -> None:
        super().__init__(*args, **kwargs)

        self.InitUI()

    def InitUI(self):
        jobMG:JobManager = Global.GetJobMG()
        self._jobList = jobMG.
        pass
