#ifndef starting_code_h
#define starting_code_h

#define TRUE 1
#define BUFFER 1024
#define PROMPT "$ "
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

char *_which(char *command, char *fullpath, char *path);
char *_getenv(const char *name);
char *_getline(FILE *fp);

/* Prortotypes */

char **split_str(char *str);
pid_t _fork(void);
char **copyArray(char **arrsource);
void debugArray(char **arr);
int _strcmp(char *name, char *variable, unsigned int length);
void _prompt(int fd, struct stat buf);
void _puts(char *str);

#endif
