#include <stdio.h>
#include <stdlib.h>

#include "../include/fifo.h"
#include "../include/helpers.h"

int main(int argc, char* argv[])
{
	if (argc != 2) {
		fprintf(stderr, "[-] Error: usage: %s config_file\n", argv[0]);
		return EXIT_FAILURE;
	}

	char* filename = argv[1];

	FILE* fp = fopen(filename, "r");
	if (!fp) {
		fprintf(stderr, "[-] Error: failed to open file %s\n", filename);
		return EXIT_FAILURE;
	}



	fclose(fp);
	return EXIT_SUCCESS;
}
