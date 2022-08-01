#include "sshell.h"

<<<<<<< HEAD
int main(int __attribute__((__unused__)) argc, char **argv)
=======
int main(int argc, char **argv)
>>>>>>> origin/mia2
{
	char *cmdline;
	char **cmdargs;
	int signal = 1;

<<<<<<< HEAD
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
=======
	while (signal == 1 && argc >= 1)
	{
		printf("#cisfun$ ");
		cmdline = read_cmd();
		if (cmdline != NULL)
		{
			/*check if command is exit to exit program*/
	//		if (!strcmp(cmdline, "exit"))
	//			return (1);

>>>>>>> origin/mia2
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
