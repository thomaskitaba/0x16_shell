/**
 * _print_2d - print 2D array
 * @av: argument vector
 * @argc: argument count
 * Return: void
 */
void _print_2d(char **av, int argc)
{
  int i; 
for (i = 0; i < argc - 1; i++)
{
  printf("%s\n", av[i]);
}
}