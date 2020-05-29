#!python   
# coding=utf-8

from tool import toolsFunc as tool

import re
import operator

import sys
sys.getdefaultencoding()
reload(sys)
sys.setdefaultencoding('utf-8')

targetPath = ''
recodeKeyToVal = {}
recodeValToKey = {}
recodeNewKeyToVal = []

excludeFile = []
excludeFodler = []

# 检查一下文件是否需要提取中文
def isExclude(filePath):
    filePath = filePath.replace('\\', '/')
    filePath = filePath.replace(targetPath + '/', '')
    if filePath in excludeFile:
        return True
    else:
        for val in excludeFodler:
            if filePath.find(val) > -1:
                return True
    
    return False

def is_contain_chinese(check_str):
    """
    判断字符串中是否包含中文
    :param check_str: {str} 需要检测的字符串
    :return: {bool} 包含返回True， 不包含返回False
    """
    check_str = check_str.decode("utf-8")
    for ch in check_str:
        if u'\u4e00' <= ch <= u'\u9fff':
            return True
    return False

def getTextKeyName(srcFileName):
    pos1 = tool.find_last(srcFileName, '/')
    pos2 = tool.find_last(srcFileName, '.')

    if pos1 == -1 and pos2 > -1:
        key = srcFileName[:pos2]
    elif pos1 > -1 and pos2 == -1:
        key = srcFileName[pos1+1:]
    elif pos1 > -1 and pos2 > -1:
        key = srcFileName[pos1+1:pos2]
    
    i = 0
    while True:
        tmpkey = key + "_" + str(i)
        if tmpkey in recodeKeyToVal:
            i += 1
        else:
            key = tmpkey
            break

    if key.find('kfPeakCombatView') > -1 and i == 58:
        a = 1

    return key


# 检测整个文件夹
def checkPaths(path):
    path = tool.os.path.abspath(path)

    for root, _, files in tool.os.walk(path):
        for everyFile in files:
            srcFile = root + '/' + everyFile
            srcFile = srcFile.replace('\\', '/')

            if not isExclude(srcFile):
                ansiOneFile(srcFile)
            else:
                fileContent = tool.ReadFile(srcFile)
                srcFile = srcFile.replace(targetPath + '/', "")
                srcFile = tool.os.path.join(targetPath1, srcFile)
                tool.createDir(srcFile)
                tool.WriteFile(srcFile, fileContent)

# 检测文件
def ansiOneFile(srcFile):
    len1 = len(recodeNewKeyToVal)
    print tool.showTime(), srcFile , " ... staring!"
    fileContent = tool.ReadFile(srcFile)

    totalLen = len(fileContent)
    pSeek = 0

    while True:
        if pSeek >= totalLen:
            break

        if pSeek == 0:
            a = 1
        # --
        pos1 = fileContent.find('--', pSeek)
        # --[[
        pos2 = fileContent.find('--[[', pSeek)
        # "
        flg = '\"'
        pos3 = fileContent.find('\"', pSeek)
        pos4 = fileContent.find('\'', pSeek)

        if (pos3 == -1 and pos4 > -1) or (pos3 > -1 and pos4 > -1 and pos4 < pos3):
            pos3 = pos4
            flg = '\''

        if pos3 > -1:
            if pos1 > -1 and pos2 > -1 and (pos1 < pos3 or pos2 < pos3):
                if pos2 <= pos1:
                    sympos = fileContent.find(']]', pos2)
                    if sympos > -1:
                        pSeek = sympos + 2
                    else:
                        break
                elif pos1 < pos2:
                    sympos = fileContent.find('\n', pos1)
                    pSeek = sympos + 2
                else:
                    print 'switch this is error!', srcFile, pSeek
            elif pos1 > -1 and pos2 == -1 and pos3 > pos1:
                sympos = fileContent.find('\n', pos1)
                pSeek = sympos + 1
            else:
                sympos = fileContent.find(flg, pos3 + 1)

                tmppSeek = pos3 + 1
                while True:
                    tmpPos = fileContent.find('\\' + flg, tmppSeek)
                    if tmpPos > -1 and tmpPos - sympos == -1:
                        tmppSeek = sympos + 1
                        sympos = fileContent.find(flg, tmppSeek)
                    else:
                        break

                tmpContent = fileContent[pos3 + 1: sympos]
                if is_contain_chinese(tmpContent):
                    
                    key = ''
                    if tmpContent in recodeValToKey:
                        key = recodeValToKey[tmpContent]
                    else:
                        key = getTextKeyName(srcFile)
                        recodeKeyToVal[key] = tmpContent
                        recodeValToKey[tmpContent] = key
                        recodeNewKeyToVal.append(key)

                    # print tmpContent, key

                    #替换内容
                    con1 = fileContent[:pos3]
                    con2 = fileContent[sympos + 1:]
                    keyStr = 'game.getStrByKey(\"{0}\")'.format(key)
                    fileContent = con1 + keyStr + con2

                    totalLen = len(fileContent)
                    pSeek = pos3 + len(keyStr)
                else:
                    pSeek = sympos + 1
        else:
            break

    srcFile = srcFile.replace(targetPath + '/', "")
    srcFile = tool.os.path.join(targetPath1, srcFile)
    tool.createDir(srcFile)
    tool.WriteFile(srcFile, fileContent)

    addNum = len(recodeNewKeyToVal ) - len1
    if addNum > 0:
        recodeNewKeyToVal.append('ZZZ')
    print tool.showTime(), srcFile , " ... ok!", 'len:', addNum

# 分析一个stringCfg.lua
def ansiStringCfgFile(filePath):
    filePath = tool.os.path.abspath(filePath)
    fileContent = tool.ReadFile(filePath)

    pos1 = fileContent.find('{\r\n')
    pos2 = fileContent.find('}\r\n')

    realContent = fileContent[pos1+3:pos2]

    totalLen = len(realContent)
    pSeek = 0
    pos = 0
    while True:
        pos = realContent.find('\r\n', pSeek)
        if pos > -1:
            lineContent = realContent[pSeek: pos]
            if lineContent:
                equipSymbolPos = lineContent.find('=')
                if equipSymbolPos > -1:
                    key = lineContent[:equipSymbolPos].strip()
                    tmpVal = lineContent[equipSymbolPos+1:]
                    pRight, pLeft = tool.matchSymbol(tmpVal, '\"', '\"')
                    if pRight > -1 and pLeft > -1:
                        val = tmpVal[pLeft:pRight]
                        recodeKeyToVal[key] = val
                        recodeValToKey[val] = key
                    else:
                        print lineContent, " no deal need check Reason!"

            if pos + 2 == totalLen:
                break
            else:
                pSeek = pos + 2
        else:
            break

def saveFile(srcFile):
    fileContent = tool.ReadFile(srcFile)
    srcFile = srcFile.replace(targetPath + '/', "")
    srcFile = tool.os.path.join(targetPath1, srcFile)

    con = ''
    for key in recodeNewKeyToVal:
        if key != "ZZZ":
            con += "\t"+ key + ' = ' + '\"{0}\",\n'.format(recodeKeyToVal[key])
        else:
            con += '\n'

    pos = fileContent.find('}\r\n')
    if pos > -1:
        con1 = fileContent[:pos]
        con2 = fileContent[pos:]

        fileContent = con1 + con + con2

        tool.createDir(srcFile)
        tool.WriteFile(srcFile, fileContent)

    print "recodeNewKeyToVal len:", len(recodeNewKeyToVal)

def initExcludeFile():
    global excludeFile
    excludeFile = ['configOp/StringCfg_old.lua', 'configOp/StringCfg.lua', 'protobuf.lua', 'configOp/StringCfg_HK.lua']

    global excludeFodler
    excludeFodler = ['config/']

def main():
    # 查找整个文件夹
    global targetPath
    targetPath = 'res/src'
    targetPath = tool.os.path.abspath(targetPath)
    targetPath = targetPath.replace('\\', '/')

    global targetPath1
    targetPath1 = 'out/src'
    targetPath1 = tool.os.path.abspath(targetPath1)
    targetPath1 = targetPath1.replace('\\', '/')

    tool.delFolders(targetPath1)
    initExcludeFile()
    ansiStringCfgFile(tool.os.path.join(targetPath, 'configOp/StringCfg.lua'))

    checkPaths(targetPath)

    saveFile(tool.os.path.join(targetPath1, 'configOp/StringCfg.lua'))

if __name__=="__main__":
    main()