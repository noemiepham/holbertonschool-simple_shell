#include "shell.h"
/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    ssize_t nread;
	size_t len = 0;
    char *str = NULL;
    unsigned int i = 0;
    char **arr;

    printf("$ ");

    fork();
	nread = getline(&str, &len, stdin);

    arr = split_str(str);
    while (arr[i])
    {
    printf("%s\n", arr[i]);
        i++;
    }
    
    return (0);
}