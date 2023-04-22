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
  if (w_count == -1)
  return (NULL);
  /*_print_2d(token, w_count + 1);*/
  
  *len = (w_count + 1);
  /*free memory */
  return (token);
}
/**
 * 2_2d_string - change word to 2d word
 * @string: string to be converted
 * Return: 1 on success, -1 on faliur
 */
int **2_2d_string(char **2d_string, char *string)
{
  strcpy(2d_string[0], string);
  _free_2D(2d_string);
  return (1);
}
