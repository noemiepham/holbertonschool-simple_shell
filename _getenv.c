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
			return (envValue);
		}
		envValue = strtok(environ[i], "/");
		i++;
	}
	return (NULL);
}
