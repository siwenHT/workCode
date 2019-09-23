@echo off
CHCP 65001
setlocal enabledelayedexpansion

echo.
echo 开始时间:
echo %date% %time%

set flg=hajy
set resDest=..\sg!flg!
set sourPath=..\sg1
set destPath=E:\magicRpg\magic_ios\sg!flg!

rmdir /s /q  !resDest!\
md !resDest!\

rmdir /s /q ..\sgTmp\src\
md ..\sgTmp\src\

REM ============================================================================================
REM 加密
REM 用另外的文件加密, 是因为需要对文件加入注释, 如果加入到sg1里面. 就会导致sg1资源做热更异常
set srcPath=sg/src
set spaceNum=4
set specSpace=1111
echo 源码加密中..
xxteaEncry.py %srcPath% %spaceNum% %specSpace% 1 sgTmp/src
echo 源码加密完成...

copy outAppendRes\!flg!\rep_resFullPathName.txt outAppendRes\rep_resFullPathName.txt
copy outAppendRes\!flg!\rep_resPath.txt outAppendRes\rep_resPath.txt
copy outAppendRes\!flg!\initFile_ex.lua !sourPath!\cocos\initFile_ex.lua

echo.
echo %date% %time%
echo 向 !resDest! 资源拷贝中 ... 
subIosRes.py !sourPath! !resDest! 0 0 4 3 1
subIosRes.py ..\sgTmp !resDest! 0 0 4 3 1
echo 向 !resDest! 资源拷贝完成 ...

rmdir /s /q ..\sgTmp\

del /s /q !resDest!\src\net\NetMsgDefWithComments.lua
del /s /q !resDest!\src\config\aiGroup.lua
del /s /q !resDest!\src\configOp\StringCfg_old.lua
del /s /q !resDest!\src\config\Sheet1.lua

if exist ..\sgChange\sg!flg! (
echo 存在替换资源
subIosRes.py ..\sgChange\sg!flg! !resDest! 0 0 4 3 1
REM xcopy /s /r /y ..\sgChange\sg!flg! !resDest!
)

echo.
echo %date% %time%
echo 资源拷贝到目标
rmdir /s /q  !destPath!\

md !destPath!\
echo 目标文件清理完毕

xcopy /s /r /y /q !resDest! !destPath!
echo 资源拷贝到目标完成
REM subIosRes.py ..\sg\res\particle\ E:\magicRpg\magic_ios\sg\res\particle\ 0 0 4 3 1
REM xcopy /s /r /y ..\sg\res\particle\*.plist E:\magicRpg\magic_ios\sg\res\particle\

echo 拷贝资源结束...

echo.
echo 拷贝杂质资源 ...
subIosRes.py outAppendRes\target!flg! !destPath! 0 0 4 3 1 0 0 
echo 拷贝杂质资源完成 ...

echo.
echo %date% %time%
echo 准备资源打包
zipFiles.py !flg!
copy outAppendRes\!flg!\DeprecatedExtend_ex.lua !destPath!\cocos\cocos2d\DeprecatedExtend_ex.lua

echo 准备删除空文件夹
delEmptyFolder.py !destPath!\

echo.
echo 完成时间:
echo %date% %time%

pause
exit 
