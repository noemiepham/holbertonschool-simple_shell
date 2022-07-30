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

    if (get == -1)
	{
		printf("Error");
		free(str);
		return (1);
	}

    arr = split_str(str);

    arrcp = copyArray(arr);

    while (arrcp[i])
    {
        if (stat(arrcp[i], &st) == 0)
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
                printf("$ ");
            }
            else if (pid == 0)
            {
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
