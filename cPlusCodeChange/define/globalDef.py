#!python   
# -*- coding: utf-8 -*-
from enum import Enum

AnalysisRet = 'AnalysisRet'
ClassName = 'ClassName'
Name = 'name'
Funcs= 'funcs'
Attrs = 'attrs'
CLASSINFO = 'classInfo'
NAMELIST = 'nameList'
TYPE = 'type'
FROM = 'from'
HEADFILENAME = 'headFileName'
CLASS = 'class'
CONTENTBEGIN = 'ContentBegin'
CONTENTEND = 'ContentEnd'
FULLFILEPATH = 'fullFilePath'

CClassType = Enum('CClassType', ('base', 'manager', 'tools'))
FROMTYPE = Enum('FROMTYPE', ('add', 'old'))
Static = "static"

CPLUS = 'cplus'
