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
