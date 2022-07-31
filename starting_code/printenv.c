#include "starting_code.h"
#include <stdio.h>
/**
 * @brief 
 * 
 */
argv[], char * envp[]){
   int i;
   for (i = 0; envp[i] != NULL; i++)
   printf("\n%s", envp[i]);
   getchar();
   return 0;
}
