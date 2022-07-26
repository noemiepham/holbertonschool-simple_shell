#include "shell.h"
/**
 * split_str - diviser string
 *
 * @str: string array
 * Return: new array
 */
char **split_str(char *str, char *sep)
{
	char **array;
	char *cur_word;
	unsigned int i = 0;
	

	
	array = malloc(sizeof(char) * BUFFER);
	if (array == NULL)
		return (NULL);
		
	cur_word = strtok(str, sep);

	while (cur_word != NULL)
	{
		array[i] = cur_word;
		i++;
		cur_word = strtok(NULL, sep);
	}
	array[i] = NULL;
	return (array);
}
/**
* _strlen - length of string;
* @s : pointer
* Return: _strlen
*/

int _strlen(char *s)
{
	int strlen;

	strlen = 0;
	while (s[strlen] != '\0')
	{
		strlen++;
	}
return (strlen);
}
/**
 * _printev - prints environnement variables
 *
 * Return: any value
 */
void _printev(void)
{
	int i = 0;
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
}

/**
 * debugArray - pour debuge le projet
 *@arr: varibale pour tester
 */
void debugArray(char **arr)
{
	unsigned int i = 0;
	if (arr != NULL)
	{
		while (arr[i] != NULL)
		{
			printf("DEBUG arr at index i %d=[%s]\n", i, arr[i]);
			i++;
		}
	} else
	{
		printf("Array source id null\n");
	}
}
