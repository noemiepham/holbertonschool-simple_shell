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
		for (k = 0 ; k < strlen(arrsource[j]); k++)
		{
			if (arrsource[j][k] != '\n') {
				strCopy[k] = arrsource[j][k];
			}
		}
		arrDestination[j] = strCopy;
	}
	return (arrDestination);
}
