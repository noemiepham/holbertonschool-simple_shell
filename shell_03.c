#include "shell.h"
/**
 * main - simple shell
 *
 * Return:0
 */
int main(void)
{

    char *str = NULL;
    size_t len = 0;
    unsigned int commandPosition;
    char **arr;
    pid_t pid;
    int status, get;
    int signal = 1;
    struct stat st;
    while (signal == 1)
    {
       signal = isatty(0);
		
		if (signal == 1)
		printf("$ ");

        get = getline(&str, &len, stdin);
        if (get == -1)
        {
            free(str);
            exit(EXIT_SUCCESS);
        }
        arr = split_str(str);
        commandPosition = 0;
        if (arr[0])
        {
            if (strcmp(arr[0], "exit") == 0)
            {
                free(arr);
                exit(0);
            }
            if (strcmp(arr[0], "env") == 0)
            {
               _printev();
               free(arr);
                continue;
            }
            if (stat(arr[commandPosition], &st) == 0)
            {
                pid = fork();
                if (pid == -1)
                {
                    perror("error");
                    return (1);
                }
                else if (pid != 0)
                {
                    wait(&status);
                }
                else if (pid == 0)
                {
                    if (execve(arr[commandPosition], arr, NULL) == -1)
                    {
                        perror("Error:");
                        return (1);
                    }
                }
            }
            else
            {
                printf("%s NOT FOUND\n", arr[commandPosition]);
            }
        }
        free(arr);
    }
    return (0);
}
