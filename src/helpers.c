#include "../include/helpers.h"
#include <stdio.h>
#include <stdlib.h>

void parse_memsize(char* buffer, int* size)
{
	char s[4];
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
	char i[4];
	char s[4];
	char found_id = 0;
	char last_char_was_digit = 0;
	int pos_i = 0;
	int pos_s = 0;

	while (*buffer) {
		if (last_char_was_digit && ((*buffer == ' ') || (*buffer == '\t'))) {
			found_id = 1;
		}
		if (!found_id) {
			if ((*buffer >= '0') && (*buffer <= '9')) {
				last_char_was_digit = 1;
				i[pos_i++] = *buffer;
			}
		} else { // Já temos ID, achar size
			if ((*buffer >= '0') && (*buffer <= '9')) {
				s[pos_s++] = *buffer;
			}
		}
		buffer++;
	}

	*id = atoi(i);
	*size = atoi(s);
}

void parse_read(char* buffer, int* page, int* id)
{

}

void parse_write(char* buffer, int* page, int* id)
{

}

void parse_endproc(char* buffer, int* id)
{
	char i[4];
	int pos = 0;
	
	while (*buffer) {
		if ((*buffer >= '0') && (*buffer <= '9')) {
			i[pos++] = *buffer;
		}
		buffer++;
	}
	
	*id = atoi(i);
}

