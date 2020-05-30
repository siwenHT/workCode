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
echo ���Դ�ļ���: 1:sg, 2:sg_waiwang, 3:sgPlaneB
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

echo ���Դ�ļ���:!sourcePath!
echo 1��������Դ��2���ְ���Դ
if defined input1 (
set packageType=!input1!
) else (
set /p packageType=
)

echo ��Դ��ʽ:1��pvrtc4, 2��RGB444, 3��ETC2, 4��pvrtc2
if defined input2 (
set format=!input2!
) else (
set /p format=
)

set flg='100'
echo ��Ϸ���:1��ios, 2��lmjy, 3��ahywl
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

echo �Ƿ��������1���ǣ�2����
if defined input4 (
set typeId=!input4!
) else (
set /p typeId=
)

REM ��������Դ�ȿ�������, ����İ�fileplist���Ƕ�Ӧ��
if !typeId!==1 (
	echo ����������ļ�����:
	set /p tishenName=
	
	if exist ..\sgChange\sg!tishenName! (
		echo ------------------------------�����滻��Դ----------------------------------
		xcopy /s /r /y /q ..\sgChange\sg!tishenName!\*.* ..\!sourcePath!\
	)
)

echo !packageType!.!format!.!gameId!.!flg!.!typeId!

echo.
echo ��ʼ���:%date% %time%
echo ------------------------------ɾ������Դ----------------------------------
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
echo ʱ��:%date% %time%
echo ------------------------------��ȡ�ְ��ļ��б�----------------------------------
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
echo ��ȡ�ְ��ļ��б����...
echo %date% %time%

echo.
echo ʱ��:%date% %time%
echo ------------------------------��Դѹ��----------------------------------
echo ׼��plst,pvr���

rmdir /s /q pvrTmp
md pvrTmp

echo ����׼�����´��ͼ��
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
echo �����ɹ�

echo plistѹ����ʼ
python !script!/plistConvertor_ios.py 0 !format! !sourcePath!

echo ��Դѹ�����

echo.
echo ʱ��:%date% %time%
echo ------------------------------������Դ----------------------------------
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
echo ʱ��:%date% %time%
echo ------------------------------����Դ��----------------------------------
set srcPath=!sourcePath!/src
set spaceNum=4
set specSpace=1111
echo Դ�������..
python !script!\xxteaEncry.py %srcPath% %spaceNum% %specSpace%
echo Դ��������...

echo.
echo ʱ��:%date% %time%
echo ------------------------------��������ļ�----------------------------------

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
REM �汾��
echo ��Դ���汾��:
type ..\sg1\version.txt
echo.

if !packageType!==3 (
	echo.
	echo ʱ��:%date% %time%
	echo ------------------------------�޳��ְ���Դ----------------------------------
	python !script!\afterSubcontractingSg1.py filelist_sub_!flg!.txt
    goto over
)

if !packageType!==2 (
	echo.
	echo ʱ��:%date% %time%
	echo ------------------------------�޳��ְ���Դ----------------------------------
    python !script!\afterSubcontractingSg1.py filelist_sub_!flg!.txt
)

echo.
echo ʱ��:%date% %time%
echo ------------------------------�����ȸ���Դ----------------------------------

cd android-kuniu
rd /q /s assets
rd /q /s temp
md "assets\"
md "temp\"

echo ���� sg1 �б�MD5ֵ....
python md5_sg1.py
echo �����ȸ����ļ�......
python hotUpdateCheck.py filelist_!flg!.txt
echo ��ȡ�ȸ��ļ���MD5ֵ... 
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
echo ���ʱ��:%date% %time%

if not defined input1 (
pause
)
goto out


:error1
echo �ְ���id�ظ�����鿴 luaecode\getPackagedFileList\idError.txt
echo �ְ���id�ظ�����鿴 luaecode\getPackagedFileList\idError.txt
type getPackagedFileList\idError.txt
echo.

pause

:out
exit