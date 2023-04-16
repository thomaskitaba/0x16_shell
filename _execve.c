#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "main.h"
/**
 * _exceve - execve 
 * @av: 2D of CL arguments
 * @env: environment variable
 * Return: Always 0.
 */

int _execve(char **av, char **env)
{
if (!env)
  env = NULL;
    
    if (execve(av[0], av, NULL) == -1)
    {
        perror("Error:");
        exit(-1);
    }
    return (0);
}
