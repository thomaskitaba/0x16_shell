#include "main.h"
/**
 * main - entry point of the program
 * 
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
  int a; /*to accept returned value from hsh*/
  /*initialize some variables here*/
  /*step 1: send string and recive 2d array*/
  /*step 2: send the 2d array to tokenzier
  */
  if (strcmp(argv[0], "./hsh"))
  hsh(argc, argv, 1); /*interactive*/
  else
  hsh(argc, argv, 0); /*command line*/
  return (0);
}