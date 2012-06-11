#ifndef _PROCESS_H_
#define _PROCESS_H_
#include "page.h"

struct process {
	int id;
	int numpages;
	struct page* *pages;
};

struct process* create_process(int id, int numpages);

#endif /* _PROCESS_H_ */
