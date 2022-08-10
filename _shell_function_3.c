#include "shell.h"

/**
 * execute_command - execute la commande if true
 * @command: commande from getline
 * @argument: argument
 * Return: 1 if not found
 */

int execute_command(char *command, char **argument)
{
	pid_t pid;
	int status;
	int exec = 0;

	pid = fork();
	if (pid == -1)
	{
		perror("error");
		exec = 1;
	}
	else if (pid != 0)
	{
		wait(&status);
	}
	else if (pid == 0)
	{
		if (execve(command, argument, NULL) == -1)
		{
			perror("Error:");
			exec = 1;
		}
	}
	return (exec);
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
 * _makeFullCommand - make full command
 *
 * @dst: dest string copy
 * @command: command getline
 * @fullPath: full path
 * Return: Dest
 */
char *_makeFullCommand(char *dst, char *command, char *fullPath)
{
	int commandLength = 0;
	int fullPathLength = 0;
	int i, j;

	commandLength = _strlen(command);
	fullPathLength = _strlen(fullPath);

	/* printf("DEBUG _makeFullCommand command length : %d\n", commandLength); */
	/* printf("DEBUG _makeFullCommand fullPathLength : %d\n", fullPathLength); */

	dst = calloc((commandLength + 1 + fullPathLength), sizeof(char));

	if (dst == NULL)
		return (NULL);

	for (i = 0; i < fullPathLength; i++)
	{
		dst[i] = fullPath[i];
	}
	/* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

	dst[fullPathLength] = '/';

	/* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

	for (i = 0, j = fullPathLength + 1; i < commandLength; i++, j++)
	{
		dst[j] = command[i];
	}

	/* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

	return (dst);
}
