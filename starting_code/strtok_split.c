#include "starting_code.h"
#include <stdio.h>
#include <string.h>

int main()
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	printf("$ ");

	nread = getline(&line, &len, stdin);

	int init_size = strlen(line);
	char delim[] = " ";

	char *ptr = strtok(line, delim);

	while(ptr != NULL)
	{
		printf("%s\n", ptr);
 		ptr = strtok(NULL, delim); 
	} 

	/* This loop will show that there are zeroes in the str after tokenizing */
	for (int i = 0; i < init_size; i++)
	{
		printf("%d ", line[i]); /*Convert the character to integer, in this case
							   the character's ASCII equivalent */
	}
	printf("\n"); 

	return 0;
}