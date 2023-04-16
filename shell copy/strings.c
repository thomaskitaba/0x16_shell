#include "main.h"
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