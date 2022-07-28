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
	char delim[] = " ";

	char *ptr = strtok(line, delim);

	while(ptr != NULL)
	{
		printf("%s\n", ptr);
 		ptr = strtok(NULL, delim);
	} 
	return 0;
}
