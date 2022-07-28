#include "starting_code.h"

int main(void)
{

extern char **environ;

int i = 0;
while (environ[i] != NULL) {
  {
    printf("environ[%d] = %p\n", i, environ[i]);
  i++;
  }
printf("last address(or pointer) of the environment = %p\n", environ[i]);
printf("address of the last address of environ = %p\n", &environ[i]);
  return (0);

}
// environ is a "pointer to pointer to char".  See http://cdecl.org/
// The last useful pointer in array `environ` should be a NULL.
// The address(pointer) of that last pointer(pointer) is ...
}