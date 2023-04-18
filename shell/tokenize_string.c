#include "main.h"
/**
 * tokenize_string - change string to 2D array
 * @str: string to be tokenized
 * Return: 1 on success, -1 on failur
 */
char **tokenize_string(char *str, char **token, int *len)
{
  /*char str[] = "thomas kitaba feyissa";*/
  char *delimeter = " ";
  int i, w_count;
  w_count = 0;
  /*malloc for 2d array **token  row*/
  w_count = _strtok(str, delimeter, token);
  
  _print_2d(token, w_count + 1);
  
  *len = (w_count + 1);
  
  /*free memory */
  return (token);
}