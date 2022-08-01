#include "starting_code.h"
/**
 * @brief 
 * 
 */
extern char **environ;

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
            return (envValue);
        }
        i++;
    }
    return (NULL);
}

int main(void)
{
    printf("%s\n", _getenv("PATH"));
    return (0);
}