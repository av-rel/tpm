@echo off

set COM=gcc
set MAIN=tests\test.c
set BIN=bin\test.exe
:: set CFLAGS=-g -Wall -Wextra
set FLAGS=

if not exist bin mkdir bin

call %COM% %MAIN% -o %BIN% %CFLAGS%
call %BIN% %FLAGS%
