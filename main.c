#include "header.h"
/**
 *main - sheeel
 *Return: 0
 */
int main(void)
{
char *buffer, **cmd, *ch;
struct stat st;
buffer = malloc(sizeof(char));
if (!buffer)
{
perror("Unable to allocate buffer");
free(buffer);
exit(1);
}
while (1)
{
buffer = get_line();

cmd = tok_buff(buffer);
if (stat(cmd[0], &st) != 0)
cmd[0] = pathcmd(cmd[0]);
if (cmd[0] == NULL)
write(STDOUT_FILENO, "./hsh: No such file or directory\n", 34);
else
_exec(cmd);
}
free(buffer);
return (0);
}
