#include <stdio.h>
#include <unistd.h>

/**
 * _exceve - execve 
 * @av: 2D of CL arguments
 * @env: environment variable
 * Return: Always 0.
 */

int _exceve(char **av, char **env)
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