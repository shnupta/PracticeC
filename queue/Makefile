
CC=gcc
CFLAGS=
RM=rm -rf
OUT=main

all: build

build: main.o queue.o queuetests.o linkedlist.o
	$(CC) $(CFLAGS) -o $(OUT) main.c queue.c queuetests.c linkedlist.c
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.c queuetests.h
	$(CC) $(CFLAGS) -c main.c

queue.o: queue.c queue.h linkedlist.h
	$(CC) $(CFLAGS) -c queue.c

queuetests.o: queuetests.c queuetests.h queue.h linkedlist.h
	$(CC) $(CFLAGS) -c queuetests.c

linkedlist.o: linkedlist.c linkedlist.h
	$(CC) $(CFLAGS) -c linkedlist.c

clean:
	$(RM) *.o $(OUT)
