#!python   
# -*- coding: utf-8 -*-

from tool import toolsFunc as tool
from tool import worldsDic
from cplus import index as cplusTool
from define import globalDef as DEF
from cplus import createAttr as ATTR
from OC import index as osMain

import re
import operator

otherLan = 'OC'
lanType = 'cplus'  
def createOneClass(params):
    if lanType == 'cplus':
       return cplusTool.createClass(params)

    return '', {}

def saveCreateClass(params):
    if lanType == 'cplus':
        cplusTool.saveClass(params)

def createClassFiles(nameList, ansDic, prefixName = '', destPath = ''):
    classInfo = {}
    tool.delFolders( tool.os.path.abspath(destPath + '/'))
    totalClassNum = tool.random.randint(120, 250)
    for _ in range(totalClassNum):
        # print "begin Create class"
        tmpClassName, info = createOneClass({DEF.NAMELIST:nameList, DEF.AnalysisRet:ansDic})
        classInfo[tmpClassName + '.h'] = info
        # print "className:" , tmpClassName
        info[DEF.FULLFILEPATH] = tool.os.path.abspath(destPath + '/' + tmpClassName + '.h')
        saveCreateClass({DEF.CLASS: info})
        # print "create class OK!:" , tmpClassName

    print 'total class num:' + str(totalClassNum)
    return classInfo

#检查一个类的内容.
def checkClassContent(clsCont, clsInfo, fileName):
    retInfo = {"attrs":[], "funcs":[]}
    if clsCont.strip() == '':
        return retInfo
    
    # print fileName
    pSeed = 0
    flg = 'public'
    conLen = len(clsCont)
    while True:
        pPos = clsCont.find(';', pSeed)
        # if fileName.find('SpriteBase.h') > -1:
        #     print str(pSeed) + ' pSeed ' + str(conLen)
        if pPos > -1 and pPos < conLen - 1 and pSeed < conLen - 1:
            lineStr = clsCont[pSeed:pPos]

            if pPos == 2714:
                a = 1
            #检查是不是空行
            tmplineStr = lineStr.replace('\t', '')
            if tmplineStr.strip() == '':
                pSeed = pPos + 1
                continue

            if lineStr.find('getIsHide') > -1:
                a = 1
                
            #如果是找到标记。处理一下标记先
            if lineStr.find('public') > -1:
                flg = 'public'
                lineStr = lineStr[lineStr.find(':') + 1:]
            elif lineStr.find('protected') > -1:
                flg = 'protected'
                lineStr = lineStr[lineStr.find(':') + 1:]
            elif lineStr.find('private') > -1:
                flg = 'private'
                lineStr = lineStr[lineStr.find(':') + 1:]
            
            if clsInfo['type'] == 'class' and lineStr.find(clsInfo['name'] + '(') > -1:
                tmpFunc = {}
                retInfo['funcs'].append(tmpFunc)
                tmpFunc['limit'] = 'public'
                tmpFunc['retType'] = ''
                tmpFunc['params'] = []
                tmpFunc['createFunc'] = 1
                if lineStr.find('~') > -1:
                    tmpFunc['name'] = '~' + clsInfo['name']
                else:
                    tmpFunc['name'] = clsInfo['name']

                if lineStr.find('{') > -1:
                    pEnd, pBegin = tool.matchSymbol(lineStr, '{', '}')
                    if pEnd == -1:
                        pEnd, pBegin = tool.matchSymbol(clsCont, '{', '}', pSeed)
                    else:
                        pEnd = pEnd + pSeed
                    
                    if pEnd > -1:
                        pSeed = pEnd + 1
                        continue
                    else:
                        print fileName + "-- line error11!----------" + lineStr

                pSeed = pSeed + lineStr.find(')') + 1
                continue
            elif lineStr.find('CC_SYNTHESIZE') > -1:
                pEnd, pBegin = tool.matchSymbol(lineStr, '(', ')', tool.find_ex(lineStr, 'CC_SYNTHESIZE'))
                if pEnd > -1:
                    tmpStr = lineStr[pBegin:pEnd]
                    strs = tmpStr.split(',')
                    tmpAttr = {}
                    retInfo['attrs'].append(tmpAttr)
                    tmpAttr['name'] = strs[1].strip()
                    tmpAttr['type'] = strs[0].strip()
                    tmpAttr['limit'] = 'private'

                    tmpFunc = {}
                    retInfo['funcs'].append(tmpFunc)
                    tmpFunc['name'] = 'get' + strs[2].strip()
                    tmpFunc['limit'] = 'public'
                    tmpFunc['retType'] = strs[0].strip()
                    tmpFunc['params'] = []
                    tmpFunc['isGet'] = 1
                    
                    tmpFunc1 = {}
                    retInfo['funcs'].append(tmpFunc1)
                    tmpFunc1['name'] = 'set' + strs[2].strip()
                    tmpFunc1['limit'] = 'public'
                    tmpFunc1['retType'] = 'void'
                    tmpPar = {'type':strs[0].strip(), 'name':'var'}
                    
                    tmpFunc1['params'] = [tmpPar]
                    tmpFunc1['isSet'] = 1

                    pSeed = pSeed + pEnd + 1
                    continue
                else:
                    print 'CC_SYNTHESIZE error!! inFile:' + fileName
                    symbolEndPos = tool.find_ex(lineStr, 'CC_SYNTHESIZE')
                    pSeed = pSeed + symbolEndPos + 1
                    continue
            elif lineStr.find('(') > -1:
                #至少是个函数
                pLeft = lineStr.find('(')
                pEnd, pBegin = tool.matchSymbol(lineStr, '(', ')')

                #函数名
                pName = tool.findLastStr(lineStr, ' ', 0, pLeft)
                if lineStr[pLeft - 1] == ' ':
                    pName = tool.findLastStr(lineStr, ' ', 0, pLeft - 1)
                funcName = lineStr[pName + 1: pLeft]
                funcName = funcName.strip()
                
                tmpFunc = {}
                retInfo['funcs'].append(tmpFunc)
                tmpFunc['name'] = funcName
                tmpFunc['limit'] = flg

                funcRetType = lineStr[0:pName]
                funcRetType = funcRetType.strip()
                tmpFunc['retType'] = funcRetType

                if funcRetType.find('virtual') > -1:
                    tmpFunc['isVirtualFunc'] = 1
                
                paramsList = []
                tmpFunc['params'] = paramsList
                paramStr = lineStr[pBegin:pEnd]
                if paramStr:
                    params = paramStr.split(',')
                    for oneParam in params:
                        if oneParam:
                            pDefEquip = oneParam.find('=')
                            oneInfo = {}
                            if pDefEquip > -1:
                                defVal = oneParam[pDefEquip + 1:]
                                defVal = defVal.strip()
                                oneInfo['defVal'] = defVal
                                oneParam = oneParam[:pDefEquip]
                                oneParam = oneParam.strip()

                            tmpPos = tool.findLastStr(oneParam, ' ', 0)
                            oneInfo['type'] = oneParam[:tmpPos]
                            oneInfo['name'] = oneParam[tmpPos+1:]
                            paramsList.append(oneInfo)
                        else:
                            print 'oneParam error! info:' +  paramStr
                            retInfo['funcs'].remove(tmpFunc)

                if lineStr.find('{') > -1:
                    pEnd, pBegin = tool.matchSymbol(lineStr, '{', '}')
                    if pEnd == -1:
                        pEnd, pBegin = tool.matchSymbol(clsCont, '{', '}', pSeed)
                    else:
                        pEnd = pSeed + pEnd
                    
                    if pEnd > -1:
                        pSeed = pEnd + 1
                        continue
                    else:
                        print fileName + "-- line error!----------" + lineStr
                    

                pSeed = pPos + 1
                continue
            else:
                tmpAttr = {}
                retInfo['attrs'].append(tmpAttr)
                tmpPos = tool.findLastStr(lineStr, ' ')
                tmpAttr['type'] = lineStr[0:tmpPos]
                tmpAttr['name'] = lineStr[tmpPos + 1:]
                tmpAttr['limit'] = flg
                pSeed = pPos + 1
                continue
        else:
            break

    return retInfo

def checkClassFromContent(content, layer, srcFile):
    classInfo = []
    posFind = 0
    classTypeHead = 'class'

    #友元类、枚举类
    matcherDic = {}
    findList = [r'friend *class', r'enum *class']
    for val in findList:
        posList = [i.start() for i in re.finditer(val , content)]
        valList = [i.group() for i in re.finditer(val , content)]
        for i in range(len(posList)):
            matcherDic[posList[i]] = valList[i]

    while True:
        pClass = content.find(classTypeHead, posFind)

        list=sorted(matcherDic.items(),key=operator.itemgetter(0),reverse=False)
        for item in list:
            pos = item[0]
            val = item[1]
            if pos + len(val) == pClass + len(classTypeHead):
                posFind = pos + len(val)
                pClass = content.find(classTypeHead, posFind)
        
        # pLuaClass = tool.findLastStr(content, 'tolua_cclass', posFind, pClass + len(classTypeHead))
        # if pLuaClass > -1 and pLuaClass + len('tolua_cclass')  == pClass + len(classTypeHead):
        #     posFind = pLuaClass + len('tolua_cclass')
        #     pClass = content.find(classTypeHead, posFind)

        # pLuaClass = tool.findLastStr(content, 'classesBoundSynthesize', posFind)
        # if pLuaClass > -1 and pLuaClass  == pClass:
        #     posFind = pLuaClass + len('classesBoundSynthesize')
        #     pClass = content.find(classTypeHead, posFind)

        if pClass > -1:
            #如果class后面冲突了.
            pNextChar = content[pClass + len(classTypeHead)]
            pBeforeChar = content[pClass - 1]

            if pNextChar.isdigit() or pNextChar.isalnum() or pNextChar == "_":
                posFind = pClass + len(classTypeHead)
                pClass = content.find(classTypeHead, posFind)
            elif pBeforeChar.isdigit() or pBeforeChar.isalnum() or pBeforeChar == "_":
                posFind = pClass + len(classTypeHead)
                pClass = content.find(classTypeHead, posFind)

        if pClass > -1:
            oneClassInfo = {}
            classInfo.append(oneClassInfo)
            oneClassInfo['type'] = classTypeHead
            posFind = pClass + len(classTypeHead)

            # 找到类的名字
            pClassDefEnd = tool.getEndPosByEndList(content, posFind, ['\r\n', '\n', ':'])
            if pClassDefEnd > -1:
                pClassName = tool.getNameFromStr(content, posFind, pClassDefEnd)
                oneClassInfo['name'] = pClassName

                if pClassName.find(';') > -1:
                    classInfo.remove(oneClassInfo)
                    continue

            # 找到类的内容区域
            if srcFile.find("MapView.h") > -1:
                a = 1
            pClassContentEnd, pClassContentBegin = tool.matchSymbol(content, '{', '}', posFind)
            if pClassContentEnd > -1:
                oneClassInfo['inClass'] = checkClassFromContent(content[pClassContentBegin:pClassContentEnd], layer + 1, srcFile)
                oneClassInfo['ContentBegin'] = pClassContentBegin
                oneClassInfo['ContentEnd'] = pClassContentEnd
                oneClassInfo['StructStar'] = pClass

                cls_con = content[pClassContentBegin:pClassContentEnd]
                new_con = ''
                contentList = []
                if oneClassInfo['inClass']:
                    posSplit = 0
                    for tmpInfo in oneClassInfo['inClass']:
                        pBegin = tmpInfo['StructStar']
                        pEnd = tmpInfo['ContentEnd']
                        contentList.append(cls_con[posSplit:pBegin])
                        posSplit = pEnd + 2

                    contentList.append(cls_con[posSplit:])
                else:
                    new_con = cls_con

                for con in contentList:
                    if con:
                        new_con = new_con + con
                oneClassInfo['classInfo'] = checkClassContent(new_con, oneClassInfo, srcFile)

                posFind = pClassContentEnd + 1
            else:
                classInfo.remove(oneClassInfo)
        else:
            break
    checkStructFromContent(classInfo, content, layer, srcFile)

    return classInfo

def checkStructFromContent(classInfo, content, layer, srcFile):
    posFind = 0
    headCfg = ['enum ', 'struct ']
    for head in headCfg:
        while True:
            classHead = head
            pEnum1 = content.find(classHead, posFind)
            if pEnum1 > -1:
                for checkClass in classInfo:
                    if checkClass['ContentBegin'] <= pEnum1 <= checkClass['ContentEnd']:
                        posFind = checkClass['ContentEnd'] + 1
                        pEnum1 = content.find(classHead, posFind)

            if pEnum1 > -1:
                if classHead == 'enum ':
                    pEx = content[pEnum1: pEnum1 + 20].find('class')
                    if pEx > -1:
                        classHead = content[pEnum1: pEnum1 + pEx + len('class')]
                
                pChar1 = content.find(';', pEnum1)
                pChar2 = content.find(',', pEnum1)

                pChar = content.find('{', pEnum1)
                if pChar1 > -1 and (pChar == -1 or pChar > pChar1):
                    posFind = pChar1 + 1
                    continue

                elif pChar2 > -1 and  (pChar == -1 or pChar > pChar2):
                    posFind = pChar2 + 1
                    continue
                oneEnumInfo = {}
                classInfo.append(oneEnumInfo)
                posFind = pEnum1 + len(classHead)
                oneEnumInfo['type'] = classHead
                
                pEnumDefEnd = tool.getEndPosByEndList(content, posFind, ['\r\n', '\n', '{', ':'])
                if pEnumDefEnd > -1:
                    pEnumName = tool.getNameFromStr(content, posFind, pEnumDefEnd)
                    if pEnumName:
                        oneEnumInfo['name'] = []
                        oneEnumInfo['name'].append(pEnumName)
                pContentEnd, pContentBegin = tool.matchSymbol(content, '{', '}', posFind)
                if pContentEnd > -1:
                    oneEnumInfo['ContentBegin'] = pContentBegin
                    oneEnumInfo['ContentEnd'] = pContentEnd
                    oneEnumInfo['StructStar'] = pEnum1
                    cls_con = content[oneEnumInfo['ContentBegin']:oneEnumInfo['ContentEnd']]
                    if head.find('enum') == -1:
                        oneEnumInfo['classInfo'] = checkClassContent(cls_con, oneEnumInfo, srcFile)
                    
                    posFind = pContentEnd
            
                pEnumDefEnd = tool.getEndPosByEndList(content, pContentEnd + 1, ['\r\n', '\n', ';', ":"])
                if pEnumDefEnd > -1:
                    pEnumName = tool.getNameFromStr(content, pContentEnd + 1, pEnumDefEnd)
                    if pEnumName:
                        if type(pEnumName) is list :
                            oneEnumInfo['name'] = pEnumName
                        else:
                            oneEnumInfo['name'] = []
                            oneEnumInfo['name'].append(pEnumName)

                if not 'name' in oneEnumInfo:
                    classInfo.remove(oneEnumInfo)
                    continue

                for key in oneEnumInfo['name']:
                    if ' ' in key or '*' in key:
                        print 'check:' + srcFile
                        print 'name error! info:' + key
            else:
                break

#分析单个文件
def analysisFile(lanType, srcFile):
    # print '==================================================================='
    # print 'check:' + srcFile

    funInfo = {'class':{}}
    if lanType == "cplus":
        #C++ 头文件解析
        if srcFile.find('.h') > -1:
            f_content = tool.ReadFile(srcFile)
            f_len = len(f_content)
            #头文件宏定义
            pHeadDef = f_content.find('#ifndef')
            if pHeadDef > -1:
                pHeadDef1 = pHeadDef + len('#ifndef')
                pHeadDefEnd = tool.getEndPosByEndList(f_content, pHeadDef1)
                
                headStr = f_content[pHeadDef1:pHeadDefEnd]
                headStr = headStr.strip()
                funInfo['HDef'] = headStr
            
            if srcFile.find('tolua_') > -1:
                return funInfo
            
            funInfo[DEF.CLASS] = checkClassFromContent(f_content, 1, srcFile)

    funInfo[DEF.FULLFILEPATH] = srcFile
    return funInfo

#分析文件夹
def analysisFiles(path, lanType):
    fileSuf = []
    if lanType == "cplus":
        # fileSuf.append('.cpp')
        fileSuf.append('.h')

    analyRet = {}
    path = tool.os.path.abspath(path)
    for root,dirs,files in tool.os.walk(path):
        for everyFile in files:
            bFind = False
            for suf in fileSuf:
                if suf in everyFile:
                    bFind = True
                    break
            if bFind and ('\\pbc' not in root) and root.find('\\YunVaSDK') == -1 and root.find('\\ide-support') == -1 and root.find('\\lua-cjson') and root.find("\\Ycommon") == -1:
                srcFile = tool.os.path.join(path, root + "/" + everyFile)
                analyRet[everyFile] = analysisFile(lanType, srcFile)

    return analyRet

def changeLogToLuaFile(changeLog, destFile):
    wContent = 'local function initFile()\n'
    wContent1 = 'local classCfg = {\n'        
    for key, val in changeLog.items():
        if key.find('.') == -1:
            wContent += '    ' + val + ' = ' + val + ' or {} \n'
            wContent += '    ' + key + ' = ' + val + '\n'
            wContent1 += '    ' + key + ' = ' + '\"'+ val + '\"' + ',\n'

    for key1, val1 in changeLog.items():
        if key1.find('.') > -1:
            wContent += '    ' + key1 + ' = ' + val1 + '\n'
    wContent += 'end\n' + 'initFile()\n'

    wContent1 += '}\nfunction getRelClassName(clsName)\n'
    wContent1 += '    if classCfg[clsName] then return classCfg[clsName] end\n'
    wContent1 += '    return clsName\n'
    wContent1 += 'end'
    wContent += wContent1
    tool.WriteFile(destFile, wContent)

def encryptionStringCpluse(oldPath, newPath):
    oldPath = tool.os.path.abspath(oldPath)
    newPath = tool.os.path.abspath(newPath)

    #找到对应的文件
    keyFileName = 'AppDelegate.cpp'
    filePath = tool.os.path.join(oldPath, keyFileName)
    newFilePath = tool.os.path.join(newPath, keyFileName)
    if not tool.os.path.exists(filePath):
        print keyFileName + ' not find !!!!'
        return

    key = 'strCfgList'
    fContent = tool.ReadFile(filePath)
    pos = fContent.find(key)
    tmpCfg = None
    newContent = ''
    if pos > -1:
        tmpCfg = tool.randomStrCfg()
        line = tool.strRandomList(tmpCfg)

        posRight, posLeft = tool.matchSymbol(fContent, '{', '}', pos)
        con1 = fContent[:posLeft]
        con2 = fContent[posRight:]
        newContent = con1 + line + con2

        tool.createDir(newFilePath)
        tool.WriteFile(newFilePath, newContent)

    if not tmpCfg:
        print "no  new strCfgList !!!"
        return

    for root,_,files in tool.os.walk(oldPath):
        for everyFile in files:
            fileName = root + '\\' + everyFile
            fileName = fileName.replace(oldPath + '\\', '')
            oldFilePath = tool.os.path.join(oldPath, fileName)
            newFilePath = tool.os.path.join(newPath, fileName)
            if oldFilePath.find(keyFileName) == -1:
                fContent = tool.ReadFile(oldFilePath)
            else:
                fContent = newContent

            pos = 0
            while True:
                pos = fContent.find("int tmpSymbolKey", pos)
                if pos == -1:
                    pos = fContent.find("int  tmpSymbolKey", pos)

                if pos > -1:
                    posRight, posLeft = tool.matchSymbol(fContent, '{',  '}', pos)
                    posSymRight, posSymLeft = tool.matchSymbol(fContent, '\"',  '\"', pos)
                    if posLeft > -1 and posRight > -1 and posSymRight > -1 and posSymLeft > -1:
                        strContent = fContent[posSymLeft: posSymRight]
                        newContent = tool.strRandomList(tool.getStrEnc(strContent, tmpCfg))

                        con1 = fContent[:posLeft]
                        con2 = fContent[posRight:]

                        fContent = con1 + newContent + con2
                        pos = posLeft + len(newContent)
                        oldPos = pos

                        key = "STRNUMSIG"
                        pos = fContent.find(key, pos)
                        con1 = fContent[:pos]
                        con2 = fContent[pos + len(key):]
                        fContent = con1 + str(len(strContent)) + con2

                        pos = oldPos
                else:
                    break
            
            tool.createDir(newFilePath)
            tool.WriteFile(newFilePath, fContent)

def changeDicToText(changeDic, destFile):
    outStr = ''
    for key,val in changeDic.items():
        if key:
            outStr += key + "|" + val +'\r\n'
    tool.WriteFile(destFile, outStr)

def initChangeDic(destFile):
    ret = {}
    def func(strVal):
        strs = strVal.split('|')
        ret[strs[0]] = strs[1]
    tool.ReadLineFile(destFile, func)
    return ret

def setChanDIc(changeDic, itemKey, itemVal):
    if itemKey == 'Container':
        a = 1
    if itemKey in changeDic.keys():
        return
    else:
        if itemKey == 'MsgID':
            a = 1
        changeDic[itemKey] = itemVal

def main():
    print tool.showTime() + u"准备混淆c++代码"
    worldsDic.initWorldArray('res/worldDic.txt')

    # files = 'D:/tools/workCode/cPlusCodeChange/out/oc_targetIosFile/LXrConvertedClassesHelper.mm'
    # mFileContent = tool.ReadFile(files)
    # # filterStr = r'[-+]+\(.*\)[\t\f]*'+ 'didRotateFromInterfaceOrientation' + ':*\\n+'
    # filterStr = r'[\n][-+]+[^\n]*' + 'didRotateFromInterfaceOrientation' + '[^\n]*[\n]'
    # ret = re.search(filterStr, mFileContent)
    # if ret:
    #     print ret.span()[1]
    # return
    retList = []

    CplusList = ['overloaded/specializationDeclaration4.zip', 'sets/splitHex.lua', 'precedes/Extend_ex.lua']
    CplusCfg = [69,56,87,77,88,48,92,34,53,63,109,113,81,65,74,42,114,32,78,55,39,115,118,80,72,45,52,66,104,99,41,106,120,100,82,70,103,101,44,73,49,83,79,121,108,57,43,84,98,107,117,54,35,50,33,97,86,116,47,90,95,75,85,40,122,89,111,76,110,71,37,58,67,112,64,105,102,68,119,51,46]
    for val in CplusList:
        newContent = tool.strRandomList(tool.getStrEnc1(val, CplusCfg))
        retList.append([val, newContent])

    OCList = ['an.ywl.']
    OCCfg = [95,40,79,107,49,35,44,89,113,106,67,42,56,116,119,112,104,75,88,63,54,101,117,99,90,118,109,37,92,102,105,115,48,45,66,52,64,68,50,46,76,122,103,78,43,87,108,81,121,65,98,33,86,58,32,85,57,72,74,83,97,34,53,100,55,82,39,111,41,47,110,114,84,73,51,69,77,71,70,120,80]
    for val in OCList:
        newContent = tool.strRandomList(tool.getStrEnc1(val, OCCfg))
        retList.append([val, newContent])

    # worldsDic.setClsHead(tool.getRandomChar(1, 65, 90).upper() + tool.getRandomChar(1, 65, 90).upper()+ tool.getRandomChar(1, 65, 90).upper())
    worldsDic.setClsHead("JIG")
    if True:
        osMain.myMain()
        # return

    # 确认需要创建多少类
    # 创建类
    # 创建函数
    # 创建属性

    # 准备几个工具类.

    # 准备创建互相调用关系,可以相互调用.
    # 工具类添加子属性，方法内加子属性的方法调用.


    # 输出调用示例， 准备追加到原来的文件中.

    #分析C++文件语法，能直接分析到函数最好了，批量改函数。
    
    # 分析oc文件语法
    # oc 暂时不分析语法了. 直接来
    
    cfg = tool.randomStrCfg()
    line = tool.strRandomList(cfg)

    classPath1 = 'res/Classes'
    classPath2 = 'out/Classes'
    classPath3 = 'out/c_changeClass'
    classPath4 = 'out/c_CreateClass'
    classPath5 = 'out/c_dealString'
    
    # classPath1 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes/'
    # classPath2 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes_ex/'
    # classPath3 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes_ex/'
    # classPath4 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes_ex/'
    tool.delFolders(classPath2)
    tool.delFolders(classPath3)
    tool.delFolders(classPath4)
    tool.delFolders(classPath5)
    tool.createDir(tool.os.path.abspath(classPath5) + '/')

    encryptionStringCpluse(classPath1, classPath5)
    worldsDic.clearnFiles('cplus', classPath5, classPath2)
    # print '!!clearnFiles over!!'

    ansDic = analysisFiles(classPath2, 'cplus')

    changeDic = initChangeDic('out/changeText.txt')
    changeLog = {}

    className = worldsDic.randomWorldS(13000, 'cplusClass')
    classFunc = worldsDic.randomWorldS(19000, 'cplusFunc')
    classAttr = worldsDic.randomWorldS(19000, 'cplusAttr')
    exFuncName = ['setPosition', 'getPosition', 'getPositionX', 'setPositionX', 'getPositionY','getPositionY', 'setLocalZOrder', 'setOpacity', 'setVisible', 'init', 'setEnable'
    ,'initWithFile', 'getOpacity', 'getLocalZOrder','cleanup', 'setColor', 'create', 'onTouchDown', 'setSwallowTouch', 'SwallowTouch', 'GUID', 'setDimensions', 'setSystemFontSize'
    ,'initWithTexture', 'setAdditionalKerning', 'setHorizontalAlignment', 'setVerticalAlignment', 'setLineBreakWithoutSpace', 'setColor', 'getColor', 'getString', 'setString', 'runAction'
    ,'getMapTileSize', 'getLayerSize', 'unselected', 'applicationDidEnterBackground', 'applicationDidFinishLaunching', 'applicationWillEnterForeground', 'initGLContextAttrs', 'getOpacity'
    ,'setContentSize', 'ContentSize', 'getInstance', 'setContentOffset', 'getContentSize', 'Instance', 'ViewRect', 'Handler','onTouchBegan','onTouchMoved','onTouchEnded', 'setRenderMode'
    ,'RenderMode', 'toluafix_pushusertype_ccobject', 'CREATE_FUNC', 'Delegate', 'getHandler', 'setDelegate', 'pushString', 'updateTweenAction', 'onTouchCancelled', 'instance', 'Container'
    ,'ContentOffsetInDuration', 'ContentOffset', 'getContentOffset']

    for key in changeDic.keys():
        if key in exFuncName:
            del changeDic[key]
            print 'move-----' + key

    for key, val in ansDic.items():
        if val['class']:
            def showClass(classInfo, layer):
                classNameList = []
                if type(classInfo['name']) is list:
                    for name in classInfo['name']:
                        if tool.checkStrIsOk(name) and name.find('AppDelegate') == -1 and name not in exFuncName:
                            setChanDIc(changeDic, name, className.pop())
                            changeLog[name] = changeDic[name]
                            classNameList.append(name)
                else:
                    name = classInfo['name']
                    if tool.checkStrIsOk(name) and name.find('AppDelegate') == -1 and name not in exFuncName:
                        setChanDIc(changeDic, name, className.pop())
                        changeLog[name] = changeDic[name]
                        classNameList.append(name)
                
                if 'inClass' in classInfo and classInfo['inClass']:
                    for tmpClass in classInfo['inClass']:
                        showClass(tmpClass, layer + 1)

                if 'classInfo' in classInfo:
                    for tmpFunc in classInfo['classInfo']['funcs']:
                        funcName = tmpFunc['name']
                        if tool.checkStrIsOk(funcName) and len(funcName) >= 10 :
                            val = ''
                            if 'createFunc' in tmpFunc:
                                continue
                            elif funcName in exFuncName:
                                continue
                            elif funcName[0:3] == "get" and funcName[3:] not in exFuncName:
                                setChanDIc(changeDic, funcName[3:], classFunc.pop())
                                val = 'get' + changeDic[funcName[3:]]
                            elif funcName[0:3] == "set" and funcName[3:] not in exFuncName:
                                setChanDIc(changeDic, funcName[3:], classFunc.pop())
                                val = 'set' + changeDic[funcName[3:]]
                            else:
                                setChanDIc(changeDic, funcName, classFunc.pop())
                                val = changeDic[funcName]
                            
                            for clsName in classNameList:
                                changeLog[clsName + '.' + funcName] = changeDic[clsName] + '.' + val

                    for tmpFunc in classInfo['classInfo']['attrs']:
                        attrName = tmpFunc['name']
                        if tool.checkStrIsOk(attrName) and len(attrName) >= 10 :
                            # if attrName[0:2] == 'm_' and Name:
                            #     attrName = attrName[2:]
                            #     setChanDIc(changeDic, attrName, classAttr.pop())
                            # el
                            if attrName in exFuncName:
                                continue
                            else:
                                randInt = tool.random.randint(1, 5)
                                if randInt < 4:
                                    setChanDIc(changeDic, attrName, 'm_' + classAttr.pop())
                                else:
                                    setChanDIc(changeDic, attrName, classAttr.pop())

            for classInfo in val['class']:
                showClass(classInfo, 1)
                
    # print '==========------------------------------------------------=============='    
    # print changeDic
    # print '==========------------------------------------------------=============='
    # print changeLog
    print '==========------------------------------------------------=============='
    print '!!check over!! changeDic:' + str(len(changeDic)) + ",changeLog:" + str(len(changeLog))
    print '==========------------------------------------------------=============='
    print 'left className' + str(len(className)) + ", classFunc" + str(len(classFunc)) + ", classAttr" + str(len(classAttr))
    changeLog['createDownloadDir'] = changeDic['createDownloadDir']

    cplusTool.extendClass(ansDic, {DEF.NAMELIST:[className, classFunc, classAttr]})
    createClassList = createClassFiles([className, classFunc, classAttr], ansDic, '', classPath4)

    staticFunCallStr = ''
    staticFuncNum = tool.random.randint(30, 80)
    for filePath, val in ansDic.items():
        if val['class']:
            for classInfo in reversed(val['class']):
                if classInfo[DEF.TYPE] == DEF.CLASS and staticFuncNum > 0:
                    for funcInfo in classInfo[DEF.CLASSINFO][DEF.Funcs]:
                        if DEF.FROM in funcInfo and funcInfo[DEF.FROM] == DEF.FROMTYPE.add:
                            if tool.random.randint(1, 5) == 2 and staticFuncNum > 0 :
                                staticFuncNum -= 1
                                funcInfo[DEF.Static] = True
                                staticFunCallStr += classInfo[DEF.Name] + "::"
                                
                                paramStr = cplusTool.getCallFuncLine(funcInfo)
                                staticFunCallStr += paramStr + ';\n'
                            elif staticFuncNum == 0:
                                break
                elif staticFuncNum == 0:
                    break
        elif staticFuncNum == 0:
            break
    staticFunCallStr += '\n'
    
    newClassItems = createClassList.items()
    for filePath, val in ansDic.items():
        if val['class']:
            filePath = val[DEF.FULLFILEPATH]
            tmpCallOther = []
            callOtherClass = None
            for classInfo in reversed(val['class']):
                if classInfo[DEF.TYPE] == DEF.CLASS:
                    if tool.os.path.exists(filePath):
                        
                        if tool.random.randint(1, 2) == 2 and not callOtherClass:
                            tmpClsHead, tmpClsInfo = tool.random.choice(newClassItems)
                            tmpLine = cplusTool.getCallClsContent(tmpClsInfo)
                            tmpCallOther.append( '#include \"' + tmpClsHead + '\"\n')
                            tmpCallOther.append(tmpLine)
                            callOtherClass = classInfo

                            # print "file add call", filePath, classInfo[DEF.Name], tmpClsHead

                        cplusTool.addExternFuncInfo(filePath , classInfo)
                    else:
                        print filePath + " not find ... "
                        
            if callOtherClass:
                cplusTool.addCallClassContent(filePath, callOtherClass, tmpCallOther)

    changeLogToLuaFile(changeLog, 'out/roleTargetChenged.lua')
    changeDicToText(changeDic, 'out/changeText.txt')
    osMain.changeTextFiles(changeDic, classPath2, classPath3, True)
    print '==========------------------------------------------------============== allNewFuncNum' + str(DEF.TCplusNum)
    print "change OK"

    staticFunCallStr = osMain.changeStrByDic(changeDic, staticFunCallStr)
    # print('staticFunCallStr:', staticFunCallStr)
    tool.WriteFile("out/StaticCallText.txt", staticFunCallStr)
    tool.os.system("pause")

if __name__=="__main__":
    main()