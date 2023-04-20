#include "main.h"
/**
 * _execve - execve 
 * @av: 2D of CL arguments
 * @env: environment variable
 * Return: succes 1, failur -1.
 */
int _execve(char **av, char **env)
{
/*char *av_tem[] = {"/bin/ls", "-l", NULL};*/
int status;
pid_t child_pid;
child_pid = fork();

if (child_pid == 0)
{
if (execve(av[0], av, env) == -1){
    perror("Error:");
    exit(1);
}
}
else if (child_pid > 0){
wait(&status);
return (1);
}
else{
perror("Error Creating process:");
exit (1);
/*TODO: update exit struct*/
return (-1);
}
return (-1);
}