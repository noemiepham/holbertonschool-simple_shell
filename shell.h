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

/* Prortotypes */

char **split_str(char *str, char *sep);
int _strlen(char *s);
void debugArray(char **arr);
void _printev(void);
void get_absolute_path(char **cmd);
char *_getenv(const char *name);
int execute_command(char *command, char **argument);

char* getEnvKey(char *env, char *envKey);
char *getEnvValue(char *env);
int _countCharInString(char *string, char toLook);
char *_copyString(char *src, char *dst);
char *_makeFullCommand(char *dst, char *command, char *fullPath);
void clearAndFree(char *string);
void _reset(char *string);
char *_which(char *fullPathCommand, char *executable, char *copyEnvPath);

#endif
