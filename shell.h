#ifndef starting_code_h
#define starting_code_h


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_which(char *command, char *fullpath, char *path);
char *_getenv(const char *name);

/* Prortotypes */

char **split_str(char *str);
pid_t _fork(void);
char **copyArray(char **arrsource);
void debugArray(char **arr);

#endif
