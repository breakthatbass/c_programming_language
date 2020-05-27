/*
  chapter 1: Exercise 1-6
  Verify that the expression getchar() != EOF is 0 or 1
*/

#include <stdio.h>

int main()
{
  int c;

  c = getchar() != EOF;

  if (c == 1 || c == 0)
  {
    printf("c is either 0 or 1");
  }
  return 0;
}
