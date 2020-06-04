#!python   
# -*- coding: utf-8 -*-
from define import globalDef as DEF
from tool import toolsFunc as tool
import globalInfo as G

def analysis(filePath):
    if filePath.find('.h') == -1:
        return
        
    filePath = tool.os.path.abspath(filePath)
    content = tool.ReadFile(filePath)
    content = tool.delCplusNotes(content)
    
    _, tmpfilename = tool.os.path.split(filePath)

    pos = content.find('@interface')
    while pos > -1:
        endPos = content.find('@end', pos)
        clsCon = content[pos + len('@interface'):endPos]
        clsInfo = {}
        clsInfo[DEF.Funcs] = funcs(clsCon)
        clsInfo[DEF.PROP] = prop(clsCon)
        clsInfo[DEF.Name] = clsName(clsCon)
        clsInfo[DEF.FILEPATH] = tmpfilename
        clsInfo[DEF.FROM] = DEF.FROMTYPE.old
        clsInfo[DEF.ADDHEAD] = []
        clsInfo[DEF.IMPROTCLS] = []

        G.appendClsList(clsInfo)
        pos = content.find('@interface', endPos + len("@end"))

def headDef(con):
    key = '#ifndef'
    pos = con.find(key)
    if pos > -1:
        pend, pbegin = tool.matchSymbol(con, key + ' ', '\n')
        tmp = con[pbegin:pend]
        return tool.re.sub('[^A-Za-z]', '', tmp)

    return []

def funcs(con):
    ret = []

    strList = con.split('\n')
    bWaitCheck = False
    while strList:
        curStr = strList.pop().strip()
        if curStr:
            if bWaitCheck:
                if '}' in curStr:
                    bWaitCheck = False
                    continue
            if '{' in curStr:
                bWaitCheck = True
                continue
            elif '@' in curStr:
                continue
            elif '+' in curStr:
                pos1 = curStr.find(')')
                pos2 = curStr.find(':')
                if pos2 == -1:
                    pos2 = curStr.find(';')

                if pos1 > -1 and pos2 > -1 and pos2 > pos1:
                    tmp = curStr[pos1 + 1: pos2].strip()
                    funcInfo = {}
                    funcInfo[DEF.Name] = tmp
                    funcInfo[DEF.FROM] = DEF.FROMTYPE.old
                    funcInfo[DEF.FUNCRET] = curStr[:pos1 - 1].strip().replace(' ', '')
                    funcInfo[DEF.NameList] = []
                    funcInfo[DEF.EXTERN] = []
                    funcInfo[DEF.ScopeType] = DEF.SCOPE.Public

                    ret.append(funcInfo)
            elif '-' in curStr:
                pos1 = curStr.find(')')
                pos2 = curStr.find(':')

                if pos1 > -1 and pos2 > -1 and pos2 > pos1:
                    tmp = curStr[pos1 + 1: pos2].strip()
                    funcInfo = {}
                    funcInfo[DEF.Name] = tmp
                    funcInfo[DEF.FROM] = DEF.FROMTYPE.old
                    funcInfo[DEF.FUNCRET] = curStr[:pos1 - 1].strip().replace(' ', '')
                    funcInfo[DEF.NameList] = []
                    funcInfo[DEF.EXTERN] = []
                    funcInfo[DEF.ScopeType] = DEF.SCOPE.Private
                    
                    ret.append(funcInfo)
            else:
                pos1 = curStr.find(')')
                pos2 = curStr.find(';')

                if pos1 > -1 and pos2 > -1 and pos2 > pos1:
                    tmp = curStr[pos1 + 1: pos2].strip()
                    funcInfo = {}
                    funcInfo[DEF.Name] = tmp
                    funcInfo[DEF.FROM] = DEF.FROMTYPE.old
                    funcInfo[DEF.FUNCRET] = curStr[:pos1 - 1].strip().replace(' ', '')
                    funcInfo[DEF.NameList] = []
                    funcInfo[DEF.EXTERN] = []

                    ret.append(funcInfo)

    return ret

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
    key = "@property"
    pos = con.find(key)

    ret = []
    while pos > -1:
        pEnd = con.find(';', pos)
        pBegin = pos
        if pBegin > -1 and pEnd > -1:
            tmp = con[pBegin:pEnd]
            typePos = tool.findLastStr(tmp, ')')
            if typePos == -1:
                typePos = pBegin + len(key)
            else:
                typePos = typePos + 1
            spaceEndPos = tool.findLastStr(tmp, ' ')
            starEndPos = tool.findLastStr(tmp, '*')

            if spaceEndPos > -1:
                name = tmp[spaceEndPos + 1:]
            elif starEndPos > -1:
                if starEndPos > spaceEndPos:
                    name = tmp[starEndPos+1:]
            
            propInfo = {}
            propInfo[DEF.Name] = name
            propInfo[DEF.FROM] = DEF.FROMTYPE.old
            propInfo[DEF.TYPE] = tmp[typePos:spaceEndPos].strip().replace(' ', '')

            # ret.append(tool.re.sub('[^A-Za-z]', '', tmp))
            ret.append(propInfo)
            pos = con.find(key, pos + len(key))
        else:
            break
    return ret

def clsName(con):
    pos2 = con.find('\n')
    pos3 = con.find(':')

    if pos3 > pos2:
        return con[: pos2-1].strip()
    elif pos2 > pos3:
        return con[: pos3-1].strip()
    
    return ''