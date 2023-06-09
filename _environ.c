#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/**
 * _getenv - get value of env name
 * @name: name to look for 
 * Return: return value or NUll 
 */
char *_getenv(const char *name)
{
  extern char **environ;
  char **env;
  int len;
  len = strlen(name);
  for (env = environ; *env != NULL; env++)
  {
    if (strncmp(name, *env, len) == 0 && (*env)[len] == '=')
    {
      return  &((*env)[len + 1]);
    }
  }
  return (NULL);
}
int main(int argc, char **argv) {
  char *value;
  char *name = {"OS"};
  value = _getenv(name);
  printf("%s\n", value);
return (0);
}
