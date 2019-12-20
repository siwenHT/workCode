#!python   
# -*- coding: utf-8 -*-

from define import globalDef as DEF
from tool import toolsFunc as tool
import globalInfo as G
from tool import worldsDic

# 生成垃圾文件的过程
# 按标准生成 
# 参数类, 做为参数使用
createClsList = []
retCfg = [
        'BOOL',
        'NSString*',
        'NSUInteger',
        'NSInteger',
        'NSArray*',
        'NSMutableString*',
        'NSNumber*',
        'void',
]

cfg = [
        'BOOL',
        'NSString*',
        'NSString*',
        'NSString*',
        'NSString*',
        'NSString*',
        'NSUInteger',
        'NSInteger',
        'NSArray*',
        'NSMutableString*',
        'NSNumber*',
]

propCfg = [
    'NSString*',
    'NSUInteger',
    'NSInteger',
]

totalClsNum = tool.random.randint(40, 60)
stringCount = 0

def createFiles(resPath):
    global totalClsNum
    global createClsList

    num = round(totalClsNum / 4 * 3)
    num = num > 0 and num or 1
    num2 = totalClsNum - num

    num = int(num)
    num2 = int(num2)

    print("level1 classNum: {0} level2 classNum: {1}".format(str(num), str(num2)))

    for _ in range(num):
        clsRet = newCls()
        clsRet[DEF.CRTTYPE] = DEF.CLSTYPE.level1
        createClsList.append(clsRet)

    for _ in range(num2):
        clsRet = newCls()
        clsRet[DEF.CRTTYPE] = DEF.CLSTYPE.level2
        createClsList.append(clsRet)

    # createFiles_ex(resPath)
    createClassFile(resPath)
    return createClsList

def createClassFile(resPath):
    for clsRet in createClsList:
        #属性
        tmpAttrNum = tool.random.randint(1, 4)
        for i in range(tmpAttrNum):
            tmpProp = {}
            tmpProp[DEF.Name] = G.getAttrName()
            tmpProp[DEF.TYPE] = tool.random.choice(propCfg)
            tmpProp[DEF.FROM] = DEF.FROMTYPE.add
            clsRet[DEF.PROP].append(tmpProp)

        #函数
        tmpFuncNum = tool.random.randint(5, 12)
        for i in range(tmpFuncNum):

            # 留2个外部调用函数
            # 1级类只处理内部函数跟属性. 不调用外部类
            # 2级类可以调用外部类的外部函数.
            
            createType = DEF.FUNTYPE.outer if (tmpFuncNum - i < 3) else DEF.FUNTYPE.inner
            funcInfo = newFunc(clsRet, createType)
            fillFunc(funcInfo, clsRet)

    for val in createClsList:
        saveClsFile(val, resPath)

    print stringCount, "stringCount"
    return createClsList

def chooseCls_ex(notInclude, clsInfo = None):
    while True:
        clsRet = tool.random.choice(createClsList)
        if not notInclude or (notInclude and clsRet[DEF.ISINCLUDE] == 0):
            if not clsInfo or clsInfo[DEF.Name] != clsRet[DEF.Name]:
                break

    return clsRet

def newCls():
    ret = {}
    ret[DEF.HEAD] = '#import <Foundation/Foundation.h>\n#import <UIKit/UIKit.h>\n'
    name = G.getClsName()
    ret[DEF.Name] = name
    ret[DEF.FILEPATH] = name + '.h'
    ret[DEF.IMPROTCLS] = []
    ret[DEF.Funcs] = []
    ret[DEF.PROP] = []
    ret[DEF.ADDHEAD] = []
    ret[DEF.ISINCLUDE] = 0
    ret[DEF.FROM] = DEF.FROMTYPE.add
    # print("new class ", ret[DEF.Name])

    return ret

def newFunc(clsRet, createType):
    funcInfo = {}
    funcInfo[DEF.CONTENT] = ''
    funcInfo[DEF.Name] = G.getFuncName()
    funcInfo[DEF.PARAMS] = []
    funcInfo[DEF.CALLFUNCLIST] = []
    funcInfo[DEF.FROM] = DEF.FROMTYPE.add
    funcInfo[DEF.NameList] = []
    funcInfo[DEF.CRTTYPE] = createType
    # print "new func:", clsRet[DEF.Name] + ":" + funcInfo[DEF.Name]

    def getType():
        # flg = tool.random.randint(1, 5)

        # if flg == 6 and clsRet[DEF.CRTTYPE] == DEF.CLSTYPE.level2 or clsRet[DEF.CRTTYPE] == DEF.CLSTYPE.level3:
        #     ty = None
        #     if clsRet.get(DEF.CRTTYPE) == DEF.CLSTYPE.tool:
        #         ty = DEF.CLSTYPE.params
        #     tmpClsInfo = chooseCls(ty, clsRet)
        #     retType = tmpClsInfo[DEF.Name]
        #     if not retType:
        #         print tmpClsInfo
        #     clsRet[DEF.IMPROTCLS].append(retType)
        #     clsRet[DEF.ADDHEAD].append(tmpClsInfo[DEF.FILEPATH])
        #     retType += '*'
        # else:
        retType = randomOcType()
        
        return retType

    #函数的返回值类型
    if createType == DEF.FUNTYPE.outer:
        propInfo = chooseOne(clsRet[DEF.PROP], DEF.HASUSE, None)
        if propInfo:            
            funcInfo[DEF.FUNCRET] = propInfo[DEF.TYPE]
            funcInfo[DEF.RELATION] = propInfo
        else:
            funcInfo[DEF.FUNCRET] = getType()
    else:
        funcInfo[DEF.FUNCRET] = tool.random.choice(retCfg)

    # 函数的参数类型
    bSet = False
    flg = tool.random.randint(0, 3)
    for i in range(flg):
        paramType = getType()
        paramName = getNoRepeatName(funcInfo)

        if createType == DEF.FUNTYPE.outer and not bSet and tool.random.randint(1, 2) == 2:
            paramType = funcInfo[DEF.FUNCRET]
            bSet = True

        tmp = {}
        tmp[DEF.TYPE] = paramType
        tmp[DEF.Name] = paramName
        if i > 0:
            tmp[DEF.Name1] = 'arg' + str(i + 1)
        else:
            tmp[DEF.Name1] = paramName
        funcInfo[DEF.PARAMS].append(tmp)

    clsRet[DEF.Funcs].append(funcInfo)
    return funcInfo

def chooseOne(items, key, value, randomChoose = True):
    canChoose = []
    for item in items:
        if item.get(key) == value:
            canChoose.append(item)

    ret = None
    if canChoose:
        ret = tool.random.choice(canChoose)
    elif randomChoose:
        ret = tool.random.choice(items)

    return ret

def chooseList(items, key, value):
    canChoose = []
    for item in items:
        if item.get(key) == value:
            canChoose.append(item)

    return canChoose

def callFuncStr_ex(funcInfo, clsInfo, targetFuncInfo, targetClsInfo):
    funContent = ''
    paramName = ''
    first = True

    tmpClsName = getNoRepeatName(targetFuncInfo)
    callClsInit = '\t{0}* {1} = [[{0} alloc] init];\n'.format( clsInfo[DEF.Name], tmpClsName)
    callLineStr = funcInfo[DEF.Name] + getFuncCallLine(funcInfo, targetFuncInfo)

    tmpRetName = getNoRepeatName(targetFuncInfo)
    callLine = '\t{2} {3} = [{0} {1}];\n'.format(tmpClsName, callLineStr, funcInfo[DEF.FUNCRET], tmpRetName)
    return callClsInit + callLine, tmpRetName

#准备填充函数
def fillFunc(funcInfo, clsInfo):
    retType = funcInfo[DEF.FUNCRET]
    if funcInfo[DEF.CRTTYPE] == DEF.FUNTYPE.outer:
        #调用内部函数
        funContent, retName = getInnerFunc(funcInfo, clsInfo)
    else:
        #生成字符串就好了
        funContent, retName = getFunContent(funcInfo, clsInfo)

    retStr = ''
    if retName:
        retStr = '\treturn ' + retName + ';\n'

    funcInfo[DEF.CONTENT] = funContent + retStr

def fillFunc_ex(funcInfo, clsInfo):
    retType = funcInfo[DEF.FUNCRET]

    funContent = ''
    callNum = tool.random.randint(1, 3)
    for _ in range(callNum):
        callClsInfo = None
        
        level2List = chooseList(createClsList, DEF.CRTTYPE, DEF.CLSTYPE.level2)        
        if level2List:
            for param in funcInfo[DEF.PARAMS]:
                ifStr = ''
                if param[DEF.TYPE].find('*') > -1:
                    ifStr += '\t if ( {0} ) {1}\n'.format(param[DEF.Name], "{")
                elif param[DEF.TYPE] == "BOOL":
                    ifStr += '\t if ( {0} ) {1}\n'.format(param[DEF.Name], "{")
                elif param[DEF.TYPE] == "NSInteger" or param[DEF.TYPE] == "NSUInteger":
                    ifStr += '\t if ( {0} == {1} ) {2}\n'.format(param[DEF.Name], '-' + str(tool.random.randint(1, 8)), "{")

                callClsInfo = chooseOne(level2List, DEF.ISINCLUDE, 0)
                if callClsInfo:
                    fun = chooseOne(callClsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.outer, False)
                    if fun:
                        con, retName= callFuncStr_ex(fun, callClsInfo, funcInfo, clsInfo)
                        funContent += con
                        funContent += '\t'
                        funContent += '\tif ( {0} ) {1}\n'.format(retName, "{")
                        funContent += '\tMLog(@"{0} {2} {1}");\n{3}\n'.format(fun[DEF.Name], retName, worldsDic.getOneWorld(), '\t}')
                        callFlg = getCallFuncFlg(callClsInfo, fun)
                        callClsInfo[DEF.ISINCLUDE] = 1
                        clsInfo[DEF.ADDHEAD].append(callClsInfo[DEF.FILEPATH])
                        funcInfo[DEF.CALLFUNCLIST].append(callFlg)
                        break

    retType = funcInfo[DEF.FUNCRET]
    con, retName = getOcTypeLine(retType, funcInfo)
    funContent += con

    retStr = ''
    if retName:
        retStr = '\treturn ' + retName + ';\n'    

    funcInfo[DEF.CONTENT] = funContent + retStr

# 内部去函数填充
# 属性
# 外部函数
# 函数参数
# 返回值
def getFunContent(funcInfo, clsInfo):
    #定义两个变量
    funcContent = ''

    def getFuncParamType(pType):
        param = chooseOne(funcInfo[DEF.PARAMS], DEF.TYPE, pType, False)
        if param:
            return param[DEF.Name1]
        return getParamVal(pType)

    # 随便找一个属性
    propInfo = tool.random.choice(clsInfo[DEF.PROP])

    conlist = []
    #根据参数构建函数体
    for param in funcInfo[DEF.PARAMS]:
        if param[DEF.TYPE] == "NSString*":
            partCon = '( {0} ) {1} \n'.format(param[DEF.Name1], "{")
            val = param[DEF.Name1] if (propInfo[DEF.TYPE] == "NSString*") else getFuncParamType(propInfo[DEF.TYPE])
            partCon += '\t\t{0} = {1};\n'.format(propInfo[DEF.Name], val)
            
            rand = tool.random.randint(1, 6)
            for _ in range(rand):
                val = getVal_ex(propInfo[DEF.TYPE], propInfo[DEF.Name])
                partCon += '\t\t' + val

            rand = tool.random.randint(1, 6)
            con1 = '{0}'.format(param[DEF.Name1])
            con2 = ''

            for _ in range(rand):
                con1 += " %@"
                con2 += ', ' + getParamVal('NSString*')

            partCon += '\t\tMLog(@"{0}" {1});\n'.format(con1, con2)

            partCon += '\t}\n'
            conlist.append(partCon)
        elif param[DEF.TYPE] == "BOOL":
            partCon = '( {0} ) {1} \n'.format(param[DEF.Name1], '{')
            partCon += '\t\t{0} = {1};\n'.format(propInfo[DEF.Name], getFuncParamType(propInfo[DEF.TYPE]))
            rand = tool.random.randint(0, 4)
            for _ in range(rand):
                val = getVal_ex(propInfo[DEF.TYPE], propInfo[DEF.Name])
                partCon += '\t\t' + val

            rand = tool.random.randint(0, 4)
            con1 = '{0}%@%@'.format(param[DEF.Name1])
            con2 = ', " is", " True"'

            for _ in range(rand):
                con1 += " %@"
                con2 += ", " + getParamVal('NSString*')

            partCon += '\t\tMLog(@"{0}" {1});\n'.format(con1, con2)
            partCon += '\t}\n'
            conlist.append(partCon)
        elif param[DEF.TYPE] == "NSInteger" or param[DEF.TYPE] == "NSUInteger":
            partCon = '( {0} == 1 ) {1} \n'.format(param[DEF.Name1], '{')
            val = param[DEF.Name1] if (propInfo[DEF.TYPE] == "NSInteger" or propInfo[DEF.TYPE] == "NSUInteger") else getFuncParamType(propInfo[DEF.TYPE])
            partCon += '\t\t{0} = {1};\n'.format(propInfo[DEF.Name], val)
            rand = tool.random.randint(0, 2)
            for _ in range(rand):
                val = getVal_ex(propInfo[DEF.TYPE], propInfo[DEF.Name])
                partCon += '\t\t' + val

            rand = tool.random.randint(0, 4)
            con1 = '{0} = {1}'.format(param[DEF.Name1], "%d")
            con2 = ', {0}'.format(param[DEF.Name1])

            for _ in range(rand):
                con1 += " %@"
                con2 += ", " + getParamVal('NSString*')

            partCon += '\t\tMLog(@"{0}" {1});\n'.format(con1, con2)
            partCon += '\t}\n'
            conlist.append(partCon)
        else:
            partCon = '( {0} ) {1} \n'.format(param[DEF.Name1], "{")
            val = getFuncParamType(propInfo[DEF.TYPE])
            partCon += '\t\t{0} = {1};\n'.format(propInfo[DEF.Name], val)
            rand = tool.random.randint(0, 4)
            for _ in range(rand):
                val = getVal_ex(propInfo[DEF.TYPE], propInfo[DEF.Name])
                partCon += '\t\t' + val

            rand = tool.random.randint(0, 4)
            con1 = '{0} = '.format(propInfo[DEF.Name]) + '%@' if (propInfo[DEF.TYPE] == 'NSString*') else '%d'
            con2 = ', {0}'.format(propInfo[DEF.Name])

            for _ in range(rand):
                con1 += " %@"
                con2 += ", " + getParamVal('NSString*')

            partCon += '\t\tMLog(@"{0}" {1});\n'.format(con1, con2)
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
        level1List = chooseList(createClsList, DEF.CRTTYPE, DEF.CLSTYPE.level1)
        callClsInfo = chooseOne(level1List, DEF.ISINCLUDE, 0)

        fun = chooseOne(callClsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.outer, False)
        if fun:
            callClsFuncStr,retName = callFuncStr_ex(fun, callClsInfo, funcInfo, clsInfo)
            funcContent += callClsFuncStr
            if fun[DEF.FUNCRET] == propInfo[DEF.TYPE]:
                funcContent += '\t' + combineParam(propInfo[DEF.TYPE], propInfo[DEF.Name], retName)
            funcContent += '\tif ( {0} ) {1}\n'.format(retName, "{")
            funcContent += '\t\tMLog(@"{0} is back {1}");\n{2}\n'.format(fun[DEF.Name], retName, '\t}')

            callFlg = getCallFuncFlg(callClsInfo, fun)
            callClsInfo[DEF.ISINCLUDE] = 1
            clsInfo[DEF.ADDHEAD].append(callClsInfo[DEF.FILEPATH])
            funcInfo[DEF.CALLFUNCLIST].append(callFlg)

    #对属性进行log
    flg = tool.random.randint(1, 2)
    if flg == 1:
        if propInfo[DEF.TYPE] == "NSString*":
            funcContent += '\tif ({0}){1}\n'.format(propInfo[DEF.Name], "{")
        elif propInfo[DEF.TYPE] == "NSUInteger" or propInfo[DEF.TYPE] == "NSInteger":            
            funcContent += '\tif ({0} == {1}){2}\n'.format(propInfo[DEF.Name], '-' + str(tool.random.randint(1, 8)), "{")
        
        con1 = ''
        con2 = ''
        rand = tool.random.randint(0, 6)
        for _ in range(rand):
            con1 += " %@"
            con2 += ", " + getParamVal('NSString*')

        funcContent += '\t\tMLog(@"{0}{1}"{3});\n{2}\n'.format(propInfo[DEF.Name], con1, '\t}', con2)

    retName = ''
    retType = funcInfo[DEF.FUNCRET]
    if retType != "void":
        if propInfo[DEF.TYPE] == retType:
            retName = propInfo[DEF.Name]
        else:
            con, retName = getOcTypeLine(retType, funcInfo)
            funcContent += con

    return funcContent, retName

def getInnerFunc(funcInfo, clsInfo):
    retCon = ''
    retName = ''

    funList = chooseList(clsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.inner)
    if funList:
        if funcInfo[DEF.PARAMS]:
            for param in funcInfo[DEF.PARAMS]:
                ifStr = ''
                if param[DEF.TYPE].find('*') > -1:
                    ifStr += '\tif ( {0} ) {1}\n'.format(param[DEF.Name1], "{")
                elif param[DEF.TYPE] == "BOOL":
                    ifStr += '\tif ( {0} ) {1}\n'.format(param[DEF.Name1], "{")
                elif param[DEF.TYPE] == "NSInteger" or param[DEF.TYPE] == "NSUInteger":
                    ifStr += '\tif ( {0} == {1} ) {2}\n'.format(param[DEF.Name1], '-' + str(tool.random.randint(1, 8)), "{")

                func = chooseOne(funList, DEF.ISINCLUDE, 0)
                if func:
                    retCon += ifStr
                    if func[DEF.FUNCRET] != 'void':
                        tmpRetName = getNoRepeatName(funcInfo)
                        retCon += '\t\t{1} {2} = [self {0}];\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo), func[DEF.FUNCRET], tmpRetName)
                        retCon += '\t\tif ( {0} ) {1}\n'.format(tmpRetName, "{")
                        retCon += '\t\t\tMLog(@"{0} {2} {1}");\n{3}\n'.format(func[DEF.Name], retName, worldsDic.getOneWorld(), '\t\t}')
                    else:
                        retCon += '\t\t[self {0}];\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo))
                        retCon += '\t\tMLog(@"{0} {1}");\n'.format(func[DEF.Name], worldsDic.getOneWorld())
                    addStrCount()
                retCon += '\t}\n'
        else:
            rand = tool.random.randint(1, 4)
            for _ in range(rand):
                func = chooseOne(funList, DEF.ISINCLUDE, 0)
                if func:
                    if func[DEF.FUNCRET] != 'void':
                        tmpRetName = getNoRepeatName(funcInfo)
                        retCon += '\t{1} {2} = [self {0}];\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo), func[DEF.FUNCRET], tmpRetName)
                        retCon += '\tif ( {0} ) {1}\n'.format(tmpRetName, "{")
                        retCon += '\t\tMLog(@"{0} {2} {1}");\n{3}\n'.format(func[DEF.Name], retName, worldsDic.getOneWorld(), '\t}')
                    else:
                        retCon += '\t[self {0}];\n'.format(func[DEF.Name] + getFuncCallLine(func, funcInfo))
                        retCon += '\tMLog(@"{0} {1}");\n'.format(func[DEF.Name], worldsDic.getOneWorld())

                    addStrCount()                       

    if tool.random.randint(1, 2) == 1 and clsInfo[DEF.CRTTYPE] == DEF.CLSTYPE.level2:
        level1List = chooseList(createClsList, DEF.CRTTYPE, DEF.CLSTYPE.level1)
        callClsInfo = chooseOne(level1List, DEF.ISINCLUDE, 0)

        fun = chooseOne(callClsInfo[DEF.Funcs], DEF.CRTTYPE, DEF.FUNTYPE.outer, False)
        if fun:
            callClsFuncStr, retName = callFuncStr_ex(fun, callClsInfo, funcInfo, clsInfo)
            retCon += callClsFuncStr
            propInfo = chooseOne(clsInfo[DEF.PROP], DEF.TYPE, fun[DEF.FUNCRET], False)
            if propInfo:
                retCon += '\t' + combineParam(propInfo[DEF.TYPE], propInfo[DEF.Name], retName)
            retCon += '\tif ( {0} ) {1}\n'.format(retName, "{")
            retCon += '\t\tMLog(@"{0} {2} {1}");\n{3}\n'.format(fun[DEF.Name], retName, worldsDic.getOneWorld(), '\t}')
            addStrCount()

            callFlg = getCallFuncFlg(callClsInfo, fun)
            callClsInfo[DEF.ISINCLUDE] = 1
            clsInfo[DEF.ADDHEAD].append(callClsInfo[DEF.FILEPATH])
            funcInfo[DEF.CALLFUNCLIST].append(callFlg)

    retName = ''
    retType = funcInfo[DEF.FUNCRET]
    if retType != "void":
        propInfo = chooseOne(clsInfo[DEF.PROP], DEF.TYPE, funcInfo[DEF.FUNCRET], False)
        if propInfo:
            retName = propInfo[DEF.Name]
        else:
            con, retName = getOcTypeLine(retType, funcInfo)
            retCon += con
    
    return retCon, retName

def saveClsFile(clsInfo, resPath):
    resPath = tool.os.path.abspath(resPath)
    filePath = tool.os.path.join(resPath, clsInfo[DEF.FILEPATH])
    fileCppPath = filePath.replace('.h', '.m')
    tool.createDir(filePath)
    tool.createDir(fileCppPath)
    fHeadContent = clsInfo[DEF.HEAD]

    # 用到的参数类型
    clsInfo[DEF.IMPROTCLS] = tool.popReList(clsInfo[DEF.IMPROTCLS])
    for val in clsInfo[DEF.IMPROTCLS]:
        fHeadContent += "@class " + val + ";\n"
    clsInfo[DEF.IMPROTCLS] = []

    fHeadContent += tool.random.randint(1, 2) * '\n' + '@interface ' + clsInfo[DEF.Name] + " : NSObject\n" + tool.random.randint(1, 2) * '\n'

    #如果类完全没有属性, 给它添加几个属性
    if len(clsInfo[DEF.PROP]) == 0:
        tmpNum = tool.random.randint(1,5)
        for i in range(tmpNum):
            tmpProp = {}
            tmpProp[DEF.Name] = G.getAttrName()
            tmpProp[DEF.TYPE] = randomOcType()
            tmpProp[DEF.FROM] = DEF.FROMTYPE.add
            clsInfo[DEF.PROP].append(tmpProp)

    # 属性
    for prop in clsInfo[DEF.PROP]:
        if '*' in prop[DEF.TYPE]:
            fHeadContent += "@property(nonatomic, strong) " + prop[DEF.TYPE] + " " + prop[DEF.Name] + ";\n" 
        else:
            fHeadContent += "@property(nonatomic, assign) " + prop[DEF.TYPE] + " " + prop[DEF.Name] + ";\n"
        prop[DEF.FROM] = DEF.FROMTYPE.old

    fHeadContent += tool.random.randint(1, 2) * '\n'

    tool.random.shuffle(clsInfo[DEF.Funcs])
    # 函数
    for fun in clsInfo[DEF.Funcs]:
        tmpCon = ''
        first = True
        for param in fun[DEF.PARAMS]:
            if first:
                tmpCon += '({0}){1}'.format(param[DEF.TYPE], param[DEF.Name1])
                first = False
            else:
                tmpCon += ' {0}:({1}){2}'.format(param[DEF.Name], param[DEF.TYPE], param[DEF.Name1])
        if tmpCon:
            fHeadContent += '- ({0}) {1}:{2}'.format(fun[DEF.FUNCRET], fun[DEF.Name], tmpCon) + ';\n'
        else:
            fHeadContent += '- ({0}) {1}'.format(fun[DEF.FUNCRET], fun[DEF.Name]) + ';\n'
        fun[DEF.FROM] = DEF.FROMTYPE.old

    #结束标记
    fHeadContent += tool.random.randint(1, 2) * '\n' + "@end\n"
    tool.WriteFile(filePath, fHeadContent)
    
    fMContent = ''
    clsInfo[DEF.ADDHEAD].append(clsInfo[DEF.FILEPATH])
    clsInfo[DEF.ADDHEAD] = tool.popReList(clsInfo[DEF.ADDHEAD])
    for head in clsInfo[DEF.ADDHEAD]:
        fMContent += '#import \"{0}\"'.format(head) + '\n'
    clsInfo[DEF.ADDHEAD] = []

    fMContent += tool.random.randint(1, 2) * '\n' + '@implementation ' + clsInfo[DEF.Name] + '\n' + tool.random.randint(1, 2) * '\n'
    for prop in clsInfo[DEF.PROP]:
        fMContent += '@synthesize ' + prop[DEF.Name] + ';\n'

    for fun in clsInfo[DEF.Funcs]:
        tmpCon = ''
        first = True
        for param in fun[DEF.PARAMS]:
            if first:
                tmpCon += '({0}){1}'.format(param[DEF.TYPE], param[DEF.Name])
                first = False
            else:
                tmpCon += ' {0}:({1}){2}'.format(param[DEF.Name], param[DEF.TYPE], param[DEF.Name1])
        if tmpCon:
            fMContent += '- ({0}) {1}:{2}'.format(fun[DEF.FUNCRET], fun[DEF.Name], tmpCon) + '{\n'
        else:
            fMContent += '- ({0}) {1}'.format(fun[DEF.FUNCRET], fun[DEF.Name]) + '{\n'
        fMContent += fun[DEF.CONTENT] + '}\n\n'

    fMContent += tool.random.randint(1, 2) * '\n' + "@end\n"
    tool.WriteFile(fileCppPath, fMContent)

def randomOcType():
    global cfg
    return tool.random.choice(cfg)

def randomOcMark(ty):
    a = 1

def getNoRepeatName(funInfo):
    while True:
        tmpName = worldsDic.getOneWorld()
        if tmpName not in funInfo[DEF.NameList]:
            funInfo[DEF.NameList].append(tmpName)
            return tmpName

    return worldsDic.getOneWorld()

def getCallFuncFlg(clsInfo, funcInfo):
    return clsInfo[DEF.Name] + ":" + funcInfo[DEF.Name]

def getClsFilePathByName(clsName):
    for clsInfo in createClsList:
        if clsInfo[DEF.Name] == clsName:
            return clsInfo[DEF.FILEPATH]

    print 'can not find filePath by clsName:' + clsName
    return ''

#根据类型生成获取类型的随机代码
def getOcTypeLine(ty, targetFuncInfo):
    con = ''
    name = ''
    if ty == 'BOOL':
        val = tool.random.choice(['TRUE', 'FALSE'])
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = {2};\n'.format(ty, name, val)
    elif ty == 'NSString*':
        global stringCount
        stringCount = stringCount + 1
        flg = tool.random.randint(1, 3)
        name = getNoRepeatName(targetFuncInfo)
        if flg == 1:
            val1 = worldsDic.randomWorldS(1, 'ocString')[0]
            val2 = worldsDic.randomWorldS(1, 'ocString')[0]
            num = tool.random.randint(1, 4)

            con1 = ''
            con2 = ''
            cfg = ['%@', "%d", "%@", "%@"]
            for _ in range(num):
                tmp = tool.random.choice(cfg)
                con1 += tmp
                if tmp == '%@':
                    stringCount = stringCount + 1
                    con2 += ', @\"{0}\"'.format(worldsDic.randomWorldS(1, 'ocString')[0])
                elif tmp == '%d':
                    con2 += ', {0}'.format(str(tool.random.randint(1, 20000))) 

            val = '[[NSString alloc] initWithFormat:@\"{0}\" {1}]'.format( con1, con2)
            con = '\t{0} {1} = {2};\n'.format(ty, name, val)
        elif flg == 2:
            val1 = worldsDic.randomWorldS(1, 'ocString')[0]
            val2 = worldsDic.randomWorldS(1, 'ocString')[0]
            name2 = getNoRepeatName(targetFuncInfo)
            val = '[{0} stringByAppendingString:@\"{1}\"]'.format(name2, val2)
            con = '\tNSString* {0} = @"{1}";\n'.format(name2, val1)
            con += '\t{0} {1} = {2};\n'.format(ty, name, val)
            stringCount = stringCount + 1
        else:    
            val = '@\"{0}\"'.format( worldsDic.randomWorldS(1, 'ocString')[0])
            con = '\t{0} {1} = {2};\n'.format(ty, name, val)
    elif ty == 'NSUInteger':
        val = 'arc4random_uniform({0})'.format(tool.random.randint(10, 3000))
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = {2};\n'.format(ty, name, val)
    elif ty == 'NSInteger':
        val = 'arc4random_uniform({0})'.format(tool.random.randint(10, 3000))
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = {2};\n'.format(ty, name, val)        
    elif ty == 'UILabel*':
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = [[UILabel alloc] init];\n'.format(ty, name)
    elif ty == 'NSArray*':
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = [[NSArray alloc] init];\n'.format(ty, name)
    elif ty == 'UITextView*':
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = [[UITextView alloc] init];\n'.format(ty, name)
    elif ty == 'NSMutableString*':
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = [[NSMutableString alloc] init];\n'.format(ty, name)
    elif ty == 'NSNumber*':
        name = getNoRepeatName(targetFuncInfo)
        con = '\t{0} {1} = [NSNumber  numberWithInt:{2}];\n'.format(ty, name, str(tool.random.randint(50, 50000)) )

    return con, name

#根据类型生成获取类型的随机代码
def getParamVal(ty):
    val = ''
    if ty == 'BOOL':
        val = tool.random.choice(['TRUE', 'FALSE'])
    elif ty == 'NSString*': 
        global stringCount
        stringCount = stringCount + 1
        val = tool.random.choice(['@\"{0}\"'.format(worldsDic.getOneWorld()), '@\"{0}\"'.format(tool.getRandomUpDown(tool.random.randint(6, 15)))])
    elif ty == 'NSUInteger':
        val = str(tool.random.randint(10, 3000))
    elif ty == 'NSInteger':
        val = str(tool.random.randint(10, 3000))
    elif ty == 'NSNumber*':
        val = '[NSNumber  numberWithInt:{0}]'.format(str(tool.random.randint(50, 50000)) )
    else:
        val = 'nil'

    return val

#根据类型生成类型扩展代码
def getVal_ex(ty, paramName):
    val = ''
    if ty == 'NSString*': 
        #paramName = = [NSString stringWithFormat:@"%@",paramName];
        ch = tool.random.randint(1, 4)
        flg = tool.random.randint(2, 4)
        if ch == 1 or ch == 4:
            con1 = ''
            con2 = ''
            for i in range(flg):
                flg1 = tool.random.randint(1, 5)
                if flg1 == 3:
                    con1 += '%d'
                    con2 += ', {0}'.format(str(tool.random.randint(10, 500)) )
                else: 
                    con1 += '%@'
                    con2 += ", {0}".format(paramName if (i == 1) else getParamVal(ty))
            
                global stringCount
                stringCount = stringCount + 1  
            val = '{0} = [NSString stringWithFormat:@"{1}" {2}];\n'.format(paramName, con1, con2)
        elif ch == 2:
            tmpVal = worldsDic.randomWorldS(1, 'ocString')[0]
            val = '{0} = [{0} stringByAppendingPathComponent:@\"{1}\"];\n'.format(paramName, tmpVal)
        else:
            tmpVal = worldsDic.randomWorldS(1, 'ocString')[0]
            val = '{0} = [{0} stringByAppendingString:@\"{1}\"];\n'.format(paramName, tmpVal)
    elif ty == 'NSUInteger':
        val = '{0} = {1} + {2};\n'.format(paramName, paramName, tool.random.randint(50, 3000))
    elif ty == 'NSInteger':
        val = '{0} = {1} + {2};\n'.format(paramName, paramName, tool.random.randint(50, 3000))

    return val


#根据类型生成类型合并变量
def combineParam(ty, paramName, paramName1):
    val = ''
    if ty == 'NSString*': 
        val = '{0} = [NSString stringWithFormat:@"%@%@", {0}, {1}];\n'.format(paramName, paramName1)
    elif ty == 'NSUInteger':
        val = '{0} = {1} + {2};\n'.format(paramName, paramName, paramName1)
    elif ty == 'NSInteger':
        val = '{0} = {1} + {2};\n'.format(paramName, paramName, paramName1)

    return val

# 生成直接调用函数参数内容（不调用其它内容）
def getFuncCallLine(funInfo, callFuncInfo):
    content = ''
    if funInfo[DEF.PARAMS]:
        content = ':'

        def getFuncParamType(pType):
            if callFuncInfo.get(DEF.PARAMS):
                param = chooseOne(callFuncInfo[DEF.PARAMS], DEF.TYPE, pType, False) 
                if param:
                    return param[DEF.Name1]
                return getParamVal(pType)
            else:
                return getParamVal(pType)

        first = True
        for param in funInfo[DEF.PARAMS]:
            val = getFuncParamType(param[DEF.TYPE])
            if first:
                first = False
                content += str(val) + ' '
            else:
                content += param[DEF.Name] + ':' + str(val) + ' '
    
    return content

def addStrCount(num = 1):
    global stringCount
    stringCount += num