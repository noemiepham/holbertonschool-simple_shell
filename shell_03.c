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
	int get, j, status_exec;
	int signal = 1;
	struct stat st;
	char *fullPathCommand = NULL;
	char *envPath = NULL;
	char *copyEnvPath = NULL;

	char *sep = "\n\t\r ";
	char *pathSep = ":";
	char *cur_word = NULL;

	envPath = _getenv("PATH");

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
				/* envPath = _getenv("PATH"); */
				copyEnvPath = _copyString(envPath);

				cur_word = strtok(copyEnvPath, pathSep);
				/* printf("DEBUG getenv envValue=[%s]\n", cur_word); */
				j = 0;
				while (cur_word != NULL)
				{
					/* printf("DEBUG PATH j=[%d], value=[%s] for cmd=[%s]\n", j, cur_word, command[0]); */
					fullPathCommand = _makeFullCommand(fullPathCommand, command[0], cur_word);
					/* printf("DEBUG PATH fullPathCommand=[%s]\n", fullPathCommand); */
					if (stat(fullPathCommand, &st) == 0)
					{
						status_exec = execute_command(fullPathCommand, command);
						clearAndFree(fullPathCommand);
						break;
					}
					/*else 
					{
						printf("DEBUG bloc PATH fullCommand not found, try next\n");
					}*/
					clearAndFree(fullPathCommand);

					cur_word = strtok(NULL, pathSep);
					j++;
				}

				/* j = 0;
				while (envPath[j])
				{
					printf("DEBUG bloc PATH assert : %s\n", envPath[j]);
					j++;
				} */

				if (status_exec == 1)
					printf("%s NOT FOUND\n", command[0]);
				/* free(envPath); */
				free(copyEnvPath);
			}
		}
	}
	free(envPath);
	free(command);
	return (0);
}
