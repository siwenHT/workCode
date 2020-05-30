#!python   
# -*- coding: utf-8 -*-

import json
import os
import sys
from optparse import OptionParser
import toolsFunc3 as tool
import pushFolder
import versionChange as version
import refreshUrl
import tkinter
import tkinter.messagebox
import datetime
import time

from toolsFunc3 import commondLine

totoalCfg = {}

class package:
    def __init__(self, jsonInfo, platform, ignoreSubError):
        self.data = jsonInfo
        self.platform = platform
        self.aNewVersion = None
        self.bNewVersion = None
        self.subCfgError = False
        self.ignoreSubError = ignoreSubError

    def newVersionFolder(self):
        import upFolderName as UpFolder
        if self.platform == 1 or self.platform == 3:
            self.androidNewUpFile = UpFolder.main(['update/' + self.data['androidHotFilePath'], 4])

        if self.platform == 2 or self.platform == 3:
            self.iosNewUpFile = UpFolder.main(['update/' + self.data['iosHotFilePath'], 4])

    def showNewVersion(self):
        if self.platform == 1:
            print ("安卓生成文件夹方式: 1.升级小版本号，2.升级中间版本，3.版本号不变，4.输入版本号")
            print ("安卓", self.androidNewUpFile)
        elif self.platform == 2:
            print ("Ios生成文件夹方式: 1.升级小版本号，2.升级中间版本，3.版本号不变，4.输入版本号")
            print ("Ios", self.iosNewUpFile)
        elif self.platform == 3:
            print ("生成文件夹方式: 1.升级小版本号，2.升级中间版本，3.版本号不变，4.输入版本号")
            print ("安卓", self.androidNewUpFile)
            print ("Ios", self.iosNewUpFile)
        
        idx = tool.waitInputIdx(1, 4)
        if idx == 4:
            ver1 = tool.waitInput()
            if self.platform == 3:
                ver2 = tool.waitInput()
                self.confirmVersion(idx, ver1, ver2)
            elif self.platform == 1:
                self.confirmVersion(idx, ver1)
            elif self.platform == 2:
                self.confirmVersion(idx, None, ver1)
        else:
            self.confirmVersion(idx)

    def confirmVersion(self, upType, newVersion=None, newVersion1=None):
        if self.platform == 1 or self.platform == 3:
            if upType < 4:
                self.aNewVersion = self.androidNewUpFile[upType - 1]
            elif upType == 4:
                self.aNewVersion = newVersion
            else:
                print(f'confirmVersion upType error {upType}')

        if self.platform == 2 or self.platform == 3:
            if upType < 4:
                self.bNewVersion = self.iosNewUpFile[upType - 1]
            elif upType == 4:
                self.bNewVersion = newVersion1
            else:
                print(f'confirmVersion upType error {upType}')

        self.createFolder()
        
    def createFolder(self):
        def newFplders(version, subFile, updateFile):
            updateFile = os.path.join(root, f'update/{updateFile}/' + str(version))
            subFile = os.path.join(root, 'subcontracting/' + subFile)

            tool.delFile(updateFile)
            tool.delFile(subFile)
            print (f'[package.createFolder]:{updateFile=} {subFile=}')
            tool.createDir(updateFile + '/')

        if self.aNewVersion:
            newFplders(self.aNewVersion, self.data['andoridSubFilePath'], self.data['androidHotFilePath'])
        
        if self.bNewVersion:
            newFplders(self.bNewVersion, self.data['iosSubFilePath'], self.data['iosHotFilePath'])

    def beginPack(self):
        if self.platform == 1 or self.platform == 3:
            self.beginPackA()
        
        if self.platform == 2 or self.platform == 3:
            self.beginPackB()

        if self.subCfgError:
            print("分包处理异常!")
            tkinter.messagebox.askokcancel('提示', '分包处理异常!')
            os.system("pause")
            return

        import checkMD5
        
        key = 'androidHotFilePath'
        if self.platform == 2:
            key = 'iosHotFilePath'

        checkMD5.main(["update/" + self.data[key]])

    def errorAndSizeInfo(self, targetFolder, platform):
        srcFile1 = self.data['clientPath'] + '/luaecode/sizeInfo.txt'
        srcFile2 = self.data['clientPath'] + '/luaecode/subPackageError.txt'

        tarFile1 = self.data['clientPath'] + '/z_subSizeInfo/' + targetFolder + '/sizeInfo.txt'
        tarFile2 = self.data['clientPath'] + '/z_errorInfo/' + targetFolder + '/subPackageError.txt'

        tool.copyFile(srcFile1, tarFile1)
        if not self.ignoreSubError:
            if os.path.exists(srcFile2):
                print(f'分包有异常，请查看文件:{tarFile2}')
                tool.copyFile(srcFile2 , tarFile2)
                self.subCfgError = True
                return False

        srcSubFileList = self.data['clientPath'] + '/luaecode/subContent/filelist_sub.txt'
        tarSubFileList = root + '/z_subSizeInfo/' + targetFolder + '/filelist_sub.txt'
        tool.copyFile(srcSubFileList, tarSubFileList)

        return True

    def beginPackA(self):
        print(f'\r\n{tool.showTime()} android begin ===========================>')
        batFile = self.data['clientPath'] + '/luaecode/z_resource_package_android.bat'

        param1 = self.data['sourceResPath']
        param2 = self.data.get('isSubRes', 2)

        cmd = f'start /wait {batFile} {param1} {param2}'
        os.system(cmd)

        if not self.subCfgError and self.errorAndSizeInfo(self.data['androidHotFilePath'], 1):
            updateSrcFolder = self.data['clientPath'] + '/luaecode/android-kuniu/assets'
            subSrcFolder = self.data['clientPath'] + '/luaecode/subContentAssert'

            tarUpdateFolder = root + '/update/' + self.data['androidHotFilePath'] + '/' + str(self.aNewVersion) + '/assets'
            if 'updateAllFile' in self.data:
                updateSrcFolder = self.data['clientPath'] + '/sg1'
                tarUpdateFolder += '/sg'

            tarSubFolder = root + '/subcontracting/' + self.data['andoridSubFilePath']

            tool.delFile(tarUpdateFolder)
            tool.delFile(tarSubFolder)
            print('拷贝更新资源到推送文件夹')
            tool.copyFile(updateSrcFolder , tarUpdateFolder)

            print('拷贝分包资源到推送文件夹')
            tool.copyFile(subSrcFolder , tarSubFolder)

            print(f'\r\n{tool.showTime()} android end time <===================')

    def beginPackB(self):
        print(f'\r\n{tool.showTime()} ios begin ===========================>')
        batFile = self.data['clientPath'] + '/luaecode/z_resource_package_ios.bat'

        param1 = 2
        param2 = 3
        param3 = self.data['iosGameFlg']
        param4 = 2
        param5 = self.data['sourceResPath']

        cmd = f'start /wait {batFile} {param1} {param2} {param3} {param4} {param5}'
        os.system(cmd)
        if not self.subCfgError and self.errorAndSizeInfo(self.data['iosHotFilePath'], 2):
            updateSrcFolder = self.data['clientPath'] + '/luaecode/android-kuniu/assets'
            subSrcFolder = self.data['clientPath'] + '/luaecode/subContentAssert'

            tarUpdateFolder = root + '/update/' + self.data['iosHotFilePath'] + '/' + str(self.bNewVersion) + '/assets'
            if 'updateAllFile' in self.data:
                updateSrcFolder = self.data['clientPath'] + '/sg1'
                tarUpdateFolder += '/sg'

            tarSubFolder = root + '/subcontracting/' + self.data['iosSubFilePath']

            tool.delFile(tarUpdateFolder)
            tool.delFile(tarSubFolder)

            print('拷贝更新资源到推送文件夹')
            tool.copyFile(updateSrcFolder , tarUpdateFolder)

            print('拷贝分包资源到推送文件夹')
            tool.copyFile(subSrcFolder , tarSubFolder)

            print(f'\r\n{tool.showTime()} ios end <===================')

    def isSubError(self):
        return self.subCfgError

def createPackage(paramsList):
    gameId = paramsList['target']
    platform = paramsList['platform']
    ignoreSubError = paramsList['ignore']

    newPackage = package(totoalCfg[gameId], platform, ignoreSubError)
    newPackage.newVersionFolder()
    newPackage.showNewVersion()
    newPackage.beginPack()

    if newPackage.isSubError():
        return False

    return True

    print('更新包,分包资源准备完成!\n')

def pushFolders(paramsList):
    gameId = paramsList['target']
    pushFolder.main(paramsList, totoalCfg[gameId])

def versionFileChange(paramsList):
    gameId = paramsList['target']
    version.main(paramsList, totoalCfg[gameId])

def refreshUrlByAPI(paramsList):
    gameId = paramsList['target']
    refreshUrl.main(paramsList, totoalCfg[gameId])

def copyBackSubFile(paramsList):
    gameId = paramsList['target']
    gameCfg = totoalCfg[gameId]
    platform = paramsList['platform']

    if platform == 1 or platform == 3:
        tarSubFileList = gameCfg['clientPath'] + '/luaecode/subContentOld/filelist_sub_' + gameCfg['sourceResPath'] + '.txt'
        srcSubFileList = root + '/z_subSizeInfo/' + gameCfg['androidHotFilePath'] + '/filelist_sub.txt'
        tool.copyFile(srcSubFileList, tarSubFileList)
    
    if platform == 2 or platform == 3:
        tarSubFileList = gameCfg['clientPath'] + '/luaecode/subContentOld/filelist_sub_'+ gameCfg['iosGameFlg'] + '.txt'
        srcSubFileList = root + '/z_subSizeInfo/' + gameCfg['iosHotFilePath'] + '/filelist_sub.txt'
        tool.copyFile(srcSubFileList, tarSubFileList)

def initCfg():
    global totoalCfg
    res = tool.ReadFile("packageCfg.json")
    totoalCfg = json.loads(res)

# -target game1
# -platform (1, 2, 3)
# -arrow

# -package   -ph (1, 0) -ver(0, 1) -ref (0, 1)
# -push 
# -version -arrow (up, down) -debug (0, 1)
# -refresh -debug (0, 1)

# -tip  0. 不提示
#       1. 打印警告信息
#       2. 弹出提示框, 暂停执行等待确认


class comm:
    def __init__(self):
        self.params = {}
        usage = '使用脚本打包客户端更新包, 分包资源'
        self.parser = OptionParser(usage=usage)
        self.parser.add_option('--time', '--time', dest='time', type = "string", help = "时间")
        self.parser.add_option('-t', '--target', dest='target', type = "string", help = "gameId:" + str(totoalCfg.keys()))
        self.parser.add_option('-p', '--platform', dest='platform', type = "int", help = "platform:1.android,2.IOS, 3.ALL")
        self.parser.add_option('--tip', dest='tipLevel', type = "int", default=0)
        
        self.parser.add_option('--package', dest='package', action="store_true", default=False, help = '生成更新文件,分包文件')
        self.parser.add_option('--push', dest='push', action="store_true", default=False, help = '推送生成更新文件,分包文件')
        self.parser.add_option('-r', '--refresh', dest='refresh', action="store_true", default=False, help= '刷新配置url')
        self.parser.add_option('-v', '--version', dest='version', action="store_true", default=False , help = "根据本地文件夹更新版本")
        self.parser.add_option('-s', '--show', dest='show', action="store_true", default=False , help = "显示链接信息")

        self.parser.add_option('-d', '--debug', dest='debug', action="store_true", default=False, help = '是否是debug模式. 对应 _tmp.cfg')
        self.parser.add_option('-n', '--notice', dest='notice', action="store_true", default=False, help = '刷新公告url')
        self.parser.add_option('--arrow', dest='arrow', action="store", default='up', help = '版本号: up.最新文件夹对应版本号,down.次新文件夹对应版本号')
        self.parser.add_option('-b', dest='back', action="store_true", default=False)
        self.parser.add_option('-i', '--ignore', dest='ignore', action="store_true", default=False)

        (options, _) = self.parser.parse_args()
        self.options = options

    def delArgv(self):
        gameId = self.options.target
        if not gameId:
            while gameId is None:
                print("选择需要打包的游戏id", totoalCfg.keys())
                gameId = tool.waitInputIdx()
                if gameId:
                    if gameId not in totoalCfg:
                        print("请输入正确的游戏id.", totoalCfg.keys())
                        gameId = None
        
        platform = self.options.platform
        if not platform:
            if platform is None:
                print("选择需要打包的平台: 1. 安卓， 2.IOS，3.全部")
                platform = tool.waitInputIdx(1, 3)

        self.toParams()

        self.params['target'] = gameId
        self.params['platform'] = platform

        platforms = []
        self.params['platforms'] = platforms

        if platform == 1 or platform == 3:
            platforms.append('android')
        
        if platform == 2 or platform == 3:
            platforms.append('ios')

        if self.options.tipLevel > 0:
            print('参数信息如下,请确认!')
            print(self.params)

            if tkinter.messagebox.askokcancel('提示', '输入参数解析检查!'):
                self.begin()
        else:
            self.begin()
             
    def begin(self):
        if self.options.package:
            if not createPackage(self.params):
                return
        
        if self.options.push:
            pushFolders(self.params)

        if self.options.time:
            pos = self.options.time.find(":")
            if pos > -1:
                hour = self.options.time[:pos]
                mins = self.options.time[pos+1:]
                hour = int(hour)
                mins = int(mins)
                if hour and mins and 0 <= int(hour) < 24 and  0 <= int(mins) < 60:
                    while True:
                        curHour = datetime.datetime.now().strftime("%H")
                        curHour = int(curHour)

                        curMins = datetime.datetime.now().strftime("%M")
                        curMins = int(curMins)

                        if (curHour > hour) or (curHour == hour and curMins > mins):
                            print(f"执行时间{curHour}:{curMins}")
                            break
                        else:
                            print(f"执行时间{hour}:{mins} 当前时间{curHour}:{curMins}")
                            time.sleep(60)            

        if self.options.version:
            versionFileChange(self.params)

        if self.options.refresh:
            refreshUrlByAPI(self.params)

        if self.options.back:
            copyBackSubFile(self.params)


    def toParams(self):
        if not self.params:
            for option in dir(self.options):
                if option.find("_") == -1:
                    self.params[option] = getattr(self.options, option)

def main():
    global root
    root = os.getcwd()
    print(root)
    initCfg()

    commond = comm()
    commond.delArgv()

    os.system("pause")

if __name__ == "__main__":
    main()