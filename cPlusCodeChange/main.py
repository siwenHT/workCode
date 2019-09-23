#!python   
# -*- coding: utf-8 -*-

from tool import toolsFunc as tool
from tool import worldsDic
from cplus import index as cplusTool
from define import globalDef as DEF
from cplus import createAttr as ATTR

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
    totalClassNum = tool.random.randint(20, 50)
    for _ in range(totalClassNum):
        # print "begin Create class"
        tmpClassName, info = createOneClass({DEF.NAMELIST:nameList, DEF.AnalysisRet:ansDic})
        classInfo[tmpClassName + '.h'] = info
        # print "className:" , tmpClassName
        info[DEF.FULLFILEPATH] = tool.os.path.abspath(destPath + '/' + tmpClassName + '.h')
        saveCreateClass({DEF.CLASS: info})
        print "create class OK!:" , tmpClassName
    return classInfo

#删除所有注释
def clearnFiles(lanType, srcPath, dstPath):
    if lanType == "cplus":
        srcPath = tool.os.path.abspath(srcPath) 
        dstPath = tool.os.path.abspath(dstPath)
        for file in tool.os.listdir(srcPath):
            srcFile = tool.os.path.join(srcPath, file)
            dstFile = tool.os.path.join(dstPath, file)
            if tool.os.path.isfile(srcFile):
                f_content = tool.ReadFile(srcFile)
                tool.createDir(dstFile)
                # print "clearnFiles start:" + srcFile
                f_content = tool.delCplusNotes(f_content)
                tool.WriteFile(dstFile, f_content)
            elif tool.os.path.isdir(srcFile):
                clearnFiles(lanType, srcFile, dstFile)

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

def changeStrByDic(changeDic, targetStr):
    pFind = 0
    while True:
        pInclude = targetStr.find("#include" , pFind)
        if pInclude > -1:
            pEnd = targetStr.find('\n', pInclude)
            includeLineInfo = targetStr[pInclude:pEnd]
            if ('GUI/' in includeLineInfo or '/common/' in includeLineInfo or 'mapview/' in includeLineInfo 
            or 'widget/' in includeLineInfo or 'common/Ycommon' in includeLineInfo or 'tolua++/Young_binding' in includeLineInfo):
                pos = includeLineInfo.find('\"')
                if pos == -1:
                    pos = includeLineInfo.find('<')
                pos1 = tool.findLastStr(includeLineInfo, '/')
                if pos1 > -1:
                    strA = includeLineInfo[0:pos+1]
                    strB = includeLineInfo[pos1 + 1:]
                    newLineInfo = strA + strB
                    # print includeLineInfo + " ===== " + newLineInfo
                    targetStr = targetStr.replace(includeLineInfo, newLineInfo)
                    pFind = pFind + len(newLineInfo) + 1
                else:
                    pFind = pEnd + 1
            else:
                pFind = pEnd + 1
        else:
            break
    # if targetStr.find("#include") > -1 and ('GUI/' in targetStr or '/common/' in targetStr or 'mapview/' in targetStr or 'widget/' in targetStr ):
    #     pos = targetStr.find('\"')
    #     if pos == -1:
    #         pos = targetStr.find('<')
    #     tmpStr = targetStr[0:targetStr.find('\n')]
    #     pos1 = tool.findLastStr(tmpStr, '/')
    #     if pos1 > -1:
    #         strA = targetStr[0:pos+1]
    #         strB = targetStr[pos1 + 1:]
    #         print targetStr + " ===== " + strA + strB

    #         targetStr = strA + strB

    pFind = 0
    totlaItems = changeDic.items()
    while True:
        pos = -1
        changeItem = ''
        
        #找到最前、最长的匹配内容
        for key, val in totlaItems:
            tmpPos = targetStr.find(key, pFind)
            if tmpPos > -1:
                if pos == -1:
                    pos = tmpPos
                    changeItem = key
                elif tmpPos < pos or (tmpPos == pos and len(changeItem) < len(key)):
                    pos = tmpPos
                    changeItem = key

        if pos > -1:
            conA = targetStr[0:pos]
            conB = targetStr[pos+len(changeItem):]
            targetStr = conA + changeDic[changeItem] + conB
            pFind = pos + len(changeDic[changeItem])
        else:
            break
    return targetStr

def changeTextFiles(changeDic, path, destPath, changeDir):
    path = tool.os.path.abspath(path)
    destPath = tool.os.path.abspath(destPath)
    tool.delFolders(destPath)
    for root,dirs,files in tool.os.walk(path):
        for everyFile in files:
            srcFile = tool.os.path.join(path, root + "/" + everyFile)
            tmpPath = root.replace(path, '') + "/" + everyFile
            tmpPath = tmpPath[1:]
            destFile = tool.os.path.join(destPath, tmpPath)
            f_content = tool.ReadFile(srcFile)
            if srcFile.find('Md5.cpp') > -1:
                a = 1
            if (srcFile.find('.cpp') > -1 or srcFile.find('.h') > -1 or srcFile.find('.m') > -1 or srcFile.find('.pch') > -1):
                if ('\\pbc' not in root) and root.find('\\YunVaSDK') == -1 and root.find('\\ide-support') == -1 and root.find('\\lua-cjson') == -1:
                    # contentList = f_content.split('\n')
                    
                    conLineNum = len(f_content)
                    if changeDir:
                        destFile = tool.os.path.join(destPath, 'files/' + everyFile)

                    if conLineNum > 1500:
                        fSeek = 0
                        contentList = []
                        while True:
                            pPos = f_content.find('\n', fSeek + 1500)
                            if pPos > -1:
                                con = f_content[fSeek:pPos]
                                contentList.append(changeStrByDic(changeDic, con))
                                fSeek = pPos
                            else:
                                con = f_content[fSeek:]
                                contentList.append(changeStrByDic(changeDic, con))
                                break
                            
                            if fSeek + 1500 > conLineNum:
                                con = f_content[fSeek:]
                                contentList.append(changeStrByDic(changeDic, con))
                                break

                        f_content = ''
                        for con in contentList:
                            f_content += con #+ '\n'
                            
                        # if newContent != f_content:
                        #     a = 1
                    # for i in range(conLineNum):
                    #     print tool.showTime() + str(i)
                    #     con = contentList[i]
                    #     contentList[i] = changeStrByDic(changeDic, con)

                    # f_content = ''
                    else:
                        f_content = changeStrByDic(changeDic, f_content)
                #改变文件名
                newFileName = changeStrByDic(changeDic, everyFile)
                destFile = destFile.replace(everyFile, newFileName)
            # print tool.showTime() + srcFile + " --- " + destFile            
            dirN = tool.os.path.dirname(destFile)
            tool.createDir(dirN + '\\')
            tool.WriteFile(destFile, f_content)

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
    # changeDic = {}
    # changeDic = {'sendLogin':1, 
    #              'sendAppstore':1, 
    #              'getAdchannel':1,
    #              'initWithParams':1, 
    #              'loginWithParams':1,
    #              'showRealNameBindingWithParams':1,
    #              'loginoutWithParams':1,
    #              'getIAPProductID':1,
    #              'SYLOG':'MLog',
    #              'SysInfoOC':1,
    #              'GameSoftCaller':1,
    #             #  'GameSoftCaller_IAP':1,
    #              'GameCaller':1,
    #              'GameServer':1,
    #              'GameSoftDevKit':1,
    #              'channel_ios':1,
    #              'qqqWithParams':1}
    # funcName = worldsDic.randomWorldS(50, 'cplusFunc')
    # for key, val in changeDic.items():
    #     if val == 1:
    #         changeDic[key] = funcName.pop()

    # tool.delFolders('E:/magicRpg/magic_ios/frameworks/runtime-src/proj.ios_mac/file')
    # tool.delFolders('E:/magicRpg/magic_ios/frameworks/runtime-src/proj.ios_mac/fileChange')
    # clearnFiles('cplus', 'E:/magicRpg/magic_ios/frameworks/runtime-src/proj.ios_mac/files', 'E:/magicRpg/magic_ios/frameworks/runtime-src/proj.ios_mac/file')
    # changeTextFiles(changeDic, 'E:/magicRpg/magic_ios/frameworks/runtime-src/proj.ios_mac/file', 'E:/magicRpg/magic_ios/frameworks/runtime-src/proj.ios_mac/fileChange', False)
    # print changeDic
    # return

    classPath1 = 'res/Classes'
    classPath2 = 'out/Classes'
    classPath3 = 'out/changeClass'
    classPath4 = 'out/CreateClass'
    
    # classPath1 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes/'
    # classPath2 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes_ex/'
    # classPath3 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes_ex/'
    # classPath4 = 'F:/magicRpg/magic_ios/frameworks/runtime-src/Classes_ex/'
    tool.delFolders(classPath2)
    tool.delFolders(classPath3)
    tool.delFolders(classPath4)

    clearnFiles('cplus', classPath1, classPath2)
    # print '!!clearnFiles over!!'

    ansDic = analysisFiles(classPath2, 'cplus')

    changeDic = initChangeDic('out/changeText.txt')
    changeLog = {}

    className = worldsDic.randomWorldS(900, 'cplusClass')
    classFunc = worldsDic.randomWorldS(2500, 'cplusFunc')
    classAttr = worldsDic.randomWorldS(2000, 'cplusAttr')
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

                            print "file add call", filePath, classInfo[DEF.Name], tmpClsHead

                        cplusTool.addExternFuncInfo(filePath , classInfo)
                    else:
                        print filePath + " not find ... "
                        
            if callOtherClass:
                cplusTool.addCallClassContent(filePath, callOtherClass, tmpCallOther)

    changeLogToLuaFile(changeLog, 'out/roleTargetChenged.lua')
    changeDicToText(changeDic, 'out/changeText.txt')
    changeTextFiles(changeDic, classPath2, classPath3, True)
    print '==========------------------------------------------------=============='
    print "change OK"

    staticFunCallStr = changeStrByDic(changeDic, staticFunCallStr)
    # print('staticFunCallStr:', staticFunCallStr)
    tool.WriteFile("out/StaticCallText.txt", staticFunCallStr)
    tool.os.system("pause")

if __name__=="__main__":
    main()