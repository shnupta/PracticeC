
CC=gcc
CFLAGS=
RM=rm -rf
OUT=main

all: build

build: main.o linkedlist.o listtests.o
	$(CC) $(CFLAGS) -o $(OUT) main.c linkedlist.c listtests.c
	$(RM) *.o
debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.c linkedlist.h listtests.h
	$(CC) $(CFLAGS) -c main.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

listtests.o: listtests.c listtests.h linkedlist.h
	$(CC) $(CFLAGS) -c listtests.c

clean:
	$(RM) *.o $(OUT)
