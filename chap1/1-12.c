/*

  chapter 1: exercise 12

  write a program that prints its input one word per line

*/

#include <stdio.h>

int main ()
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t') {
      c = '\n';
    }
    putchar(c);
  }
}
