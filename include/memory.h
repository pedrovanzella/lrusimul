#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "page.h"

struct memory {
	int size;
	struct page* *pages;
};

struct memory* memory;

struct memory* make_memory(int size);

#endif /* _MEMORY_H_ */
