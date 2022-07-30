#include "sshell.h"

int main(int argc, char **argv)
{
	char *cmdline;
	char **cmdargs;
	int signal = 1;

	while (signal == 1)
	{
		printf("#cisfun$ ");

		cmdline = readprompt();
		if (cmdline != NULL)
		{
			cmdargs = format_cmd(cmdline);
			signal = exec_cmd(argv, cmdargs);
			free(cmdargs);
		}
		else
		{
			printf("detected NULL cmd\n");
		}
		free(cmdline);
	}
	return (0);
}
