#include "main.h"

/**
 * _get_word_count - length of string
 * @str: string
 * Return: int 
 */
int _get_word_count(char *str, char *delim)
{
  int word_count = 0;
  char *token;
  token = strtok(str, delim);
  while (token)
  {
    word_count++;
    token = strtok(NULL, delim);
  }
  return word_count;
}
/**
 * _strlen - length of string
 * @str: string
 * Return: int 
 */
int _strlen(char *str)
{
  int i;
  i = 0;
  while(str[i] != '\0')
  {
    i++;
  }
return (i);
}

/**
* _strcspn - find \\n and replace it with \0 
*@c: char to be searched
*Return: replace buf
*/
int _strcspn(char *buf, char c)
{
int i, n;
if (!buf)
return (0);
for (i = 0, n = (int)strlen(buf) ; i < n; i++)
{
  if (buf[i] == c)
  {
    return (i);
    break;
  }
}
return (0);
}

