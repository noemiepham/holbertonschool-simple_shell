#include "shell.h"
/**
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

	char **copyEnvironment = NULL;
	char *envValue = NULL;
	char *currentEnvProperty = NULL;

	while (environ[environSize])
		environSize++;

	copyEnvironment = _copyEnvironment(environSize);

	while (copyEnvironment[i])
	{
		currentEnvProperty = copyEnvironment[i];

		if (currentEnvProperty != NULL)
		{
			/* printf("DEBUG getenv loop property i:%d", i); */
			/* printf(", value=[%s]", currentEnvProperty); */

			if (_strContains(currentEnvProperty, (char *)name, envLength) == 0)
			{
				/* printf("DEBUG getenv key found =[%s]\n", envKey); */
				pathFound = 1;
				break;
			}
		}
		i++;
	}

	envValue = getEnvValue(currentEnvProperty, envValue);
	/* printf("DEBUG getenv found =[%s] with value=[%s]\n", envKey, envValue); */

	freeArray(copyEnvironment, environSize);

	return (envValue);
}

/**
 * _copyEnvironment - copie array environ
 * @environSize: taille array environ
 * Return: copy de array environ
 */
char **_copyEnvironment(int environSize)
{
	int i = 0;
	char **copyEnvironment = NULL;
	int environPropertyLength = 0;
	char *envProperty = NULL;
	char *copyEnvProperty = NULL;

	copyEnvironment = malloc(environSize * sizeof(char *));
	if (copyEnvironment == NULL)
		return (NULL);

	while (environ[i])
	{
		envProperty = environ[i];
		environPropertyLength = _strlen(envProperty);
		copyEnvProperty = malloc(environPropertyLength * sizeof(char));
		_strCopy(envProperty, copyEnvProperty);
		copyEnvironment[i] = copyEnvProperty;
		i++;
	}

	return (copyEnvironment);
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

/**
 * freeArray - free array of strings
 *
 * @array: array to free
 * @size: size of array
 */
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
