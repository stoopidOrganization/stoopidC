@echo off

mingw32-make compile-windows
mingw32-make exe
mingw32-make del

echo ------------------------

.\build\stoopid.exe .\stpd\test.stpd

@echo on