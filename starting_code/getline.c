#include <stdio.h>
#include <stdlib.h>
#include "starting_code.h"
/**
 * @brief
 *
 */
int main(void)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;

	printf("$ ");

	/* Get the standard input line */
	line_size = getline(&line_buf, &line_buf_size, stdin);

	if (line_size >= 0)
	{
		/* Show the line details */
		printf("command: %s\n", line_buf);
		printf("size: %zu\n", line_buf_size);
		printf("Line_size: %zd\n", line_size);
	}
	/* Free the allocated line buffer */
	free(line_buf);
	return (EXIT_SUCCESS);
}
