@echo off

set COM=gcc
set MAIN=main.c
set BIN=bin
set OUT=main.exe
set FLAGS=-Wall -Wextra

if not exist bin mkdir bin

call %COM% %MAIN% -o %BIN%\%OUT% %FLAGS%
call %BIN%\%OUT%