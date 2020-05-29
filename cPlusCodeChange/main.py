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

def saveCreateClass(params):
    cplusTool.saveClass(params)

def createClassFiles(nameList, destPath = ''):
    classInfo = {}
    tool.delFolders( tool.os.path.abspath(destPath + '/'))
    totalFuncNum = 0
    totalAttrNum = 0
    totalClassNum = tool.random.randint(50, 80)
    num = round(totalClassNum / 4 * 3)
    num = num > 0 and num or 1

    for i in range(totalClassNum):
        clsType = DEF.CLSTYPE.level2 if (i > num ) else DEF.CLSTYPE.level1
        tmpClassName, info = cplusTool.createClass({DEF.NAMELIST:nameList, DEF.CRTTYPE:clsType, "classList": classInfo})
        classInfo[tmpClassName + '.h'] = info

        info[DEF.FULLFILEPATH] = tool.os.path.abspath(destPath + '/' + tmpClassName + '.h')
        saveCreateClass({DEF.CLASS: info})
        
        totalFuncNum += len(info[DEF.CLASSINFO][DEF.Funcs])
        totalAttrNum += len(info[DEF.CLASSINFO][DEF.Attrs])

    print 'Total create class num:' + str(totalClassNum)
    print 'Total create func  num:' + str(totalFuncNum)
    print 'Total create attr  num:' + str(totalAttrNum)
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
                tmpFunc[DEF.FUNCRET] = ''
                tmpFunc[DEF.PARAMS] = []
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
                    tmpFunc[DEF.FUNCRET] = strs[0].strip()
                    tmpFunc[DEF.PARAMS] = []
                    tmpFunc['isGet'] = 1
                    
                    tmpFunc1 = {}
                    retInfo['funcs'].append(tmpFunc1)
                    tmpFunc1['name'] = 'set' + strs[2].strip()
                    tmpFunc1['limit'] = 'public'
                    tmpFunc1[DEF.FUNCRET] = 'void'
                    tmpPar = {'type':strs[0].strip(), 'name':'var'}
                    
                    tmpFunc1[DEF.PARAMS] = [tmpPar]
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
                tmpFunc[DEF.FUNCRET] = funcRetType

                if funcRetType.find('virtual') > -1:
                    tmpFunc['isVirtualFunc'] = 1
                
                if funcRetType.find('static') > -1:
                    tmpFunc[DEF.Static] = 1

                if funcRetType.find('inline') > -1:
                    tmpFunc[DEF.Static] = 1
                
                paramsList = []
                tmpFunc[DEF.PARAMS] = paramsList
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
                oneClassInfo['classInfo'][DEF.CRTTYPE] = DEF.CLSTYPE.level3
                oneClassInfo['classInfo'][DEF.NewFunc] = []
                oneClassInfo['classInfo'][DEF.NewAttrs] = []
                oneClassInfo['classInfo'][DEF.ADDHEAD] = []
                oneClassInfo['classInfo'][DEF.Name] = pClassName
                
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

    # files = 'D:/tools/workCode/cPlusCodeChange/res/Classes/young/GUI/ScrollView/YScrollView.h'
    # mFileContent = tool.ReadFile(files)
    # # filterStr = r'[-+]+\(.*\)[\t\f]*'+ 'didRotateFromInterfaceOrientation' + ':*\\n+'
    # filterStr = r'[\n]+' + 'class YScrollView' + '[^A-Za-z0-9_;][^;\{\n]*[\n]?\{'
    # ret = re.search(filterStr, mFileContent)
    # if ret:
    #     pos = ret.span()[0]
    #     pos1 = ret.span()[1]
    #     print pos, mFileContent[pos:pos1]
    # return

    print tool.showTime() + u"准备混淆c++代码"
    worldsDic.initWorldArray('res/worldDic.txt')

    def randomKey(log, totalNum, minNum, maxNum):
        cfgList = []
        num = tool.random.randint(minNum, maxNum)
        for i in range(num):
            while True:
                newNum = tool.random.randint(1, totalNum)
                if newNum in cfgList:
                    continue
                cfgList.append(newNum)
                break
        
        print(log, cfgList)
    
    cfg = {"idx", "page", "num", "status", "frame", "curInput", "serverInfo", "from", "goin", "goto", "signKey", "ver"}
    randomKey("BuryPoint:", len(cfg), 3, 8)
    cfg = {"idx", "page", "num", "status", "frame", "curInput", "serverInfo", "from", "goin", "goto", "signKey", "ver", "errorNo", "trace"}
    randomKey("loginScene:", len(cfg), 3, 6)
    randomKey("simulateLoadFile:", 299, 30, 60)

    # retList = []
    # CplusList = ['84f0e46fe5', 'syntax/tendButton2.png', 'reuse/convertibleVariesQuestion5.txt']
    # CplusCfg = [71,76,41,117,103,47,90,69,99,78,52,37,56,114,92,85,51,87,50,112,35,70,54,89,32,53,82,100,81,63,118,72,65,33,48,105,80,77,97,49,40,111,42,115,79,75,101,120,98,107,45,102,55,57,110,95,67,104,108,66,83,46,64,106,39,84,119,73,44,43,88,109,68,86,116,58,74,113,122,121,34]
    # for val in CplusList:
    #     newContent = tool.strRandomList(tool.getStrEnc1(val, CplusCfg))
    #     retList.append([val, newContent])

    # OCList = ['pasteboard']
    # OCCfg = [99,109,100,65,98,77,49,48,56,50,103,42,82,107,63,43,51,121,52,39,57,33,64,55,104,74,37,102,83,41,117,66,46,120,73,58,86,79,76,80,71,32,88,72,68,118,40,90,111,44,47,105,89,54,92,45,112,108,87,34,81,106,85,78,84,97,113,101,69,70,114,95,122,116,53,75,110,115,119,35,67]
    # for val in OCList:
    #     newContent = tool.strRandomList(tool.getStrEnc1(val, OCCfg))
    #     retList.append([val, newContent])

    # worldsDic.setClsHead(tool.getRandomChar(1, 65, 90).upper() + tool.getRandomChar(1, 65, 90).upper()+ tool.getRandomChar(1, 65, 90).upper())
    worldsDic.setClsHead("MRK")
    # if True:
    #     osMain.myMain()
    #     return

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
    classPath2 = 'out/c_cleanClasses'
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

    className = worldsDic.randomWorldS(13000, 'cplusClass')
    classFunc = worldsDic.randomWorldS(19000, 'cplusFunc')
    classAttr = worldsDic.randomWorldS(19000, 'cplusAttr')

    # createClassList = createClassFiles([className, classFunc, classAttr], classPath4)

    encryptionStringCpluse(classPath1, classPath5)
    worldsDic.clearnFiles('cplus', classPath5, classPath2)
    print '!!clearn cplus Files over!!'
    if True:
        return

    ansDic = analysisFiles(classPath2, 'cplus')

    changeDic = initChangeDic('out/changeText.txt')
    changeLog = {}

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
    # print '==========------------------------------------------------=============='
    # print '!!check over!! changeDic:' + str(len(changeDic)) + ",changeLog:" + str(len(changeLog))
    # print '==========------------------------------------------------=============='
    # print 'left className' + str(len(className)) + ", classFunc" + str(len(classFunc)) + ", classAttr" + str(len(classAttr))
    changeLog['createDownloadDir'] = changeDic['createDownloadDir']

    createClassList = createClassFiles([className, classFunc, classAttr], classPath4)
    
    # 新类已经创建了
    # 准备扩张老类，扩展包括添加对新类的调用函数, 内部调用新函数
    for filePath, val in ansDic.items():
        if val['class']:
            filePath = val[DEF.FULLFILEPATH]
            for classInfo in reversed(val['class']):
                if classInfo[DEF.TYPE] == DEF.CLASS:
                    if tool.os.path.exists(filePath):
                        cplusTool.addExternFuncInfo(filePath , classInfo, createClassList, [className, classFunc, classAttr])
                    else:
                        print filePath + " not find ... "

    changeLogToLuaFile(changeLog, 'out/roleTargetChenged.lua')
    changeDicToText(changeDic, 'out/changeText.txt')
    osMain.changeTextFiles(changeDic, classPath2, classPath3, True)
    # print '==========------------------------------------------------============== '

    noUse = 0
    for _,clsInfo in createClassList.items():
        clsInfo = clsInfo[DEF.CLASSINFO]
        if clsInfo[DEF.ISINCLUDE] == 0:
            noUse += 1

    print 'allNewFuncNum:' + str(DEF.TCplusNum)
    print 'allStrNum:' + str(DEF.TCplusStrNum)
    print 'noUseClass:' + str(noUse)

    print "change OK"

    # staticFunCallStr = osMain.changeStrByDic(changeDic, staticFunCallStr)
    # print('staticFunCallStr:', staticFunCallStr)
    # tool.WriteFile("out/StaticCallText.txt", staticFunCallStr)

    # tool.delFolders(classPath2)
    # tool.delFolders(classPath5)    
    tool.os.system("pause")

if __name__=="__main__":
    main()