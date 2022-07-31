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
    struct stat st;
    while (TRUE)
    {
        fstat(STDIN_FILENO, &st);
        if (S_ISCHR(st.st_mode) > 0)
            printf("$ ");

        get = getline(&str, &len, stdin);
        if (get == -1)
        {
            free(str);
            exit(EXIT_SUCCESS);
        }
        arr = split_str(str);
        removeCR(arr);

        commandPosition = 0;
        if (arr[0])
        {
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
