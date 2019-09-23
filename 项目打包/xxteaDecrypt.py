import xxteaModule
import os
import shutil

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

def DecodeWithXxteaModule(filePath,key,signment):    
    all_the_text = ReadFile(filePath)    

    if all_the_text[:len(signment)] != signment :
        return
    all_the_text = all_the_text[len(signment):]
    decrypt_content = xxteaModule.decrypt(all_the_text,key)
    WriteFile(filePath,decrypt_content)
    
def DecodeLua(path,key,signment):
    fileList = ListLua(path)
    for files in fileList:
        DecodeWithXxteaModule(files,key,signment)
    
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

key = "JW183hy128"
signment = "dfwsileuv"
sourceDir = 'encrypt'
targetDir = 'decrypt'
# shutil.rmtree(targetDir,True)
# copyFiles(sourceDir,targetDir)
# DecodeLua(targetDir,key,signment)
DecodeWithXxteaModule("D:\workFiles\1Update\1_mzy_android_version/2000017_1/assets/sg/src/layers/activitys/shouchong/rechargeView.lua", key, signment)
print "decode ok"




