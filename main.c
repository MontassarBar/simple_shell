#include "header.h"
/**
 * _strdup - duplicate string in new memory addr
 * @str: string
 *
 * Return: new string addr
 **/
char *_strdup(char *str)
{
	char *s;
	unsigned int l, i;


	if (str == NULL)
	{
		return (NULL);
	}

	else
	{

		l = _strlen(str);
		s = malloc(l + 1);
		if (s == NULL)
		{
			return (NULL);
		}
		for (i = 0; i <= l; i++)
		{
			s[i] = str[i];
		}

	}

	return (s);
}
/**
 * shellloop - loop
 * @x: integer
 * Return: 0
 */
int shellloop(int x)
{
char *buffer, **cmd;
struct stat st;
buffer = malloc(sizeof(char));
if (!buffer)
{
perror("Unable to allocate buffer");
free(buffer);
exit(1);
}
while (x)
{
buffer = get_line();
x--;
cmd = tok_buff(buffer);
if (stat(cmd[0], &st) != 0)
cmd[0] = pathcmd(cmd[0]);
_exec(cmd);
}
free(buffer);
return (0);
}
/**
 *main - sheeel
 *Return: 0
 */
int main(void)
{
if (isatty(STDIN_FILENO) == 1)
shellloop(1000);
else
shellloop(1);
return (0);
}
