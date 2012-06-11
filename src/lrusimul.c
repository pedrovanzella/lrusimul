#include <stdio.h>
#include <stdlib.h>

#include "../include/fifo.h"
#include "../include/helpers.h"
#include "../include/lrusimul.h"
#include "../include/process.h"

#define MAX_PROCESSES 128

extern struct process* processes[MAX_PROCESSES];

void memsize(int size)
{

}

void procsize(int id, int size)
{
	processes[id] = create_process(id, size);
}

void read_p(int page, int id)
{

}

void write_p(int page, int id)
{

}

void endproc(int id)
{
	struct process* p = processes[id];
	if (!p) {
		fprintf(stderr, "[-] ERROR: Trying to end a unexisting process!\n");
	}

	int i;

	for (i = 0; i <= p->numpages - 1; i++) {
		free(p->pages[i]);
	}
	free(p);
}

