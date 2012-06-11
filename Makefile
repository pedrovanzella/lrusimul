CC = clang
CFLAGS = -Wall

all: prepare bin/lrusimul

prepare:
	mkdir -p bin
	mkdir -p perf

bin/lrusimul: bin/main.o bin/lrusimul.o bin/page.o bin/helpers.o bin/process.o bin/memory.o
	$(CC) $(CFLAGS) -o bin/lrusimul bin/main.o bin/lrusimul.o bin/page.o bin/helpers.o bin/process.o bin/memory.o

bin/main.o: src/main.c include/helpers.h include/lrusimul.h
	$(CC) $(CFLAGS) -c src/main.c
	mv main.o bin/main.o

bin/lrusimul.o: src/lrusimul.c include/lrusimul.h include/helpers.h include/process.h include/memory.h
	$(CC) $(CFLAGS) -c src/lrusimul.c
	mv lrusimul.o bin/lrusimul.o

bin/page.o: src/page.c include/page.h
	$(CC) $(CFLAGS) -c src/page.c
	mv page.o bin/page.o

bin/helpers.o: src/helpers.c include/helpers.h
	$(CC) $(CFLAGS) -c src/helpers.c
	mv helpers.o bin/helpers.o

bin/process.o: src/process.c include/process.h include/page.h
	$(CC) $(CFLAGS) -c src/process.c
	mv process.o bin/process.o

bin/memory.o: src/memory.c include/memory.h
	$(CC) $(CFLAGS) -c src/memory.c
	mv memory.o bin/memory.o

clean:
	rm -rf bin
