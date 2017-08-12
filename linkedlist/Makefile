
CC=gcc
CFLAGS=
RM=rm -rf
OUT=main

all: build

build: main.o linkedlist.o
	$(CC) $(CFLAGS) -o $(OUT) main.c linkedlist.c
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.c linkedlist.h
	$(CC) $(CFLAGS) -c main.c

vector.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	$(RM) *.o $(OUT)
