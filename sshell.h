#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>

char *readprompt(void);
int exec_cmd(char **argv, char **args);
char **format_cmd(char *line);

#endif
