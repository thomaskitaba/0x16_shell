#include "main.h"
/**
 * _free_2D - free 2D array
 * @2d: 2d array
 * Return: void
 */
void _free_2D(char **token, int rows)
{
int i;
for (int i = 0; i < rows; i++) {
    free(token[i]);
}
free(token);
}
/**
 * create_buffer - create buffer
 * Return: buffer
 */
char *create_buffer(void)
{
char *buf;
buf = malloc(sizeof(char) * BUFFER_SIZE);
if (!buf)
        return (NULL);
return (buf);
}
char *create_2D_buffer(char **av)
{
  av = (char **)malloc(sizeof(char *) * MAX_WORDS);
  if (!av) {
    return (NULL);
  }
for (i = 0; i < MAX_WORDS; i++) {
av[i] = (char *)malloc(sizeof(char) * MAX_WORD_LENGTH);
if (!av[i])
return (NULL);
}
return (av);
}