#include "shell.h"
/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    
    char *str = NULL;
	size_t len = 0;
    ssize_t line_cm;
    unsigned int i = 0;
    char **arr;

    printf("$ ");

	line_cm = getline(&str, &len, stdin);

    arr = split_str(str);

    while (arr[i])
    {
        printf("%s\n", arr[i]);
        i++;
    }
    free(arr);
    return (0);
}