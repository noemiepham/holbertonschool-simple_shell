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
 * @fullPathCommand: chemin commande complète
 */
void _freeAll(char **command, char *str, char *envPath, char *fullPathCommand)
{
	free(command);
	_strFree(str);
	_strFree(envPath);
	_strFree(fullPathCommand);
}

/**
 * readCommandLineAndExecute - libère tous les objets
 * @command: commande from getline
 * @str: buffer command
 * Return: flag pour free
 */
int readCommandLineAndExecute(char **command, char *str)
{
	int freePath = 1;
	struct stat st;
	char *envPath = NULL;
	char *fullPathCommand = NULL;

	if (strcmp(command[0], "exit") == 0)
	{
		_freeAll(command, str, envPath, fullPathCommand);
		exit(EXIT_SUCCESS);
	}
	else if (strcmp(command[0], "env") == 0)
	{
		_printev();
		free(command);
	}
	else if (stat(command[0], &st) == 0)
	{
		execute_command(command[0], command);
	}
	else
	{
		executePath(command, envPath, fullPathCommand);
		_freeAll(command, str, envPath, fullPathCommand);
		freePath = 0;
		envPath = NULL;
		fullPathCommand = NULL;
	}

	return (freePath);
}

/**
 * executePath - lexecute avec PATH
 * @command: commande from getline
 * @envPath: variable env PATH
 * @fullPathCommand: chemin commande complète
 */
void executePath(char **command, char *envPath, char *fullPathCommand)
{
	int status_exec = 1;

	envPath = _getenv("PATH");

	fullPathCommand = _which(fullPathCommand, command[0], envPath);
	if (fullPathCommand != NULL)
	{
		status_exec = execute_command(fullPathCommand, command);
		if (status_exec == 1)
			printf("Erreur execution de %s\n", command[0]);
	}
	else
	{
		printf("%s NOT FOUND\n", command[0]);
	}
}
