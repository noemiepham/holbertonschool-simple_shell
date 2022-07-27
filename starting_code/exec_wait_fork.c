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
        if (child > 0)
        { // parent
            wait(&stat);
        }
        else if (child == -1)
        { // negative donc fork KO
            perror("Error:");
            return (1);
        }
        else if (child == 0)
        { // cas process enfant
            int codeRetour = execve(argv[0], argv, NULL);
            if (codeRetour == -1)
            {
                perror("Error:");
                return (1);
            }
        }
    }
    return (0);
}
