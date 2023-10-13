#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
	int fd;  // file descriptor
	char *endptr;	
	int BUFFER_SIZE = strtol(argv[2], &endptr, 10);
	if (endptr == NULL) {
		printf("Invalid arg");
		return -1;
	}	
	char buffer[BUFFER_SIZE];
	ssize_t characters;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1) {
		printf("File Operation unsuccessful");
		return -1;
	}

	characters = read(fd, buffer, BUFFER_SIZE);
	if (characters == -1) {
		printf("Error file not read");
		close(fd);
		return -1;
	}	
	
	close(fd);
	return 0;
}

