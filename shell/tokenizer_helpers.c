#include "main.h"
/**
 * _to_cmd - argv to 2D array
 * @av: new argument vector
 * @argv:  argument vector
 * @argc: argument count 
 */
int _tokenize(char **av, char **argv, int argc)
{
  int i, k;
for (i = 1, k = 0; i < argc; i++)
{
  if (i == 1)
  {
    strcpy(av[k], "/bin/echo"); /*replace /bin with append this with */
    k++;
    continue;
  }
  strcpy(av[k], argv[i]);
  k++;
}
av[argc-1] = NULL;
return (0);
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