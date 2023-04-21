
#include "main.h"
/**
 * shell_loop_hsh - loop and accept command input
 * @av_token: 2D array to stor input command
 * Return: on exit 0, error -1, success 1 
 */
  int shell_loop_hsh(char **av_token)
  {
    char *buffer;
    int i, result, w_len;
    ssize_t read;
    size_t len; 
  do{
  buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
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
	return (-1)
  }
  if (result == 0)
  {
	/*handle ERROR*/
    free(buffer);
	return (0);
  }
  if (read > 0)
  {
  /*printf("%s\n", buffer); call convert buffer to 2d array*/
  w_len = 0;
  av_token = tokenize_string(buffer, av_token, &w_len);
  /*_print_2d(av_token, w_len);*/
  _execve(av_token, NULL);
  /*_putchar('\n');*/
  /*send tokenized 2D array to execve()*/
  /*fork here*/
  }
  free(buffer);
  _free_2D(av_token, w_len);
  }while (result != 0 && read != -1 && read > 1 && buffer[read - 1] != '\n');
  
  }