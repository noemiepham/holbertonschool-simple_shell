/*
 * _getenv - get environ
 * @name: name de environ
 * Return: environ value
 */

char *_getenv(const char *name)
{
    int i = 0;
    char *envName;
    char *envValue;
    char *command;
    char *array;
    char *cur_word;
    char sep[] = ":";

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
    cur_word = strtok(envValue, sep);

    while (cur_word != NULL)
    {
        cur_word = strtok(NULL, sep);
        printf("%s\n", cur_word);
    }
    array = split_str(cur_word);

        return (cur_word);
}

 int main(void)
{
    printf("%s\n", _getenv("PATH"));
    return (0);
}
 