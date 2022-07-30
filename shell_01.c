#include "shell.h"
/**
 * @brief
 *
 * @return int
 */
int main(void)
{

    char *str = NULL;
    size_t len = 0;
    unsigned int i = 0;
    char **arr, **arrcp;
    pid_t pid;
    int status, get;
    struct stat st;

    printf("$ ");

    get = getline(&str, &len, stdin);
    arr = split_str(str);

    arrcp = copyArray(arr);
    debugArray(arrcp);

    while (arrcp[i])
    {
        if (stat(arrcp[i], &st) == 0)
        {
            printf("%s FOUND\n", arrcp[i]);
            pid = fork();
            if (pid == -1)
            {
                perror("error");
                return (1);
            }
            if (pid != 0)
            {
                printf("This is parent\n");
                wait(&status);
                printf("$ ");
            }
            if (pid == 0)
            {
                printf("This is child hello\n");
                printf("%d\n", execve(arrcp[i], arrcp, NULL));
            }
        }
        else
        {
            printf("%s NOT FOUND\n", arrcp[i]);
        }
        i++;
    }
    return (0);
}
