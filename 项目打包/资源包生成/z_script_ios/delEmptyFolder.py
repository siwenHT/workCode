import os
import sys
import random
import toolsFunc as tool

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
        tool.delEmptyFolder(srcPath)

    print "del ok"

if __name__=="__main__":
    main()
