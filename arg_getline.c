#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

/**
 * create_buffer - create buffer
 * Return: buffer
 */
char *create_buffer(void)
{
        char *buf;
buf = malloc(sizeof(char) * BUFFER_SIZE);
if (!buf)
        return (NULL);
return (buf);
}
/**
* _strcspn - find \\n and replace it with \0 
*@c: char to be searched
*Return: replace buf
*/
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

int main(int ac, char *av[])
{
  int result;
  char *buffer;
  char eof[1];
  ssize_t read;
  size_t len;
  buffer = create_buffer();
  do{
  putchar('$');
  read = getline(&buffer, &len, stdin);
  
  /*TODO: we have to remove the new line from buffer*/
  buffer[_strcspn(buffer, '\n')] = '\0';
  result = strcmp(buffer,  "exit");
  if (read == -1)
  {
    /*add error to error log*/
	  free(buffer);
	  exit(1);
  }
  if (result == 0)
  {
	  /*add exit status to log*/
	  exit (1);
  }
  if (read > 0)
  {
  printf("%s\n", buffer); /*call convert buffer to 2d array*/
  
  }
  }while (result != 0 && read != -1 && read > 1 && buffer[read - 1] != '\n');
  return (0);
}
