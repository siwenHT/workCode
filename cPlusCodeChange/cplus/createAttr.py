#!python   
# -*- coding: utf-8 -*-
from tool   import toolsFunc as tool
from tool   import worldsDic
from define import globalDef as DEF
import createClass as CLASS

additional_attrName = []

def initData():
    a = 1

def addExAttr(tyName, fileName):
    additional_attrName.append({DEF.Name:tyName, DEF.HEADFILENAME:fileName})

def getExAttr():
    if additional_attrName:
        totalLen = len(additional_attrName)
        num = tool.random.randint(1, totalLen)
        return additional_attrName[num -1]
    return getValueType()

def getValueType():
    normalValueType = [
        'int',
        'short',
        'std::string',
        'long',
        'bool',
        'float',
        'char',
        'unsigned short',
        'void *',
        'double'
    ]

    return tool.random.choice(normalValueType)

def getValTypeRadomValue(valueType):
    if valueType in ['int', 'short', 'long', 'unsigned short']:
        return str(tool.random.randint(1, 1000))
    if valueType == 'bool':
        return tool.random.randint(1,2) == 1 and 'true' or 'false'
    if valueType == 'std::string':
        return '\"' + worldsDic.getOneWorld() + '\"'
    if valueType in ['double', 'float']:
        val = str(tool.random.randint(5, 1000)) + '.' + str(tool.random.randint(0, 20))
        if valueType == 'float':
            return val + 'f'
        return val
    if valueType == 'char':
        a,b = 65, 90
        num = tool.random.randint(1, 3)
        if num == 1:
            a, b = 97, 122
        elif num == 2:
            a, b = 49, 57

        return '\'' + chr(tool.random.randint(a, b)) + '\''
    if valueType == 'void *':
        return 'nullptr'
    return '\"' + str(tool.random.randint(1, 40)) + '\"'

def getRandomValTypeOp(valueType):
    normalValueType = {
        'int':['+', "-", '*', '/', '%'],
        'short':['+', "-", '*', '/', '%'],
        'std::string':[],
        'long':['+', "-", '*', '/', '%'],
        'bool':[],
        'float':['+', "-", '*', ],
        'char':[],
        'unsigned short':['+', "-", '*', '/', '%'],
        'void *':[],
        'double':['+', "-", '*', ],
    }

    if len(normalValueType[valueType]) > 0:
        return tool.random.choice(normalValueType[valueType])
    else:
        return ''

def getFuncValTypeTmp(valueType):
    preVal = getValTypeRadomValue(valueType)
    op = getRandomValTypeOp(valueType)
    if op:
        return preVal + ' ' + op + ' ' + getValTypeRadomValue(valueType)
    else:
        return preVal

def getValTypeRadomName(valueType = None):
    return worldsDic.getOneWorld()

def getAttrName(num1, num2):
    return 'm_' + worldsDic.getTmpName(num1, num2)

def create(params):
    nameList = params[DEF.NAMELIST]
    # funType  = params[DEF.TYPE]
    # ansInfo  = params[DEF.AnalysisRet]
    attrNameList = nameList[1]
    clsInfo = params[DEF.CLASSINFO]

    tmpAttr = {}
    tmpAttr[DEF.TYPE] = getValueType()
    tmpAttr[DEF.Name] = attrNameList.pop()
    while True:
        if CLASS.checkClassHasAttr(clsInfo, tmpAttr[DEF.Name]) \
        or CLASS.checkClassHasAttr(clsInfo, 'm_' + tmpAttr[DEF.Name]):
            tmpAttr[DEF.Name] = attrNameList.pop()
        else:
            break

    tmpAttr['limit'] = 'private'
    tmpAttr[DEF.FROM] = DEF.FROMTYPE.add

    if tmpAttr[DEF.Name].find('m_') == -1:
        tmpAttr[DEF.Name] = 'm_' + tmpAttr[DEF.Name]

    return tmpAttr

def getHeadFileStr(attrInfo):
    tmpStr = '\t' + attrInfo[DEF.TYPE] + ' ' + attrInfo[DEF.Name] + ';\n'
    return tmpStr