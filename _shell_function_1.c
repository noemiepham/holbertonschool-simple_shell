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

	array = malloc(sizeof(char) * BUFFER);
	if (array == NULL)
		return (NULL);

	cur_word = strtok(str, COMMAND_LINE_SEPARATROR);

	while (cur_word != NULL)
	{
		array[i] = cur_word;
		i++;
		cur_word = strtok(NULL, COMMAND_LINE_SEPARATROR);
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
 * _strCopy - coppy string
 *
 * @src: source file
 * @dst: dest string
 * Return: string dest
 */
char *_strCopy(char *src, char *dst)
{

	int size = 0;
	int i;

	while (src[size])
		size++;

	for (i = 0; i < size; i++)
	{
		dst[i] = src[i];
	}

	return (dst);
}

/**
 * _strContains - test si un string est contenu
 *  dans l'autre jusqu'à maxLength
 * @str1: 1ere string
 * @str2: 2e string
 * @maxLength:longueur max jusqu'où chercher
 * Return: int
 */
int _strContains(char *str1, char *str2, int maxLength)
{
	int contains = 0;
	int i;

	for (i = 0; i < maxLength; i++)
	{
		if (str1[i] != str2[i])
		{
			contains = 1;
			break;
		}
	}
	return (contains);
}

/**
 * _strFree - free string
 *
 * @string: string to free
 */
void _strFree(char *string)
{
	if (string != NULL)
	{
		free(string);
	}
}
