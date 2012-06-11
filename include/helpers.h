#ifndef _HELPERS_H_
#define _HELPERS_H_
#include <stdio.h>

void parse_memsize(char* buffer, int* size);
void parse_procsize(char* buffer, int* id, int* size);
void parse_read(char* buffer, int* page, int* id);
void parse_write(char* buffer, int* page, int* id);
void parse_endproc(char* buffer, int* id);

void write_stats();

#endif /* _HELPERS_H_ */
