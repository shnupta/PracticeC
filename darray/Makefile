CC=gcc
CFLAGS=
RM=rm -rf
OUT=main

all: build

build: main.o darray.o
	$(CC) $(CFLAGS) -o $(OUT) main.c darray.c
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.c darray.h
	$(CC) $(CFLAGS) -c main.c

vector.o: darray.c darray.h
	$(CC) $(CFLAGS) -c darray.c

clean:
	$(RM) *.o $(OUT)
