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
    info = {DEF.CLASSINFO:{}, DEF.Name:clsName}
    info[DEF.CLASSINFO] = { DEF.Funcs:[], DEF.Attrs:[] }

    tmpFuncBack = FUNC.createNormalFun(params, info, 1)
    info[DEF.CLASSINFO][DEF.Funcs].append(tmpFuncBack)
    
    tmpFuncBack = FUNC.createNormalFun(params, info, 2)
    info[DEF.CLASSINFO][DEF.Funcs].append(tmpFuncBack)

    addFuncNum = tool.random.randint(6, 50)
    for _ in range(addFuncNum):
        tmpFuncBack = FUNC.create({DEF.TYPE:DEF.CClassType.base, DEF.NAMELIST:nameList, DEF.CLASSINFO:info})
        info[DEF.CLASSINFO][DEF.Funcs].append( tmpFuncBack )
    
    addAttrNum = tool.random.randint(3, 10)
    for _ in range(addAttrNum):
        tmpAttrBack = ATTR.create({DEF.TYPE:DEF.CClassType.base, DEF.NAMELIST:nameList, DEF.CLASSINFO:info})
        info[DEF.CLASSINFO][DEF.Attrs].append(tmpAttrBack)

    return clsName, info

def extendClass(analRet, params):
    nameList = params[DEF.NAMELIST]

    for _, info in analRet.items():
        if not info[DEF.CLASS]:
            continue
        
        for cInfo in info[DEF.CLASS]:
            clsName = cInfo[DEF.Name]
            if cInfo['type'] == 'class':
                hasFuncNum = len(cInfo[DEF.CLASSINFO][DEF.Funcs])
                # print 'extend class [' + clsName + '] begin ...'
                addFuncNum = 0
                if hasFuncNum < 10 or hasFuncNum > 20:
                    # 如果类的函数少于10个
                    addFuncNum = tool.random.randint(5, 12)
                    for _ in range(addFuncNum):
                        tmpFuncBack = FUNC.create({DEF.TYPE:DEF.CClassType.base, DEF.NAMELIST:nameList, DEF.CLASSINFO:cInfo})
                        cInfo[DEF.CLASSINFO][DEF.Funcs].append( tmpFuncBack )
                
                hasAttrNum = len(cInfo[DEF.CLASSINFO][DEF.Attrs])
                addAttrNum = 0
                if hasAttrNum < 6 or hasAttrNum > 15:
                    addAttrNum = tool.random.randint(1, 5)

                    for _ in range(addAttrNum):
                        tmpAttrBack = ATTR.create({DEF.TYPE:DEF.CClassType.base, DEF.NAMELIST:nameList, DEF.CLASSINFO:cInfo})
                        cInfo[DEF.CLASSINFO][DEF.Attrs].append(tmpAttrBack)

                # print 'extend class [' + clsName + '] addfunc:' + str(addFuncNum) + ",addAttr:" + str(addAttrNum) + ' end ...'                
            # else:
            #     if type(cInfo[DEF.Name]) is list:
            #         print cInfo[DEF.Name][0] + 'is a ' + cInfo['type']
            #     else:
            #         print cInfo[DEF.Name] + 'is a ' + cInfo['type']

def checkClassHasAttr(info, attrName):
    attrInfo = info[DEF.CLASSINFO][DEF.Attrs]
    for tmpInfo in attrInfo:
        if tmpInfo[DEF.Name] == attrName:
            return True
    
    return False

def checkHasClass(info, funcName):
    funcInfo = info[DEF.CLASSINFO][DEF.Funcs]
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

def addHeadFileCon(clsInfo, filePath, funcNeedReal):
    classInfo = clsInfo[DEF.CLASSINFO]
            
    flg = False
    funcList = 'public:\n'
    for funcInfo in classInfo[DEF.Funcs]:
        if DEF.FROM in funcInfo and funcInfo[DEF.FROM] == DEF.FROMTYPE.add:
            if funcNeedReal:
                funcList += FUNC.getFuncRealize(funcInfo, clsInfo, True)
            else:
                funcList += FUNC.getHeadFileStr(funcInfo)
            flg = True
    
    attrList = 'private:\n'
    for attrInfo in classInfo[DEF.Attrs]:
        if DEF.FROM in attrInfo and attrInfo[DEF.FROM] == DEF.FROMTYPE.add:
            attrList += ATTR.getHeadFileStr(attrInfo)
            flg = True

    if flg:
        endPos = clsInfo[DEF.CONTENTEND]
        fHeadContent = tool.ReadFile(filePath)
        fHeadContentA = fHeadContent[:endPos]
        fHeadContentB = fHeadContent[endPos:]
        newContent = fHeadContentA + funcList + attrList + fHeadContentB
        tool.WriteFile(filePath, newContent)
        if funcNeedReal:
            return False
        return True

    return False

def addCppFileCon(clsInfo, filePath):
    classInfo = clsInfo[DEF.CLASSINFO]
    
    flg = False
    funcList = '\n'
    clsName = clsInfo[DEF.Name]
    #如果有添加的类
    for funcInfo in classInfo[DEF.Funcs]:
        if DEF.FROM in funcInfo and funcInfo[DEF.FROM] == DEF.FROMTYPE.add:
            funcList += FUNC.getFuncRealize(funcInfo, clsInfo)
            flg = True

    if filePath.find('YGirdViewCell') > -1:
        a = 1
    if flg:
        fContent = tool.ReadFile(filePath)
        endPos = tool.findLastStr(fContent, clsName + '::')
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
            print 'no Find ' + clsName + '::' + 'in file ' + filePath + '~'

#添加随机的函数
def addExternInfo(filePath ,clsInfo):
    cppFilePath = filePath.replace('.h', '.cpp')
    cppFilePath = tool.os.path.abspath(cppFilePath)
    if tool.os.path.exists(cppFilePath):
        flg = checkCppFile(clsInfo, cppFilePath)
        flg = addHeadFileCon(clsInfo, filePath, not flg)

        if flg:
            # 找到类的最后一个字符，在这个位置加上新加的代码.
            addCppFileCon(clsInfo, cppFilePath)

    else:
        print tool.showTime() + filePath + " not find ... " 

#在文件中添加随机调用类的内容
def addCallClassContent(filePath, clsInfo, callInfo):
    cppFilePath = filePath.replace('.h', '.cpp')
    cppFilePath = tool.os.path.abspath(cppFilePath)
    if tool.os.path.exists(cppFilePath):
        flg = checkCppFile(clsInfo, cppFilePath)
        if flg:
            filePath = cppFilePath

        callHead = callInfo[0]
        callLine = callInfo[1]
        fContent = tool.ReadFile(filePath)
        func = tool.random.choice(clsInfo[DEF.CLASSINFO][DEF.Funcs])
        funcFlg = clsInfo[DEF.Name] + "::" + func[DEF.Name]
        pos = fContent.find(funcFlg)

        if pos == -1:
            pos = tool.find_last(fContent, func[DEF.Name])

        if pos > -1:
            pos = fContent.find('{', pos + 1)
            if pos > -1:
                con1 = fContent[:pos + 1]
                con2 = fContent[pos + 1:]

                hPos = con1.find('#include')
                if hPos > -1:
                    hPos = con1.find("\n", hPos)
                    hCon1 = con1[:hPos + 1]
                    hCon2 = con1[hPos + 1:]
                    con1 = hCon1 + callHead + hCon2
                else:
                    mpos = con1.find("#ifndef")
                    if mpos > -1:
                        mpos = con1.find("#definde", mpos)
                        if mpos > -1:
                            mpos = con1.find("\n", mpos)
                            hCon1 = con1[:mpos + 1]
                            hCon2 = con1[mpos + 1:]
                            con1 = hCon1 + callHead + hCon2
                    else:
                        con1 = callHead + con1
                callLine = tool.unicodeToAscii(callLine)
                newCon = con1 + callLine + con2
                tool.WriteFile(filePath, newCon)

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
    a = 1
    
def createHeadFileCon(clsInfo):
    clsName = clsInfo[DEF.Name]

    headTmp = \
'#ifndef _{0}_H_\n\
#define _{0}_H_\n\
#include <string>\n\
#include <iostream>\n\
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