#include "shell.h"
/**
 * copyArray - copy array sans retour chariot
 * @arrsource: source array
 * Return: new array
 */
char **copyArray(char **arrsource)
{
	int i = 0;
	unsigned long int k;
	int j;
	char **arrDestination = NULL;
	char *strCopy = NULL;

	while (arrsource[i])
	{
		i++;
	}
	arrDestination = malloc(sizeof(char) * i);
	if (arrDestination == NULL)
		return (NULL);
	for (j = 0; j < i; j++)
	{
		arrDestination[j] = arrsource[j];
		strCopy = malloc(sizeof(char) * strlen(arrsource[j]));
		for (k = 0; k < strlen(arrsource[j]); k++)
		{
			if (arrsource[j][k] != '\n')
			{
				strCopy[k] = arrsource[j][k];
			}
		}
		arrDestination[j] = strCopy;
	}
	free(strCopy);
	return (arrDestination);
}

/**
 * @brief
 *
 * @param arrsource
 */

void removeCR(char **arrsource)
{
	char *line = NULL;
	int sizeCmd;
	int size;
	int i;

	size = sizeArray(arrsource);
	for (i = 0; i < size; i++)
	{
		line = arrsource[i];
		sizeCmd = strlen(line);
		if (sizeCmd > 0 && line[sizeCmd] == '\n')
			line[sizeCmd - 1] = '\0';
	}
}

/**
 * @brief
 *
 * @param arrsource
 * @return int
 */
int sizeArray(char **arrsource)
{
	int size = 0;

	while (arrsource[size])
	{
		size++;
	}
	return size;
}

void trim(char *str)
{
	int sizeString;
	char *ptr  = NULL;
	char ar;
	int i, j, k;

	i = 0;
	j = 0;
	sizeString = _strlen(str);
	k = sizeString + 1;
	ar = ptr[k];
	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != ' ' && str[i] != '\t')
			ptr[j++] = str[i];
	}
	ptr[j] = '\0';
	
	str = &ar;
}
