CC=gcc
CFLAGS=
RM=rm -rf
OUT=main

all: build

build: main.o kcarray.o
	$(CC) $(CFLAGS) -o $(OUT) main.c kcarray.c
	$(RM) *.o

debug: CFLAGS+=-DDEBUG_ON
debug: build

main.o: main.c kcarray.h
	$(CC) $(CFLAGS) -c main.c

vector.o: kcarray.c kcarray.h
	$(CC) $(CFLAGS) -c vector.c

clean:
	$(RM) *.o $(OUT)
