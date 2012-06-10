#include <stdio.h>
#include <stdlib.h>

#include "../include/helpers.h"
#include "../include/lrusimul.h"

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

	/* File buffer */
	char* buffer;
	int nbytes = 128;

	/* Parsing vars */
	int m_size;
	int p_id;
	int p_size;
	int r_page;
	int r_id;
	int w_page;
	int w_id;
	int e_id;

	/* Main loop */
	while ((getline(&buffer, (size_t*)&nbytes, fp) != -1)) {
		printf("[+] %s", buffer); // buffer already has \n

		/* Todas as operações começam com letras diferentes */
		switch(buffer[0]) {
			case 'M': /* MEMSIZE SIZE */
			case 'm':
				parse_memsize(buffer, &m_size);
				memsize(m_size);
				break;

			case 'P': /* PROCSIZE ID SIZE */
			case 'p':
				parse_procsize(buffer, &p_id, &p_size);
				procsize(p_id, p_size);
				break;

			case 'R': /* READ PAGE ID */
			case 'r':
				parse_read(buffer, &r_page, &r_id);
				read_p(r_page, r_id);
				break;

			case 'W': /* WRITE PAGE ID */
			case 'w':
				parse_write(buffer, &w_page, &w_id);
				write_p(w_page, w_id);

				break;

			case 'E': /* ENDPROC ID */
			case 'e':
				parse_endproc(buffer, &e_id);
				endproc(e_id);
				break;

			default:
				printf("[-] Invalid Operation!\n");
		}
	}

	fclose(fp);
	return EXIT_SUCCESS;
}
