# -*- coding: utf-8 -*-

import sys
import os
import math
import shutil
import toolsFunc as tool
import xlrd

def file2Lua(srcFile, destPath):
    beginTime = tool.time.clock()
    workbook = xlrd.open_workbook(filename = srcFile)
    worksheets = workbook.sheet_names()
    outFileName = worksheets[0]
    outFile = os.path.join(destPath, outFileName + '.Lua')

    worksheet1 = workbook.sheets()[0]
    num_rows = worksheet1.nrows
    num_cols = worksheet1.ncols

    _,sName, suf = tool.getFile_path_name_suf(srcFile)
    print sName
    srcFileName = '--' + sName + suf
    fileHead = 'local Items = {\r\n'
    fileEnd = '};\r\nreturn Items'

    #获取key信息
    keys = {}
    rows1 = worksheet1.row_values(0)
    for coln in range(num_cols):
        cell = rows1[coln]
        keys[coln] = cell.strip()

    fileContent = ''
    lines = []
    for rown in range(num_rows - 3):
        rown += 3
        lineStr = '\t{'
        rows = worksheet1.row_values(rown)
        for coln in range(num_cols):
            if keys[coln]:
                cell = rows[coln]
                if lineStr.find('q_map_id = 1106') > -1:
                    if keys[coln] == 'tip_content':
                        a = 1

                if cell or (isinstance(cell, float) and cell == 0):
                    if isinstance(cell, unicode):
                        # if cell[-1] == '\n':
                        #     cell = cell[0:-1] + ' '
                        cell = cell.replace('\n', ' ')
                        lineStr += keys[coln]
                        lineStr += ' = \''
                        lineStr += cell
                        lineStr += '\','
                    else:
                        if isinstance(cell, float):
                            if int(cell) == cell:
                                cell = int(cell)
                        lineStr += keys[coln]
                        lineStr += ' = '
                        lineStr += str(cell)
                        lineStr += ','
        
        
        if len(lineStr) > 2:
            if rown != num_rows - 1:
                lineStr += '},\n'
            else:
                lineStr += '},\r\n'
            lines.append(lineStr)
            
    fileContent = fileContent.join(lines)
    fileContent = tool.to_bytes(fileContent)
    srcFileName = tool.to_bytes(srcFileName)
    fullFileContent = srcFileName + '\r\n' + fileHead + fileContent + fileEnd

    tool.createDir(outFile)
    tool.WriteFile(outFile, fullFileContent)
    # print "is done! cost:", tool.time.clock() - beginTime

def files2Lua(resPath, destPath):
    beginTime = tool.time.clock()
    resPath = os.path.abspath(resPath)
    destPath = os.path.abspath(destPath)
    for everyFile in os.listdir(resPath):
        if everyFile.find('.xls') > -1:
            if everyFile.find('K-AAA') > -1:
                a = 1
            everyFile = os.path.join(resPath, everyFile)
            everyFile = everyFile.decode('gbk')
            file2Lua(everyFile, destPath)
    
    print 'finsh it.', tool.time.clock() - beginTime

def main():
    resPath  = 'config/data/'
    destPath = 'lua'

    argLen = len(sys.argv)
    if argLen >= 2:
        resPath = sys.argv[1]

    if argLen >= 3:
        destPath = sys.argv[2]
    
    if os.path.exists(destPath):
        shutil.rmtree(destPath)
    files2Lua(resPath, destPath)

if __name__ == "__main__":
    main()