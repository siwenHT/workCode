#!python   
# -*- coding: utf-8 -*-
from tool   import toolsFunc as tool
from tool   import worldsDic
from define import globalDef as DEF
import createAttr as ATTR
import createClass as CLASS

lanType = 'cplus'

def create(params):
    DEF.totoalCPlusFuncNum()
    nameList = params[DEF.NAMELIST]
    funType  = params[DEF.TYPE]
    # ansInfo  = params[DEF.AnalysisRet]
    funcNameList = nameList[1]

    retInfo = {}

    #函数名
    clsInfo = params[DEF.CLASSINFO]
    funName = funcNameList.pop()
    while True:
        if CLASS.checkHasClass(clsInfo, funName):
            funName = funcNameList.pop()
        else:
            break
    retInfo[DEF.Name] = funName

    retInfo[DEF.TYPE] = funType
    retInfo[DEF.FROM] = DEF.FROMTYPE.add

    #返回值
    retVal = 'void'
    if tool.random.randint(1, 15) > 3:
        retVal = ATTR.getValueType()            
        retInfo['ret'] = ATTR.getValTypeRadomValue(retVal)
    retInfo['retType'] = retVal

    #参数
    retInfo['params'] = []
    retInfo['userName'] = []
    totalParamsNum = tool.random.randint(1, 4)
    for _ in range(totalParamsNum):
        paramsDic = {}
        paramType = ATTR.getValueType()
        paramName = ATTR.getValTypeRadomName(paramType)
        while True:
            pFind = False
            if paramName in retInfo['userName']:
                paramName = ATTR.getValTypeRadomName(paramType)
            else:
                break

        paramsDic['type'] = paramType
        paramsDic['name'] = paramName
        retInfo['userName'].append(paramName)
        retInfo['params'].append(paramsDic)

    return retInfo

#创建构造函数、析构函数
def createNormalFun(params, clsInfo, ty):
    clsName = clsInfo[DEF.Name]
    classInfo = clsInfo[DEF.CLASSINFO]

    retInfo = {}
    retInfo['retType'] = ''
    retInfo['ret'] = ''
    retInfo['createFunc'] = 1
    if ty == 1:
        retInfo[DEF.Name] = clsName
    elif ty == 2:
        retInfo[DEF.Name] = '~' + clsName
    retInfo['params'] = []
    retInfo['userName'] = []

    return retInfo


def randomFuncContent(clsInfo, funcInfo, clsName):
    retStr = ''
    totalAttrNum = len(clsInfo[DEF.Attrs])
    pFind = False
    if tool.random.randint(1, 3) == 2 and totalAttrNum > 0 and DEF.Static not in funcInfo:
        for idx in range(totalAttrNum):
            attrInfo = clsInfo[DEF.Attrs][idx]
            if DEF.FROM in attrInfo and attrInfo[DEF.FROM] == DEF.FROMTYPE.add:
                pFind = True
                break
        if pFind:
            attrIdx = tool.random.randint(idx, totalAttrNum - 1)
            attrInfo = clsInfo[DEF.Attrs][attrIdx]

            retStr += '\t' + attrInfo[DEF.Name] + ' = ' + ATTR.getValTypeRadomValue(attrInfo[DEF.TYPE]) + ';\n'

    if not pFind:
        nameList = funcInfo['userName']
        num = tool.random.randint(1, 3)
        for i in range(num):
            isSetPar = False
            tmpType = ''
            parVal = ''
            # 如果随机出的内容比参数少, 需要把参数用上
            if i < len(funcInfo['params']):
                tmpPar = funcInfo['params'][i]
                tmpType = tmpPar[DEF.TYPE]
                parVal = tmpPar[DEF.Name]
                isSetPar = True
            else:
                tmpType = ATTR.getValueType()
            
            tmpName = ATTR.getValTypeRadomName(tmpType)
            while True:
                if tmpName in nameList:
                    tmpName = ATTR.getValTypeRadomName(tmpType)
                else:
                    break
            
            if isSetPar:
                tmpVal = '\t' + tmpType + ' ' + tmpName + ' = ' + parVal
                op = ATTR.getRandomValTypeOp(tmpType)
                if op:
                    op = ' ' + op + ' ' + ATTR.getValTypeRadomValue(tmpType)
                
                retStr += tmpVal + op + ";\n" 
            else:
                tmpVal = ATTR.getFuncValTypeTmp(tmpType)
                retStr += '\t' + tmpType + ' ' + tmpName + ' = ' + tmpVal + ';\n'
            nameList.append(tmpName)

    #在添加的函数中添加无用注释
    if tool.random.randint(1, 2) == 2:
        retStr += generateStrForIos(clsInfo, funcInfo, clsName)
    
    if funcInfo['retType'] != 'void' and funcInfo['retType'] != '':
        retStr += '\treturn ' + funcInfo['ret'] + ';\n'
    return retStr

#在函数中添加字符串,混淆字符比较的比例
def generateStrForIos(clsInfo, funcInfo, clsName):
    #1.直接使用
    ret = ''
    cfg = ['done', 'finish', 'ok', 'doing', 'begin', 'end', 'checking', 'calling', 'called']
    cfg1 = ['Ok', 'Error', 'need Check', 'is woring', 'careful', 'is error?', 'is ok?']

    num = tool.random.randint(1, 2)
    nameList = funcInfo['userName']
    tmpName = ATTR.getValTypeRadomName()
    while True:
        if tmpName in nameList:
            tmpName = ATTR.getValTypeRadomName()
        else:
            break

    if num == 1:
        ret += '\tstd::string {3} = \"{0} [{1}:{2}] {4}!\";\n'.format('function ', clsName, funcInfo[DEF.Name], tmpName, tool.random.choice(cfg))
        ret += '\t{0}.append(\"{1}\");\n'.format(tmpName, worldsDic.getTmpName(1))
    elif num == 2:
        num1 = tool.random.randint(1, 3)
        if num1 == 1:
            ret += '\t bool {0} = false;\n'.format(tmpName)
            ret += '\tif({0})\n'.format(tmpName)
        elif num1 == 2:
            tmpNum = tool.random.randint(1, 80000)
            ret += '\t int {0} = {1};\n'.format(tmpName, str(tmpNum))
            ret += '\tif({0} == {1})\n'.format(tmpName, str(tmpNum))
        elif num1 == 3:
            tmpNum = tool.random.randint(1, 80000)
            ret += '\t std::string {0} = \"{1}\";\n'.format(tmpName, str(tmpNum))
            ret += '\tif({0} == \"{1}\")\n'.format(tmpName, str(tmpNum))

        ret += '\t{\n'
        ret += '\t\tstd::string {3} = \"{0} [{1}:{2}] {4}!\";\n'.format('function ', clsName, funcInfo[DEF.Name], tmpName, tool.random.choice(cfg))
        ret += '\t}\n'

        ret += '\telse\n'
        ret += '\t{\n'
        params = funcInfo['params']
        ret += '\t\tstd::string {0};\n'.format(tmpName)

        key = tool.random.choice(cfg1)
        i = 0
        for info in params:
            i += 1
            ret += '\t\t{0}.append(\"{4} arguments {1} {2} {3}!\");\n'.format(tmpName, str(i), info[DEF.Name], key, funcInfo[DEF.Name])
        ret += '\t}\n'

    return ret

def getHeadFileStr(funcInfo):
    tmpStr = ''
    if DEF.Static in funcInfo:
        tmpStr = 'static'
    tmpStr += '\t' + funcInfo['retType']

    if 'createFunc' not in funcInfo:
        tmpStr += ' '
    tmpStr += funcInfo[DEF.Name]
    
    paramStr = ''
    for tmpParam in funcInfo['params']:
        paramStr += tmpParam[DEF.TYPE] + ' ' + tmpParam[DEF.Name] + ','
    
    tmpStr += '(' + paramStr[:-1] + '); \n'
    
    tmpStr = tool.unicodeToAscii(tmpStr)
    # tmpStr = worldsDic.unicodedata.normalize('NFKD',tmpStr).encode('ascii','ignore')
    
    return tmpStr

def getFuncRealize(funcInfo, classInfo, isInHead = False):
    clsName = classInfo[DEF.Name]
    tmpStr =  funcInfo['retType']

    if 'createFunc' not in funcInfo:
        tmpStr += ' '

    if isInHead:
        if DEF.Static in funcInfo:
            tmpStr = 'static ' + tmpStr
        tmpStr +=  funcInfo[DEF.Name]
    else:
        tmpStr +=  clsName + '::' + funcInfo[DEF.Name]

    
    paramStr = ''
    for tmpParam in funcInfo['params']:
        paramStr += tmpParam[DEF.TYPE] + ' ' + tmpParam[DEF.Name] + ','
    
    tmpStr += '(' + paramStr[:-1] + ')\n'
    tmpStr += '{\n'+ randomFuncContent(classInfo[DEF.CLASSINFO], funcInfo, classInfo[DEF.Name]) + '}\n'
    
    tmpStr = tool.unicodeToAscii(tmpStr)
    # tmpStr = worldsDic.unicodedata.normalize('NFKD',tmpStr).encode('ascii','ignore')
    return tmpStr

def getFunCallingLine(funcInfo):
    paramStr = ''
    for tmpParam in funcInfo['params']:
        paramStr += ATTR.getValTypeRadomValue(tmpParam[DEF.TYPE]) + ','
    return funcInfo[DEF.Name] + '(' + paramStr[:-1] + ')'