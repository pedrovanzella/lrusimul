#ifndef _FIFO_H_
#define _FIFO_H_
#include "page.h"

struct fifo {
	struct page* page;
	struct fifo* next;
};

int fifo_push(struct page* page);
struct page* fifo_pop();

#endif /* _FIFO_H_ */
