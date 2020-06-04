@echo off
setlocal enabledelayedexpansion
cd /d %~dp0

set input=%1%

set destPath=E:\magicRpg\magic_ios\frameworks\runtime-src
if not defined input (
echo 输入IOS游戏标识
set /p flgName=
) else (
set flgName=!input!
)
set destFodler=!destPath!\classes_!flgName!

echo destFodler=!destFodler!
rmdir /s /q !destFodler!\
mkdir !destFodler!\


rmDir /s /q out\c_changeClass\young\
rmDir /s /q out\c_changeClass\YunVaSDK\

xcopy /s /r /y /q out\c_changeClass\*.* !destFodler!\
xcopy /s /r /y /q out\c_CreateClass\*.* !destFodler!\files\

exit