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
	int get, execOk;
	int signal = 1;

	while (1)
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
			execOk = readCommandLineAndExecute(command, str);
			if (execOk == 0)
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
