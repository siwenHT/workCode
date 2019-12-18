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
set destFodler=!destPath!\file_!flgName!

echo destFodler=!destFodler!
rmdir /s /q !destFodler!\
md !destFodler!\

xcopy /s /r /y /q res\os_ex\*.* !destFodler!\
xcopy /s /r /y /q out\oc_targetIosFile\*.* !destFodler!\

pause