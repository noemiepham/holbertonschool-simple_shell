#include "sshell.h"

/**
* readprompt - read the line
* Return: line
*/

char *readprompt(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	int sizeline = 0;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		//got EOF (ctrl+D) problem here
		printf("Error !");
		return (line);
	}
	else
	{
		sizeline = strlen(line);
		line[sizeline - 1] = '\0';
		return (line);
	}
}

/**
* format_cmd - put pointer line in cmd_args
* Return: cmd_args
*/

char **format_cmd(char *line)
{
	char **cmd_args;
	char *args;

	cmd_args = malloc(1024 * (sizeof(char *)));
	if (!cmd_args)
	{
		perror("Error of allocation of cmd_args\n");
		exit(-1);
	}
	args = strtok(line, " ");

	cmd_args[0] = args;
	cmd_args[1] = NULL;

	return (cmd_args);
}

/**
* exec_cmd - execute the program
* Return: 1
*/

int exec_cmd(char **argv, char **args)
{
	pid_t pid;
	int signal;
	char *env[] = {0};

	pid = fork();
	if (pid == -1)
	{
		perror("Process creation error\n");
		return (-1);
	}
	if (pid == 0)
	{
		if (!(args[0][0] == '\n'))
		{
			if (execve(args[0], args, env) == -1)
			{
				perror(args[0]);
			}
		}
		return (-1);
	}
	wait(&signal);
	return (1);
}
