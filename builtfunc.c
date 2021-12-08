#include "header.h"
/**
 *get_env - get the environment
 *@name: pointer to the path name
 *Return: envv or NULL
 **/
char *get_env(const char *name)
{
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
/**
 * _strlen - get length of string
 *
 * @s: string
 *
 * Return: length
 **/
int _strlen(char *s)
{
int i;
i = 0;
while (*(s + i) != '\0')
{
i++;
}
return (i);
}
/**
* *_strcat -  concatenates two strings
*loop
*@dest: pointer
*@src: pointer
*Return: dest
**/
char *_strcat(char *dest, char *src)
{
int ls, ld, i;
ls = strlen(src);
ld = strlen(dest);
for (i = 0; i < ls; i++)
{
dest[ld + i] = src[i];
}
dest[ls + ld] = '\0';
return (dest);
}
/**
*_strcmp - compares two strings
*loop
*@s1: pointer
*@s2: pointer
*Return: a
**/
int _strcmp(char *s1, char *s2)
{
int x, y, z, a;
y = _strlen(s1);
z = 0;
a = 0;
for (x = 0; ((x < y)&&(z == 0)); x++)
{
if (s1[x] != s2[x])
z = 1;
if (z == 1)
a = s1[x] - s2[x];
}
return (a);
}
