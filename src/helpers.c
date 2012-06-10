#include "../include/helpers.h"
#include <stdio.h>
#include <stdlib.h>

void parse_memsize(char* buffer, int* size)
{
	char* s = (char*)malloc(4);
	int pos = 0;

	while (*buffer) {
		if ((*buffer >= '0') && (*buffer <= '9')) {
			s[pos++] = *buffer;
		}
		buffer++;
	}

	*size = atoi(s);
}

void parse_procsize(char* buffer, int* id, int* size)
{

}

void parse_read(char* buffer, int* page, int* id)
{

}

void parse_write(char* buffer, int* page, int* id)
{

}

void parse_endproc(char* buffer, int* id)
{
	char* i = (char*)malloc(4);
	int pos = 0;
	
	while (*buffer) {
		if ((*buffer >= '0') && (*buffer <= '9')) {
			i[pos++] = *buffer;
		}
		buffer++;
	}
	
	*id = atoi(i);
}

