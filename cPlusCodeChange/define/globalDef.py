#!python   
# -*- coding: utf-8 -*-
from enum import Enum

AnalysisRet = 'AnalysisRet'
ClassName = 'ClassName'
Name = 'name'
Name1 = 'name1'
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
ID = 'Id'
HEAD = 'head'
ADDHEAD = 'addHead'
PROP    = 'property'
HEADDEF = 'headDef'
FILEPATH = 'filePath'
CRTTYPE = 'createTypeFor'
IMPROTCLS = 'importClass'
FUNCRET = 'funcRet'
PARAMS = 'params'
CONTENT = "Content"
CALLFUNCLIST = "CallFuncList"
NameList = "nameList"
ISINCLUDE = "isIncluded"

EXTERN = "extern"

SCOPE = Enum('SCOPE', ('Public', 'Private'))
ScopeType = 'ScopeType'

CLSTYPE = Enum('clsType', ('tool', 'params', 'manage'))
FUNTYPE = Enum('funcType', ('inner', 'outer'))

TCplusNum = 0
TCplusStrNum = 0

def totoalCPlusFuncNum():
    global TCplusNum
    TCplusNum += 1

def totoalCPlusStrNum():
    global TCplusStrNum
    TCplusStrNum += 1