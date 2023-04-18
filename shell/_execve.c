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
/*char *av_tem[] = {"/bin/ls", "-l", NULL};*/
pid_t parent_id, child_pid;
child_pid = fork();

if (child_pid == 0)
{
if (execve(av[0], av, env) == -1){
    perror("Error:");
    exit(1);
}
}
else if (child_pid > 0){
wait();
return (0);
}
else{
perror("Error Creating process:");
exit (1);
}

}