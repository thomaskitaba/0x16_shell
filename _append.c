#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "main.h"

/**
 * _free_2D - free 2D array
 * @2d: 2d array
 * Return: void
 */
void _free_2D(char **token, int rows)
{
int i;
for (int i = 0; i < rows; i++) {
    free(token[i]);
}
free(token);

}
/* Return 1 on success */
int _append(char *new, char *arg, char *path, int path_len, int len)
{
  int j, k;

  for (j = path_len, k = 0; j < (path_len + len); j++)
  {
    new[j] = arg[k];
    k++;
  }
  new[j] = '\0'; // Null-terminate the resulting string

  return (1);
}

int main(int argc, char **argv)
{
  int i, k, arg_len, path_len, new_len;
  char *d_path = "/bin/";
  char *new_arg_0;
  char **av;

  /*malloc space for 2d array*/
  av = (char **)malloc(sizeof(char *) * (argc - 1));
  /*TODO: add NULL check*/
for (i = 0; i < argc - 1; i++)
{
  av[i] = (char *)malloc(sizeof(char) * MAX_WORD_LENGTH);
  /*TODO: add NULL check*/
}
  /* if we have to append*/
  arg_len = strlen(argv[0]);
  path_len = strlen(d_path);
  new_len = arg_len + path_len;
  // Allocate memory for new_arg_0
  new_arg_0 = malloc(sizeof(char) * (arg_len + path_len + 1));
  if (new_arg_0 == NULL) {
    perror("malloc");
    exit(1);
  }
  // Copy d_path to new_arg_0
  strcpy(new_arg_0, d_path);
  // Concatenate argv[1] to new_arg_0
  _append(new_arg_0, argv[1], d_path, path_len, arg_len);
  printf("%s\n", new_arg_0);
  /* end of append */
  
  free(new_arg_0); // Free the allocated memory
  _free_2D(av, argc - 1);
  return 0;
}
