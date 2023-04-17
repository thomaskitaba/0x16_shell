#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/*
char *create_buffer(void)
{
        char *buf;
buf = malloc(sizeof(char) * BUFFER_SIZE);
if (!buf)
        return (NULL);
return (buf);
}

int _strcspn(char *buf, char c)
{
int i, n;
if (!buf)
return (0);
for (i = 0, n = (int)strlen(buf) ; i < n; i++)
{
  if (buf[i] == c)
  {
    return (i);
    break;
  }
}
return (0);
}
*/
int hsh(int argc, char **argv)
{
  int result;
  char *buffer;
  char eof[1];
  ssize_t read;
  size_t len;
  buffer = create_buffer();
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
