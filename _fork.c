#include "shell.h"
/**
 * _fork - processor
 *
 * Return: Sucesse
 */
pid_t _fork(void)
{
	pid_t pid;
	int i, status;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	for (i = 0; i < 5; i++)
	{
		if (pid != 0)
		{
			pid = fork();
			wait(&status);
		}
		if (pid == 0)
		{
			if (execve("/bin/ls", argv, NULL) == -1)
				perror("Error:");
		}
	}
	return (0);
}
