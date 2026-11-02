CC = gcc
DIR = examples/simple
SRC = $(DIR)/src
SPEC = $(DIR)/spec
SPECC = src
MAIN = $(DIR)/main.c
SRC_FILES := $(shell find $(SRC) -name '*.c')
SPEC_FILES := $(shell find $(SPEC) -name '*.c')

main: compile-main
	$(CC) *.o -o main
	rm -f *.o

spec-auto:
	find . -name '*.[ch]' | entr make spec

spec: compile-spec
	$(CC) *.o -o specc
	rm -f *.o
	./specc

compile-spec:
	-$(CC) -c -DSPECC $(SRC_FILES)
	$(CC) -c $(SPEC_FILES) $(SPECC)/specc.c

compile-main: compile-src
	$(CC) -c $(MAIN)

compile-src:
	$(CC) -c $(SRC_FILES)

clean:
	rm -f *.o