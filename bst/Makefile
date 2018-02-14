CC = gcc
COMPILE_FLAGS = -Wall -g -pedantic -c
SOURCE_LIST = src/bst.c
TEST_LIST = tests/tests.c build/bst.o
SRD_DIR = src/
BUILD_DIR = build/
TESTS_DIR = tests/


all:
	$(CC) $(COMPILE_FLAGS) $(SOURCE_LIST) -o $(BUILD_DIR)bst.o

tests: all
	$(CC) $(TEST_LIST) -o main_tests
	./main_tests

clean:
	find . -type f -name '*.o' -delete
