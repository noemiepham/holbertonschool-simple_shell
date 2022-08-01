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

<<<<<<< HEAD
	nread = getline(&line, &len, stdin); 
=======
	nread = getline(&line, &len, stdin); /*getline allocate a buffer for us*/
>>>>>>> origin/mia2
	if (nread == -1)
	{
		/*got EOF (ctrl+D) problem here, solved with exit(1)!*/
		free(line);
<<<<<<< HEAD
		line = NULL;
=======
>>>>>>> origin/mia2
		exit(EXIT_SUCCESS);
	}
	else
	{
		sizeline = strlen(line);
<<<<<<< HEAD
		line[sizeline - 1] = '\0';
=======
		line[sizeline - 1] = '\0'; /*avoid getline return to newline*/
>>>>>>> origin/mia2
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
<<<<<<< HEAD
	char *delim = "\n\t\r ";
=======
>>>>>>> origin/mia2

	cmd_args = malloc(1024 * (sizeof(char *)));
	if (!cmd_args)
	{
		perror("Error of allocation of cmd_args\n");
		exit(-1);
	}
<<<<<<< HEAD
	args = strtok(line, delim);
	
	while (args != NULL)
	{
		cmd_args[position] = args;
		args = strtok(NULL, delim);
		position++;
	}
	cmd_args[position] = NULL;
	free(args);
=======
	args = strtok(line, " ");

	while (args != NULL)
	{
		cmd_args[position] = args;
		args = strtok(NULL, " ");
		position++;
	}

	cmd_args[position] = NULL;
>>>>>>> origin/mia2
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
<<<<<<< HEAD
	struct stat filestat;

	if (stat(argv[0], &filestat) == 0)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("Process creation error\n");
		}
		if (pid == 0)
		{
			/*the prompt is displayed again each time a cmd has been executed*/
			if (execve(args[0], args, env) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		wait(&status);
	}
	return (1);
}

/**
* printenv - print environment
* Return: 0
*/

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
=======

	pid = fork();
	if (pid < 0)
	{
		perror("Process creation error\n");
		return (-1);
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
		}
		return (-1);
	}
	wait(&status);
	return (1);
}
>>>>>>> origin/mia2
