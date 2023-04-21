#include "main.h"
/**
 * hsh - the shell part
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 or 1 
 */
int hsh(int argc, char **argv)
{
  int hsh_val;
  ssize_t read;
  size_t len;
  char **av;

/* create and allocate 2D array */
/*char **av_token;
av_token = (char **)malloc(sizeof(char *) * MAX_WORDS);
for (i = 0; i < MAX_WORDS; i++)
{
av_token[i] = (char *)malloc(sizeof(char) * MAX_WORD_LENGTH);
}*/
if (argc == 1 && (strcmp(argv[0], "./hsh") == 0)) {
  
  printf("interactive mode\n");
   hsh_val = shell_loop_hsh(argc, argv);
  if (hsh_val == -1)
  
}
/*else if more than one argument
  it means it is not interactive mode so just send 
  tokenize_cmd (av, ar, av)*/
else
{
  /*printf("command line mode\n");*/
  av = (char**)malloc(sizeof(char *) * (argc + 1));
  for (i = 0; i < argc + 1; i++)
  {
    av[i] = (char *)malloc(sizeof(char) * _strlen(av[i] + 1));
    strcpy(av[i], argv[i]);
    if (i + 1 == argc)
    {
      av[i + 1] = NULL;
      break;
    }
  }
  /*add NULL to argv*/
  _execve(av, NULL);
/*TODO: add error check for execve*/
/*tokenize the argv arguments */
/*send them to execve*/
}
_free_2D(av, argc + 1);
return (0);
}
