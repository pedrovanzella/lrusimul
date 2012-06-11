#ifndef _PAGE_H_
#define _PAGE_H_

struct page {
	int process_id; // Processo dono da página
	int page_id;
	char referenciada;
	char suja;
};

struct page* create_page(int process_id, int page_id);

#endif /* _PAGE_H_ */
