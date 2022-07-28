#include "shell.h"

int main(void)
{
    /* getline() */
    ssize_t nread;
	size_t len = 0;
    char *str = NULL;
    unsigned int i = 0;

    printf("$ ");

	nread = getline(&str, &len, stdin);

    char **arr;
    arr = split_str(str);
    while (arr[i])
    {
    printf("%s\n", arr[i]);
        i++;
    }
    
    return (0);
}