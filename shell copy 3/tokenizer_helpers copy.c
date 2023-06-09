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
/*
if path_arg initial != "/bin/"
append /bin/ to path_arg
return (path_buffer)
 
  if path_len <= 5;
    printf(error: it is directory not path)
  else
    append;
else
    return (NULL)
*/
if (!path_arg)
return (NULL); /*TODO: check this out latter*/

/*check if /bin/ exitst in path_arg*/
for (i = 0; i < default_len; i++)
{
  if (path_buffer[i] != path_arg[i])
  {
    need_correction = 1;
    break;
  }
}
if (need_correction == 1)
{
  /*append /bin/ and ls*/
  strcpy(path_buffer, default_path);
  k = 0;
  for (i = default_len; i < default_len + path_len; i++)
  {
    path_buffer[i] = path_arg[k];
  }
  path_buffer[i] = '\0';
  return (path_buffer);
}
if (need_correction == 0)
{
  
if (path_len <= 5)
  {
    printf("it is a directory");
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
/*if path was corrected and added */
if (buffer){

}
while(word && w_count <= WORD_COUNT)
{
  if (w_count == 0 && buffer){
    strcpy(token[w_count], buffer);
  }
  else{
  strcpy(token[w_count], word);
  }
  w_count++;
  word = strtok(NULL, delim); 
}
/*add NULL at the end of token*/
token[w_count] = NULL;
/*TODO: add token to info_t->argc   and info_t->argv*/
/*TODO*/
/*TODO*/
/*TODO*/
free(buffer);
return (w_count);
}