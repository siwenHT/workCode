CHCP 65001
echo off

set srcPath=sg_waiwang/src
set spaceNum=0
echo 源码加密中..
xxteaEncry.py %srcPath% %spaceNum%
echo 源码加密完成...

del /s /q ..\sg1\src\net\NetMsgDefWithComments.lua
del /s /q ..\sg1\src\config\aiGroup.lua
del /s /q ..\sg1\src\configOp\StringCfg_old.lua
del /s /q ..\sg1\src\config\Sheet1.lua 

echo 资源包版本号:
type ..\sg1\version.txt
echo.
pause
exit 
