@echo off
TITLE  VS工程冗余文件清除工具
ECHO 开始清理...
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
ECHO 清理完毕...
@echo on