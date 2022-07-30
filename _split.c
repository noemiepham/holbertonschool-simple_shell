#include "shell.h"
/**
 * @brief 
 * 
 * @param str 
 * @return char** 
 */
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
