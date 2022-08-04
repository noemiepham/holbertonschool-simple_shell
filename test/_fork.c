#include "shell.h"
/**
 * @brief
 *
 */

int execute_command(char *command, char **argument)
{
    pid_t pid;
    int status;
    int exec = 0;

    pid = fork();
    if (pid == -1)
    {
        perror("error");
        exec = 1;
    }
    else if (pid != 0)
    {
        wait(&status);
    }
    else if (pid == 0)
    {
        if (execve(command, argument, NULL) == -1)
        {
            perror("Error:");
            exec = 1;
        }
    }
    return (exec);
}
