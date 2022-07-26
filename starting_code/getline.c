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
	line_buf = (char *)malloc(line_buf_size);
	if (line_buf == NULL)
		return (-1);
	printf("$ ");

	/* Get the first line of the file. */
	line_size = getline(&line_buf, &line_buf_size, stdin);

	/* Loop through until we are done with the file. */
	while (line_size >= 0)
	{
		/* Increment our line count */
		line_count++;

		/* Show the line details */
		printf("command: %s\n", line_buf);
		printf("size: %zu\n", line_buf_size);
		printf("Line_size: %zd\n", line_size);

		/* Get the next line */
		line_size = getline(&line_buf, &line_buf_size, stdin);
	}
	/* Free the allocated line buffer */
	free(line_buf);
	return (EXIT_SUCCESS);
}
