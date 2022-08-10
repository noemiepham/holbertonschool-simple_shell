#include "shell.h"
/**
 * _getenv - get environ
 * @name: name de environ
 * Return: environ value
 */
char *_getenv(const char *name)
{
	int i = 0;
	int envLength = _strlen((char *)name);
	int environSize = 0;

	char *envValue = NULL;
	char *currentEnvProperty = NULL;

	while (environ[environSize])
		environSize++;

	while (environ[i])
	{
		currentEnvProperty = environ[i];

		if (currentEnvProperty != NULL)
		{
			/* printf("DEBUG getenv loop property i:%d", i); */
			/* printf(", value=[%s]\n", currentEnvProperty); */

			if (_strContains(currentEnvProperty, (char *)name, envLength) == 0)
			{
				/* printf("DEBUG getenv key found =[%s]\n", name); */
				envValue = getEnvValue(currentEnvProperty, envValue);
				break;
			}
		}
		i++;
	}

	/* printf("DEBUG getenv found =[%s] with value=[%s]\n", name, envValue); */

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
