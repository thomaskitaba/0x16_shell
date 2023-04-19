#include "main.h"

/**
 * tokenize_cmd - tokenize cmd * 
 * @argc: argument count
 * @argv: argument vector
 * Return: int
 */
int tokenize_cmd(int argc, char **argv)
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

_tokenize(av, argv, argc);

/*_print_2d(av, argc);*/
printf("\n");
k = execve(av[0], av, NULL);
if (k == -1)
perror("file not found");

return (0);
}


