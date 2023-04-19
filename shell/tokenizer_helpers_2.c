#include "main.h"
/** add_path: add path to cmd if not provided
 * @path_arg: path argument at index 0
 * @path_buffer: buffer holding string
 * Return: append path return1,  path not appended, -1 
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
for (i = 0; i < default_len; i++) {
  if (default_path[i] != path_arg[i]) {
    need_correction = 1;
    break;
  }
}
if (need_correction == 1) {
  /*append /bin/ and ls*/
  strcpy(path_buffer, default_path);
  k = 0;
  for (i = default_len; i < default_len + path_len; i++) {
    path_buffer[i] = path_arg[k];
    k++; }
  path_buffer[i] = '\0';
  return (path_buffer);
}
if (need_correction == 0) {
if (path_len <= 5) {
    printf("it is a directory");
    return (NULL);
  }
  else {
    strcpy(path_buffer, path_arg);
    return (path_buffer);
  }
}
}