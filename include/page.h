#ifndef _PAGE_H_
#define _PAGE_H_

struct page {
	int page_id;
	char referenciada;
	char suja;
	int process_id; // Processo dono da página
};

#endif /* _PAGE_H_ */
