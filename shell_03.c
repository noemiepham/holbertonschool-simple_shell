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

	while (signal == 1)
	{
		signal = isatty(0);

		if (signal == 1)
			printf("$ ");

		get = getline(&str, &len, stdin);
		if (get == -1)
		{
			free(str);
			exit(EXIT_SUCCESS);
		}
		command = split_str(str, sep);
		if (command[0])
		{
			if (strcmp(command[0], "exit") == 0)
			{
				free(command);
				exit(EXIT_SUCCESS);
			}
			if (strcmp(command[0], "env") == 0)
			{
				_printev();
				free(command);
				continue;
			}
			if (stat(command[0], &st) == 0)
			{
				status_exec = execute_command(command[0], command);
			}
			else
			{
				envPath = _getenv("PATH");

				for (j = 0; envPath[j] != NULL; j++)
				{
					fullPathCommand = envPath[j];

					strcat(fullPathCommand, "/");
					strcat(fullPathCommand, command[0]);

					if (stat(fullPathCommand, &st) == 0)
					{
						status_exec = execute_command(fullPathCommand, command);
					}
				}
				if (status_exec == 1)
					printf("%s NOT FOUND\n", command[0]);
			}
		}
	}
	free(command);
	return (0);
}
