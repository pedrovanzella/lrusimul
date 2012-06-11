#include <stdlib.h>
#include "../include/process.h"
#include "../include/page.h"

struct process* create_process(int id, int numpages)
{
	struct process* p = (struct process*)malloc(sizeof(struct process));
	p->id = id;
	p->numpages = numpages;
	p->pages = (struct page**)malloc(numpages * sizeof(struct page*)); // Aloca espaço pra numpages ponteiros de struct page

	int i;
	for (i = 0; i <= numpages - 1; i++) {
		p->pages[i] = create_page(id, i);
	}

	return p;
}
