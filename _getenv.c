
#include "shell.h"
/**
 * _getenv - get environ
 * @name: name de environ
 * Return: environ value
 */

char *_getenv(const char *name)
{
    int i = 0;
    char *envName;
    char *envValue;

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
    i = 0;
    while (envValue[i])
    {
        envName = strtok(&envValue[i], ":");
        if (strcmp(envName, name) == 0)
        {
            envName = strtok(NULL, ":");
            envValue = envName;
        }
        i++;
    }
    return (NULL);
}

/* int main(void)
{
    printf("%s\n", _getenv("PATH"));
    return (0);
} */
