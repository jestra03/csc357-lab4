#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8192

int main() {
	FILE *fp;  // file pointer
	char buffer[SIZE];
	size_t bytes;  // bytes read

	fp = fopen("/usr/lib/locale/locale-archive", "rb");
	if (fp == NULL) {
		printf("File Operation unsuccessful\n");
		return -1;
	}

	while ((bytes = fread(buffer, 1, SIZE, fp)) > 0) {
		// do nothing, just read
	}		
	fclose(fp);
	return 0;
}

