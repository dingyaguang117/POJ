@echo off
TITLE  VS���������ļ��������
ECHO ��ʼ����...
rmdir /s /q Debug
rmdir /s /q ipch
del   *.sdf
del   *.sln
del   *.vcxproj
del   *.filters
del   *.user
del   *.txt
del   *.in
del   *.out
ECHO �������...
@echo on