echo off

echo 解析准备重新打包图集
rmdir /s /q pvrTmp
md pvrTmp
pngPlistToPvr2.py 4
echo 解析成功
pause
exit 
