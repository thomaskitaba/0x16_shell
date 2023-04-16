#include "main.h"
/**
 * _to_cmd - argv to 2D array
 * @av: new argument vector
 * @argv:  argument vector
 * @argc: argument count 
 */
int _tokenize(char **av, char **argv, int argc)
{
  int i, k;
for (i = 1, k = 0; i < argc; i++)
{
  if (i == 1)
  {
    strcpy(av[k], "/bin/echo"); /*replace /bin with append this with */
    k++;
    continue;
  }
  strcpy(av[k], argv[i]);
  k++;
}
av[argc-1] = NULL;
return (0);
}