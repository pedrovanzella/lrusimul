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

	char* buffer;

	int nbytes = 128;
	while ((getline(&buffer, (size_t*)&nbytes, fp) != -1)) {
		printf("[+] %s", buffer); // buffer already has \n
	}

	fclose(fp);
	return EXIT_SUCCESS;
}
