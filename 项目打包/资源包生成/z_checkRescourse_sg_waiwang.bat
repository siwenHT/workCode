@echo off

setlocal enabledelayedexpansion
cd /d %~dp0
set sourcePath=sg_waiwang
REM set input=%1%
REM set input2=%2%
REM echo ���Դ�ļ���: 1.sg, 2:sg_waiwang
REM if defined input (
REM set inputFloder=!input!
REM ) else (
REM set /p inputFloder=
REM )

REM if !inputFloder!==1 (
REM set sourcePath=sg
REM )

REM if !inputFloder!==2 (
REM set sourcePath=sg_waiwang
REM )
	
echo ���Դ�ļ���:!sourcePath!
REM echo 1��������Դ��2���ְ���Դ
REM if defined input2 (
REM set packageType=!input2!
REM ) else (
REM set /p packageType=
REM )
set packageType=2
echo ��Դ������:�ְ���Դ

echo.
echo ��ʼʱ��:
echo %date%%time%
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

copy /y ..\!sourcePath!\src\config\resouceCfg.lua getPackagedFileList\src\resouceCfg.lua
cd getPackagedFileList
magic1111.exe
cd ..

if exist getPackagedFileList\idError.txt goto error1

copy /y getPackagedFileList\packagedFileList.txt packagedFileList.txt
copy /y getPackagedFileList\packagedFileList2.txt packagedFileList2.txt
copy /y getPackagedFileList\status.cfg status.cfg
echo ��ȡ�ְ��ļ��б����...
echo %date%%time%

REM ============================================================================================
REM ��Դѹ��
REM echo ��Դѹ����Androidƽ̨ģʽ
REM cd ..\Arts\texturepacker_Tool\MaliTextureCompressionTool_v4.3.0\bin\
REM python ..\..\pkmConvertor.py !sourcePath!
REM python ..\..\plistConvertor.py !sourcePath!
REM cd /d %~dp0
REM echo ��Դѹ�����

REM echo %date%%time%
REM echo ��׿��Դ������..
REM xcopy /s /r /y /q ..\sgAndroid ..\sg1
REM xcopy /s /r /y /q ..\sgCommon ..\sg1
REM xcopy /s /r /y /q ..\!sourcePath!\res\particle ..\sg1\res\particle
REM echo ��׿�������...
REM echo %date%%time%

REM REM ============================================================================================
REM REM ����sg��sg1
REM echo ʣ����Դ������ʼ...
REM REM xcopy /s /r /y /q  ..\!sourcePath! ..\sg1
REM python partCopyFilesEx.py ../!sourcePath! ../sg1
REM echo ʣ����Դ��������...
REM echo %date%%time%

REM REM ============================================================================================
REM �µ���Դ����
echo %date%%time%
echo copyFiles to sg1 and subContent
python totalCopyFiles.py
xcopy /s /r /y /q ..\!sourcePath!\res\particle ..\sg1\res\particle
echo %date%%time%

REM ============================================================================================
REM ����
REM set srcPath=!sourcePath!/src
REM set spaceNum=0
REM echo Դ�������..
REM xxteaEncry.py %srcPath% %spaceNum%
REM echo Դ��������...
REM echo %date%%time%

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
echo %date%%time%

REM ============================================================================================
REM �汾��
echo ��Դ���汾��:
type ..\sg1\version.txt
echo.

if !packageType!==2 (
python afterSubcontractingSg1.py
)

echo %date%%time%
REM echo �����ȸ���Դ
REM cd android-kuniu

REM rd /q /s assets
REM rd /q /s temp
REM md "assets\"
REM md "temp\"

REM echo sg1 md5Val list....
REM python md5_sg1.py

REM echo update files......
REM python hotUpdateCheck.py

REM echo update files md5Val list...
REM python md5_asset.py

REM echo.
REM echo copy updateFile md5File to assets
REM copy /y temp\filelist.txt assets\sg\filelist.txt

REM echo copy currentFiles md5File to sg1
REM copy /y MD5_current\filelist.txt ..\..\sg1\filelist.txt

cd /d %~dp0

echo ɾ�����ļ���
delEmptyFolder.py ..\sg1\

echo.
echo ���ʱ��:
echo %date%%time%

if not defined input (
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