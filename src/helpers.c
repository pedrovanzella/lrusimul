#include "../include/helpers.h"
#include <stdio.h>
#include <stdlib.h>

char* read_line(FILE* fp)
{
	int curr_max = 128;
	char* buffer = (char*)malloc(sizeof(char) * curr_max); // Alocar 128 bytes
	int lenght = 0; // Tamanho da string lida

	char ch = getc(fp); // pega o primeiro char do arquivo

	while ((ch != '\n') && (ch != EOF)) {
		if (lenght == curr_max) { // Se o buffer está cheio
			curr_max *= 2;
			buffer = realloc(buffer, curr_max); // Dobra o buffer
		}
		buffer[lenght] = ch;
		ch = getc(fp);
		lenght++;
	}

	return buffer;
}
