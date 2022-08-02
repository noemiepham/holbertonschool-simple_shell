#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - fork & wait example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t child_pid;
	int status;
	int i, j;

	for (j = 0; j < 2; j++)
	{
		child_pid = fork();
		if (child_pid == 0)
		{
			printf("Wait for me, wait for me\n");
			for (i = 0; i < 3; i++)
			{
				printf("%d\n", i);
			}
		}
		else
		{
			wait(&status);
		}
	}
	return (0);
}
