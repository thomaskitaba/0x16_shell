#include "main.h"
/**
 * hsh - the shell part
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1 
 */
int hsh(int argc, char **argv, int mode)
{
  int i, hsh_val; ssize_t read;
  size_t len; char **av;

if (argc == 1 && (strcmp(argv[0], "./hsh") == 0))
{
  printf("interactive mode\n");
  hsh_val = shell_loop_hsh(argc, argv, mode);
  if (hsh_val == 0)
    return (0);
}
else{
  exit(1);
}
/*else {
  av = (char**)malloc(sizeof(char *) * (argc + 1));
  for (i = 0; i < argc + 1; i++)   {
    av[i] = (char *)malloc(sizeof(char) * _strlen(av[i] + 1));
    strcpy(av[i], argv[i]);
    if (i + 1 == argc) {
      av[i + 1] = NULL;
      break;
    }
  }
  _execve(av, NULL);
}
_free_2D(av, argc + 1);*/
return (0);
}
