#ifndef header_h
#define header_h
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <stddef.h>
#include <sys/wait.h>
extern char **environ;
char *get_line();
char **tok_buff(char *buffer);
int _exec(char **cmd);
char *pathcmd(char *ch);
char *get_env(const char *name);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);

#endif
