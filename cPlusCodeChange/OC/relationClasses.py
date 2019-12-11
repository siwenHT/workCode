#!python   
# -*- coding: utf-8 -*-

from define import globalDef as DEF
from tool import toolsFunc as tool
import globalInfo as G
from tool import worldsDic
import createFile

#在原有类上面加一些新属性. 跟方法
#并且调用生成的类的方法
#在原生类中调用新生成类的方法

def relationCls(oldclsList, newClsList, oldFilesPath, createFilesPath, targetFilesPath):
    print  '---------------------------------------createFiles ok'
    externOldClass(oldclsList, newClsList)
    print  '---------------------------------------externOldClass ok'
    # externNewClass(oldclsList, newClsList)
    print  '---------------------------------------externNewClass ok'
    saveToFile(oldclsList, oldFilesPath, targetFilesPath)
    saveToFile(newClsList, createFilesPath, targetFilesPath)

def externOldClass(oldclsList, newClsList):
    #添加属性
    for clsInfo in oldclsList:
        num = len(clsInfo[DEF.PROP])
        num1 = round(num / 3)
        num2 = round(num * 2.5)

        num1 = num1 < 1 and 1 or num1
        num2 = num2 < 1 and 2 or num2
        num = tool.random.randint(num1, num2)

        clsInfo[DEF.ADDHEAD] = []
        for _ in range(num):
            prop = {}
            prop[DEF.Name] = G.getAttrName()
            prop[DEF.FROM] = DEF.FROMTYPE.add
            prop[DEF.TYPE] = createFile.randomOcType()

            clsInfo[DEF.PROP].append(prop)
                    

    #添加方法
    createFile.createClsList = newClsList
    for clsInfo in oldclsList:
        num = len(clsInfo[DEF.PROP])
        num1 = round(num / 3)
        num2 = round(num * 2.5)

        num1 = num1 < 1 and 1 or num1
        num2 = num2 < 1 and 2 or num2
        num = tool.random.randint(1, 3)

        for _ in range(num):
            funcInfo = createFile.newFunc(clsInfo)
            createFile.fillFunc(funcInfo, clsInfo)

        # 老函数调用新函数
        oldList = []
        newList = []
        for func in clsInfo[DEF.Funcs]:
            if func[DEF.Name] == 'shared' or 'getInstance' == func[DEF.Name] or 'destroyInstance' == func[DEF.Name]:
                continue
            elif func[DEF.FROM] == DEF.FROMTYPE.old:
                oldList.append(func)
            else:
                newList.append(func)
        
        if len(oldList) > 0:
            num = tool.random.randint(1, len(oldList))
            for _ in range(num):
                callFunc = tool.random.choice(oldList)
                calledFunc = tool.random.choice(newList)
                callFunc[DEF.EXTERN].append(calledFunc)

def externNewClass(oldclsList, newClsList):
    #添加方法
    createFile.createClsList = oldclsList
    for clsInfo in oldclsList:
        num = tool.random.randint(1, 3)


        for _ in range(num):
            funcInfo = createFile.newFunc(clsInfo)
            createFile.fillFunc(funcInfo, clsInfo)

def saveToFile(clsList, old, target):
    oldPath = ''
    totalFunc = 0
    for clsInfo in clsList:
        hFilePath = old + '/' + clsInfo[DEF.FILEPATH]
        if oldPath == hFilePath:
            hFilePath = target + '/' + clsInfo[DEF.FILEPATH]
        else:
            oldPath = hFilePath
        
        hFilePath = tool.os.path.abspath(hFilePath)
        thFilePath = target + '/' + clsInfo[DEF.FILEPATH]
        thFilePath = tool.os.path.abspath(thFilePath)

        #老文件头文件保存下来
        hFileContent = tool.ReadFile(hFilePath)

        headContent = ''
        clsInfo[DEF.IMPROTCLS] = tool.popReList(clsInfo[DEF.IMPROTCLS])
        for val in clsInfo[DEF.IMPROTCLS]:
            headContent += "@class " + val + ";\n"

        propContent = ''
        for prop in clsInfo[DEF.PROP]:
            if prop[DEF.FROM] == DEF.FROMTYPE.add:
                if '*' in prop[DEF.TYPE]:
                    propContent += "@property(nonatomic, strong) " + prop[DEF.TYPE] + " " + prop[DEF.Name] + ";\n" 
                else:
                    propContent += "@property(nonatomic, assign) " + prop[DEF.TYPE] + " " + prop[DEF.Name] + ";\n"

        funContent = ''
        totalFunc += len(clsInfo[DEF.Funcs])
        for fun in clsInfo[DEF.Funcs]:
            if fun[DEF.FROM] == DEF.FROMTYPE.add:
                first = True
                tmpCon = ''
                for param in fun[DEF.PARAMS]:
                    if first:
                        tmpCon += '({0}){1}'.format(param[DEF.TYPE], param[DEF.Name1])
                        first = False
                    else:
                        tmpCon += ' {0}:({1}){2}'.format(param[DEF.Name], param[DEF.TYPE], param[DEF.Name1])
                if tmpCon:
                    funContent += '- ({0}) {1}:{2}'.format(fun[DEF.FUNCRET], fun[DEF.Name], tmpCon) + ';\n'
                else:
                    funContent += '- ({0}) {1}'.format(fun[DEF.FUNCRET], fun[DEF.Name]) + ';\n'

        # 找到放入属性的地方
        if propContent or funContent:
            pos = hFileContent.find("@interface")
            pos = hFileContent.find(clsInfo[DEF.Name], pos)
            if pos > -1:
                pos1 = hFileContent.find("@property", pos)
                pos2 = hFileContent.find("-", pos)
                pos3 = hFileContent.find("@end", pos)

                pos = -1
                if pos1 > -1 and pos3 > -1 and pos1 < pos3:
                    pos = pos1
                elif pos2 > -1 and pos3 > -1 and pos2 < pos3:
                    pos = pos2
                elif pos1 == -1 and pos2 == -1 and pos3 > -1:
                    pos = pos3
                else:
                    print "file {0} find class {1} property error! {2}, {3}, {4}".format(hFilePath, clsInfo[DEF.Name], pos1, pos2, pos3)

                if pos > -1:
                    con1 = hFileContent[:pos]
                    con2 = hFileContent[pos:]
                    hFileContent = con1 + propContent + funContent + con2

                if headContent:
                    pos1 = tool.findLastStr(hFileContent, "#import")
                    if pos1 > -1:
                        pos2 = hFileContent.find('\n', pos1)
                        con1 = hFileContent[0:pos2+1]
                        con2 = hFileContent[pos2+1:]
                        hFileContent = con1 + headContent + con2
                    else:
                        hFileContent = headContent + hFileContent

                tool.createDir(thFilePath)
                tool.WriteFile(thFilePath, hFileContent)

        #保存 .m 文件
        mFilePath = hFilePath.replace('.h', '.mm')
        if not tool.os.path.exists(mFilePath):
            mFilePath = mFilePath.replace('.mm', '.m')
        mFileContent = tool.ReadFile(mFilePath)
        tmFilePath = target + '/' + clsInfo[DEF.FILEPATH]
        tmFilePath = tmFilePath.replace('.h', '.mm')
        if not tool.os.path.exists(tmFilePath):
            tmFilePath = tmFilePath.replace('.mm', '.m')
        tmFilePath = tool.os.path.abspath(tmFilePath)

        headContent = ''
        clsInfo[DEF.ADDHEAD] = tool.popReList(clsInfo[DEF.ADDHEAD])
        for head in clsInfo[DEF.ADDHEAD]:
            headContent += '#import \"{0}\"'.format(head) + '\n'

        fMContent = ''
        for fun in clsInfo[DEF.Funcs]:
            if fun[DEF.FROM] == DEF.FROMTYPE.add:
                tmpCon = ''
                first = True
                for param in fun[DEF.PARAMS]:
                    if first:
                        tmpCon += '({0}){1}'.format(param[DEF.TYPE], param[DEF.Name])
                        first = False
                    else:
                        tmpCon += ' {0}:({1}){2}'.format(param[DEF.Name], param[DEF.TYPE], param[DEF.Name1])
                if tmpCon:
                    fMContent += '- ({0}) {1}:{2}'.format(fun[DEF.FUNCRET], fun[DEF.Name], tmpCon) + '{\n'
                else:
                    fMContent += '- ({0}) {1}'.format(fun[DEF.FUNCRET], fun[DEF.Name]) + '{\n'
                fMContent += fun[DEF.CONTENT] + '}\n\n'
                fMContent = tool.unicodeToAscii(fMContent)
        
        if fMContent:
            isOK = 0
            while True:                
                pos = mFileContent.find("@implementation")
                if pos == -1:
                    isOK = 1
                    break

                pos = mFileContent.find(clsInfo[DEF.Name], pos)
                if pos == -1:
                    isOK = 2
                    break

                pos = mFileContent.find("@end", pos)
                if pos == -1:
                    isOK = 3
                    break

                con1 = mFileContent[0:pos]
                con2 = mFileContent[pos:]
                mFileContent = headContent + con1 + fMContent + con2

                tool.createDir(tmFilePath)
                tool.WriteFile(tmFilePath, mFileContent)
                break

            if isOK != 0:
                print "file {0} save class {1} error!".format(tmFilePath, clsInfo[DEF.Name])

        for func in clsInfo[DEF.Funcs]:
            if func.get(DEF.EXTERN):
                content = ''

                list2 = []
                list3 = []
                for call in func[DEF.EXTERN]:
                    if call[DEF.Name] not in list3:
                        list2.append(call)
                        list3.append(call[DEF.Name])

                func[DEF.EXTERN] = list2
                for call in func[DEF.EXTERN]:
                    if call[DEF.Name] != func[DEF.Name]:
                        if func[DEF.ScopeType] == DEF.SCOPE.Private:                
                            content += '\n[self {0}];'.format(call[DEF.Name] + createFile.getFuncCallLine(call))
                        # else:
                        #     content += '\n[{0} {1}];'.format(clsInfo[DEF.Name], call[DEF.Name] + createFile.getFuncCallLine(call))
                
                if content:
                    content += '\n'
                    filterStr = r'[\n][-+]+[^\n]*' + func[DEF.Name] + '[^\n]*[\n]'
                    ret = tool.re.search(filterStr, mFileContent)

                    isOk = False
                    if ret:
                        if ret.span():
                            if ret.span()[1]:
                                pos = mFileContent.find('{', ret.span()[1])
                                if pos > -1:
                                    con1 = mFileContent[:pos+1]
                                    con2 = mFileContent[pos+1:]
                                    mFileContent = con1 + content + con2
                                    isOk = True

                                    # print '{0}.{1} extern Str {2}'.format(clsInfo[DEF.Name], func[DEF.Name], content)
                                    

                    if not isOk:
                        a = 1
                        # print 'file {0} find func {1} error!'.format(tmFilePath, func[DEF.Name])

        tool.WriteFile(tmFilePath, mFileContent)

    print("ios class", len(clsList), "func", totalFunc,)

        # print thFilePath, tmFilePath