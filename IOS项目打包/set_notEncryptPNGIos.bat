@echo off

setlocal enabledelayedexpansion
cd /d %~dp0
set sourcePath=..\client\sg_waiwang
set input1=%1%
set input2=%2%
set input3=%3%
set input4=%4%
set input5=%5%
echo !input1!_!input2!_!input3!_!input4!_!input5!

if defined input5 (
set sourcePath=!input5!
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

set flg=''
echo 游戏标记:1、flg, 2、lmjy, 3、ahqy 4、hajy
if defined input3 (
set gameId=!input3!
) else (
set /p gameId= 
)

if !gameId!==1 (
set flg=flg
) 
if !gameId!==2 (
set flg=lmjy
) 
if !gameId!==3 (
set flg=ahqy
) 
if !gameId!==4 (
set flg=hajy
) 

echo 是否提审包：1、是，2、否
if defined input4 (
set typeId=!input4!
) else (
set /p typeId=
)

echo !packageType!.!format!.!gameId!.!flg!.!typeId!
echo.
echo 开始时间:
echo %date% %time%

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

if !typeId!==1 (
echo copy /y ..\!sourcePath!\src\config\resouceCfg_ios.lua getPackagedFileList\src\resouceCfg.lua
copy /y ..\!sourcePath!\src\config\resouceCfg_ios.lua getPackagedFileList\src\resouceCfg.lua
) else (
echo copy /y ..\!sourcePath!\src\config\resouceCfg.lua getPackagedFileList\src\resouceCfg.lua
copy /y ..\!sourcePath!\src\config\resouceCfg.lua getPackagedFileList\src\resouceCfg.lua
)
cd getPackagedFileList
magic1111.exe
cd ..

REM if exist getPackagedFileList\idError.txt goto error1 

copy /y getPackagedFileList\packagedFileList.txt packagedFileList.txt
copy /y getPackagedFileList\packagedFileList2.txt packagedFileList2.txt
copy /y getPackagedFileList\status.cfg status.cfg
echo 获取分包文件列表结束...
echo %date% %time%

REM ============================================================================================
REM 资源压缩
echo 准备plst,pvr打包

cd ..\Arts\texturepacker_Tool
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
cd ./MaliTextureCompressionTool_v4.3.0/bin
python ../../pkmConvertor.py 4 !sourcePath!
cd ../../
)

echo 解析成功

echo plist压缩开始
cd ./MaliTextureCompressionTool_v4.3.0/bin
python ../../plistConvertor.py 0 !format! !sourcePath!
echo plist压缩完成
REM start /wait ..\Arts\texturepacker_Tool\plistChangeToIos.bat
cd /d %~dp0
echo 资源压缩完成
echo %date% %time%

REM ============================================================================================
REM 新的文件复制逻辑
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

python totalCopyFiles.py !path1! !sourcePath!
xcopy /s /r /y ..\!sourcePath!\res\particle ..\sg1\res\particle
echo %date% %time%

REM echo Ios资源拷贝中..
REM if !format!==1 (
REM subIosRes.py ..\sgIos_pvrtc4 ..\sg1 1111 1
REM )
REM if !format!==2 (
REM subIosRes.py ..\sgIos ..\sg1 1111 1
REM )
REM if !format!==3 (
REM subIosRes.py ..\etc2 ..\sg1 1111 1
REM )

REM subIosRes.py ..\sgCommon ..\sg1 1111 1
REM xcopy /s /r /y ..\!sourcePath!\res\particle ..\sg1\res\particle
REM echo Ios资源拷贝完成...
REM echo %date% %time%
    
REM REM ============================================================================================
REM echo 剩余资源拷贝开始
REM REM xcopy /s /r /y /q ..\!sourcePath! ..\sg1
REM python partCopyFilesEx.py ../!sourcePath! ../sg1
REM echo 剩余资源拷贝结束...
REM echo %date% %time%

REM ============================================================================================
REM 加密
set srcPath=!sourcePath!/src
set spaceNum=4
set specSpace=1111
echo 源码加密中..
xxteaEncry.py %srcPath% %spaceNum% %specSpace%
echo 源码加密完成...
echo %date% %time%

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
echo %date% %time%

REM ============================================================================================
REM 版本号
echo 资源包版本号:
type ..\sg1\version.txt
echo.

if !packageType!==3 (
	python afterSubcontractingSg1.py filelist_sub_!flg!.txt
    goto over
)

if !packageType!==2 (
    python afterSubcontractingSg1.py filelist_sub_!flg!.txt
)

echo 生成热更资源
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
echo 拷贝热更文件 md5 值
copy /y temp\filelist.txt assets\sg\filelist.txt

echo 拷贝最新资源 md5 值
copy /y MD5_current\filelist.txt ..\..\sg1\filelist.txt

REM start /wait afterSubcontractingSg1.bat
cd /d %~dp0

:over
echo.
echo 完成时间:
echo %date% %time%

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