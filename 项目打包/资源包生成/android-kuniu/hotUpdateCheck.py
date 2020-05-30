import sys
import os
import hashlib

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

def md5sum(filename):
    fd = open(filename,"r")
    fcont = fd.r
    fd.close()
    fmd5 = hashlib.md5(fcont)
    return fmd5

def display_path(path):
    path_new = path.replace("\\", "/")
    m = path_new[-1]
    if m.strip() == "/":
        path_new = path_new[:-1]
    return path_new
    
def MD5(MD5_current,MD5_package,MD5_changePath,MD5_loadPath,MD5_resDir):
    MD5_currentDict = {}
    MD5_packageDict = {}
	
    #TODO parse current md5
    file_md5 = open(MD5_current,'r')
    if file_md5:
        line = file_md5.readline()
        while line:
            lineTab = line.split("|")
            MD5_currentDict[lineTab[0]] = lineTab
            line = file_md5.readline()
    file_md5.close()
	
    # TODO parse package md5
    file_md5 = open(MD5_package,'r')
    if file_md5:
        line = file_md5.readline()
        while line:
            lineTab = line.split("|")
            MD5_packageDict[lineTab[0]] = lineTab
            line = file_md5.readline()
    file_md5.close()
	
    MD5_changeList = []
    #TODO check md5 change
    for key in MD5_currentDict.keys():
        value = MD5_currentDict.get(key)

        if key.find('filelist_sub.txt') == -1 and key.find('adChannel.png') == -1 and key.find("DeprecatedExtend_ex.lua") == -1 and key.find("initFile_ex.lua") == -1 and key.find("version.txt") == -1 and key.find("logo.png") == -1:
            if MD5_packageDict.has_key(key):
                value2 = MD5_packageDict.get(key)
                if value[1] != value2[1]:
                    MD5_changeList.append(value)
            else:
                MD5_changeList.append(value)
				
    #TODO generate change files
    count = 0
    for value in MD5_changeList:
        save_path = os.path.join(MD5_changePath,value[0])
        load_path = MD5_loadPath + value[0][len(MD5_resDir)+1:]#os.path.join(MD5_loadPath,value[0][6:])
        
        if os.path.isfile(load_path):
            t_path_dir = os.path.dirname(save_path).strip()
            if not os.path.exists(t_path_dir):
                os.makedirs(t_path_dir)
            open(save_path,"wb").write(open(load_path,"rb").read())
            count = count + 1
    print "assert FileNum:" , count

def main():
    MD5_current = "MD5_current/filelist.txt"
    MD5_package = "MD5_package/filelist.txt"
    if len(sys.argv) >= 2:
        MD5_package = "MD5_package/" + sys.argv[1]
        
    MD5_changePath = "assets/"
    MD5_resDir = "sg"
    MD5_loadPath = "../../" + MD5_resDir + "1/"
    MD5(MD5_current,MD5_package,MD5_changePath,MD5_loadPath,MD5_resDir)

if __name__=="__main__":
    main()




