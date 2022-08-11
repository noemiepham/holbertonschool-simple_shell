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
 * _freeAll - libère tous les objets
 * @command: commande from getline
 * @str: buffer command
 * @envPath: variable env PATH
 */
void _freeAll(char **command, char *str, char *envPath)
{
	free(command);
	free(str);
	_strFree(envPath);
}

/**
 * readAndExec - parse la commande et exécute
 * @command: commande from getline
 * @str: buffer command
 * @argc: nombre d'arguments main
 * @arv: prog et arguments main
 * Return: flag pour free
 */
int readAndExec(char **command, char *str, int argc, char *arv[])
{
	int execOk = -1;
	struct stat st;
	char *envPath = NULL;

	if (strcmp(command[0], "exit") == 0)
	{
		_freeAll(command, str, envPath);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		_printev();
		free(command);
	}
	else if (stat(command[0], &st) == 0)
	{
		execOk = execute_command(command[0], command);
	}
	else
	{
		execOk = (int)argc;
		execOk = executePath(command);
		if (execOk > 0)
		{
			if (command[1] == NULL)
			{
				printf("%s: 1: %s: not found\n", arv[0], command[0]);
			}
			else
			{/* dans main */
				printf("%s: 1: %s not found\n", command[0], command[1]);
			}
		}
	}

	return (execOk);
}

/**
 * executePath - lexecute avec PATH
 * @command: commande from getline
 * Return: statut execute
 */
int executePath(char **command)
{
	int status_exec = 1;
	char *envPath = NULL;
	char *fullPathCommand = NULL;

	envPath = _getenv("PATH");

	if (envPath != NULL)
	{
		fullPathCommand = _which(fullPathCommand, command[0], envPath);
		if (fullPathCommand != NULL)
		{
			status_exec = execute_command(fullPathCommand, command);
			if (status_exec == 1)
				printf("Erreur execution de %s\n", command[0]);
		}
		else
		{
			status_exec = 2;
		}
	}
	else
	{
		status_exec = 127;
	}

	free(fullPathCommand);
	fullPathCommand = NULL;
	free(envPath);
	envPath = NULL;

	return (status_exec);
}
