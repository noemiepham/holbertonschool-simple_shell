#include "starting_code.h"

int main(void)
{
    char *full_path = NULL;
    
    full_path = _which("ls", full_path);
    printf("%s\n", full_path);

    free(full_path);
    return (0);
}