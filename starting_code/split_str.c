#include "starting_code.h"
char **split_str(char *str)
{
    int buf = 1024;
    char *cur_word;
    char **array;
    unsigned int i = 0;

    array = malloc(sizeof(char) * buf);
    if (array == NULL)
        return (NULL);
    cur_word = strtok(str, " ");

    while (cur_word != NULL)
    {
        array[i] = cur_word;
        cur_word = strtok(NULL, " ");
        i++;
    }
    array[i] = NULL;
    return (array);
}

int main(void)
{
    /* getline() */
    char str[] = "ls -al";
    char **arr;
    unsigned int i = 0;
    arr = split_str(str);
    printf("%s\n", arr[0]);
    return (0);
}