# -*- coding: utf-8 -*-

import xxteaModule
import os
import sys
import random
import commonDef
import toolsFunc as tool

reload(sys)
sys.setdefaultencoding( "utf-8" )

specSpace = ''
needAddEnd = False
noCopy = False


def ReadFile(filePath):
    file_object = open(filePath,'rb')
    all_the_text = file_object.read()
    file_object.close()
    return all_the_text

def WriteFile(filePath,all_the_text):    
    file_object = open(filePath,'wb')    
    file_object.write(all_the_text)
    file_object.close()
    
def BakFile(filePath,all_the_text):
    file_bak = filePath[:len(filePath)-3] + 'bak'   
    WriteFile(file_bak,all_the_text)

def ListLua(path):
    fileList = [] 
    for root,dirs,files in os.walk(path):
       for eachfiles in files:
           if eachfiles[-4:] == '.lua' :               
               fileList.append(root + '/' + eachfiles)
    return fileList

# def EncodeWithXxteaModule(filePath, key, signment, spaceNum):    
#     all_the_text = ReadFile(filePath)    

#     if all_the_text[:len(signment)] == signment :
#         return

#     if needAddEnd:
#         all_the_text = all_the_text +  '--' + tool.getRandomChar(random.randint(3, 15), 65, 90)
#     #bak lua
#     #BakFile(filePath,all_the_text)
       
#     encrypt = xxteaModule.encrypt(all_the_text,key)
    
#     if spaceNum != 0:
#         if specSpace == '':
#             count = 1
#             space = ""
#             while (count <= spaceNum):
#                 space = space + chr(random.randint(33, 90))
#                 count = count + 1
#             # print(filePath + ":" + space)
#             signment = signment + space + encrypt
#         else:
#             signment = signment + specSpace + encrypt
#     else:
#         signment = signment + encrypt
#     WriteFile(filePath,signment)
    
def EncodeLua(targetDir, spaceNum, specSpace):
    path = targetDir
    fileList = ListLua(path)
    for files in fileList:
        all_the_text = tool.ReadFile(files)
        content = tool.EncodeContent_ex(all_the_text, spaceNum, specSpace, 0, files)
        tool.WriteFile(files, content)

def FixCpp(projectPath,key,signment):
    filePath = projectPath + '/frameworks/runtime-src/Classes/AppDelegate.cpp'
    all_the_text = ReadFile(filePath)

    #bak cpp
    BakFile(filePath,all_the_text)    

    pos = all_the_text.find('->setXXTEAKeyAndSign')
    left = all_the_text.find('(',pos)
    right = all_the_text.find(';',pos)   

    word = str.format('("%s", strlen("%s"), "%s", strlen("%s"))' % (key,key,signment,signment))
    
    all_the_text = all_the_text[:left] + word + all_the_text[right:-1]
    
    WriteFile(filePath,all_the_text) 
    
def copyFiles(sourceDir,targetDir): 
    if sourceDir.find(".svn") > 0: 
        return

    for file in os.listdir(sourceDir): 
        sourceFile = os.path.join(sourceDir,  file) 
        targetFile = os.path.join(targetDir,  file) 
        if os.path.isfile(sourceFile): 
            if not os.path.exists(targetDir):  
                os.makedirs(targetDir)  
            if not os.path.exists(targetFile) or targetFile[-4:] == '.lua'  or(os.path.exists(targetFile) and (os.path.getsize(targetFile) != os.path.getsize(sourceFile))):
                content = open(sourceFile, "rb").read()
                open(targetFile, "wb").write(content)
                # print sourceFile + "----" + targetFile
        if os.path.isdir(sourceFile):
            copyFiles(sourceFile, targetFile)

def main():
    def hexStr(line):
        hexStr = tool.b2a_hex(line)
        lenHex = len(hexStr)
        newHexStr = ''
        for i in range(lenHex/2):
            if newHexStr:
                newHexStr = newHexStr + ', 0x' + hexStr[i * 2: i * 2 + 2]
            else:
                newHexStr = '0x' + hexStr[i * 2: i * 2 + 2]

        return newHexStr + ', 0x00'

    def hexStr1(line):
        hexStr = tool.b2a_hex(line)
        lenHex = len(hexStr)
        newHexStr = ''
        for i in range(lenHex/2):
            newHexStr = newHexStr + hexStr[i * 2: i * 2 + 2]
            # if newHexStr:
            #     newHexStr = newHexStr + ', 0x' + hexStr[i * 2: i * 2 + 2]
            # else:
            #     newHexStr = '0x' + hexStr[i * 2: i * 2 + 2]

        return newHexStr

    keyList = commonDef.getKeyList() + commonDef.getKeyList1()
    for val in keyList:
       val['keyHex'] = hexStr(val['key'])
       val['signHex'] = hexStr(val['sign'])

    hexList = []
    listKey = ['expanding/initFile_ex.json',
    'queryresult/line.json',
    'I88SI4M7L2RU',
    'roleId',
    'money',
    'factionName',
    '215f4f1d20',
    ]
    for i in listKey:
        hexList.append([hexStr(i), hexStr1(i), i])
    
    # os.system("pause")
    projectPath = "../"
    srcPath = '../client/sg_waiwang/src'
    spaceNum = 0
    
    print sys.getdefaultencoding()
    print "========================================================"
    argvLen = len(sys.argv)
    for index in range(argvLen):
        print "argv" + str(index) + ":" + str(sys.argv[index])
    print "========================================================"    
        
    if argvLen >= 2:
        srcPath = sys.argv[1]
    
    if argvLen >= 3:
        spaceNum = int(sys.argv[2])
    
    if argvLen >= 4:
        if sys.argv[3] != "\'\'":
            global specSpace
            specSpace = str(sys.argv[3])
        else:
            print 'sys.argv[3]|' + sys.argv[3] + "|"
    
    if argvLen >= 5:
        global needAddEnd
        if sys.argv[4] == '1':
            needAddEnd = True
    
    sourceDir = projectPath + srcPath
    targetDir = projectPath + 'sg1/src'

    if argvLen >= 6:
        if sys.argv[5] != '':
            targetDir = projectPath + sys.argv[5]

    global noCopy
    if argvLen >= 7:
        if sys.argv[6] == 'F':
            noCopy = True
    
    if not noCopy:
        print "copyFiles From" + sourceDir + "  To  "+ targetDir
        copyFiles(sourceDir,targetDir)
    EncodeLua(targetDir, spaceNum, specSpace)

    #FixCpp(projectPath,key,signment)
    print "encode ok"

if __name__=="__main__":
    main()
