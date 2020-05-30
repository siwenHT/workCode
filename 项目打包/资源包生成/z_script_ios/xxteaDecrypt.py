import xxteaModule
import os
import shutil
import random

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

def to_bytes(bytes_or_str):
        if isinstance(bytes_or_str, unicode):
            return bytes_or_str.encode('utf-8')
        return bytes_or_str

def ListLua(path):
    fileList = [] 
    for root,dirs,files in os.walk(path):
       for eachfiles in files:
           if eachfiles[-4:] == '.lua' :               
               fileList.append(root + '/' + eachfiles)
    return fileList

def getRandomStr(num, key1 = 1, key2 = 255):
    ret = ""
    count = 1
    while (count <= num):
        ret = ret + unichr(random.randint(key1, key2))
        count = count + 1

    ret = to_bytes(ret)
    ret = ret[0:num]
    return ret

def getResRandomChar(key1):
    start = key1

    startAscii = ord(start)
    if startAscii == 49:
        return 4#start + getRandomStr(3)
    elif 50 <= startAscii <= 90:
        return 24#start + getRandomStr(23)
    elif 91 <= startAscii <= 116:
        return 43#start + getRandomStr(42)
    elif 117 <= startAscii <= 125:
        return 38#start + getRandomStr(37)
    else:
        return 36#start + getRandomStr(35)

def DecodeWithXxteaModule(filePath,key,signment, spaceNum):    
    all_the_text = ReadFile(filePath)    

    if all_the_text[:len(signment)] != signment :
        return
    
    spaceNum = getResRandomChar(all_the_text[len(signment)])
    all_the_text = all_the_text[len(signment) + spaceNum:]
    decrypt_content = xxteaModule.decrypt(all_the_text,key)
    WriteFile(filePath,decrypt_content)
    
def DecodeLua(path,key,signment,spaceNum):
    fileList = ListLua(path)
    for files in fileList:
        DecodeWithXxteaModule(files,key,signment,spaceNum)
    
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

if __name__=="__main__":
    projectPath = "../"
    key = "ZYA14ageb8642F58"
    signment = "Signal"
    srcPath = 'sg/src'
    spaceNum = 4
    DecodeWithXxteaModule("E:/magicRpg/magic_ios/sglmjy/attempted/wrong/conswhat/essentialConsult.txt", key, signment, spaceNum)



