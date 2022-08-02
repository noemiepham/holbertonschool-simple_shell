#include <stdio.h>
#include <stdlib.h>
#include "starting_code.h"
/**
 * @brief
 *
 */
char *getline(char *file)
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	int line_count = 0;
	ssize_t line_size;

	/* Get the standard input line */
	line_size = getline(&line_buf, &line_buf_size, stdin);

	if (line_size == - 1)
	{
	/* Free the allocated line buffer */
		free(line_buf);
		exit (EXIT_SUCCESS);
	}
	/* Show the line details */
	return(line_buf);
}
