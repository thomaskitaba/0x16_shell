#include "main.h"
/**
 * shell_loop_hsh - loop and accept command input
 * @av_token: 2D array to stor input command
 * Return: on exit 0, error -1, success 1 
 */
  int shell_loop_hsh(int argc, char **argv, int mode)
  {
    char *buffer; char **av_token; extern char **environ;
    int i, result, w_len; ssize_t read; size_t len; 
  do{
  av_token = create_2D_buffer(av_token); 
  buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
  if (argv[0] != "|")
  putchar('$');
  read = getline(&buffer, &len, stdin);
  /*TODO: we have to remove the new line from buffer*/
  buffer[_strcspn(buffer, '\n')] = '\0';
  result = strcmp(buffer,  "exit");
  /*(*get_builtin_cmd(buffer))(environ);*/
  if (strcmp(buffer, "printenv") == 0)
  _printenv(environ);
  if (result == 0) {
    _exit_shell(environ);
  }
  if (read == -1) {
  	free(buffer);
	  return (-1);  }
  if (result == 0) {
	/*handle ERROR*/
    free(buffer);
	  return (0); }
  
  if (read > 0) {
  /*printf("%s\n", buffer); call convert buffer to 2d array*/
  w_len = 0;
  /**TODO: add built in here */
  av_token = tokenize_string(buffer, av_token, &w_len);
  /*_print_2d(av_token, w_len);*/
  _execve(av_token, NULL);
  }
  free(buffer); _free_2D(av_token, w_len);
  if (mode == 0)
  exit(1);
  }while (result != 0 && read != -1 && read > 1 && buffer[read - 1] != '\n');
  }


