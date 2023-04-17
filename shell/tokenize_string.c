#include "main.h"
int tokenize_string(char *str)
{
  /*char str[] = "thomas kitaba feyissa";*/
  char *delimeter = " ";
  char **token;
  int i, w_count;
  w_count = 0;
  
  /*malloc for 2d array **token  row*/
token = (char **)malloc(sizeof(char *) * WORD_COUNT);
for (i = 0; i < WORD_SIZE; i++)
{
  token[i] = (char *)malloc(sizeof(char) * WORD_SIZE);
}
  w_count = _strtok(str, delimeter, token);
  _print_2d(token, w_count + 1);
  /*free memory */
  _free_2D(token, w_count);
  return (0);
}