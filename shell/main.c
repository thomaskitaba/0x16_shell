#include "main.h"
/**
 * main - entry point of the program
 * 
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
  int a, mode; /*to accept returned value from hsh*/
  /*initialize some variables here*/
  /*step 1: send string and recive 2d array*/
  /*step 2: send the 2d array to tokenzier
  */
  if (argc == 1)
  mode = 1; /*interactive*/
  else 
  mode = 0; /*interactive*/
  hsh(argc, argv, mode); 

  return (0);
}