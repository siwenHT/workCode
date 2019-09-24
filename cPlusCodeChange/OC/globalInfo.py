#!python   
# -*- coding: utf-8 -*-

# 全局类列表、全局函数列表 便于查询 
# 结构目前不太确定，后续持续变化
# 不再一个类一个类的添加，变成像写代码一样, 随机写入, 中途保存调用记录、更新记录  用最新的记录创建最新的内容, 是代码库丰富起来

#添加函数到函数列表中 (结构为双向结构)
# funcInfo： {}
# [DEF.Name]:string, 
# ['params']:{}
#           {[DEF.Type]:string, [DEF.Name]:string}
#           {[DEF.Type]:string, [DEF.Name]:string}
#           . . .
# ['parent']:id
# ['callInfo']: {}
#           [DEF.CLASSINFO]:id, [DEF.Funcs]:id}


# clsInfo: {}
# ['exten']
# [DEF.Name]:string,
# [DEF.Funcs]:[]
# ['callInfo']:{}
#           [DEF.CLASSINFO]:id, [DEF.Funcs]:id}
#           [DEF.CLASSINFO]:id, [DEF.Funcs]:id}
#           . . .
# [DEF.prop]:{}
#           {[DEF.Type]:string, [DEF.Name]:string}
#           {[DEF.Type]:string, [DEF.Name]:string}
#           . . .

from tool import toolsFunc as tool
from tool import worldsDic
from define import globalDef as DEF

funcsList = []
clsList   = []
count = 1

clsName = []
funcName = []
attrName = []

def getInstanceID():
    global count
    count = count + 1
    return count

def appendFunList(funInfo):
    tmpId = getInstanceID()
    funInfo[tmpId] = funInfo
    funInfo[DEF.ID] = tmpId

def appendClsList(clsInfo):
    tmpId = getInstanceID()
    clsList[tmpId] = clsInfo
    clsInfo[DEF.ID] = tmpId

def getClsName():
    global clsName
    if not clsName:
        clsName = worldsDic.randomWorldS(900, 'ocClass')
    return clsName.pop()

def getFuncName():
    global funcName
    if not funcName:
        funcName = worldsDic.randomWorldS(900, 'ocFunc')
    return funcName.pop()    

def getAttrName():
    global attrName
    if not attrName:
        attrName = worldsDic.randomWorldS(900, 'ocAttr')
    return attrName.pop()