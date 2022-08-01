#include "starting_code.h"
char **split_str(char *str)
{
    int buf = 1024;
    char *sep = " ";
    char *cur_word;
    char **array;
    unsigned int i = 0;

    array = malloc(sizeof(char) * buf);
    if (array == NULL)
        return (NULL);
    cur_word = strtok(str, sep);

    while (cur_word != NULL)
    {
        array[i] = cur_word;
        cur_word = strtok(NULL, sep);
        i++;
    }

    array[i] = NULL;
    return (array);
}

/* int _fork(void)
{
    pid_t pid;
    int i, status;
    char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};
    for (i = 0; i < 5; i++)
    {
        if (pid != 0)
        {
            pid = fork();
            wait(&status);
        }
        if (pid == 0)
        {
            if (execve("/bin/ls", argv, NULL) == -1)
            {
                perror("Error:");
            }
            return (0);
        }
    }
} */

int main(void)
{
    /* getline() */
    ssize_t nread;
    size_t len = 0;
    char *str = NULL;
    unsigned int i = 0;

    printf("$ ");
    int pid = fork();
    nread = getline(&str, &len, stdin);
   
    while (str[i])
    {
        if(str[i] == '\n')
            break; 
        printf("[%d %c]\n",i, str[i]);

        i++;
    }
    char **arr;
    arr = split_str(str);

    while (arr[i])
    {
        printf("[%s\n]", arr[i]);
        i++;
    } 
    return (0);
}
