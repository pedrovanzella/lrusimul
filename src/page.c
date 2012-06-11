#include <stdlib.h>
#include "../include/page.h"

struct page* create_page(int process_id, int page_id)
{
	struct page* p = (struct page*)malloc(sizeof(struct page));

	p->process_id = process_id;
	p->page_id = page_id;
	p->referenciada = 0;
	p->suja = 0;

	return p;
}
