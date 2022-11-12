@echo off

mingw32-make compile-windows
mingw32-make exe
mingw32-make del
.\build\stoopid.exe test.stpd

@echo on