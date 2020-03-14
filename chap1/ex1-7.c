/*
  Exercise 1-7
  Write a program to print the value of EOF
*/

#include <stdio.h>

int main()
{
  int c;

  c = getchar() != EOF;

  printf("%i\n", EOF);

  if (c == 1 || c == 0)
  {
    printf("%d\n", c);
  }
  return 0;
}
