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

returnType = [
        'int',
        'short',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'long',
        'bool',
        'float',
        'char',
        'unsigned short',
        'void',
        'double'
    ]

def getFunRetType():
    return tool.random.choice(returnType)

attrType = [
        'int',
        'short',
        'std::string',
        'long',
        'bool',
        'float',
        'char',
        'unsigned short',
        'double'
    ]

def getAttrRetType():
    return tool.random.choice(attrType)

intCfg = [
    'long',
    'float',
    'short',
    'int',
    'unsigned short',
    'double'
]
def allInt(ty):
    return (ty in intCfg)

normalValueType = [
        'int',
        'short',
        'std::string',
        'std::string&',
        'std::string&',
        'std::string&',
        'std::string&',
        'std::string&',
        'std::string&',
        'std::string&',
        'std::string&',
        'std::string&',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'std::string',
        'long',
        'bool',
        'float',
        'char',
        'unsigned short',
        'double'
    ]
def getValueType():
    return tool.random.choice(normalValueType)

def getValTypeRadomValue(valueType):
    if valueType in ['int', 'short', 'long', 'unsigned short']:
        return str(tool.random.randint(1, 1000))
    if valueType == 'bool':
        return tool.random.randint(1,2) == 1 and 'true' or 'false'
    if valueType == 'std::string' or valueType == 'std::string&':
        DEF.totoalCPlusStrNum()
        if tool.random.randint(1, 5) > 1:
            return '\"' + worldsDic.getOneWorld() + '\"'
        else:
            return '\"' + tool.getRandomUpDown(tool.random.randint(4, 12)) + '\"'
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
    if valueType == 'void':
        return ''
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
    DEF.totoalCPlusStrNum()
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
    tmpAttr[DEF.TYPE] = getAttrRetType()
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

#根据类型生成类型扩展代码
def getVal_ex(ty, paramName):
    val = ''
    if ty == 'std::string' or ty == "std::string&": 
        ch = tool.random.randint(1, 2)
        if ch == 1:
            val = '{0} += {1};\n'.format(paramName, getValTypeRadomValue(ty))
        else:
            val = '{0}.append({1});\n'.format(paramName, getValTypeRadomValue(ty))
    elif allInt(ty):
        val = '{0} = {1} {3} {2};\n'.format(paramName, paramName, tool.random.randint(50, 3000), tool.random.choice(["+", "-", "*"]))

    return val

def conditionByType(ty, name):
    val = ''
    if ty == "bool":
        val = name
    elif allInt(ty):
        val = '(int) {0} == {1}'.format(name, tool.random.randint(1, 100))
    elif ty == "std::string" or ty == "std::string&":
        val = '{0}.empty()'.format(name)
        val1 = '!{0}.empty()'.format(name)
        val3 = '{0}.size() == {1}'.format(name, tool.random.randint(1, 20))
        val = tool.random.choice([val, val1, val3])
    elif ty == 'char':
        val = '{0} == \'{1}\''.format(name, chr(tool.random.randint(65, 90)))

    return val

#根据类型生成类型合并变量
def combineParam(ty, paramName, paramName1):
    val = ''
    if ty == 'std::string'  or ty == 'std::string&': 
        val1 = '{0} += {1};\n'.format(paramName, paramName1)
        val2 = '{0} = {0} + {1};\n'.format(paramName, paramName1)
        val3 = '{0} = {0}.append({1});\n'.format(paramName, paramName1)

        val = tool.random.choice([val1, val2, val3])
    elif allInt(ty):
        val = '{0} = {1} {3} {2};\n'.format(paramName, paramName, paramName1, tool.random.choice(['+', '-', '*']))
    elif ty == 'bool':
        val = '{0} = {1};\n'.format(paramName, paramName1)
    else:
        print("ATTR.combineParam not deal ", ty)

    return val