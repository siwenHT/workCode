import xxteaModule
import os
import sys
import random

specSpace = ''

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

def EncodeWithXxteaModule(filePath, key, signment, spaceNum):    
    all_the_text = ReadFile(filePath)    

    if all_the_text[:len(signment)] == signment :
        return
    #bak lua
    #BakFile(filePath,all_the_text)
       
    encrypt = xxteaModule.encrypt(all_the_text,key)
    
    if spaceNum != 0:
        if specSpace == '':
            count = 1
            space = ""
            while (count <= spaceNum):
                space = space + chr(33) #random.randint(33, 125))
                count = count + 1
            print(filePath + ":" + space)
            signment = signment + space + encrypt
        else:
            signment = signment + specSpace + encrypt
    else:
        signment = signment + encrypt
    WriteFile(filePath,signment)    
    
def EncodeLua(projectPath,key,signment, spaceNum):
    path = projectPath + 'sg1/src'
    fileList = ListLua(path)
    for files in fileList:
        EncodeWithXxteaModule(files,key,signment, spaceNum)

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
                    open(targetFile, "wb").write(open(sourceFile, "rb").read()) 
        if os.path.isdir(sourceFile): 
            First_Directory = False 
            copyFiles(sourceFile, targetFile)

def main():
    projectPath = "../"
    key = "JW183hy128"
    signment = "dfwsileuv"
    srcPath = 'sg/src'
    spaceNum = 0
    
    argvLen = len(sys.argv)
    print argvLen
    for index in range(argvLen):
        print "argv" + str(index) + ":" + str(sys.argv[index])
        
    if argvLen >= 2:
        srcPath = sys.argv[1]
    
    if argvLen >= 3:
        spaceNum = int(sys.argv[2])
    
    if argvLen >= 4:
        global specSpace
        specSpace =  str(sys.argv[3])
    
    sourceDir = projectPath + srcPath
    targetDir = projectPath + 'sg1/src'
    
    copyFiles(sourceDir,targetDir)
    EncodeLua(projectPath, key, signment, spaceNum)

    #FixCpp(projectPath,key,signment)
    print "encode ok"

if __name__=="__main__":
    main()



