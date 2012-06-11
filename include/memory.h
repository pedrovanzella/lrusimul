#ifndef _MEMORY_H_
#define _MEMORY_H_

#include "page.h"

struct memory {
	int size;
	struct page* *pages;
};

struct memory* memory;

struct memory* make_memory(int size);

/* Descobre se a página está em memória.
 * Caso não esteja, marca como pagefault,
 * procura a primeira página vazia e coloca ela lá.
 * Caso a memória esteja cheia, substitui alguma página */
void find_page_and_maybe_substitute(int page, int id);

#endif /* _MEMORY_H_ */
