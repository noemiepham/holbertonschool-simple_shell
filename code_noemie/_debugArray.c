#include "shell.h"
/**
 * @brief
 *
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
