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
if (res)
return (res);
else
return (NULL);
/*
if (correct == 1)
{
strcpy(path_buffer, default_path);
for (i = default_len; i < default_len + path_len; i++)
{
path_buffer[i] = path_arg[k];
k++;
}
path_buffer[i] = '\0';
return (path_buffer);
}
if (correct == 0)
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
*/
}
