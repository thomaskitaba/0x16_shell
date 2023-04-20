#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "main.h"

int hsh(int argc, char **argv)
{
  int i, result, w_len;
  char *buffer; ssize_t read; size_t len;
  pid_t pid; char **av;
  
/* create and allocate 2D array */
char **av_token;
av_token = create_2D_buffer(av_token);
/*av_token = (char **)malloc(sizeof(char *) * MAX_WORDS);
for (i = 0; i < MAX_WORDS; i++) {
av_token[i] = (char *)malloc(sizeof(char) * MAX_WORD_LENGTH);
}*/
if (argc == 1 && (strcmp(argv[0], "./hsh") == 0)) {
  buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
  printf("interactive mode\n");
  do{
  putchar('$');
  read = getline(&buffer, &len, stdin);
  /*TODO: we have to remove the new line from buffer*/
  buffer[_strcspn(buffer, '\n')] = '\0';
  result = strcmp(buffer,  "exit");
  if (read == -1)   {
    /*add error to error log*/
    /* handle ERROR */
	  free(buffer);
	  exit(1);
  }
  if (result == 0) {
	  /*TODO: WRITE EXIT CODE here*/
	  exit (1);
  }
  if (read > 0)
  {
  w_len = 0;
  av_token = tokenize_string(buffer, av_token, &w_len);
  /*_print_2d(av_token, w_len);*/
  _execve(av_token, NULL);
  }
   } while (result != 0 && read != -1 && read > 1 && buffer[read - 1] != '\n');
}
else {
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
_free_2D(av_token, w_len);
return (0);
}
