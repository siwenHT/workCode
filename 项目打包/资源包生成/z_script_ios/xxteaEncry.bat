CHCP 65001
echo off

set srcPath=..\client\sg_waiwang\src
set spaceNum=4
set specSpace=1111
echo 源码加密中..
xxteaEncry.py %srcPath% %spaceNum% %specSpace%
echo 源码加密完成...

echo 资源包版本号:
type ..\sg1\version.txt
echo.
pause
exit 
