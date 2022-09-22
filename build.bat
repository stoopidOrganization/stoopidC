@echo off
del .\build\* /q
rmdir .\build\
mkdir build

echo compiling scripts...
cd .\src\
gcc -Wall -c *.c
echo compiled scripts
echo:

echo building exe...
cd ..\build\
gcc -o stoopid ..\src\*.o
echo build finished
echo:

del ..\src\*.o
echo successfully build exe
echo:
@echo on