#include "shell.h"

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
 * _makeFullCommand - make full command
 *
 * @dst: dest string copy
 * @executable: executable from getline
 * @fullPath: full path
 * Return: Dest
 */
char *_makeFullCommand(char *dst, char *executable, char *fullPath)
{
	int executableLength = 0;
	int fullPathLength = 0;
	int i, j;

	executableLength = _strlen(executable);
	fullPathLength = _strlen(fullPath);

	/* printf("DEBUG _makeFullCommand exe length : %d\n", executableLength); */
	/* printf("DEBUG _makeFullCommand fullPathLength : %d\n", fullPathLength); */

	/* +1 pour le caractère de fin d'un string */
	dst = calloc((executableLength + 1 + fullPathLength + 1), sizeof(char));

	if (dst == NULL)
		return (NULL);

	for (i = 0; i < fullPathLength; i++)
	{
		dst[i] = fullPath[i];
	}
	/* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

	dst[fullPathLength] = '/';

	/* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

	for (i = 0, j = fullPathLength + 1; i < executableLength; i++, j++)
	{
		dst[j] = executable[i];
	}

	/* il faut que argv se termine NULL. Sinon la fonction exec va traiter */
	/* tous les caractères non null comme un argument */
	/* conduisant à un comportement indéfini avec l'erreur */
	/* même si le code libère bien explictement */
	/* Syscall param access(pathname) points to unaddressable byte(s) */
	/* "in use at exit: 0 bytes in 0 blocks" car trop bloquant pour Valgrind */
	dst[j] = END_STRING_CHAR;

	/* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

	return (dst);
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
