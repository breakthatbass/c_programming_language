/*

  chapter 1: exercise 10

  write a program to copy its input to its output, replacing each tab by \t,
  each backspace by \b and each backslash by \\. this makes tabs and
  backspaces visible in an unambiguous way.

*/

#include <stdio.h>

int main ()
{
  int c;
  while ((c = getchar()) != EOF)
  {
    if (c == '\t')
    {
      putchar('\\');
      c = 't';
    }
    else if (c == '\b')
    {
      putchar('\\');
      c = 'b';
    }
    else if (c == '\\')
    {
      putchar('\\');
      c = '\\';
    }
    putchar(c);
  }
}
