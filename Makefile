CC = gcc
FL = src/main.c
CF = -std=c99 -Wpedantic -lm
OUT = bin/main.exe

.SILENT:
all: $(FL)
	mkdir -p bin
	$(CC) -o $(OUT) $(FL) $(CF)
	$(OUT)

