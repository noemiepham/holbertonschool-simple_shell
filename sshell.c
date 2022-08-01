#include "sshell.h"

int main(int argc, char **argv)
{
	char *cmdline;
	char **cmdargs;
	int signal = 1;

	while (signal == 1)
	{
		printf("#cisfun$ ");

		cmdline = read_cmd();
		if (cmdline != NULL)
		{
			cmdargs = split_cmd(cmdline);
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
