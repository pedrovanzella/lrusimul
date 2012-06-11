#include <stdlib.h>

#include "../include/memory.h"

struct memory* make_memory(int size)
{
	struct memory* m = (struct memory*)malloc(sizeof(struct memory));

	return m;
}
