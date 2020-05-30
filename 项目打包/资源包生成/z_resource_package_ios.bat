@echo off

setlocal enabledelayedexpansion
cd /d %~dp0
set nowPath=%~dp0
set script=z_script_ios
set sourcePath=sg_waiwang
set input1=%1%
set input2=%2%
set input3=%3%
set input4=%4%
set input5=%5%
echo !input1!_!input2!_!input3!_!input4!_!input5!

if defined input5 (
set sourcePath=!input5!
) else (
echo 打包源文件夹: 1:sg, 2:sg_waiwang, 3:sgPlaneB
set /p sourcePath=
)
if !sourcePath! == 1 (
set sourcePath=sg
)

if !sourcePath! == 2 (
set sourcePath=sg_waiwang
)
if !sourcePath! == 3 (
set sourcePath=sgPlaneB
)

echo 打包源文件夹:!sourcePath!
echo 1：整包资源，2：分包资源
if defined input1 (
set packageType=!input1!
) else (
set /p packageType=
)

echo 资源格式:1、pvrtc4, 2、RGB444, 3、ETC2, 4、pvrtc2
if defined input2 (
set format=!input2!
) else (
set /p format=
)

set flg='100'
echo 游戏标记:1、ios, 2、lmjy, 3、ahywl
if defined input3 (
set gameId=!input3!
set flg=!input3!
) else (
set /p gameId= 
)

if !gameId!==1 (
set flg=ios
) 
if !gameId!==2 (
set flg=lmjy
) 
if !gameId!==3 (
set flg=ahywl
) 

echo 是否提审包：1、是，2、否
if defined input4 (
set typeId=!input4!
) else (
set /p typeId=
)

REM 把提审资源先拷贝过来, 打出的包fileplist才是对应的
if !typeId!==1 (
	echo 输入提审包文件夹名:
	set /p tishenName=
	
	if exist ..\sgChange\sg!tishenName! (
		echo ------------------------------存在替换资源----------------------------------
		xcopy /s /r /y /q ..\sgChange\sg!tishenName!\*.* ..\!sourcePath!\
	)
)

echo !packageType!.!format!.!gameId!.!flg!.!typeId!

echo.
echo 开始打包:%date% %time%
echo ------------------------------删除老资源----------------------------------
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

echo.
echo 时间:%date% %time%
echo ------------------------------获取分包文件列表----------------------------------
REM if !typeId!==1 (
REM copy /y ..\!sourcePath!\src\config\resouceCfg_ios.lua getPackagedFileList\src\resouceCfg.lua
REM ) else (
copy /y ..\!sourcePath!\src\config\resouceCfg.lua getPackagedFileList\src\resouceCfg.lua
REM )
cd getPackagedFileList
magic1111.exe
cd ..

REM if exist getPackagedFileList\idError.txt goto error1 

copy /y getPackagedFileList\packagedFileList.txt packagedFileList.txt
copy /y getPackagedFileList\packagedFileList2.txt packagedFileList2.txt
copy /y getPackagedFileList\status.cfg status.cfg
echo 获取分包文件列表结束...
echo %date% %time%

echo.
echo 时间:%date% %time%
echo ------------------------------资源压缩----------------------------------
echo 准备plst,pvr打包

rmdir /s /q pvrTmp
md pvrTmp

echo 解析准备重新打包图集
if !format!==2 (
python pngPlistToPvr2.py 2 !sourcePath!
)
if !format!==1 (
python pngPlistToPvr2.py 1 !sourcePath!
)
if !format!==4 (
python pngPlistToPvr2.py 4 !sourcePath!
)
if !format!==3 (
python !script!/pkmConvertor_ios.py 4 !sourcePath!
)
rmdir /s /q pvrTmp
echo 解析成功

echo plist压缩开始
python !script!/plistConvertor_ios.py 0 !format! !sourcePath!

echo 资源压缩完成

echo.
echo 时间:%date% %time%
echo ------------------------------拷贝资源----------------------------------
set path1=../sgIos
if !format!==1 (
set path1=../sgIos_pvrtc4
)

if !format!==3 (
set path1=../etc2
)

if !format!==4 (
set path1=../pvrtc2
)

python !script!\totalCopyFiles.py !path1!_!sourcePath! !sourcePath!
xcopy /s /r /y ..\!sourcePath!\res\particle\*.* ..\sg1\res\particle\

echo.
echo 时间:%date% %time%
echo ------------------------------加密源码----------------------------------
set srcPath=!sourcePath!/src
set spaceNum=4
set specSpace=1111
echo 源码加密中..
python !script!\xxteaEncry.py %srcPath% %spaceNum% %specSpace%
echo 源码加密完成...

echo.
echo 时间:%date% %time%
echo ------------------------------清理残余文件----------------------------------

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
echo %date% %time%

REM ============================================================================================
REM 版本号
echo 资源包版本号:
type ..\sg1\version.txt
echo.

if !packageType!==3 (
	echo.
	echo 时间:%date% %time%
	echo ------------------------------剔除分包资源----------------------------------
	python !script!\afterSubcontractingSg1.py filelist_sub_!flg!.txt
    goto over
)

if !packageType!==2 (
	echo.
	echo 时间:%date% %time%
	echo ------------------------------剔除分包资源----------------------------------
    python !script!\afterSubcontractingSg1.py filelist_sub_!flg!.txt
)

echo.
echo 时间:%date% %time%
echo ------------------------------生成热更资源----------------------------------

cd android-kuniu
rd /q /s assets
rd /q /s temp
md "assets\"
md "temp\"

echo 生成 sg1 列表MD5值....
python md5_sg1.py
echo 生成热更新文件......
python hotUpdateCheck.py filelist_!flg!.txt
echo 获取热更文件的MD5值... 
python md5_asset.py 

echo . 
copy /y temp\filelist.txt assets\sg\filelist.txt
copy /y MD5_current\filelist.txt ..\..\sg1\filelist.txt

REM start /wait afterSubcontractingSg1.bat
cd /d %~dp0
del /s /q status.cfg
del /s /q packagedFileList.txt
del /s /q packagedFileList2.txt

:over
echo.
echo 完成时间:%date% %time%

if not defined input1 (
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