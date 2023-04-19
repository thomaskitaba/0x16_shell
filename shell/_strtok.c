#include "mian.h"

/**
 * _strtok - string to words
 * @str: string
 * @delim: delimeter
 * Return: int 
 */
int _strtok(char *str, char *delim, char **token)
{
int i, w_count, total_w_len ;
char *word, *str_cpy, *buffer;

buffer = (char *)malloc(sizeof(char) * WORD_SIZE);
w_count = 0;
total_w_len = 0;
str_cpy = strdup(str);

word = strtok(str_cpy, delim);
buffer = add_path(word, buffer);
/*if path was corrected and added */
while(word && w_count <= WORD_COUNT) {
  if (w_count == 0 && buffer){
    strcpy(token[w_count], buffer);
  }
  else
  strcpy(token[w_count], word);
  w_count++;
  word = strtok(NULL, delim); 
}
/*add NULL at the end of token*/
token[w_count] = NULL;
/*TODO: add token to info_t->argc   and info_t->argv*/

free(buffer);
return (w_count);
}