@echo off

setlocal enabledelayedexpansion
cd /d %~dp0
set sourcePath=sg_waiwang
set input=%1%
set input2=%2%
echo 打包源文件夹: 1.sg, 2:sg_waiwang
if defined input (
set inputFloder=!input!
) else (
set /p inputFloder=
)

if !inputFloder!==1 (
set sourcePath=sg
)

if !inputFloder!==2 (
set sourcePath=sg_waiwang
)
	
echo 打包源文件夹:!sourcePath!
echo 1：整包资源，2：分包资源
if defined input2 (
set packageType=!input2!
) else (
set /p packageType=
)
echo 资源包类型:!packageType!

echo.
echo 开始时间:
echo %date%%time%
REM ============================================================================================
REM 删除老资源
del /s /q getPackagedFileList\src\resouceCfg.lua
del /s /q getPackagedFileList\packagedFileList.txt
del /s /q getPackagedFileList\packagedFileList2.txt
del /s /q getPackagedFileList\status.cfg
del /s /q packagedFileList.txt
del /s /q status.cfg
del /s /q subPackageError.txt

rmdir /s /q subContent\

rmdir /s /q  ..\sg1\
md "..\sg1\"

REM ============================================================================================
REM 验证分包表
echo 获取分包文件列表...

copy /y ..\!sourcePath!\src\config\resouceCfg.lua getPackagedFileList\src\resouceCfg.lua
cd getPackagedFileList
magic1111.exe
cd ..

if exist getPackagedFileList\idError.txt goto error1

copy /y getPackagedFileList\packagedFileList.txt packagedFileList.txt
copy /y getPackagedFileList\packagedFileList2.txt packagedFileList2.txt
copy /y getPackagedFileList\status.cfg status.cfg
echo 获取分包文件列表结束...
echo %date%%time%

REM ============================================================================================
REM 资源压缩
echo 资源压缩到Android平台模式
cd ..\Arts\texturepacker_Tool\MaliTextureCompressionTool_v4.3.0\bin\
python ..\..\pkmConvertor.py !sourcePath!
python ..\..\plistConvertor.py !sourcePath!
cd /d %~dp0
echo 资源压缩完成

REM echo %date%%time%
REM echo 安卓资源拷贝中..
REM xcopy /s /r /y /q ..\sgAndroid ..\sg1
REM xcopy /s /r /y /q ..\sgCommon ..\sg1
REM xcopy /s /r /y /q ..\!sourcePath!\res\particle ..\sg1\res\particle
REM echo 安卓拷贝完成...
REM echo %date%%time%

REM REM ============================================================================================
REM REM 拷贝sg到sg1
REM echo 剩余资源拷贝开始...
REM REM xcopy /s /r /y /q  ..\!sourcePath! ..\sg1
REM python partCopyFilesEx.py ../!sourcePath! ../sg1
REM echo 剩余资源拷贝结束...
REM echo %date%%time%

REM REM ============================================================================================
REM 新的资源拷贝
echo %date%%time%
echo copyFiles to sg1 and subContent
python totalCopyFiles.py
xcopy /s /r /y /q ..\!sourcePath!\res\particle ..\sg1\res\particle
echo %date%%time%

REM ============================================================================================
REM 加密
set srcPath=!sourcePath!/src
set spaceNum=0
echo 源码加密中..
xxteaEncry.py %srcPath% %spaceNum%
echo 源码加密完成...
echo %date%%time%

REM ============================================================================================
REM 分包

REM echo 生成分包文件列表文件夹..
REM subcontracting.py
REM echo 生成分包文件列表文件夹成功..

copy /y status.cfg ..\sg1\status.cfg
copy /y status.cfg ..\!sourcePath!\status.cfg
copy /y ..\!sourcePath!\version.txt ..\sg1\version.txt
copy /y ..\!sourcePath!\adChannel.png ..\sg1\adChannel.png

del /s /q ..\sg1\src\net\NetMsgDefWithComments.lua
del /s /q ..\sg1\src\config\aiGroup.lua
del /s /q ..\sg1\src\configOp\StringCfg_old.lua
del /s /q ..\sg1\src\config\Sheet1.lua 

del /s /q ..\sg1\serverList.txt
del /s /q ..\sg1\filelist.txt
echo %date%%time%

REM ============================================================================================
REM 版本号
echo 资源包版本号:
type ..\sg1\version.txt
echo.

if !packageType!==2 (
python afterSubcontractingSg1.py
)
echo %date%%time%
echo 生成热更资源
cd android-kuniu

rd /q /s assets
rd /q /s temp
md "assets\"
md "temp\"

echo sg1 md5Val list....
python md5_sg1.py

echo update files......
python hotUpdateCheck.py

echo update files md5Val list...
python md5_asset.py

echo.
echo copy updateFile md5File to assets
copy /y temp\filelist.txt assets\sg\filelist.txt

echo copy currentFiles md5File to sg1
copy /y MD5_current\filelist.txt ..\..\sg1\filelist.txt

cd /d %~dp0

echo 删除空文件夹
delEmptyFolder.py ..\sg1\

echo.
echo 完成时间:
echo %date%%time%

if not defined input (
pause
)
goto out

:error1
echo 分包表id重复，请查看 luaecode\getPackagedFileList\idError.txt
echo 分包表id重复，请查看 luaecode\getPackagedFileList\idError.txt
type getPackagedFileList\idError.txt
echo.
pause

:out
exit