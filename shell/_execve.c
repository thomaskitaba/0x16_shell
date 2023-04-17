#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
 * _execve - execve 
 * @av: 2D of CL arguments
 * @env: environment variable
 * Return: Always 0.
 */

int _execve(char **av, char **env)
{
char *av_tem[] = {"/bin/ls", "-l", NULL};
if (execve("/bin/ls", av_tem, NULL) == -1)
{
    perror("Error:");
    exit(1);
}
return (0);
}