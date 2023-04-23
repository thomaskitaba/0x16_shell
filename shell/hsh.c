#include "main.h"
/**
 * hsh - the shell part
 * @argc: argument count
 * @argv: argument vector
 * @mode: open mode
 * Return: 0 or 1
 */
int hsh(int argc, char **argv, int mode)
{
int i, hsh_val;
ssize_t read;
size_t len;
char **av;

if (argc == 1 && (strcmp(argv[0], "./hsh") == 0))
{
printf("interactive mode\n");
printf("$ ");
hsh_val = shell_loop_hsh(argc, argv, mode);
if (hsh_val == 0)
return (0);
}
else
{
exit(1);
}
return (0);
}
