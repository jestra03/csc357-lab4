#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
	FILE *fp;  // file pointer
	char *endptr;	
	size_t BUFFER_SIZE = strtol(argv[2], &endptr, 10);
	if (*endptr != '\0') {
		printf("Invalid Arg\n");
		return -1;
	}	
	char buffer[BUFFER_SIZE];
	size_t characters;

	fp = fopen(argv[1], "rb");
	if (fp == NULL) {
		printf("File Operation unsuccessful\n");
		return -1;
	}

	characters = fread(buffer, 1, BUFFER_SIZE, fp);
	if (characters == -1) {
		printf("Error file not read\n");
		fclose(fp);
		return -1;
	}		
	fclose(fp);
	return 0;
}

