#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
ssize_t remove_newline(char *buffer, ssize_t input);

int main(int argc, char *argv[]) {
	size_t t_bufsize;
	char *t_buffer;
	ssize_t t_chars;
	
	size_t bufsize = 10;
	char *buffer = (char*)malloc(bufsize*sizeof(char));
	ssize_t characters = 0;

	size_t bufsize1 = 10;
	char *buffer1 = (char*)malloc(bufsize*sizeof(char));
	ssize_t characters1 = 0;

	FILE *fp;  // file pointer	
	fp = fopen(argv[1], "r");  // read from arg 1 ("filename.txt")

	if (fp == NULL) {
		printf("File Operation unsuccessful\n");
		free(buffer);
		free(buffer1);
		return -1;
	}

	// get first line, return if none	
	characters = getline(&buffer, &bufsize, fp);
	if (characters == -1) {
		// printf("File is empty");
		free(buffer);
		free(buffer1);
		fclose(fp);
		return 1;
	}

	// get second line, print first line if no second
	remove_newline(buffer, characters);
        characters1 = getline(&buffer1, &bufsize1, fp);
	if (characters1 == -1) {
		printf("%s\n", buffer);
		free(buffer);
		free(buffer1);
		fclose(fp);
		return 1;
	}
	remove_newline(buffer1, characters1);
	
	
	// while True
	// get next line
	// if line is EOF print 1st 2nd, return
	// else replace 1st with 2nd, set 2nd to current line

	// initialize temp heap 
	t_bufsize = 10;
        t_buffer = (char*)malloc(bufsize*sizeof(char));
        t_chars = 0;

	// read loop here


	printf("%s\n", buffer); // print first line
	printf("%s\n", buffer1); // print second line
	// while True
	free(buffer);
	free(buffer1);
	free(t_buffer);
	fclose(fp);  // close file
	
	


	return 0;
}

ssize_t remove_newline(char *buffer, ssize_t input) {
	if (buffer[input - 1] == '\n') {
		buffer[input - 1] = '\0';
	}
	return input - 1;
}

