@echo off

if "%1" == "" (
    echo No parameter
) else (
    :: ^ is escape character
    echo execute gcc %1 ^&^& .\a.exe
    gcc %1 && .\a.exe
)