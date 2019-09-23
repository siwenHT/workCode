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

set flg=''
echo ��Ϸ���:1��flg, 2��lmjy, 3��ahqy 4��hajy
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

echo �Ƿ��������1���ǣ�2����
if defined input4 (
set typeId=!input4!
) else (
set /p typeId=
)

echo !packageType!.!format!.!gameId!.!flg!.!typeId!
echo.
echo ��ʼʱ��:
echo %date% %time%

REM ============================================================================================
REM ɾ������Դ
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
REM ��֤�ְ���
echo ��ȡ�ְ��ļ��б�...

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
echo ��ȡ�ְ��ļ��б����...
echo %date% %time%

REM ============================================================================================
REM ��Դѹ��
echo ׼��plst,pvr���

cd ..\Arts\texturepacker_Tool
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
cd ./MaliTextureCompressionTool_v4.3.0/bin
python ../../pkmConvertor.py 4 !sourcePath!
cd ../../
)

echo �����ɹ�

echo plistѹ����ʼ
cd ./MaliTextureCompressionTool_v4.3.0/bin
python ../../plistConvertor.py 0 !format! !sourcePath!
echo plistѹ�����
REM start /wait ..\Arts\texturepacker_Tool\plistChangeToIos.bat
cd /d %~dp0
echo ��Դѹ�����
echo %date% %time%

REM ============================================================================================
REM �µ��ļ������߼�
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

REM echo Ios��Դ������..
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
REM echo Ios��Դ�������...
REM echo %date% %time%
    
REM REM ============================================================================================
REM echo ʣ����Դ������ʼ
REM REM xcopy /s /r /y /q ..\!sourcePath! ..\sg1
REM python partCopyFilesEx.py ../!sourcePath! ../sg1
REM echo ʣ����Դ��������...
REM echo %date% %time%

REM ============================================================================================
REM ����
set srcPath=!sourcePath!/src
set spaceNum=4
set specSpace=1111
echo Դ�������..
xxteaEncry.py %srcPath% %spaceNum% %specSpace%
echo Դ��������...
echo %date% %time%

REM ============================================================================================
REM �ְ�
REM echo ���ɷְ��ļ��б��ļ���..
REM subcontracting.py
REM echo ���ɷְ��ļ��б��ļ��гɹ�..

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
	python afterSubcontractingSg1.py filelist_sub_!flg!.txt
    goto over
)

if !packageType!==2 (
    python afterSubcontractingSg1.py filelist_sub_!flg!.txt
)

echo �����ȸ���Դ
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
echo �����ȸ��ļ� md5 ֵ
copy /y temp\filelist.txt assets\sg\filelist.txt

echo ����������Դ md5 ֵ
copy /y MD5_current\filelist.txt ..\..\sg1\filelist.txt

REM start /wait afterSubcontractingSg1.bat
cd /d %~dp0

:over
echo.
echo ���ʱ��:
echo %date% %time%

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