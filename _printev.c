#include "shell.h"
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

