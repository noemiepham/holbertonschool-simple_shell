#include "starting_code.h"

pid_t _getppid(void)
{
	pid_t parent;

	parent = getpid();
	return(parent);
}

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t my_pid;

    my_pid = getpid();
    printf("%u\n", my_pid);
    return (0);
}