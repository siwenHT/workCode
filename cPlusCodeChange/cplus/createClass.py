#!python   
# -*- coding: utf-8 -*-
from tool import toolsFunc as tool
from tool import worldsDic
from define import globalDef as DEF
import createFunc as FUNC
import createAttr as ATTR

lanType = 'cplus'

#创建一个类
def createClass(params): 
    nameList = params[DEF.NAMELIST]
    clsNameList = nameList[0]
    clsName = clsNameList.pop()
    # ansInof = params[DEF.AnalysisRet]
    # clsType = params[DEF.CClassType.base]
    
    #填充这个类
    funcsInfo = []
    attrsInfo = []
    clsInfo = {}
    info = {DEF.CLASSINFO:clsInfo, DEF.Name:clsName}
    clsInfo[DEF.Funcs] = funcsInfo
    clsInfo[DEF.Attrs] = attrsInfo
    clsInfo[DEF.PROP] = attrsInfo
    clsInfo[DEF.Name] = clsName
    clsInfo[DEF.CRTTYPE] = params[DEF.CRTTYPE]
    clsInfo[DEF.ADDHEAD] = []
    clsInfo[DEF.ISINCLUDE] = 0

    addAttrNum = tool.random.randint(1, 5)
    for _ in range(addAttrNum):
        tmpAttrBack = ATTR.create({DEF.NAMELIST:nameList, DEF.CLASSINFO:info})
        attrsInfo.append(tmpAttrBack)

    tmpFuncBack = FUNC.createNormalFun(params, info, 1)
    funcsInfo.append(tmpFuncBack)
    
    tmpFuncBack = FUNC.createNormalFun(params, info, 2)
    funcsInfo.append(tmpFuncBack)

    addFuncNum = tool.random.randint(5, 15)
    innerNum = round(addFuncNum / 5 * 4)
    innerNum = innerNum if (innerNum > 0) else 1

    for i in range(addFuncNum):
        funcType = DEF.FUNTYPE.inner if (i < innerNum) else DEF.FUNTYPE.outer
        tmpFuncBack = FUNC.create({DEF.NAMELIST:nameList, DEF.CLASSINFO:info[DEF.CLASSINFO], DEF.CRTTYPE:funcType})
        FUNC.FillFunc(tmpFuncBack, info[DEF.CLASSINFO], params["classList"])
        funcsInfo.append( tmpFuncBack )

    return clsName, info
# def extendClass(analRet, params):
#     retAddFunc = 0
#     nameList = params[DEF.NAMELIST]

#     for _, info in analRet.items():
#         if not info[DEF.CLASS]:
#             continue
        
#         for cInfo in info[DEF.CLASS]:
#             clsName = cInfo[DEF.Name]
#             if cInfo['type'] == 'class':
#                 hasFuncNum = len(cInfo[DEF.CLASSINFO][DEF.Funcs])
#                 # print 'extend class [' + clsName + '] begin ...'
#                 addFuncNum = 0
#                 if hasFuncNum < 8 or hasFuncNum > 20:
#                     # 如果类的函数少于10个
#                     addFuncNum = tool.random.randint(3, 8)
#                     retAddFunc += addFuncNum
#                     for _ in range(addFuncNum):
#                         tmpFuncBack = FUNC.create({DEF.TYPE:DEF.CClassType.base, DEF.NAMELIST:nameList, DEF.CLASSINFO:cInfo})
#                         cInfo[DEF.CLASSINFO][DEF.Funcs].append( tmpFuncBack )
                
#                 hasAttrNum = len(cInfo[DEF.CLASSINFO][DEF.Attrs])
#                 addAttrNum = 0
#                 if hasAttrNum < 6 or hasAttrNum > 15:
#                     addAttrNum = tool.random.randint(1, 5)

#                     for _ in range(addAttrNum):
#                         tmpAttrBack = ATTR.create({DEF.TYPE:DEF.CClassType.base, DEF.NAMELIST:nameList, DEF.CLASSINFO:cInfo})
#                         cInfo[DEF.CLASSINFO][DEF.Attrs].append(tmpAttrBack)

#                 # print 'extend class [' + clsName + '] addfunc:' + str(addFuncNum) + ",addAttr:" + str(addAttrNum) + ' end ...'                
#             # else:
#             #     if type(cInfo[DEF.Name]) is list:
#             #         print cInfo[DEF.Name][0] + 'is a ' + cInfo['type']
#             #     else:
#             #         print cInfo[DEF.Name] + 'is a ' + cInfo['type']
    
#     return retAddFunc
def extendClass(oldClsInfo, namelist, newClsList):
    clsInfo = oldClsInfo[DEF.CLASSINFO]

    num = tool.random.randint(1, 4)
    for _ in range(num):
        tmpFuncBack = FUNC.create({DEF.CRTTYPE:DEF.FUNTYPE.inner, DEF.NAMELIST:namelist, DEF.CLASSINFO:clsInfo})
        clsInfo[DEF.NewFunc].append(tmpFuncBack)
        FUNC.FillFunc_ex(tmpFuncBack, newClsList, clsInfo)

def checkClassHasAttr(info, attrName):
    attrInfo = info[DEF.CLASSINFO][DEF.Attrs]
    for tmpInfo in attrInfo:
        if tmpInfo[DEF.Name] == attrName:
            return True
    
    return False

def checkClassHasFun(info, funcName):
    funcInfo = info[DEF.Funcs]
    for tmpInfo in funcInfo:
        if tmpInfo[DEF.Name] == funcName:
            return True
    
    return False

def checkCppFile(clsInfo, filePath):
    clsName = clsInfo[DEF.Name]
    fContent = tool.ReadFile(filePath)
    if fContent.find(clsName + '::') > -1:
        return True
    return False

def addHeadFileCon(clsInfo, filePath, contentInHead):
    classInfo = clsInfo[DEF.CLASSINFO]
            
    flg = False
    funcList = '\npublic:\n'
    for funcInfo in classInfo[DEF.NewFunc]:
        if contentInHead:
            funcList += FUNC.getFuncRealize(funcInfo, clsInfo, True)
        else:
            funcList += FUNC.getHeadFileStr(funcInfo)
        flg = True
    
    attrList = '\nprivate:\n'
    for attrInfo in classInfo[DEF.NewAttrs]:
        if DEF.FROM in attrInfo and attrInfo[DEF.FROM] == DEF.FROMTYPE.add:
            attrList += ATTR.getHeadFileStr(attrInfo)
            flg = True

    if flg:
        fHeadContent = tool.ReadFile(filePath)
        filterStr = r'[\n]+' + 'class '+ clsInfo[DEF.Name] + '[^A-Za-z0-9_;]+[^;\{\n]*[\n]?\{'
        ret = tool.re.search(filterStr, fHeadContent)

        isOk = False
        if ret:
            if ret.span():
                if ret.span()[0]:        
                    endPos = ret.span()[1]
                    
                    fHeadContentA = fHeadContent[:endPos]
                    fHeadContentB = fHeadContent[endPos:]
                    newContent = fHeadContentA + funcList + attrList + fHeadContentB
                    tool.WriteFile(filePath, newContent)
                    return True
        else:
            print('{0} class def not find in {1}'.format(clsInfo[DEF.Name], filePath))
            return False

def addCppFileCon(clsInfo, filePath):
    classInfo = clsInfo[DEF.CLASSINFO]
    
    flg = False
    funcList = '\n'
    clsName = clsInfo[DEF.Name]
    #如果有添加的类
    for funcInfo in classInfo[DEF.NewFunc]:
        if DEF.FROM in funcInfo and funcInfo[DEF.FROM] == DEF.FROMTYPE.add:
            funcList += FUNC.getFuncRealize(funcInfo, clsInfo)
            flg = True

    if flg:
        findStr = ''
        fContent = tool.ReadFile(filePath)
        for func in classInfo[DEF.Funcs]:
            if func.get(DEF.Static) != 1:
                findStr = clsName + "::" + func[DEF.Name]
                break

        if findStr:
            endPos = tool.findLastStr(fContent, findStr)
            if endPos > -1:
                endPos, _ = tool.matchSymbol(fContent, '{', '}', endPos)
                if endPos == -1:
                    endPos = tool.findLastStr(fContent, '}') + 1
                else:
                    endPos = endPos + 2

                if endPos < 0 or endPos > len(fContent):
                    endPos = len(fContent)

                fHeadContentA = fContent[:endPos]
                fHeadContentB = fContent[endPos:]
                newContent = fHeadContentA + funcList + fHeadContentB
                tool.WriteFile(filePath, newContent)
            else:
                a = 1
                print 'no Find ' + clsName + '::' + func[DEF.Name] + 'in file ' + filePath + '~'

#添加随机的函数
def addExternInfo(filePath ,clsInfo, newClsList, nameList):
    cppFilePath = filePath.replace('.h', '.cpp')
    cppFilePath = tool.os.path.abspath(cppFilePath)
    if tool.os.path.exists(cppFilePath) and clsInfo[DEF.Name].find("LuaMsgBuffer") == -1:
        extendClass(clsInfo, nameList, newClsList)
        
        flg = checkCppFile(clsInfo, cppFilePath)
        hasAddFunc = addHeadFileCon(clsInfo, filePath, not flg)

        if flg and hasAddFunc:
            # 找到类的最后一个字符，在这个位置加上新加的代码.
            addCppFileCon(clsInfo, cppFilePath)

        if hasAddFunc:
            addCallClassHead(filePath, clsInfo)
            addNewFuncCall(filePath, clsInfo)

#在文件中添加新增类的文件引用
def addCallClassHead(filePath, clsInfo):
    clsInfo = clsInfo[DEF.CLASSINFO]
    cppFilePath = filePath.replace('.h', '.cpp')
    cppFilePath = tool.os.path.abspath(cppFilePath)
    if tool.os.path.exists(cppFilePath):
        contentInCpp = checkCppFile(clsInfo, cppFilePath)
        if contentInCpp:
            filePath = cppFilePath

        callHead = ''
        clsInfo[DEF.ADDHEAD] = list(set(clsInfo[DEF.ADDHEAD]))
        for headName in clsInfo[DEF.ADDHEAD]:
            callHead += '#include \"{0}.h\"\n'.format(headName)

        fContent = tool.ReadFile(filePath)
        hPos = fContent.find('#include')
        if hPos > -1:
            hPos = fContent.find('\n', hPos)
            hCon1 = fContent[:hPos + 1]
            hCon2 = fContent[hPos + 1:]
            fContent = hCon1 + callHead + hCon2
        else:
            mpos = fContent.find("#ifndef")
            if mpos > -1:
                hPos = fContent.find('#definde', mpos)
                if hPos > -1:
                    hPos = fContent.find('\n', hPos)
                    hCon1 = fContent[:hPos + 1]
                    hCon2 = fContent[hPos + 1:]
                    fContent = hCon1 + callHead + hCon2                    
            else:
                fContent = callHead + fContent
        tool.WriteFile(filePath, fContent)

#在类函数中随机添加新增函数的调用
def addNewFuncCall(filePath, clsInfo):
    clsInfo = clsInfo[DEF.CLASSINFO]
    cppFilePath = filePath.replace('.h', '.cpp')
    cppFilePath = tool.os.path.abspath(cppFilePath)
    if tool.os.path.exists(cppFilePath):
        contentInCpp = checkCppFile(clsInfo, cppFilePath)
        if contentInCpp:
            filePath = cppFilePath    

        funcCfg = ['shared', 'getInstance', 'destroyInstance', 'application', 'getStrByIdx', 'splitJoinString', 'addSpriteFrameListCallBack']
        fContent = tool.ReadFile(filePath)
        for func in clsInfo[DEF.Funcs]:
            if func.get(DEF.Static) != 1 and tool.random.randint(1, 6) == 3 and func[DEF.Name].find(clsInfo[DEF.Name]) == -1 and func[DEF.Name] not in funcCfg:
                callFunc = tool.random.choice(clsInfo[DEF.NewFunc])
                if callFunc:
                    findFlg = '{0}::{1}('.format(clsInfo[DEF.Name], func[DEF.Name])
                    pos = fContent.find(findFlg)
                    if pos > -1:
                        pos = fContent.find('{', pos)
                        con1 = fContent[:pos+1]
                        con2 = fContent[pos+1:]
                        
                        callLineStr = callFunc[DEF.Name] + FUNC.getFuncCallLine(callFunc, func)
                        callLineStr = '\n\t' + callLineStr + ';\n'
                        fContent = con1 + callLineStr + con2
                    else:
                        a = 1
                        # print("{0} not find fun {1} in {2}".format(clsInfo[DEF.Name], func[DEF.Name], filePath))
            
        tool.WriteFile(filePath, fContent)

def saveFile(params):
    clsInfo = params[DEF.CLASS]
    filePath = clsInfo[DEF.FULLFILEPATH]
    cppFilePath = filePath.replace('.h', '.cpp')
    cppFilePath = tool.os.path.abspath(cppFilePath)

    headFileCon = createHeadFileCon(clsInfo)

    tool.createDir(filePath)
    tool.WriteFile(filePath,headFileCon)

    cppFileCon = createCppFileCon(clsInfo)
    tool.createDir(cppFilePath)
    tool.WriteFile(cppFilePath, cppFileCon)
    
def createHeadFileCon(clsInfo):
    clsName = clsInfo[DEF.Name]

    headTmp = \
'#ifndef _{0}_H_\n\
#define _{0}_H_\n\
#include <string>\n\
#include <iostream>\n\
#include <sstream>\n\
#include \"cocos2d.h\"\n\
using namespace std;\n'

    endTmp = \
'#endif'

    retStr = ''
    retStr += headTmp.format(clsName.upper())
    retStr += 'class ' + clsName + '\n'
    retStr += '{\n'

    classInfo = clsInfo[DEF.CLASSINFO]
    funcList = 'public:\n'
    for funcInfo in classInfo[DEF.Funcs]:
        funcList += FUNC.getHeadFileStr(funcInfo)

    attrList = 'private:\n'
    for attrInfo in classInfo[DEF.Attrs]:
        attrList += ATTR.getHeadFileStr(attrInfo)
           
    retStr += funcList + attrList
    retStr += '};\n'

    retStr += endTmp
    return retStr

def createCppFileCon(clsInfo):
    clsName = clsInfo[DEF.Name]

    retStr = ''
    for headName in clsInfo[DEF.CLASSINFO][DEF.ADDHEAD]:
        retStr += '#include \"{0}.h\"\n'.format(headName)
    retStr += '#include \"' + clsName + '.h\"\n'
    retStr += 'USING_NS_CC;\n'

    funcList = ''
    classInfo = clsInfo[DEF.CLASSINFO]
    for funcInfo in classInfo[DEF.Funcs]:
        funcList += FUNC.getFuncRealize(funcInfo, clsInfo) 

    retStr += funcList
    return retStr

def getCallClsContent(clsInfo):
    while True:
        tmpFuncInfo = tool.random.choice( clsInfo[DEF.CLASSINFO][DEF.Funcs] )
        # 如果函数是添加的
        if DEF.FROM in tmpFuncInfo and tmpFuncInfo[DEF.FROM] == DEF.FROMTYPE.add:
            clsName = clsInfo[DEF.Name]
            tmpStr = '\n\t' + clsName + ' ' + clsName.lower() + '_e' + ";\n"
            while True:
                tmpFuncInfo = tool.random.choice(clsInfo[DEF.CLASSINFO][DEF.Funcs])
                if tmpFuncInfo[DEF.Name] != clsInfo[DEF.Name] and tmpFuncInfo[DEF.Name] != '~' + clsInfo[DEF.Name]:
                    break
            
            callFunLine = FUNC.getFunCallingLine(tmpFuncInfo)

            callFlg = '.'
            if DEF.Static in tmpFuncInfo:
                callFlg = "::"
            
            tmpStr+= '\t' + clsName.lower() + '_e' + callFlg + callFunLine + ';\n'

            return tmpStr