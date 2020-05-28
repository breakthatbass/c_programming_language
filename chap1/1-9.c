/*

  chapter 1: exercise 1-9

  write a program to copy its input to its output, replacing each
  string of one or more blanks by a single blank.

*/

#include <stdio.h>

int main ()
{
  int c;
  int last_c; // set c to a global varible to keep track of previous c in each iteration

  while ((c = getchar()) != EOF)
  {
    if (last_c == ' ' && c == ' ') {
      ;  // do nothing if there are more than one spaces
    }
    else {
      putchar(c);
    }
    last_c = c;
  }
}
