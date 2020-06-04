import os
import hashlib
import sys

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
    fcont = fd.read()
    fd.close()
    fmd5 = hashlib.md5(fcont)
    return fmd5

def display_path(path):
    path_new = path.replace("\\", "/")
    m = path_new[-1]
    if m.strip() == "/":
        path_new = path_new[:-1]
    return path_new
    
def MD5(path,md5_file_name):
    #sub content
    subPackageList = {}
    
    if os.path.exists("..\packagedFileList.txt"):
        file_object = open("..\packagedFileList.txt", 'r')
        for line in open("..\packagedFileList.txt"):
            line = line.strip()
            line2 = "sg1/{0}".format(line)
            # print line2
            subPackageList[line2] = 1
        file_object.close()

    md5List = []
    for parent, dirnames, filenames in os.walk(path):
        for file in filenames:
            if file.find("filelist.txt") != -1:
                continue
            if file.find("logo.png") != -1:
                continue
            if file.find("version.txt") != -1:
                continue
            if file.find("adChannel.png") != -1:
                continue
            if file.find("packagedFileList.txt") != -1:
                continue
            if file.find("filelist_sub_common.txt") != -1:
                continue
            if file.find("status.cfg") != -1:
                continue
            if file.startswith("."):
                continue
				
            s_path = os.path.join(parent,file)
            if os.path.isfile(s_path):
                if not os.path.exists(parent):
                    os.makedirs(parent)
                s_file = open(s_path, "rb")
                s_content = s_file.read()
                s_size = os.path.getsize(s_path)
                fmd5 = (hashlib.md5(s_content).hexdigest()).strip()
                s_path_fix = display_path(s_path[len(path):])
                s_path_fix = "sg/{0}".format(s_path_fix)
                # print s_path_fix
                if not subPackageList or not subPackageList.has_key(s_path_fix):
                    md5_str = "{0}|{1}|{2}".format(s_path_fix,fmd5,s_size)
                    md5List.append(md5_str+os.linesep)
					
    dir = os.path.dirname(md5_file_name).strip()
    if not os.path.exists(dir):
        os.makedirs(dir)
    file_md5 = open(md5_file_name,'wb')
    file_md5.writelines(md5List)
    file_md5.close()

def main():
    path = "../../sg1/"
    md5_file_name = "MD5_current/filelist.txt"
    MD5(path,md5_file_name)

if __name__=="__main__":
    main()




