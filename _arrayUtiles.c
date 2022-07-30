#include "shell.h"
/**
 * @brief
 *
 */
void debugArray(char **arr)
{
    unsigned int i = 0;
    if (arr != NULL)
    {
        while (arr[i] != NULL)
        {
            printf("DEBUG arr at index i %d=[%s]\n", i, arr[i]);
            i++;
        }
    } else 
    {
        printf("Array source id null\n");
    }
}

/**
 * @brief copy array sans retour chariot
 *
 */
char** copyArray(char **arrsource)
{
    int i = 0;
    unsigned long int k;
    int j;
    char **arrDestination = NULL;
    while (arrsource[i])
    {
        i++;
    }
    arrDestination = malloc(sizeof(char) * i);
    if (arrDestination == NULL)
        return (NULL);
    for (j = 0; j < i; j++)
    {
        printf("debug %s\n", arrsource[j] );
        arrDestination[j] = arrsource[j];

        for (k = 0 ; k < strlen(arrDestination[j]); k++) {
            printf("DEBUG HERE %c\n", arrDestination[j][k]);
            if (arrDestination[j][k] == '\n')
            arrDestination[j][k] = ' ';
        }
    }
    return (arrDestination);
}

