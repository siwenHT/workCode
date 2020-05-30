CHCP 65001
echo off

set srcPath=sg_waiwang/src
set spaceNum=0
echo 源码加密中..
xxteaDecrypt.py %srcPath% %spaceNum%
echo 源码加密完成...

echo 资源包版本号:
type ..\sg1\version.txt
echo.
pause
exit 
