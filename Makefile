CC = clang
CFLAGS = -Wall

all: prepare bin/lrusimul

prepare:
	mkdir -p bin
	mkdir -p perf

bin/lrusimul: bin/lrusimul.o bin/fifo.o bin/page.o bin/helpers.o
	$(CC) $(CFLAGS) -o bin/lrusimul bin/lrusimul.o bin/fifo.o bin/page.o bin/helpers.o

bin/lrusimul.o: src/lrusimul.c include/fifo.h include/helpers.h
	$(CC) $(CFLAGS) -c src/lrusimul.c
	mv lrusimul.o bin/lrusimul.o

bin/fifo.o: src/fifo.c include/fifo.h bin/page.o include/page.h
	$(CC) $(CFLAGS) -c src/fifo.c
	mv fifo.o bin/fifo.o

bin/page.o: src/page.c include/page.h
	$(CC) $(CFLAGS) -c src/page.c
	mv page.o bin/page.o

bin/helpers.o: src/helpers.c include/helpers.h
	$(CC) $(CFLAGS) -c src/helpers.c
	mv helpers.o bin/helpers.o

clean:
	rm -rf bin
