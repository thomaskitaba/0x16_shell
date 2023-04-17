#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int _execve(char **av, char **env)
{
/*char *av_tem[] = {"/bin/ls", "-l", NULL};*/
if (execve(av[0], av, ) == -1)
{
    perror("Error:");
    exit(1);
}
return (0);
}

int hsh(int argc, char **argv)
{
  int result;
  char *buffer;
  char eof[1];
  ssize_t read;
  size_t len;
  pid_t pid;
  buffer = create_buffer();
char *av_temp[] = {"/bin/ls", "-l", NULL};

/*if ac == 1 && av[0] = "./hsh"
this means it is interactive mode do the loop*/
if (argc == 1 && (strcmp(argv[0], "./hsh") == 0))
{
  printf("interactive mode\n");
  
  do{
  putchar('$');
  
  read = getline(&buffer, &len, stdin);
  
  /*TODO: we have to remove the new line from buffer*/
  buffer[_strcspn(buffer, '\n')] = '\0';
  result = strcmp(buffer,  "exit");
  if (read == -1)
  {
    /*add error to error log*/
    /* handle ERROR */
	  free(buffer);
	  exit(1);
  }
  if (result == 0)
  {
	  /*handle ERROR*/
	  exit (1);
  }
  if (read > 0)
  {
  printf("%s\n", buffer); /*call convert buffer to 2d array*/
  tokenize_string(buffer);
  /*send tokenized 2D array to execve()*/
  /*fork here*/
  
  }
  }while (result != 0 && read != -1 && read > 1 && buffer[read - 1] != '\n');
}
/*else if more than one argument
  it means it is not interactive mode so just send 
  tokenize_cmd (av, ar, av)*/
else
{
  printf("command line mode\n");
  
/*tokenize the argv arguments */
/*send them to execve*/
}
  
return (0);
}
