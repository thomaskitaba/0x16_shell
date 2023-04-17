#include "main.h"
/**
 * _print_2d - print 2D array
 * @av: argument vector
 * @argc: argument count
 * Return: void
 */
void _print_2d(char **av, int argc)
{
  int i; 
for (i = 0; i < argc - 1; i++)
{
  printf("%s\n", av[i]);
}
}
/**
 * tokenize_string - change string to 2D array
 * @str: string to be tokenized
 * Return: 1 on success, -1 on failur
 */
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