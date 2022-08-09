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
	char **command;
	int get, status_exec;
	int signal = 1;
	struct stat st;
	char *fullPathCommand = NULL;
	char *envPath = NULL;
	char *sep = "\n\t\r ";

	/* envPath = _getenv("PATH"); */

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
				free(str);
				printf("DEBUG free envPath\n");
				_strFree(envPath);
				printf("DEBUG free fullPathCommand\n");
				_strFree(fullPathCommand);
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
				/* copyEnvPath = _copyString(envPath, copyEnvPath); */
				/* printf("DEBUG bloc PATH copyEnvPath %s\n", copyEnvPath); */

				fullPathCommand = _which(fullPathCommand, command[0], envPath);
				if (fullPathCommand != NULL)
				{
					status_exec = execute_command(fullPathCommand, command);
					if (status_exec == 1)
						printf("Erreur execution de %s\n", command[0]);
				}
				else {
					printf("%s NOT FOUND\n", command[0]);
				}

				free(str);
				str = NULL;
				free(envPath);
				envPath = NULL;
				/* _reset(copyEnvPath); */
				free(fullPathCommand);
				fullPathCommand = NULL;
			}
		}
	}
	/* free(copyEnvPath); */
	_strFree(envPath);
	free(command);
	return (0);
}
