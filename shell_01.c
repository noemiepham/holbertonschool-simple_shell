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
    unsigned int i;
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

        //arrcp = copyArray(arr);
        //free(arr);
        i = 0;
        while (arr[i])
        {
            if (stat(arr[i], &st) == 0)
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
                    if (execve(arr[0], arr, NULL) == -1)
                    {
                        perror("Error:");
                        return (1);
                    }
                }
            }
            else
            {
                printf("%s NOT FOUND\n", arr[i]);
            }
            i++;
        }
        free(arr);
    }
    return (0);
}
