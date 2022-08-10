#ifndef starting_code_h
#define starting_code_h

#define TRUE 1
#define BUFFER 1024
#define PROMPT "$ "
#define PROPERTY_SEPARATROR '='
#define PATH_SEPARATROR ':'
#define COMMAND_LINE_SEPARATROR "\n\t\r "
extern char **environ;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Prortotypes */

char **split_str(char *str);
int _strlen(char *s);
void debugArray(char **arr);
void _printev(void);
void get_absolute_path(char **cmd);
char *_getenv(const char *name);
int execute_command(char *command, char **argument);

char *getEnvValue(char *env,  char *envValue);
char *_strCopy(char *src, char *dst);
char *_makeFullCommand(char *dst, char *command, char *fullPath);
void freeArray(char **array, int size);
void _strFree(char *string);
char *_which(char *fullPathCommand, char *executable, char *copyEnvPath);
int _strContains(char *str1, char *str2, int maxLength);

#endif
