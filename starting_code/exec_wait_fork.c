#include "starting_code.h"

/**
 * _exec - Exectues a program within our program
 */

int main(void)
{
    char *argv[] = {"/bin/ls", NULL};
    pid_t parent;
    pid_t child;
    int i = 0, stat;
    for (i = 0; i < 5; i++)
    {
        printf("%d __________\n", i);
        child = fork();
        if (child != 0)
        {
            wait(&stat);
        }
        if (child == -1)
        {
            perror("Error:");
            return (1);
        }
        if (child == 0)
        {
            if (execve(argv[0], argv, NULL) == -1)
            {
                perror("Error:");
                return (1);
            }
            else
            {
                execve(argv[0], argv, NULL);
            }
        }
    }
    return (0);
}
