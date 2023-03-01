@echo off

set COM=gcc
set MAIN=test.c
set BIN=bin\test.exe
set FLAGS=-Wall -Wextra

if not exist bin mkdir bin

call %COM% %MAIN% -o %BIN% %FLAGS%
call %BIN%
