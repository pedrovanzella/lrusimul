CC = clang
CFLAGS = -Wall

all: prepare bin/lrusimul

prepare:
	mkdir -p bin
	mkdir -p perf

bin/lrusimul: src/lrusimul.c
	$(CC) $(CFLAGS) -o bin/lrusimul src/lrusimul.c

clean:
	rm -rf bin
