#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"
void _print_2d(char **av, int argc)
{
  int i; 
for (i = 0; i < argc - 1; i++)
{
  printf("%s\n", av[i]);
}
}
int _to_cmd(char **av, char **argv, int argc)
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
int main (int argc, char **argv)
{
  int i, k;
  char **av;
  /*malloc space for 2d array*/
  av = (char **)malloc(sizeof(char *) * (argc - 1));
  /*TODO: add NULL check*/
for (i = 0; i < argc; i++)
{
  av[i] = (char *)malloc(sizeof(char) * 100);
  /*TODO: add NULL check*/
}
_to_cmd(av, argv, argc);
_print_2d(av, argc);
printf("\n");
k = execve(av[0], av, NULL);
if (k == -1)
perror("file not found");
return (0);

}