echo off

rd /q /s assets
rd /q /s temp
md "assets\"
md "temp\"

echo ����sg1MD5
python md5_sg1.py
echo �����ȸ��ļ�1
python hotUpdateCheck.py
echo �����ȸ��ļ��ɹ�������
echo ��ȡ�ȸ��ļ���MD5�б�
python md5_asset.py 
echo ��ȡ�ȸ��ļ���MD5�б�ɹ�������
copy /y temp\filelist.txt assets\sg\filelist.txt
exit
pause
