#include "shell.h"
/*
 * _getenv - get environ
 * @name: name de environ
 * Return: environ value
 */

char **_getenv(const char *name)
{
    int i = 0;
    int j = 0;
    char *envName;
    char *envValue = NULL;
    char **array;
    char *cur_word;
    char *sep = ":";

    while (environ[i])
    {
        envName = strtok(environ[i], "=");
        if (strcmp(envName, name) == 0)
        {
            envName = strtok(NULL, "=");
            envValue = envName;
        }
        i++;
    }
  /*    array = split_str(envValue, sep); */
 array = malloc(sizeof(char) * BUFFER);
    if (array == NULL)
        return (NULL);

    cur_word = strtok(envValue, sep);

    while (cur_word != NULL)
    {
        array[j] = cur_word;
        cur_word = strtok(NULL, sep);
        j++;
    }
    array[i] = NULL;
    return (array);
}

/* int main(void)
{
    int i = 0;
    char **arr = _getenv("PATH");

    while (arr[i] != NULL)
    {
        printf("main %s\n", arr[i]);
        i++;
    }
    return (0);
}
 */


#include "shell.h"
/**
 * execute_command - execute la commande if true
 * @command: commande from getline
 * @argument: argument
 * Return: 1 if not found
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

