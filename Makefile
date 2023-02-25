CC = gcc
FL = src/main.c
CF = -Wpedantic -Wall
OUT = bin/main.exe

.SILENT:
all: $(FL)
	mkdir -p bin
	$(CC) -o $(OUT) $(FL) $(CF)
	$(OUT)

