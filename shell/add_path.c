#include "main.h"
/**
 * @path_arg: path argument at index 0
 * @path_buffer: buffer holding string
 * Return: append path return1,  path not appended, -1
 */
char *add_path(char *path_arg, char *path_buffer)
{
char *default_path; /*TODO: to be deleted*/
int path_len, res, default_len, buffer_len, correction;
int i, k; /*TODO: to be deleted*/
path_len = buffer_len = k = 0;
default_path = "/bin/"; /*TODO: to be deleted*/
default_len = _strlen(default_path);
path_len = _strlen(path_arg);
correction = res = 0;
/*check if /bin/ exitst in path_arg*/
for (i = 0; i < default_len; i++)
{
if (default_path[i] != path_arg[i])
{
correction = 1;
break;
}
}
path_buffer = path_helper(path_arg, path_buffer, correction, default_len, path_len);
if (path_buffer)
return (path_buffer);
else
return (NULL);
}
