#!python   
# -*- coding: utf-8 -*-
import analysisFile as ANS
import createFile   as CRT
from define import globalDef as DEF
from tool import toolsFunc as tool
from tool import worldsDic
import relationClasses as RELACLS
import globalInfo as G

cacheFile = 'changeTextIos.txt'

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
    noChange = ['setRootViewController1', "resumeAllEffects", 'pauseAllEffects']
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

        noChangeFlg = False
        for noChangeKey in noChange:
            if noChangeKey.find(changeItem) > -1:
                pos1 = targetStr.find(key, pFind)
                if pos1 > -1:
                    if pos - pos1 == len(noChangeKey) - len(changeItem):
                        noChangeFlg = True
                        print  targetStr[pos1 - 10: pos1 + len(noChangeKey) + 10], " the string no change !!!"
                        break

        if noChangeFlg:
            pFind = pos + len(changeDic[changeItem])
            continue
        elif pos > -1:
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
    for root,_,files in tool.os.walk(path):
        for everyFile in files:
            srcFile = tool.os.path.join(path, root + "/" + everyFile)
            tmpPath = root.replace(path, '') + "/" + everyFile
            tmpPath = tmpPath[1:]
            destFile = tool.os.path.join(destPath, tmpPath)
            f_content = tool.ReadFile(srcFile)

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

def ansFiles(path):
    path = tool.os.path.abspath(path)
    for root,_,files in tool.os.walk(path):
        for everyFile in files:
            if '.h' in everyFile:
                srcFile = tool.os.path.join(path, root + "/" + everyFile)
                ANS.analysis(srcFile)
    
    return

def createFile(path):
    return CRT.createFiles(path)

def changeText(resPath, cleanPath, chanegPath):
    changeDic = {}
    changeDic = {'sendLogin':1, 
                 'sendAppstore':1, 
                 'getAdchannel':1,
                 'initWithParams':1, 
                 'loginWithParams':1,
                 'showRealNameBindingWithParams':1,
                 'loginoutWithParams':1,
                 'getIAPProductID':1,
                #  'MLog':worldsDic.clsHead() + 'Log',
                 'SysInfoOC':'JIGAffectsTurnsList',
                 'GameSoftCaller':1,
                #  'GameSoftCaller_IAP':1,
                 'GameCaller':1,
                 'GameServer':1,
                 'GameSoftDevKit':1,
                 'channel_ios':"JIGImplicitlySeeminglyRes",
                 'SFHFKeychainUtils':1,
                 'RootViewController':1,
                 'qqqWithParams':1,
                 'splitJoinString':1,
                 'AppController':1,
                 'SFHFKeychainUtilsErrorDomain':1,
                 'ARRYSTRFORMAT':(worldsDic.getOneWorld() + worldsDic.getOneWorld()).upper(),
                 'PathFormat':(worldsDic.getOneWorld() + worldsDic.getOneWorld()).upper(),
                 'MoviePlayerHelper':1,}
    funcName = worldsDic.randomWorldS(50, 'ocClass')
    for key, val in changeDic.items():
        if val == 1:
            changeDic[key] = funcName.pop()

    cleanPath = tool.os.path.abspath(cleanPath)
    chanegPath = tool.os.path.abspath(chanegPath)

    tool.delFolders(cleanPath)
    tool.delFolders(chanegPath)

    worldsDic.clearnFiles('cplus', resPath, cleanPath)
    changeTextFiles(changeDic, cleanPath, chanegPath, False)
    # print changeDic
    return

def encryptionStringCpluse(oldPath, newPath):
    oldPath = tool.os.path.abspath(oldPath)
    newPath = tool.os.path.abspath(newPath)

    #找到对应的文件
    keyFileName = 'AppController.mm'
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
                pos = fContent.find("PathFormat", pos)

                if pos > -1:
                    posRight, posLeft = tool.matchSymbol(fContent, '(',  ')', pos)
                    posSymRight, posSymLeft = tool.matchSymbol(fContent, '\"',  '\"', pos)
                    if posLeft > -1 and posRight > -1 and posSymRight > -1 and posSymLeft > -1:
                        strContent = fContent[posSymLeft: posSymRight]
                        tmpList = tool.getStrEnc(strContent, tmpCfg)
                        tmpList.append(-1)
                        newContent = tool.strRandomList(tmpList)

                        con1 = fContent[:posLeft]
                        con2 = fContent[posRight:]

                        fContent = con1 + newContent + con2
                        pos = posLeft + len(newContent)
                    else:
                        print everyFile + " not find \"\"" + fContent[pos: pos + 50]
                        break
                else:
                    break
            
            tool.createDir(newFilePath)
            tool.WriteFile(newFilePath, fContent)

#oc文件混淆的主文件
def myMain():
    resFile    = 'res/iosFile'
    strPath    = 'out/oc_strIosFile'
    createPath = 'out/oc_createIosFile'
    cleanPath  = 'out/oc_cleanIosFile'
    changePath = 'out/oc_changeIosFile'
    targetPath = 'out/oc_targetIosFile'

    tool.delFolders(cleanPath)
    tool.delFolders(changePath)
    tool.delFolders(strPath)
    encryptionStringCpluse(resFile, strPath)
    changeText(strPath, cleanPath, changePath)
    
    ansFiles(changePath)

    tool.delFolders(createPath)
    createList = createFile(createPath)

    tool.delFolders(targetPath)
    tool.createDir(targetPath)

    path1 = tool.os.path.abspath(changePath)
    path2 = tool.os.path.abspath(createPath)
    path3 = tool.os.path.abspath(targetPath)
    cmd1 = 'xcopy /s /r /y /q {0}\\*.* {1}\\'.format(path1, path3)
    cmd2 = 'xcopy /s /r /y /q {0}\\*.* {1}\\'.format(path2, path3)
    tool.os.system(cmd1)
    tool.os.system(cmd2)
    
    RELACLS.relationCls(G.clsList, createList, changePath, createPath, targetPath)

    tool.delFolders(changePath)
    tool.delFolders(cleanPath)
    tool.delFolders(createPath)