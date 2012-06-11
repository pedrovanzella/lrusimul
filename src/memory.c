#include <stdlib.h>

#include "../include/memory.h"

struct memory* make_memory(int size)
{
	struct memory* m = (struct memory*)malloc(sizeof(struct memory));

	m->size = size;
	m->pages = (struct page**)malloc(size * sizeof(struct page*));

	int i;
	for (i = 0; i < size; i++) {
		m->pages[i] = NULL; // Garantir que as páginas sejam nulas no início
	}

	return m;
}
