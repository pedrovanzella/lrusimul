#include <stdlib.h>

#include "../include/memory.h"
#include "../include/process.h"
#include "../include/page.h"

struct page* prox_vitima;
int count;
extern struct process* processes[]; // Para marcar pagefaults

struct memory* make_memory(int size)
{
	struct memory* m = (struct memory*)malloc(sizeof(struct memory));

	m->size = size;
	m->pages = (struct page**)malloc(size * sizeof(struct page*));

	int i;
	for (i = 0; i < size; i++) {
		m->pages[i] = NULL; // Garantir que as páginas sejam nulas no início
	}

	prox_vitima = m->pages[0]; // Próxima vítima é a primeira página
	count = 0;

	return m;
}

void substitute(int page, int id)
{
	/* Se próxima vítima é uma página vazia, coloca a página na memória */

	/* Se próxima vítima foi desalocada, coloca a página na memória */

}

void find_page_and_maybe_substitute(int page, int id)
{
	struct page* p;
	/* Temos esta página na memória? */
	int i;
	for (i = 0; i < memory->size; i++) {
		if ((memory->pages[i]->process_id == id) && (memory->pages[i]->page_id == page)) { // Achamos nossa página
			p = memory->pages[i];
			break; // Não precisamos mais buscar
		}
	}

	/* Se não, temos que colocar ela na memória */
	if (!p) { // Não temos p
		substitute(page, id); // Coloca essa página na memória
	}
}

