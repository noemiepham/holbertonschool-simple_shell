#include "sshell.h"

int main(int __attribute__((__unused__)) argc, char **argv)
{
	char *cmdline;
	char **cmdargs;
	int signal = 1;
	while (signal == 1)
	{
		signal = isatty(0);
		
		if (signal == 1)
		printf("#cisfun$ ");

		cmdline = read_cmd();
		if (cmdline != NULL)
		{
			/*implement the exit buit-in, that exits the shell*/
		/*	if (!strcmp(cmdline, "exit"))
				return (1);
			if (!strcmp(cmdline, "env"))
				_printenv();
		*/
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
