#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;

	printf("$ ");

	nread = getline(&line, &len, stdin);

	if (nread == -1)
	{
		printf("Error");
		free(line);
		return (1);
	}
	else
		printf("%s", line);

	free(line);
	return (0);
}
