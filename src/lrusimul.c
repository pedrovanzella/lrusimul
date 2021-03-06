#include <stdio.h>
#include <stdlib.h>

#include "../include/helpers.h"
#include "../include/lrusimul.h"
#include "../include/process.h"
#include "../include/memory.h"

extern struct process* processes[];
extern struct memory* memory;

void memsize(int size)
{
	memory = make_memory(size);
}

void procsize(int id, int size)
{
	processes[id] = create_process(id, size);
}

void read_p(int page, int id)
{
	if (page >= processes[id]->numpages) {
		fprintf(stderr, "[-] ERROR: Trying to access a page that does not belong to process!\n");
	} else if (!processes[id]) {
		fprintf(stderr, "[-] ERROR: Trying to access a procces that does not exist!\n");
	} else {
		processes[id]->pages[page]->acessos++;
		processes[id]->pages[page]->referenciada = 1;

		find_page_and_maybe_substitute(page, id);
	}
}

void write_p(int page, int id)
{
	if (page >= processes[id]->numpages) {
		fprintf(stderr, "[-] ERROR: Trying to access a page that does not belong to process!\n");
	} else if (!processes[id]) {
		fprintf(stderr, "[-] ERROR: Trying to access a procces that does not exist!\n");
	} else {
		processes[id]->pages[page]->acessos++;
		processes[id]->pages[page]->suja = 1;

		find_page_and_maybe_substitute(page, id);
	}
}

void endproc(int id)
{
	struct process* p = processes[id];
	if (!p) {
		fprintf(stderr, "[-] ERROR: Trying to end a unexisting process!\n");
	}

	int i;

	for (i = 0; i <= p->numpages - 1; i++) {
		p->pages[i]->not_in_use_anymore = 1;
	}
}
