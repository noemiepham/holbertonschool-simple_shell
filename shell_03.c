#include "shell.h"
/**
 * main - simple shell
 *
 * Return:0
 */
int main(void)
{

	char *str = NULL;
	size_t len = 0;
	char **command, **envPath;
	int get, j, status_exec;
	int signal = 1;
	struct stat st;
	char *fullPathCommand;

	char *sep = "\n\t\r ";

	while (signal)
	{
		signal = isatty(0);
		status_exec = 1; /* réinitialise toujours pour tomber dans command not found si binaire introuvable avec PATH */

		if (signal == 1)
			printf("$ ");

		get = getline(&str, &len, stdin);
		if (get == -1)
		{
			free(str);
			exit(EXIT_SUCCESS);
		}
		command = split_str(str, sep);
		/* printf("DEBUG split_str %s\n", command[0]); */
		if (command[0])
		{
			if (strcmp(command[0], "exit") == 0)
			{
				free(command);
				exit(EXIT_SUCCESS);
			}
			else if (strcmp(command[0], "env") == 0)
			{
				_printev();
				free(command);
				continue;
			}
			else if (stat(command[0], &st) == 0)
			{
				status_exec = execute_command(command[0], command);
			}
			else
			{
			/* 	printf("DEBUG bloc PATH\n"); */
				envPath = _getenv("PATH");

				j = 0;
			/* 	while (envPath[j])
				{
					printf("DEBUG bloc PATH assert : %s\n", envPath[j]);
					j++;
				} */

				for (j = 0; envPath[j] != NULL; j++)
				{
				/* 	 printf("bloc PATH loop j=[%d], val=[%s]\n", j, envPath[j]); */
					/* copyFullPath = _copyString(envPath[j]); */
				/* 	printf("DEBUG bloc PATH fullCommand is : %s\n", copyFullPath);  */
					/* fullPathCommand = copyFullPath;  */ /* utilise une copie car execve consomme le fullPathCommand et donc envPath[j] */
					/*
					/strcat(fullPathCommand, "/");
					strcat(fullPathCommand, command[0]);
					*/
					fullPathCommand = _makeFullCommand(fullPathCommand, command[0], envPath[j]); 
					/* printf("DEBUG bloc PATH fullPathCommand is : %s\n", fullPathCommand); */
					if (stat(fullPathCommand, &st) == 0)
					{
						status_exec = execute_command(fullPathCommand, command);
						break;
					}
					/*else 
					{
						printf("DEBUG bloc PATH fullCommand not found, try next\n");
					} */
				}
				if (status_exec == 1)
					printf("%s NOT FOUND\n", command[0]);
			}
			free(fullPathCommand);
			free(envPath);
		}
	}
	free(command);
	return (0);
}
