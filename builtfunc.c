#include "header.h"
/**
 *get_env - get the environment
 *@name: pointer to the path name
 *Return: envv or NULL
 **/
char *get_env(const char *name)
{
extern char **environ;
int i = 0, j, x = 0;
char *envv = malloc(1024);
while (environ[i])
{
j = 0;
while (name[j] == environ[i][j])
{
j++;
if (environ[i][j] == '=')
{
j++;
while (environ[i][j])
{
envv[x] = environ[i][j];
j++;
x++;
}
return (envv);
}
}
i++;
}
return (NULL);
}
