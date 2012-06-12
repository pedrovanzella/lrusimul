#include <stdlib.h>
#include <stdio.h>

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
	/* FIXME: Esse malloc tá errado, fool! */

	int i;
	for (i = 0; i < size; i++) {
		m->pages[i] = NULL; // Garantir que as páginas sejam nulas no início
	}

	count = 0;
	prox_vitima = m->pages[count]; // Próxima vítima é a primeira página

	return m;
}

void go_to_next_memory_position()
{
	count++;
	if (count >= memory->size) {
		count = 0;
	}
	prox_vitima = memory->pages[count];
}

void substitute(int page, int id)
{
	printf("\t[+] substitute: [page (%d)] [id (%d)]\n", page, id);
	fflush(stdout);
	/* Se próxima vítima é uma página vazia, coloca a página na memória */
	if (!prox_vitima) {
		memory->pages[count] = processes[id]->pages[page];
		
		go_to_next_memory_position();
	}

	/* Se próxima vítima foi desalocada, coloca a página na memória */
	else if (prox_vitima->not_in_use_anymore) {
		memory->pages[count] = processes[id]->pages[page];

		go_to_next_memory_position();
	}

	/* Se a página está referenciada, seta referenciada para zero */
	else if (prox_vitima->referenciada) {
		prox_vitima->referenciada = 0;

		go_to_next_memory_position();
		substitute(page, id);
	}

	/* Se a página não foi referenciada, substitui ela */
	else {
		memory->pages[count] = processes[id]->pages[page];
	}
}

void find_page_and_maybe_substitute(int page, int id)
{
	printf("\t[+] find_page_and_maybe_substitute\n");
	struct page* p;
	/* Temos esta página na memória? */
	int i;
	for (i = 0; i < memory->size; i++) {
		printf("[%d]\n", memory->pages[i]->process_id);
		if ((memory->pages[i]->process_id == id) && (memory->pages[i]->page_id == page)) { // Achamos nossa página
			printf("\t[+] Achei na posição %d\n", i);
			p = memory->pages[i];
			break; // Não precisamos mais buscar
		}
	}

	/* Se não, temos que colocar ela na memória */
	if (!p) { // Não temos p
		substitute(page, id); // Coloca essa página na memória
	}
}

