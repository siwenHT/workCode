import os
import sys
import random

def delEmptyFolder(path):
    count = 0
    for root, dirs, files in os.walk(path):
        if not dirs and not files:
            os.rmdir(root)
            count = count + 1
    print u"del folders:" , count
    
def main():
    srcPath = ''

    print "========================================================"
    argvLen = len(sys.argv)
    for index in range(argvLen):
        print "argv" + str(index) + ":" + str(sys.argv[index])
    print "========================================================"    
        
    if argvLen >= 2:
        srcPath = sys.argv[1]

    if srcPath == '':
        print "path is empty"
    else:
        delEmptyFolder(srcPath)

    print "del ok"

if __name__=="__main__":
    main()
