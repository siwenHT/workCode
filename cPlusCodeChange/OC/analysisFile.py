#!python   
# -*- coding: utf-8 -*-
from define import globalDef as DEF
from tool import toolsFunc as tool

def analysis(filePath):
    filePath = tool.os.path.abspath(filePath)
    content = tool.ReadFile(filePath)
    content = tool.delCplusNotes(content)
    ansRet = {}
    ansRet[DEF.HEADDEF] = headDef(content)
    ansRet[DEF.HEAD] = head(content)
    # ansRet[DEF.Funcs] = funcs(content)
    ansRet[DEF.PROP] = prop(content)

def headDef(con):
    key = '#ifndef'
    pos = con.find(key)
    if pos > -1:
        pend, pbegin = tool.matchSymbol(con, key + ' ', '\n')
        tmp = con[pbegin:pend]
        return tool.re.sub('[^A-Za-z]', '', tmp)

    return []

def funcs(con):
    key = '#ifndef'
    pos = con.find(key)
    if pos > -1:
        pend, pbegin = tool.matchSymbol(con, key + ' ', '\n')
        tmp = con[pbegin:pend]
        return tool.re.sub('[^A-Za-z]', '', tmp)

    return []

#头部解析 (应用文件解析)
def head(con):
    key = "#import"
    pos = con.find(key)

    ret = []
    while pos > -1:
        pEnd, pBegin = tool.matchSymbol(con, key , '\n')
        tmp = con[pBegin:pEnd]
        ret.append(tool.re.sub('[^A-Za-z]', '', tmp))
        pos = con.find(key, pos + len(key))
    return ret

#属性解析
def prop(con):
    key = "#property"
    pos = con.find(key)

    ret = []
    while pos > -1:
        pEnd, pBegin = tool.matchSymbol(con, key , '\n')
        tmp = con[pBegin:pEnd]
        spaceEndPos = tool.findLastStr(tmp, ' ')
        starEndPos = tool.findLastStr(tmp, '*')

        if spaceEndPos > -1:
            name = tmp[spaceEndPos + 1:]
        if starEndPos > -1:
            if starEndPos > spaceEndPos:
                name = tmp[starEndPos+1:]
        
        propInfo = {[DEF.Name]:name,}
        # ret.append(tool.re.sub('[^A-Za-z]', '', tmp))
        ret.append(propInfo)
        pos = con.find(key, pos + len(key))
    return ret
