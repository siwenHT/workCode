import os
import hashlib
import shutil
import time
  
def copyFilesAndMD5(packagedFileList, sourcePath):
    size2 = 0
    size3 = 0
    count2 = 0
    count3 = 0
    fileDatas = open(packagedFileList, 'r')
    for line in fileDatas.readlines():
		list = line.split('|')
		floor = list[1].strip()
		line = list[0]	
		line = line.strip()
		if line.find("status.cfg") != -1 or line.find("mapDownRes.cfg") != -1:
			continue
				
		s_path = os.path.join(sourcePath, line).strip()
		if os.path.isfile(s_path):
			s_file = open(s_path, "rb")
			s_size = os.path.getsize(s_path)
			if floor == '2':
				count2 += 1
				size2 += s_size
			elif floor == '3':
				count3 += 1
				size3 += s_size

    print("package2: count:%d size:%dMB" % (count2, size2/1024/1024))
    print("package3: count:%d size:%dMB" % (count3, size3/1024/1024))

def main():
    sourcePath = "../sg1/"
    packagedFileList = "packagedFileList2.txt"
	
    copyFilesAndMD5(packagedFileList, sourcePath)
    print "subctonet and md5 ok"

if __name__=="__main__":
    main()
    time.sleep(100)




