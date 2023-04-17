#include <stdio.h>
#include <unistd.h>
#include "main.h"
/**
 * _exceve - execve 
 * @av: 2D of CL arguments
 * @env: environment variable
 * Return: Always 0.
 */

int _exceve(char **av, char **env)
{
char *av_temp[] = {"/bin/ls", "-l", NULL};

if (execve(av_temp[0], av_temp, NULL) == -1)
    {
        perror("Error:");
        exit(-1);
    }
    return (0);
}