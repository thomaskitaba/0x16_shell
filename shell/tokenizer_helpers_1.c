#include "main.h"
/**
 * _strcmp - swaps string varibles
 * @s1: char to be copied
 * @s2: char to be cpied to
 * Return: 0 if the same, -1 if after, 1 if before
 */
int _strcmp(char *s1, char *s2)
{
int i, s1_len, s2_len, result;

s1_len = (int)strlen(s1), s2_len = (int)strlen(s2);
for (i = 0; i < s1_len; i++)
{
if (s1[i] == s2[i])
{ result = 0; }
else
{
if ((s1[i] >= 97 && s1[i] <= 122) && (s2[i] >= 65 && s2[i] <= 90) &&
(s1[i] - s2[i] == 32))
{
result = s2[i] - s1[i];
return (result);
}
result = s1[i] - s2[i];
return (result);
}
}
if (i + 1 == s1_len)
{
if (s1_len < s2_len)
{
result = 0 - s2[i];
return (result);
}
}
return (0);
}

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
int i, w_count, total_w_len ;
char *word, *str_cpy, *buffer;

buffer = (char *)malloc(sizeof(char) * WORD_SIZE);

w_count = 0;
total_w_len = 0;
str_cpy = strdup(str);

word = strtok(str_cpy, delim);
/*TODO: check path  if path doesnot contain /bin/ 
check_path { send word to check path if no path defined 
append path to ls and return 1  else return -1}
*/
buffer = add_path(word, buffer);
/*if path was corrected and added */

while(word && w_count <= WORD_COUNT)
{
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
/*TODO*/

free(buffer);
return (w_count);
}
