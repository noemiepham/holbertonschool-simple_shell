#include "shell.h"
/**
 * clearAndFree
 * 
 * @string 
 */
void clearAndFree(char *string)
{
	_reset(string);
	free(string);
}
/**
 * _reset 
 * 
 * @string 
 */
void _reset(char *string)
{
	int length = 0;

	if (string != NULL)
	{
		while (string[length])
		{
			string[length] = '\0';
			length++;
		}
	}
}
/**
 * freeArray
 * 
 * @array 
 * @size 
 */
void freeArray(char **array, int size)
{
	int i;
	if (array != NULL)
	{
		for (i = 0; i < size; i++)
		{
			free(array[i]);
		}
		free(array);
	}
}
/**
 * _strFree 
 * 
 * @string 
 */
void _strFree(char *string)
{
	if (string != NULL)
	{
		free(string);
	}
}
/**
 * _which
 * 
 * @ullPathCommand 
 * @executable 
 * @envPath 
 * Return: char* 
 */
char *_which(char *fullPathCommand, char *executable, char *envPath)
{
	char *pathSep = ":";
	char *path_token = NULL;
	char *copyEnvPath = NULL;
	int j;

	copyEnvPath = malloc(_strlen(envPath) * sizeof(char));
	if (copyEnvPath == NULL)
	{
		return (NULL);
	}
	_strCopy(envPath, copyEnvPath);

	path_token = strtok(copyEnvPath, pathSep);
	/* printf("DEBUG getenv envValue=[%s]\n", path_token); */
	j = 0;
	while (path_token != NULL)
	{
		/* printf("DEBUG _which PATH j=[%d], value=[%s] for cmd=[%s]\n", j, path_token, executable); */
		fullPathCommand = _makeFullCommand(fullPathCommand, executable, path_token);
		if (access(fullPathCommand, X_OK) != 0)
		{
			free(fullPathCommand);
			fullPathCommand = NULL;
			path_token = strtok(NULL, pathSep);
		}
		else
		{
			/* printf("DEBUG _which executable found in PATH\n"); */
			break;
		}
		j++;
	}
	free(copyEnvPath);

	return (fullPathCommand);
}
/**
 * _strContains 
 * 
 * @str1 
 * @str2 
 * @maxLength 
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
	return contains;
}
