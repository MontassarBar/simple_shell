#include "header.h"
/**
 * shellloop - loop
 * 
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
printf("\n%s\n", cmd[0]);
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
    return(0);
}
