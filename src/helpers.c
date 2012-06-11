#include <stdio.h>
#include <stdlib.h>

#include "../include/helpers.h"
#include "../include/lrusimul.h"

extern struct process* processes[];

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
	char p[4];
	char i[4];
	char found_page = 0;
	char last_char_was_digit = 0;
	int pos_p = 0;
	int pos_i = 0;

	while (*buffer) {
		if (last_char_was_digit && ((*buffer == ' ') || (*buffer == '\t'))) {
			found_page = 1;
		}
		if (!found_page) {
			if ((*buffer >= '0') && (*buffer <= '9')) {
				last_char_was_digit = 1;
				p[pos_p++] = *buffer;
			}
		} else { // Já temos ID, achar size
			if ((*buffer >= '0') && (*buffer <= '9')) {
				i[pos_i++] = *buffer;
			}
		}
		buffer++;
	}

	*page = atoi(p);
	*id = atoi(i);
}

void parse_write(char* buffer, int* page, int* id)
{
	char p[4];
	char i[4];
	char found_page = 0;
	char last_char_was_digit = 0;
	int pos_p = 0;
	int pos_i = 0;

	while (*buffer) {
		if (last_char_was_digit && ((*buffer == ' ') || (*buffer == '\t'))) {
			found_page = 1;
		}
		if (!found_page) {
			if ((*buffer >= '0') && (*buffer <= '9')) {
				last_char_was_digit = 1;
				p[pos_p++] = *buffer;
			}
		} else { // Já temos ID, achar size
			if ((*buffer >= '0') && (*buffer <= '9')) {
				i[pos_i++] = *buffer;
			}
		}
		buffer++;
	}

	*page = atoi(p);
	*id = atoi(i);
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

void init_process_table()
{
	int i;
	for (i = 0; i < MAX_PROCESSES; i++) {
		processes[i] = NULL; // Garantir que não aponta pra nenhum processo
	}
}

void write_stats()
{
}
