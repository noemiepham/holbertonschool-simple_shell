#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

extern char **environ;
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

/*prototypes*/

char *read_cmd(void);
char **split_cmd(char *line);
int exec_cmd(char **argv, char **args);
int _printenv(void);

#endif
