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
 * add_path: add path to cmd if not provided
 * @path_arg: path argument at index 0
 * @Return: append path return1,  path not appended, -1 
 */
char* add_path(char *path_arg, char *path_buffer)
{
  char *default_path;
  int i, k, path_len, default_len, buffer_len, new_len, need_correction;
  
  new_len = path_len + buffer_len;
  default_path = "/bin/";
  default_len = _strlen(default_path);
  path_len = _strlen(path_arg);
  need_correction = 0;

/*check if /bin/ exitst in path_arg*/
for (i = 0; i < default_len; i++)
{
  if (default_path[i] != path_arg[i])
  {
    need_correction = 1;
    break;
  }
}
if (need_correction == 1)
{
  /*strcpy(path_buffer, default_path);*/
  path_buffer[0] = '\0';
  /*_strcat(path_buffer, default_path);
  if ((_strlen(path_buffer) + path_len) < WORD_SIZE);
    _strcat(path_buffer, path_arg);*/
  k = 0;
  for (i = default_len; i < default_len + path_len; i++)
  {
    path_buffer[i] = path_arg[k];
    k++;
  }
  path_buffer[i] = '\0';
  return (path_buffer);
}
if (need_correction == 0)
{
  
if (path_len <= 5)
  {
    return (NULL);
  }
  else
  {
    strcpy(path_buffer, path_arg);
    return (path_buffer);
  }
}
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
if (!buffer)
{
  free(buffer);
  printf("it is a directory");
  return (-1);
}
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
