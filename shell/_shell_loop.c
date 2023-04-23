#include "main.h"
/**
 * shell_loop_hsh - loop and accept command input
 * @argc: 2D array to stor input command
 * @argv: argument vector
 * @mode: open mode
 * Return: on exit 0, error -1, success 1
 */
int shell_loop_hsh(int argc, char **argv, int mode)
{
char *buffer;
char **av_token;
int i, result, w_len;
ssize_t read, len;
do {
av_token = create_2D_buffer(av_token);
buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
putchar('$');
read = getline(&buffer, &len, stdin);
if (read == -1)
{
free(buffer);
_free_2D(av_token, w_len);
return (-1);
}
/*TODO: we have to remove the new line from buffer*/
buffer[_strcspn(buffer, '\n')] = '\0';
result = strcmp(buffer,  "exit");
if (result == 0)
_exit_shell(environ);
if (strcmp(buffer, "printenv") == 0)
_printenv(environ);
if (read > 0)
{
w_len = 0;
av_token = tokenize_string(buffer, av_token, &w_len);
_execve(av_token, NULL);
}
free(buffer);
_free_2D(av_token, w_len);
} while (result != 0 && read != -1 && read > 1 && buffer[read - 1] != '\n');
}
