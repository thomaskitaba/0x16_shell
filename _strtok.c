#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define WORD_SIZE 100
#define WORD_COUNT 100
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
/**
 * _get_word_count - length of string
 * @str: string
 * Return: int 
 */
int _get_word_count(char *str, char *delim)
{
  int word_count = 0;
  char *token;
  token = strtok(str, delim);
  while (token)
  {
    word_count++;
    token = strtok(NULL, delim);
  }
  return word_count;
}
/**
 * _strlen - length of string
 * @str: string
 * Return: int 
 */
int _strlen(char *str)
{
  int i;
  i = 0;
  while(str[i] != '\0')
  {
    i++;
  }
return (i);
}
/**
 * _strtok - string to words
 * @str: string
 * @delim: delimeter
 * Return: int 
 */
int _strtok(char *str, char *delim, char **token)
{
int i, w_count, total_w_len;
char *word, *str_cpy;


w_count = 0;
total_w_len = 0;
str_cpy = strdup(str);

word = strtok(str_cpy, delim);

while(word && w_count <= WORD_COUNT)
{
  strcpy(token[w_count], word);
  w_count++;
  word = strtok(NULL, delim); 
}
return (w_count);
}
int main(void)
{
  char str[] = "thomas kitaba feyissa";
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