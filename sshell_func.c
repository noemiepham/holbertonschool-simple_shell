#include "sshell.h"

/**
* read_cmd - read the line
* Return: line
*/

char *read_cmd(void)
{
	ssize_t nread;
	size_t len = 0;
	char *line = NULL;
	int sizeline = 0;

	nread = getline(&line, &len, stdin); /*getline allocate a buffer for us*/
	if (nread == -1)
	{
		/*got EOF (ctrl+D) problem here, solved with exit(1)!*/
		free(line);
		line = 0;
		exit(EXIT_SUCCESS);
	}
	else
	{
		sizeline = strlen(line);
		line[sizeline - 1] = '\0';
	}
	return (line);
}

/**
* split_cmd - the function to put pointer line in pointer cmd_args
* Return: cmd_args
*/

char **split_cmd(char *line)
{
	char **cmd_args;
	char *args;
	int position = 0;
	char *delim = "\n\t\r ";

	cmd_args = malloc(1024 * (sizeof(char *)));
	if (!cmd_args)
	{
		perror("Error of allocation of cmd_args\n");
		exit(-1);
	}
	args = strtok(line, delim);
	
	while (args != NULL)
	{
		cmd_args[position] = args;
		args = strtok(NULL, delim);
		position++;
	}
	cmd_args[position] = NULL;
	return (cmd_args);
}

/**
* exec_cmd - execute the program
* Return: 1
*/

int exec_cmd(char **argv, char **args)
{
	pid_t pid;
	int status;
	char *env[] = {0};
	struct stat filestat;

	if (stat(argv[0], &filestat) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			perror("Process creation error\n");
		}
		if (pid == 0)
		{
			/*the prompt is displayed again each time a cmd has been executed*/
			if (!(args[0][0] == '\n')) 
			{
				if (execve(args[0], args, env) == -1)
				{
					perror(argv[0]);
				}
				exit(EXIT_FAILURE);
			}	
		}
		wait(&status);
	}
	return (1);
}

int _printenv(void)
{
	int i = 0;
	
	while (environ[i] != NULL)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
