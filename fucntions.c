#include "header.h"
/**
*printenv - printenv
*Return: print env
 */
int printenv(void)
{
int i = 0, x = 0;
while (environ[i])
{
x = _strlen(environ[i]);
write(STDOUT_FILENO, environ[i], x);
write(STDOUT_FILENO, "\n", 1);
i++;
}
return (0);
}
/**
*get_line - getline function
*Return: buffer
 */
char *get_line()
{
size_t bufsize, c, x = -1;
char *buffer = malloc(sizeof(char));
if (!buffer)
{
perror("Unable to allocate buffer");
free(buffer);
exit(1);
}
bufsize = 2;
while (bufsize == 2)
{
write(STDOUT_FILENO, "$ ", 2);
c = getline(&buffer, &bufsize, stdin);
if (c == x)
exit(0);
}
buffer[c - 1] = '\0';
if (_strcmp(buffer, "env") == 0)
printenv();
if (_strcmp(buffer, "exit") == 0)
exit(0);
return (buffer);
}
/**
 *tok_buff - strtok function
 *@buffer: pointer to the buffer
 *Return: cmd
 */
char **tok_buff(char *buffer)
{
char *str;
size_t x;
char **cmd = malloc(sizeof(char *) * 10);
str = strtok(buffer, " ");
for (x = 0; str != NULL && x < 16; x++)
{
cmd[x] = str;
str = strtok(NULL, " ");
}
x++;
cmd[x] = NULL;
return (cmd);
}
/**
 *_exec - exec the file
 *@cmd: command
 *Return: none
 */
int _exec(char **cmd)
{
pid_t child;
child = fork();
if (child == 0)
{
if (execve(cmd[0], cmd, NULL))
{
perror("./shell");
exit(0);
}
}
else
wait(NULL);
return (0);
}
/**
 *pathcmd - path handle
 *@ch: pointer
 *Return: NULL
 */
char *pathcmd(char *ch)
{
char *str, *x[100];
char *path = malloc(5000);
struct  stat st;
int i = 0, j = 0;
path = get_env("PATH");
str = strtok(path, ":");
while (str)
{
x[i] = str;
str = strtok(NULL, ":");
i++;
}
j = i - 1;
i = 0;
_strcat(x[0], "/");
_strcat(x[0], ch);
while (stat(x[i], &st) != 0)
{
i++;
if (i == j)
break;
_strcat(x[i], "/");
_strcat(x[i], ch);
}
if (i < 18)
return (x[i]);
else
return (NULL);
}
