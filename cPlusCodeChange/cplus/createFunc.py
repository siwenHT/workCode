#!python   
# -*- coding: utf-8 -*-
from tool   import toolsFunc as tool
from tool   import worldsDic
from define import globalDef as DEF
from OC     import createFile as ocCreateFile
import createAttr as ATTR
import createClass as CLASS

lanType = 'cplus'

def create(params):
    DEF.totoalCPlusFuncNum()

    nameList = params[DEF.NAMELIST]
    clsInfo  = params[DEF.CLASSINFO]
    funcType = params[DEF.CRTTYPE]

    clsType = clsInfo[DEF.CRTTYPE]
    funcNameList = nameList[1]

    funcInfo = {}
    funcInfo[DEF.PARAMS] = []
    funcInfo[DEF.NameList] = []
    funcInfo[DEF.FROM] = DEF.FROMTYPE.add
    funcInfo[DEF.CONTENT] = ''

    #函数名
    while True:
        funName = funcNameList.pop()
        if not CLASS.checkClassHasFun(clsInfo, funName):
            break

    funcInfo[DEF.Name] = funName
    funcInfo[DEF.CRTTYPE] = funcType
    
    #返回值
    while True:
        retVal = ATTR.getFunRetType()
        if funcType == DEF.FUNTYPE.outer and retVal == 'void':
            continue
        break
    
    funcInfo[DEF.FUNCRET] = retVal

    #参数
    totalParamsNum = tool.random.randint(1, 5)
    for _ in range(totalParamsNum):
        paramsDic = {}
        paramsDic[DEF.TYPE] = ATTR.getValueType()
        paramsDic[DEF.Name] = getNoRepeatName(funcInfo)
        paramsDic[DEF.FROM] = DEF.FROMTYPE.add
        funcInfo[DEF.PARAMS].append(paramsDic)

    return funcInfo

def getNoRepeatName(info):
    while True:
        tmpName = ATTR.getValTypeRadomName()
        if tmpName not in info[DEF.NameList]:
            info[DEF.NameList].append(tmpName)
            return tmpName

    return ATTR.getValTypeRadomName()

def FillFunc(funcInfo, clsInfo, classList):
    if funcInfo[DEF.CRTTYPE] == DEF.FUNTYPE.outer:
        #调用内部函数
        funContent, retName = getInnerFunc(funcInfo, clsInfo, classList)
    else:
        #生成字符串就好了
        funContent, retName = getFunContent(funcInfo, clsInfo, classList)

    retStr = ''
    if retName:
        retStr = '\treturn ' + retName + ';\n'

    funcInfo[DEF.CONTENT] = funContent + retStr

def FillFunc_ex(funcInfo, classList, clsInfo):
    retType = funcInfo[DEF.FUNCRET]

    funContent = ''
    callNum = tool.random.randint(1, 3)
    for i in range(callNum):
        callClsInfo = None
        
        level2List = chooseCls(classList, DEF.CRTTYPE, DEF.CLSTYPE.level2)        
        if level2List:
            funcParams = funcInfo.get(DEF.PARAMS)
            if funcParams and len(funcParams) > i:
                param = funcParams[i]
                paramType = param[DEF.TYPE]
                ifStr = '\tif({0})\n\t{1}\n'.format(ATTR.conditionByType(paramType, param[DEF.Name]), "{")

                callClsInfo = ocCreateFile.chooseOne(level2List, DEF.ISINCLUDE, 0)
                if callClsInfo:
                    fun = ocCreateFile.chooseOne(callClsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.outer, False)
                    if fun:
                        funContent += ifStr
                        con, retName= callFuncStr_ex(fun, callClsInfo, funcInfo)
                        con = con.replace('\t', '\t\t')
                        funContent += con
                        funContent += '\t\tif({0})\n\t\t{1}\n'.format(ATTR.conditionByType(fun[DEF.FUNCRET], retName), "{")
                        funContent += '\t\t\t{0}\n{1}\n'.format(getLogContent([fun[DEF.Name], ATTR.getValTypeRadomName(), retName], funcInfo), '\t\t}')
                        
                        funContent += '\t}\n'
                        callClsInfo[DEF.ISINCLUDE] = 1
                        clsInfo[DEF.ADDHEAD].append(callClsInfo[DEF.Name])
            else:
                callClsInfo = ocCreateFile.chooseOne(level2List, DEF.ISINCLUDE, 0)
                if callClsInfo:
                    fun = ocCreateFile.chooseOne(callClsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.outer, False)
                    if fun:
                        con, retName= callFuncStr_ex(fun, callClsInfo, funcInfo, clsInfo)
                        funContent += con
                        funContent += '\tif({0})\n\t{1}\n'.format(ATTR.conditionByType(fun[DEF.FUNCRET], retName), "{")
                        funContent += '\t\t{0}\n{1}\n'.format(getLogContent([fun[DEF.Name], ATTR.getValTypeRadomName(), retName], funcInfo), "\t}")
                        
                        callClsInfo[DEF.ISINCLUDE] = 1
                        clsInfo[DEF.ADDHEAD].append(callClsInfo[DEF.Name])

    retType = funcInfo[DEF.FUNCRET]
    con, retName = getTypeLine(retType, funcInfo)
    funContent += con

    retStr = ''
    if retName:
        retStr = '\treturn ' + retName + ';\n'    

    funcInfo[DEF.CONTENT] = funContent + retStr

# 内部函数
def getFunContent(funcInfo, clsInfo, classList):
    #定义两个变量
    funcContent = ''

    def getFuncParamType(pType):
        param = ocCreateFile.chooseOne(funcInfo[DEF.PARAMS], DEF.TYPE, pType, False)
        if param:
            return param[DEF.Name]
        return ATTR.getValTypeRadomValue(pType)

    # 随便找一个属性
    propInfo = tool.random.choice(clsInfo[DEF.Attrs])
    propTpye = propInfo[DEF.TYPE]
    propName = propInfo[DEF.Name]

    conlist = []
    #根据参数构建函数体
    for param in funcInfo[DEF.PARAMS]:
        paramType = param[DEF.TYPE]
        paramName = param[DEF.Name]
        flg = tool.random.randint(1, 3)
        if paramType == 'std::string' or paramType == 'std::string&':
            flg = 1
        elif paramType == 'bool':
            flg = 1

        for _ in range(flg):
            val =  chr(tool.random.randint(65, 90))
            partCon = '({0})\n\t{1}\n'.format(ATTR.conditionByType(paramType, paramName), "{")
            val = getFuncParamType(propTpye)
            partCon += '\t\t{0} = {1};\n'.format(propName, val)
            rand = tool.random.randint(0, 4)
            for _ in range(rand):
                val = ATTR.getVal_ex(propTpye, propName)
                if val:
                    partCon += '\t\t' + val

            con1 = []
            con1.append(paramName)
            rand = tool.random.randint(1, 8)
            for _ in range(rand):
                con1.append(ATTR.getValTypeRadomValue('std::string'))

            partCon += '\t\t{0}\n'.format(getLogContent(con1, funcInfo))
            partCon += '\t}\n'

            conlist.append(partCon)        

    tool.random.shuffle(conlist)
    first = True
    for val in conlist:
        ifelse = 'if' if (first) else 'else if'
        funcContent += '\t' + ifelse + val
        first = False

    #调用第三方类
    flg = tool.random.randint(1, 2)
    if flg == 2 and clsInfo[DEF.CRTTYPE] == DEF.CLSTYPE.level2:
        level1List = chooseCls(classList, DEF.CRTTYPE, DEF.CLSTYPE.level1)
        callClsInfo = ocCreateFile.chooseOne(level1List, DEF.ISINCLUDE, 0)

        fun = ocCreateFile.chooseOne(callClsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.outer, False)
        if fun:
            callClsFuncStr, retName = callFuncStr_ex(fun, callClsInfo, funcInfo, clsInfo)
            funcContent += callClsFuncStr
            if fun[DEF.FUNCRET] == propTpye:
                funcContent += '\t' + ATTR.combineParam(propTpye, propName, retName)
            funcContent += '\tif({0})\n\t{1}\n'.format(ATTR.conditionByType(fun[DEF.FUNCRET], retName), "{")
            funcContent += '\t\t{0}\n{1}\n'.format(getLogContent([fun[DEF.Name], 'is back', retName], funcInfo), '\t}')

            # callFlg = getCallFuncFlg(callClsInfo, fun)
            # funcInfo[DEF.CALLFUNCLIST].append(callFlg)
            callClsInfo[DEF.ISINCLUDE] = 1
            clsInfo[DEF.ADDHEAD].append(callClsInfo[DEF.Name])

    #对属性进行log
    flg = tool.random.randint(1, 2)
    if flg == 1:
        for i in range(tool.random.randint(1, 3)):
            conditionKey = 'if' if (i == 0) else 'else if'
            funcContent += '\t{2}({0})\n\t{1}\n'.format(ATTR.conditionByType(propTpye, propName), "{", conditionKey)
            
            con1 = []
            con1.append(propName)
            rand = tool.random.randint(0, 6)
            for _ in range(rand):
                con1.append(ATTR.getValTypeRadomValue('std::string'))

            funcContent += '\t\t{0}\n{1}\n'.format(getLogContent(con1, funcInfo), '\t}')

    retName = ''
    retType = funcInfo[DEF.FUNCRET]
    if retType != "void":
        if propTpye == retType:
            retName = propName
        else:
            con, retName = getTypeLine(retType, funcInfo)
            funcContent += con

    return funcContent, retName

#外部函数
def getInnerFunc(funcInfo, clsInfo, classList):
    retCon = ''
    retName = ''

    funList = ocCreateFile.chooseList(clsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.inner)
    if funList:
        if funcInfo[DEF.PARAMS]:
            for param in funcInfo[DEF.PARAMS]:
                paramType = param[DEF.TYPE]
                paramName = param[DEF.Name]
                ifStr = '\tif({0})\n\t{1}\n'.format(ATTR.conditionByType(paramType, paramName), '{')

                func = ocCreateFile.chooseOne(funList, DEF.ISINCLUDE, 0)
                if func:
                    retCon += ifStr
                    if func[DEF.FUNCRET] != 'void':
                        tmpRetName = getNoRepeatName(funcInfo)
                        retCon += '\t\t{1} {2} = {0};\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo), func[DEF.FUNCRET], tmpRetName)
                        retCon += '\t\tif({0})\n\t\t{1}\n'.format(ATTR.conditionByType(func[DEF.FUNCRET], tmpRetName), "{")
                        retCon += '\t\t\t{0}\n{1}\n'.format(getLogContent([func[DEF.Name], ATTR.getValTypeRadomName(), tmpRetName], funcInfo), '\t\t}')
                    else:
                        retCon += '\t\t{0};\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo))
                        retCon += '\t\t{0}\n'.format(getLogContent([func[DEF.Name], ATTR.getValTypeRadomName()], funcInfo))
                retCon += '\t}\n'
        else:
            rand = tool.random.randint(1, 4)
            for _ in range(rand):
                func = ocCreateFile.chooseOne(funList, DEF.ISINCLUDE, 0)
                if func:
                    if func[DEF.FUNCRET] != 'void':
                        tmpRetName = getNoRepeatName(funcInfo)
                        retCon += '\t{1} {2} = {0};\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo), func[DEF.FUNCRET], tmpRetName)
                        retCon += '\tif({0})\n\t{1}\n'.format(ATTR.conditionByType(func[DEF.FUNCRET], tmpRetName), "{")
                        retCon += '\t\t{0}\n{1}\n'.format(getLogContent([func[DEF.Name], ATTR.getValTypeRadomName(), tmpRetName], funcInfo), '\t}')
                    else:
                        retCon += '\t{0};\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo))
                        retCon += '\t{0}\n'.format(getLogContent([func[DEF.Name], ATTR.getValTypeRadomName()], funcInfo))


    if tool.random.randint(1, 2) == 1 and clsInfo[DEF.CRTTYPE] == DEF.CLSTYPE.level2:
        level1List = chooseCls(classList, DEF.CRTTYPE, DEF.CLSTYPE.level1)
        callClsInfo = ocCreateFile.chooseOne(level1List, DEF.ISINCLUDE, 0)

        fun = ocCreateFile.chooseOne(callClsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.outer, False)
        if fun:
            callClsFuncStr, retName = callFuncStr_ex(fun, callClsInfo, funcInfo, clsInfo)
            retCon += callClsFuncStr
            propInfo = ocCreateFile.chooseOne(clsInfo[DEF.PROP], DEF.TYPE, fun[DEF.FUNCRET], False)
            if propInfo:
                retCon += '\t' + ATTR.combineParam(propInfo[DEF.TYPE], propInfo[DEF.Name], retName)
            retCon += '\tif ( {0} ) {1}\n'.format(ATTR.conditionByType(fun[DEF.FUNCRET], retName), "{")
            retCon += '\t\t{0}\n{1}\n'.format(getLogContent([fun[DEF.Name], ATTR.getValTypeRadomName(), retName], funcInfo), '\t}')

            # callFlg = getCallFuncFlg(callClsInfo, fun)
            callClsInfo[DEF.ISINCLUDE] = 1
            clsInfo[DEF.ADDHEAD].append(callClsInfo[DEF.Name])
            # funcInfo[DEF.CALLFUNCLIST].append(callFlg)

    retName = ''
    retType = funcInfo[DEF.FUNCRET]
    if retType != "void":
        propInfo = ocCreateFile.chooseOne(clsInfo[DEF.PROP], DEF.TYPE, funcInfo[DEF.FUNCRET], False)
        if propInfo:
            retName = propInfo[DEF.Name]
        else:
            con, retName = getTypeLine(retType, funcInfo)
            retCon += con
    
    return retCon, retName

#创建构造函数、析构函数
def createNormalFun(params, clsInfo, ty):
    clsName = clsInfo[DEF.Name]
    classInfo = clsInfo[DEF.CLASSINFO]

    retInfo = {}
    retInfo[DEF.FUNCRET] = ''
    retInfo['createFunc'] = 1
    if ty == 1:
        retInfo[DEF.Name] = clsName
    elif ty == 2:
        retInfo[DEF.Name] = '~' + clsName
    retInfo[DEF.PARAMS] = []
    retInfo[DEF.NameList] = []

    funcontent = ''
    #初始化属性
    for attr in classInfo[DEF.Attrs]:
        funcontent += '\t{0} = {1};\n'.format(attr[DEF.Name], ATTR.getValTypeRadomValue(attr[DEF.TYPE]))
    
    funcontent += '\t{0}\n'.format( getLogContent([retInfo[DEF.Name], 'called!'], retInfo))
    DEF.totoalCPlusStrNum()

    retInfo[DEF.CONTENT] = funcontent

    return retInfo

def getHeadFileStr(funcInfo):
    tmpStr = ''
    if DEF.Static in funcInfo:
        tmpStr = 'static '
    tmpStr = '\t' + tmpStr + funcInfo[DEF.FUNCRET]

    if 'createFunc' not in funcInfo:
        tmpStr += ' '
    tmpStr += funcInfo[DEF.Name]
    
    paramStr = ''
    for tmpParam in funcInfo[DEF.PARAMS]:
        typeStr = tmpParam[DEF.TYPE] if (tmpParam[DEF.TYPE] != "std::string&") else ('const ' + tmpParam[DEF.TYPE])
        paramStr += typeStr + ' ' + tmpParam[DEF.Name] + ','
    
    tmpStr += '(' + paramStr[:-1] + '); \n'
    
    tmpStr = tool.unicodeToAscii(tmpStr)
    # tmpStr = worldsDic.unicodedata.normalize('NFKD',tmpStr).encode('ascii','ignore')
    
    return tmpStr

def getFuncRealize(funcInfo, classInfo, isInHead = False):
    clsName = classInfo[DEF.Name]
    tmpStr =  funcInfo[DEF.FUNCRET]

    if 'createFunc' not in funcInfo:
        tmpStr += ' '

    if isInHead:
        if DEF.Static in funcInfo:
            tmpStr = 'static ' + tmpStr
        tmpStr +=  funcInfo[DEF.Name]
    else:
        tmpStr +=  clsName + '::' + funcInfo[DEF.Name]

    paramStr = ''
    for tmpParam in funcInfo[DEF.PARAMS]:
        typeStr = tmpParam[DEF.TYPE] if (tmpParam[DEF.TYPE] != "std::string&") else ('const ' + tmpParam[DEF.TYPE])
        paramStr += typeStr + ' ' + tmpParam[DEF.Name] + ','
    
    tmpStr += '(' + paramStr[:-1] + ')\n'
    tmpStr += '{\n'+ funcInfo[DEF.CONTENT] + '}\n'
    
    tmpStr = tool.unicodeToAscii(tmpStr)
    # tmpStr = worldsDic.unicodedata.normalize('NFKD',tmpStr).encode('ascii','ignore')
    return tmpStr

def getFunCallingLine(funcInfo):
    paramStr = ''
    for tmpParam in funcInfo[DEF.PARAMS]:
        paramStr += ATTR.getValTypeRadomValue(tmpParam[DEF.TYPE]) + ','
    return funcInfo[DEF.Name] + '(' + paramStr[:-1] + ')'

def callFuncStr_ex(funcInfo, clsInfo, targetFuncInfo, targetClsInfo = None):
    funContent = ''
    paramName = ''
    first = True

    tmpClsName = getNoRepeatName(targetFuncInfo)
    callClsInit = '\t{0} {1};\n'.format( clsInfo[DEF.Name], tmpClsName)
    callLineStr = funcInfo[DEF.Name] + getFuncCallLine(funcInfo, targetFuncInfo)

    tmpRetName = getNoRepeatName(targetFuncInfo)
    callLine = '\t{2} {3} = {0}.{1};\n'.format(tmpClsName, callLineStr, funcInfo[DEF.FUNCRET], tmpRetName)
    return callClsInit + callLine, tmpRetName

# 生成直接调用函数参数内容（不调用其它内容）
def getFuncCallLine(funInfo, callFuncInfo):
    content = ''
    if funInfo[DEF.PARAMS]:
        content = '('

        def getFuncParamType(pType):
            if callFuncInfo and callFuncInfo.get(DEF.PARAMS):
                param = ocCreateFile.chooseOne(callFuncInfo[DEF.PARAMS], DEF.TYPE, pType, False) 
                if param:
                    return param[DEF.Name]
                return ATTR.getValTypeRadomValue(pType)
            else:
                return ATTR.getValTypeRadomValue(pType)

        first = True
        for param in funInfo[DEF.PARAMS]:
            val = getFuncParamType(param[DEF.TYPE])
            if first:
                first = False
                content += str(val)
            else:
                content += ', ' + str(val)

        content += ')'
    else:
        content = '()'
    
    return content

#根据类型生成获取类型的随机代码
def getTypeLine(ty, funInfo):
    con = ''
    name = ''

    tmpName1 = getNoRepeatName(funInfo)
    
    if ty == 'bool':
        val = tool.random.choice(['true', 'false'])
        name = tmpName1
        con = '\t{0} {1} = {2};\n'.format(ty, name, val)
    elif ty == 'std::string' or ty == 'std::string&':
        name = tmpName1  
        val = ATTR.getValTypeRadomValue(ty)
        con = '\t{0} {1} = {2};\n'.format(ty, name, val)
    elif ATTR.allInt(ty):
        val = str(tool.random.randint(10, 3000))
        name = tmpName1
        con = '\t{0} {1} = {2};\n'.format(ty, name, val)
    elif ty == 'char':
        name = tmpName1
        val = chr(tool.random.randint(65, 90))
        con = '\t{0} {1} = \'{2}\';\n'.format(ty, name, val)
    return con, name

#classList, DEF.CRTTYPE, DEF.CLSTYPE.level1, DEF.CLASSINFO
def chooseCls(clsList, key, value):
    canChoose = []
    for _, info in clsList.items():
        if info[DEF.CLASSINFO].get(key) == value:
            canChoose.append(info[DEF.CLASSINFO])

    return canChoose

#获得字符串代码
#paramsList 所有字符串
#1 string = list[0] string.append()
#2 char name[128] = {0}; sprint(name, "%s", parlsit); string name1 = name;
#3 stringstream
#4 ostringstream
def getLogContent(paramsList, funcInfo):
    cont = ''
    if not paramsList:
        return cont

    for i in range(len(paramsList)):
        tmpStr = paramsList[i]
        tmpStr = tmpStr.replace('"', '')
        paramsList[i] = tmpStr

    flg = tool.random.randint(1, 5)
    if flg == 1:
        strName = getNoRepeatName(funcInfo)
        cont = cont + 'std::string {0} = "{1}";'.format(strName, paramsList[0])

        first = True
        for tmpStr in paramsList:
            if first:
                continue
            else:
                cont = cont + '{0}.append("{1}");'.format(strName, tmpStr)
    elif flg == 2:
        chrName = getNoRepeatName(funcInfo)
        strName = getNoRepeatName(funcInfo)
        tmpCon = ''
        tmpfmt = ''
        for tmpStr in paramsList:
            tmpStr = tmpStr.replace('"', '')
            if tool.random.randint(1, 2) == 1:
                tmpfmt = tmpfmt + " %s"
                tmpCon = tmpCon + ', "' + tmpStr + '"'
            else:
                tmpfmt = tmpfmt + ' ' + tmpStr

        cont = cont + 'char {0}[128] = {1}; sprintf({0}, "{2}" {3}); std::string {4} = {0};'.format(chrName, '{0}', tmpfmt, tmpCon, strName)
    elif flg == 3:
        strName1 = getNoRepeatName(funcInfo)
        strName2 = getNoRepeatName(funcInfo)
        cont = cont + 'stringstream {0}; {0} '.format(strName1)

        tmpCon = ''
        for tmpStr in paramsList:
            tmpCon = tmpCon + ' << "' + tmpStr + '"'
        cont = cont + tmpCon + '; std::string {0} = {1}.str();'.format(strName2, strName1)
    elif flg == 4:
        strName1 = getNoRepeatName(funcInfo)
        strName2 = getNoRepeatName(funcInfo)
        cont = cont + 'ostringstream {0}; {0} '.format(strName1)

        tmpCon = ''
        for tmpStr in paramsList:
            tmpCon = tmpCon + ' << "' + tmpStr + '"'
        cont = cont + tmpCon + '; std::string {0} = {1}.str();'.format(strName2, strName1)
    elif flg == 5:
        strName = getNoRepeatName(funcInfo)

        cont = 'std::string {0}; '.format(strName)
        for tmpStr in paramsList:
            cont += '{0} += "{1}";'.format(strName, tmpStr)

    return cont