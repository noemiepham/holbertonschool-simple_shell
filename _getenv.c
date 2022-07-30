#include "shell.h"
/**
 * @brief 
 * 
 */

char *_getenv(const char *name)
{
    extern char **environ;
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
            return (envValue);
        }
        i++;
    }
    return (NULL);
}
