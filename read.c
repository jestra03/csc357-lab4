#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define SIZE 8192

int main() {
	int fd;  // file descriptor
	char buffer[SIZE];
	ssize_t bytes;  // bytes read

	fd = open("/usr/lib/locale/locale-archive", O_RDONLY);
	if (fd == -1) {
		printf("File Operation unsuccessful\n");
		return -1;
	}

	while ((bytes = read(fd, buffer, SIZE)) > 0) {
		// do nothing, just read
	}		
	close(fd);
	return 0;
}

