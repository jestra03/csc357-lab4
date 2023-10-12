#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
ssize_t remove_newline(char *buffer, ssize_t input);

int main(int argc, char *argv[]) {
	FILE *fp;  // file
	fp = fopen(argv[1], "r");
	
	size_t bufsize = 120;

	char buffer0[bufsize];
	char *b0 = buffer0;
	ssize_t chars0 = 0;

	char buffer1[bufsize];
	char *b1 = buffer1;
	ssize_t chars1 = 0;	

	if (fp == NULL) {
		printf("File Operation Unsuccessful\n");
		return -1;
	}

        chars0 = getline(&b0, &bufsize, fp);
        if (chars0 == -1) {
                printf("could not read line");
                return -1;
        }

	chars1 = getline(&b1, &bufsize, fp);
	if (chars1 == -1) {
		remove_newline(b0, chars1);
		printf("%s", b0);
		return -1;
	}


	// while loop
	
	fclose(fp);

}
ssize_t remove_newline(char *buffer, ssize_t input) {
	if (buffer[input - 1] == '\n') {
		buffer[input - 1] = '\0';
	}
	return input - 1;
}

