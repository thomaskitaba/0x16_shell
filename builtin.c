#include "main.h"

typedef struct builtin
{
char *string;
int (*builtin_f)(char **);
} built_in;


char (*get_builtin_cmd(char *s))(char **)
{
  extern char **environ;
built_in b_in[] = {
{"Exit", _exit_shell},
{"printenv", _printenv},
{NULL, NULL}
};
int i;
i = 0;
/*accept operator and return correct funtion*/
while (b_in[i].string != NULL && *(b_in[i].string) != *s)
{
i++;
}
return (b_in[i].builtin_f);
}
int main(void)
{
  char *result;
  extern char **environ;
  char *string = {"printenv"};
  result = *get_builtin_cmd(string);

  return (0);
}
