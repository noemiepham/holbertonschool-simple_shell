#include "shell.h"

/**
 * freeArray - free array of strings
 *
 * @array: array to free
 * @size: size of array
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

/**
 * _which - cherche chemin complet de executable à partir de env PATH
 *
 * @fullPathCommand: commande complète
 * @executable: executable
 * @envPath: les chemins de la var d'env PATH
 * Return: char* le chemin de commande complète
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
		/* printf("DEBUG _which PATH j=[%d]", j); */
		/* printf(", value=[%s], cmd=[%s]\n", path_token, executable); */
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
