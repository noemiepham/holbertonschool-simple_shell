#include "shell.h"
/**
 * @brief 
 * 
 * @return int 
 */
int main(void)
{
    ssize_t line_command;
	size_t len = 0;
    char *str = NULL;
    unsigned int i = 0;
    char **arr;
    int pid; 

    printf("ç ");

    pid = fork();
	line_command = getline(&str, &len, stdin);
    arr = split_str(str);
    while (arr[i])
    {
    printf("%s\n", arr[i]);
        i++;
    }
    
    return (0);
}