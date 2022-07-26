#include <stdio.h>
#include <stdlib.h>
#include "starting_code.h"

int main(void)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;
	line_buf = (char *)malloc(line_buf_size);
	if (line_buf == NULL)
		return (-1);
	printf("$ ");

	/* Get the first line of the file. */
	line_size = getline(&line_buf, &line_buf_size, stdin);

	
	int init_size = strlen(line_buf);
	char delim[] = " ";

	char *ptr = strtok(line_buf, delim);

	while(ptr != NULL)
	{
		printf("'%s'\n", ptr);
		ptr = strtok(NULL, delim);
	}

	/* This loop will show that there are zeroes in the str after tokenizing */
/* 	for (int i = 0; i < init_size; i++)
	{
		printf("%d ", line_buf[i]); Convert the character to integer, in this case
							   the character's ASCII equivalent 
	}
	printf("\n"); */

	return 0;
}
