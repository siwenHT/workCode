echo off

rd /q /s assets
rd /q /s temp
md "assets\"
md "temp\"

echo 生成sg1MD5
python md5_sg1.py
echo 生成热更文件1
python hotUpdateCheck.py
echo 生成热更文件成功。。。
echo 获取热更文件的MD5列表
python md5_asset.py 
echo 获取热更文件的MD5列表成功。。。
copy /y temp\filelist.txt assets\sg\filelist.txt
exit
pause
