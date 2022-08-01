#include "starting_code.h"

/**
 * _exec - Exectues a program within our program
 */

int main(void)
{
    char *argv[] = {"/bin/ls", NULL};
    pid_t parent;
    pid_t retour_fork;
    int i = 0, stat;
    for (i = 0; i < 5; i++)
    {
        printf("%d __________\n", i);
        retour_fork = fork();
        if (retour_fork > 0)
        { // parent
            wait(&stat);
            printf("Parent: %d\n",getpid());
        }
        else if (retour_fork == -1)
        { // negative donc fork KO
            perror("Error:");
            return (1);
        }
        else if (retour_fork == 0)
        { // cas process enfant
            printf("Child: %d, parent is %d\n",getpid(), getppid());
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
