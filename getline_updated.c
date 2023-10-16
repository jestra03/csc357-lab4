#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	FILE *fp;  // file
	fp = fopen(argv[1], "r");
	int line_cnt;

	size_t bufsize = 120;
	char buffer[bufsize];
	char *b = buffer;
	ssize_t chars = 0;

	if (fp == NULL) {
		perror("File Operation Unsuccessful\n");
		return -1;
	}
	
	line_cnt = 0;
	while (1) {
		chars = getline(&b, &bufsize, fp);
		if (chars == -1) {
		break;
		}
		line_cnt++;
	}

	fclose(fp);

	fp = fopen(argv[1], "r");
	if (line_cnt == 1) {
		getline(&b, &bufsize, fp);
		printf("%s", buffer);
	}
	else if (line_cnt == 2) {
		getline(&b, &bufsize, fp);
		printf("%s", buffer);
		getline(&b, &bufsize, fp);
		printf("%s", buffer);
	}
	else if (line_cnt > 2) {
		for (int i = 0; i < line_cnt - 2; i++) {
			getline(&b, &bufsize, fp);
		}
                getline(&b, &bufsize, fp);
                printf("%s", buffer);
                getline(&b, &bufsize, fp);
                printf("%s", buffer);
	}
	fclose(fp);
	return 0;
}



