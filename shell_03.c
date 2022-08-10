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
	int get, freePath;
	int signal = 1;

	while (signal)
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
		command = split_str(str);
		/* printf("DEBUG split_str %s\n", command[0]); */
		if (command[0])
		{
			freePath = readCommandLineAndExecute(command, str);
			if (freePath == 0)
			{
				free(command);
				command = NULL;
				free(str);
				str = NULL;
			}
		}
	}
	free(command);
	free(str);
	return (0);
}
