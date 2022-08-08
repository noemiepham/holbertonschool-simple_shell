#include "shell.h"
/*
 * _getenv - get environ
 * @name: name de environ
 * Return: environ value
 */

char *_getenv(const char *name)
{
    int pathFound = 0;
    int i = 0;
    int envLength = _strlen((char *)name);
    int environSize = 0;
    int environPropertyLength = 0;
    char **copyEnvironment = NULL;
    char *envKey = NULL;
    char *envValue = NULL;
    char *envProperty = NULL;
    char *copyEnvProperty = NULL;
    char *currentEnvProperty = NULL;

    while (environ[environSize])
        environSize++;

    copyEnvironment = malloc(environSize * sizeof(char *));
    if (copyEnvironment == NULL)
        return (NULL);

    i = 0;
    while (environ[i])
    {
        envProperty = environ[i];
        environPropertyLength = _strlen(envProperty);
        copyEnvProperty = malloc(environPropertyLength * sizeof(char));
        _strCopy(envProperty, copyEnvProperty);
        copyEnvironment[i] = copyEnvProperty;
        i++;
    }

    i = 0;
    while (copyEnvironment[i])
    {
        currentEnvProperty = copyEnvironment[i];
        /* printf("DEBUG getenv copyEnvironment i:%d, value=[%s]\n", i, currentEnvProperty); */

        if (currentEnvProperty != NULL) {
            /* printf("DEBUG getenv loop property i:%d, value=[%s]\n", i, currentEnvProperty); */

            if (_strContains(currentEnvProperty, (char *)name, envLength) == 0)
            {
                envKey = getEnvKey(currentEnvProperty, envKey);
                /* printf("DEBUG getenv key found =[%s]\n", envKey); */
                pathFound = 1;
                break;
            }
        }
        if (pathFound == 1)
            break;
        i++;
    }

    envValue = getEnvValue(currentEnvProperty, envValue);
    /* printf("DEBUG getenv found =[%s] with value=[%s]\n", envKey, envValue); */

    freeArray(copyEnvironment, environSize);

    return (envValue);
}

char *getEnvKey(char *env, char *envKey)
{
    int env_length = 0;
    int separatorPosition = 0;
    int i, j;
    while (env[env_length])
        env_length++;

    while (env[separatorPosition] != PROPERTY_SEPARATROR)
        separatorPosition++;
    /* printf("getEnvKey separatorPosition : %d\n", separatorPosition); */

    envKey = calloc(separatorPosition, sizeof(char));

    if (envKey == NULL)
        return (NULL);

    for (i = 0, j = 0; j < separatorPosition; i++, j++)
    {
        envKey[i] = env[j];
    }

    /* printf("getEnvKey : %s\n", envKey); */
    return envKey;
}

char *getEnvValue(char *env, char *envValue)
{
    int env_length = 0;
    int separatorPosition = 0;
    int i, j;
    while (env[env_length])
        env_length++;
    /* printf("getEnvValue env_length : %d\n", env_length); */

    while (env[separatorPosition] != '=')
        separatorPosition++;
    /* printf("getEnvValue separatorPosition : %d\n", separatorPosition); */

    envValue = calloc((env_length - separatorPosition), sizeof(char));

    if (envValue == NULL)
        return (NULL);

    for (i = 0, j = separatorPosition + 1; j < env_length; i++, j++)
    {
        envValue[i] = env[j];
    }

    /* printf("getEnvValue : %s\n", envValue); */

    return (envValue);
}

int _countCharInString(char *string, char toLook)
{
    int count = 0;
    int i;
    int length = _strlen(string);
    for (i = 0; i < length; i++)
    {
        if (string[i] == toLook)
        {
            count++;
        }
    }

    return (count);
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

char *_strCopy(char *src, char *dst)
{

    int size = 0;
    int i;
    while (src[size])
        size++;

    for (i = 0; i < size; i++)
    {
        dst[i] = src[i];
    }

    return dst;
}

char *_makeFullCommand(char *dst, char *command, char *fullPath)
{
    int commandLength = 0;
    int fullPathLength = 0;
    int i, j;

    commandLength = _strlen(command);
    fullPathLength = _strlen(fullPath);

    /* printf("DEBUG _makeFullCommand command length : %d\n", commandLength);
    printf("DEBUG _makeFullCommand full path length : %d\n", fullPathLength); */

    dst = calloc((commandLength + 1 + fullPathLength), sizeof(char));
    
    if (dst == NULL)
        return (NULL);

    for (i = 0; i < fullPathLength; i++)
    {
        dst[i] = fullPath[i];
    }
    /* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

    dst[fullPathLength] = '/';

    /* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

    for (i = 0, j = fullPathLength + 1; i < commandLength; i++, j++)
    {
        dst[j] = command[i];
    }

    /* printf("DEBUG _makeFullCommand dst : %s\n", dst); */

    return dst;
}

void clearAndFree(char *string)
{
    _reset(string);
    free(string);
}

void _reset(char *string)
{
    int length = 0;

    if (string != NULL)
    {
        while (string[length])
        {
            string[length] = '\0';
            length++;
        }
    }
}

void freeArray(char **array, int size)
{
    int i;
    if (array != NULL)
    {
        for (i = 0; i < size; i++)
        {
            free(array[i]);
        }
        free(array);
    }
}

char *_which(char *fullPathCommand, char *executable, char *envPath)
{
    char *pathSep = ":";
    char *path_token = NULL;
    char *copyEnvPath = NULL;
    int j;

    copyEnvPath = malloc(_strlen(envPath) * sizeof(char));
    if (copyEnvPath == NULL) {
        return (NULL);
    }
    _strCopy(envPath, copyEnvPath);

    path_token = strtok(copyEnvPath, pathSep);
    /* printf("DEBUG getenv envValue=[%s]\n", path_token); */
    j = 0;
    while (path_token != NULL)
    {
        /* printf("DEBUG _which PATH j=[%d], value=[%s] for cmd=[%s]\n", j, path_token, executable); */
        fullPathCommand = _makeFullCommand(fullPathCommand, executable, path_token);
        if (access(fullPathCommand, X_OK) != 0)
		{
			free(fullPathCommand);
			fullPathCommand = NULL;
			path_token = strtok(NULL, pathSep);
		}
		else
        {
            /* printf("DEBUG _which executable found in PATH\n"); */
			break;
        }
        j++;
    }
    free(copyEnvPath);

    return (fullPathCommand);
}

int _strContains(char *str1, char *str2, int maxLength)
{
    int contains = 0;
    int i;

    for (i=0; i<maxLength; i++)
    {
        if (str1[i] != str2[i])
        {
            contains = 1;
            break;
        }
    }

    return contains;
}
