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

		if (currentEnvProperty != NULL)
		{
			/* printf("DEBUG getenv loop property i:%d, value=[%s]\n", i, currentEnvProperty); */

			if (_strContains(currentEnvProperty, (char *)name, envLength) == 0)
			{
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

/**
 * getEnvValue - Get the Env Value object
 * 
 * @env: environ
 * @envValue: value of environ
 * Return: value
 */
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
