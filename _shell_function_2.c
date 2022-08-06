#include "shell.h"
/*
 * _getenv - get environ
 * @name: name de environ
 * Return: environ value
 */

char *_getenv(const char *name)
{
    int i = 0;
    char *envName = NULL;
    char *envValue = NULL;

    while (environ[i])
    {
        /* printf("DEBUG etenv at i=[%d], environ [%s] found\n", i, environ[i]); */
        envName = getEnvKey(environ[i], envName);

        if (strcmp(envName, name) == 0)
        {
            /* printf("DEBUG getenv at i=[%d], environ [%s] found\n", i, envName); */
            envValue = getEnvValue(environ[i]);
            clearAndFree(envName);
            break;
        }
        clearAndFree(envName);
        i++;
    }

    return (envValue);
}

char *getEnvKey(char *env, char *envKey)
{
    int env_length = 0;
    int separatorPosition = 0;
    int i, j;
    while (env[env_length])
        env_length++;

    while (env[separatorPosition] != '=')
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

char *getEnvValue(char *env)
{
    int env_length = 0;
    int separatorPosition = 0;
    char *value = NULL;
    int i, j;
    while (env[env_length])
        env_length++;
    /* printf("getEnvValue env_length : %d\n", env_length); */

    while (env[separatorPosition] != '=')
        separatorPosition++;
    /* printf("getEnvValue separatorPosition : %d\n", separatorPosition); */

    value = calloc((env_length - separatorPosition), sizeof(char));

    if (value == NULL)
        return (NULL);

    for (i = 0, j = separatorPosition + 1; j < env_length; i++, j++)
    {
        value[i] = env[j];
    }

    /* printf("getEnvValue : %s\n", value); */

    return (value);
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

char *_copyString(char *src, char *dst)
{

    int size = 0;
    int i;
    while (src[size])
        size++;

    if (dst == NULL)
    {
        /* printf("DEBUG _copyString dst is null ==> malloc\n"); */
        dst = malloc(sizeof(char) * size);
        if (dst == NULL)
            return (NULL);
    }
    else
    {
        _reset(dst);
    }

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

char *_which(char *fullPathCommand, char *executable, char *copyEnvPath)
{
    char *pathSep = ":";
    char *path_token = NULL;
    int j;

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

    return (fullPathCommand);
}
