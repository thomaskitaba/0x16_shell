#include <stdio.h>

int add(int a, int b)
  {
    printf("%d\n", a + b);
    return (0);
  }
  int (*func(char *s))(int, int)
  {
    printf("owner: %s", s);
    return (add);
  }
  int main(void)
  {
    int result;
    result = func("thomas")(2, 4);
    printf("result %d\n", result);
    return (0);
  }