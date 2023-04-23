#include "main.h"
/**
 * _free_2D - free 2D array
 * @token: 2d array
 * @rows: row
 * Return: void
 */
void _free_2D(char **token, int rows)
{
int i;
for (int i = 0; i < rows; i++)
free(token[i]);
free(token);
}
/**
 * create_buffer - Create a buffer object
 *
 * Return: created 1d buffer
 */
char *create_buffer(void)
{
char *buf;
buf = malloc(sizeof(char) * BUFFER_SIZE);
if (!buf)
return (NULL);
return (buf);
}
/**
 * create_2D_buffer - Create a buffer object
 * @av: pointer to 2d ptr variable
 * Return: created 2d buffer
 */
char **create_2D_buffer(char **av)
{
int i;
av = (char **)malloc(sizeof(char *) * MAX_WORDS);
if (!av)
return (NULL);
for (i = 0; i < MAX_WORDS; i++)
{
av[i] = (char *)malloc(sizeof(char) * MAX_WORD_LENGTH);
if (!av[i])
return (NULL);
}
return (av);
}
