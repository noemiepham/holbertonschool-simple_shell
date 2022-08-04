
#include "shell.h"
/**
 * @brief
 *
 */
void _printev(void)
{
    int i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}

/* int main(void).  
{
    _printev();
} */