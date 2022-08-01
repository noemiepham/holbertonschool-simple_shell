#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
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
			{
				perror("Error:");
			}
			return (0);
		}
	}
	return (0);
}
