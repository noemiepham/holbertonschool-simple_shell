#include "shell.h"
/**
 * split_str - diviser string
 *
 * @str: string array
 * Return: new array
 */
char **split_str(char *str)
{
	char **array;
	char *cur_word;
	unsigned int i = 0;
	char *sep = "\n\t\r ";

	
	array = malloc(sizeof(char) * BUFFER);
	if (array == NULL)
		return (NULL);
	cur_word = strtok(str, sep);

	while (cur_word != NULL)
	{
		array[i] = cur_word;
		cur_word = strtok(NULL, sep);
		i++;
	}
	array[i] = NULL;
	return (array);
}

