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
cfg = [
        'BOOL',
        'NSString*',
        'NSUInteger',
        'NSInteger',
        'UILabel*',
        'UITextView*',
        'NSArray*',
        'NSMutableString*',
        'NSNumber*',
]

totalClsNum = tool.random.randint(250, 350)
stringCount = 0

def createFiles(resPath):
    global totalClsNum
    global createClsList
    num = round(totalClsNum / 4)
    num = num > 0 and num or 1
    num2 = totalClsNum - num

    num = int(num)
    num2 = int(num2)

    for _ in range(num):
        clsRet = newCls()
        clsRet[DEF.CRTTYPE] = DEF.CLSTYPE.params
        createClsList.append(clsRet)

    for _ in range(num2):
        clsRet = newCls()
        clsRet[DEF.CRTTYPE] = DEF.CLSTYPE.tool
        createClsList.append(clsRet)

    createFiles_ex(resPath)
    return createClsList

def createFiles_ex(resPath):
    global totalClsNum
    for _ in range(totalClsNum * 10):
        # 选择一个类
        clsRet = None
        while True:
            clsRet = chooseCls(DEF.CLSTYPE.tool)
            if len(clsRet[DEF.Funcs]) < 25:
                break

        #创建一个函数
        funcInfo = newFunc(clsRet)

        fillFunc(funcInfo, clsRet)

    #准备外部调用类，全部调用工具类
    for val in createClsList:
        saveClsFile(val, resPath)

    print stringCount, "stringCount"
    return createClsList

def chooseCls(ty = None, clsInfo = None):
    while True:
        clsRet = tool.random.choice(createClsList)
        if not ty or clsRet.get(DEF.CRTTYPE) == ty:
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
    ret[DEF.FROM] = DEF.FROMTYPE.add
    # print("new class ", ret[DEF.Name])

    return ret

def newFunc(clsRet, defRetType = None):
    funcInfo = {}
    funcInfo[DEF.CONTENT] = ''
    funcInfo[DEF.Name] = G.getFuncName()
    funcInfo[DEF.PARAMS] = []
    funcInfo[DEF.CALLFUNCLIST] = []
    funcInfo[DEF.FROM] = DEF.FROMTYPE.add
    funcInfo[DEF.NameList] = []
    # print "new func:", clsRet[DEF.Name] + ":" + funcInfo[DEF.Name]

    def getType():
        flg = tool.random.randint(1, 5)
        # 工具类选择已经有的类,作为参数
        # 参数类，直接用系统类型作为参数
        if flg == 3 and (DEF.CRTTYPE not in clsRet or clsRet.get(DEF.CRTTYPE) == DEF.CLSTYPE.tool):
            ty = None
            if clsRet.get(DEF.CRTTYPE) == DEF.CLSTYPE.tool:
                ty = DEF.CLSTYPE.params
            tmpClsInfo = chooseCls(ty, clsRet)
            retType = tmpClsInfo[DEF.Name]
            if not retType:
                print tmpClsInfo
            clsRet[DEF.IMPROTCLS].append(retType)
            clsRet[DEF.ADDHEAD].append(tmpClsInfo[DEF.FILEPATH])
            retType += '*'
        else:
            retType = randomOcType()
        
        return retType

    if defRetType:
        funcInfo[DEF.FUNCRET] = defRetType
        if defRetType not in cfg:
            clsRet[DEF.ADDHEAD].append(getClsFilePathByName(defRetType))
    else:
        funcInfo[DEF.FUNCRET] = getType()

    flg = tool.random.randint(0, 6)
    for i in range(flg):
        paramType = getType()
        paramName = getNoRepeatName(funcInfo)
        # paramName2 = 'a' + G.getLastWord(paramName)

        tmp = {}
        tmp[DEF.TYPE] = paramType
        tmp[DEF.Name] = paramName
        tmp[DEF.Name1] = 'arg' + str(i + 1)
        funcInfo[DEF.PARAMS].append(tmp)

    clsRet[DEF.Funcs].append(funcInfo)
    return funcInfo

# 生成函数调用的代码
def callFuncStr(funcInfo, clsInfo, targetFuncInfo, targetClsInfo):
    funContent = ''
    retName = ''
    paramName = ''
    first = True
    
    tmpClsName = getNoRepeatName(targetFuncInfo)
    callClsInit = '\t{0}* {1} = [[{0} alloc] init];\n'.format( clsInfo[DEF.Name], tmpClsName)

    for param in funcInfo[DEF.PARAMS]:
        paramType = param[DEF.TYPE]

        flg = tool.random.randint(1, 5)
        tmpCon = ''
        tmpRetName = ''
        #找一个返回这类型的函数
        if flg == 2:
            tmpCon, tmpRetName = getContentByParamType(paramType, funcInfo, clsInfo, targetFuncInfo, targetClsInfo, tmpClsName)
        else:
            #如果是生成类
            if paramType not in cfg:
                tmpCon, tmpRetName, headPath = getClsTypeByParamType(paramType, targetFuncInfo)
                targetClsInfo[DEF.ADDHEAD].append(headPath)
            else:
                #基础类
                tmpCon, tmpRetName = getOcTypeLine(paramType, targetFuncInfo)
        funContent += tmpCon
        if first:
            paramName += tmpRetName + ' '
            first = False
        else:
            paramName += param[DEF.Name] + ":" + tmpRetName + ' '

    retName = getNoRepeatName(targetFuncInfo)
    retType = funcInfo[DEF.FUNCRET]
    if paramName:
        callLine = '\t{0} {1} = [{2} {3}:{4}];\n'.format(retType, retName, tmpClsName, funcInfo[DEF.Name], paramName)
    else:
        callLine = '\t{0} {1} = [{2} {3}];\n'.format(retType, retName, tmpClsName, funcInfo[DEF.Name])
    funContent += callClsInit + callLine
            
    return funContent, retName

#生成属性调用的代码
def propCiteStr(attrInfo, clsInfo, targetFuncInfo):
    name = clsInfo[DEF.Name]
    attrName = attrInfo[DEF.Name]
    attrType = attrInfo[DEF.TYPE]

    paramClsName = getNoRepeatName(targetFuncInfo)
    param1Name = getNoRepeatName(targetFuncInfo)
    con = "\t{0}* {1} = [[{0} alloc] init];\n\t{2} {3} = {1}.{4};\n".format(name, paramClsName, attrType, param1Name, attrName)
    return con, param1Name

#根据生成类型获得类信息
def getClsTypeByParamType(retType, targetFuncInfo):
    retType = retType.replace('*', '')
    retType = retType.strip()

    paramName = getNoRepeatName(targetFuncInfo)
    con = "\t{0}* {1} = [[{0} alloc] init];\n".format(retType, paramName)
    return con, paramName, getClsFilePathByName(retType)

#准备填充函数
def fillFunc(funcInfo, clsInfo):
    retType = funcInfo[DEF.FUNCRET]
    funContent, retName = getContentByParamType(retType, funcInfo, clsInfo)
    retStr = '\treturn ' + retName + ';\n'
    funcInfo[DEF.CONTENT] = funContent + retStr

#根据结果参数类型, 生成获取这个结果的代码
def getContentByParamType(retType, funcInfo, clsInfo, targetFuncInfo = None, targetClsInfo = None, tmpClsName = None):
    funContent = ''
    retName = ''
    targetFuncInfo = targetFuncInfo or funcInfo
    targetClsInfo = targetClsInfo or clsInfo

    # print 'getContentByParamType:', retType, targetClsInfo[DEF.Name] + '.' + targetFuncInfo[DEF.Name] , clsInfo[DEF.Name] + '.' + funcInfo[DEF.Name], tmpClsName
    # 如果是普通类型
    if retType in cfg:
        #工具类调用基础类
        flg = tool.random.randint(1, 2)
        if (DEF.CRTTYPE not in clsInfo and flg == 1) or clsInfo.get(DEF.CRTTYPE) == DEF.CLSTYPE.tool:
            #找一个类
            ty = None
            if clsInfo.get(DEF.CRTTYPE) == DEF.CLSTYPE.tool:
                ty = DEF.CLSTYPE.params
            tmpClsInfo = chooseCls(ty, targetClsInfo)
            #添加一个返回这个类型的函数
            if tool.random.randint(1, 3) == 1:
                # print 'line 111  1'
                tmpfuncInfo = newFunc(tmpClsInfo, retType)
                fillFunc(tmpfuncInfo, tmpClsInfo)
                targetFuncInfo[DEF.CALLFUNCLIST].append(getCallFuncFlg(tmpClsInfo, tmpfuncInfo))
                funContent, retName = callFuncStr(tmpfuncInfo, tmpClsInfo, targetFuncInfo, targetClsInfo)
            elif len(tmpClsInfo[DEF.PROP]) < 8:
                #添加一个属性, 值就是这个
                # print 'line 111  2'
                tmpProp = {}
                tmpProp[DEF.Name] = G.getAttrName()
                tmpProp[DEF.TYPE] = retType
                tmpProp[DEF.FROM] = DEF.FROMTYPE.add
                tmpClsInfo[DEF.PROP].append(tmpProp)
                funContent, retName = propCiteStr(tmpProp, tmpClsInfo, targetFuncInfo)
            else:
                # print 'line 111  3'
                return getContentByParamType(retType, funcInfo, clsInfo, targetFuncInfo, targetClsInfo)

            targetClsInfo[DEF.ADDHEAD].append(tmpClsInfo[DEF.FILEPATH])
        #基础类
        elif (DEF.CRTTYPE not in clsInfo and flg == 2) or clsInfo.get(DEF.CRTTYPE) == DEF.CLSTYPE.params:
            # print 'line 222'
            flg = tool.random.randint(1, 5)
            
            while True:
                flg = tool.random.randint(1, 4)
                bFind = False
                # #找自己的函数
                # if flg == 1:
                #     for func in clsInfo[DEF.Funcs]:
                #         if func[DEF.FUNCRET] == retType and getCallFuncFlg(clsInfo, funcInfo) not in func[DEF.CALLFUNCLIST]:
                #             funContent, retName = callFuncStr(func, clsInfo, targetFuncInfo, targetClsInfo)
                #             targetFuncInfo[DEF.CALLFUNCLIST].append(getCallFuncFlg(clsInfo, func))
                #             print 'line 222 1'
                #             bFind = True
                #             break
                    
                #     if bFind:
                #         break
                
                #找其它类的函数
                if flg == 4:
                    for tmpCls in createClsList:
                        if (DEF.CRTTYPE not in tmpCls or tmpCls[DEF.CRTTYPE] == DEF.CLSTYPE.params) and tmpCls[DEF.Name] != clsInfo[DEF.Name]:
                            for func in tmpCls[DEF.Funcs]:
                                if func[DEF.FUNCRET] == retType and getCallFuncFlg(targetClsInfo, targetFuncInfo) not in func[DEF.CALLFUNCLIST] and \
                                    getCallFuncFlg(tmpCls, func) not in func[DEF.CALLFUNCLIST]:
                                    funContent, retName = callFuncStr(func, tmpCls, targetFuncInfo, targetClsInfo)
                                    targetClsInfo[DEF.ADDHEAD].append(tmpCls[DEF.FILEPATH])
                                    targetFuncInfo[DEF.CALLFUNCLIST].append(getCallFuncFlg(tmpCls, func))
                                    # print 'line 222 2'
                                    bFind = True
                                    break

                            if bFind:
                                break
                            
                            for attr in tmpCls[DEF.PROP]:
                                if attr[DEF.TYPE] == retType:
                                    funContent,  retName = propCiteStr(attr, tmpCls, targetFuncInfo)
                                    targetClsInfo[DEF.ADDHEAD].append(tmpCls[DEF.FILEPATH])
                                    # print "import cls prop:",targetClsInfo[DEF.Name] + "." + targetFuncInfo[DEF.Name], tmpCls[DEF.FILEPATH], targetClsInfo[DEF.ADDHEAD], tmpCls[DEF.Name] + "." + retName
                                    # print 'line 222 3'
                                    bFind = True
                                    break

                            if bFind:
                                break
                    if bFind:
                        break
                
                #给自己添加一个属性
                if flg == 3 and len(clsInfo[DEF.PROP]) < 8:
                    tmpProp = {}
                    tmpProp[DEF.Name] = worldsDic.getOneWorld()
                    tmpProp[DEF.TYPE] = retType
                    tmpProp[DEF.FROM] = DEF.FROMTYPE.add
                    clsInfo[DEF.PROP].append(tmpProp)
                    retName = tmpProp[DEF.Name]
                    if tmpClsName:
                        retName = tmpClsName + "." + retName
                    else:
                        retName = "_" + retName                        
                    # funContent = 'return ' + tmpProp[DEF.Name] + ';\n'
                    # print 'line 222 4'
                    break
                #直接生成基础类型代码
                else:
                    # print 'line 222 5'
                    funContent, retName = getOcTypeLine(retType, targetFuncInfo)

                break
    else:
        #如果是生成类
        while True:
            bFind = False
            #找其它函数
            for tmpCls in createClsList:
                if DEF.CRTTYPE not in tmpCls or tmpCls[DEF.CRTTYPE] == DEF.CLSTYPE.tool:
                    for func in tmpCls[DEF.Funcs]:
                        if func[DEF.FUNCRET] == retType and tmpCls[DEF.Name] != targetFuncInfo[DEF.Name] and \
                            getCallFuncFlg(targetClsInfo, targetFuncInfo) not in func[DEF.CALLFUNCLIST] and \
                            getCallFuncFlg(tmpCls, func) not in func[DEF.CALLFUNCLIST]:
                            funContent,retName = callFuncStr(func, tmpCls, targetFuncInfo, targetClsInfo)
                            targetClsInfo[DEF.ADDHEAD].append(tmpCls[DEF.FILEPATH])
                            targetFuncInfo[DEF.CALLFUNCLIST].append(getCallFuncFlg(tmpCls, func))
                            # print 'line 333 1'
                            bFind = True
                            break

                if bFind:
                    break
            if bFind:
                break
            
            flg = tool.random.randint(1, 2)
            if flg == 1 and len(clsInfo[DEF.PROP]) < 8:
                #给自己添加一个属性
                tmpProp = {}
                tmpProp[DEF.Name] = G.getAttrName()
                tmpProp[DEF.TYPE] = retType
                tmpProp[DEF.FROM] = DEF.FROMTYPE.add
                clsInfo[DEF.PROP].append(tmpProp)
                retName = tmpProp[DEF.Name]
                if tmpClsName:
                    retName = tmpClsName + "." + retName
                else:
                    retName = "_" + retName
                # print 'line 333 2'
                # funContent = 'return ' + tmpProp[DEF.Name] + ';\n'
            else:
                #直接使用生产类
                # print 'line 333 3'
                funContent, retName, headPath = getClsTypeByParamType(retType, targetFuncInfo)
                targetClsInfo[DEF.ADDHEAD].append(headPath)
            break

    return funContent, retName

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
    name = 'nil'
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
            num = tool.random.randint(2, 7)

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
                    con2 += ', {0}'.format(str(tool.random.randint(1, 80000))) 

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
        elif flg == 3:
            con = ''
            name = 'nil'
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
        flg = tool.random.randint(1, 5)
        if flg == 2:
            val = '@\"{0}\"'.format( worldsDic.randomWorldS(1, 'ocString')[0])  
        else:
            val = 'nil'
    elif ty == 'NSUInteger':
        val = tool.random.randint(10, 3000)
    elif ty == 'NSInteger':
        val = tool.random.randint(10, 3000)
    elif ty == 'NSNumber*':
        val = '[NSNumber  numberWithInt:{0}]'.format(str(tool.random.randint(50, 50000)) )
    else:
        val = 'nil'

    return val

# 生成直接调用函数参数内容（不调用其它内容）
def getFuncCallLine(funInfo):
    content = ''
    if funInfo[DEF.PARAMS]:
        content = ':'

        first = True
        for param in funInfo[DEF.PARAMS]:
            if first:
                first = False
                content += str(getParamVal(param[DEF.TYPE])) + ' '
            else:
                content += param[DEF.Name] + ':' + str(getParamVal(param[DEF.TYPE])) + ' '
    
    return content