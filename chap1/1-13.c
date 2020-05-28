/*

  chapter 1: exercise 1-13

  write a program to print a histogram of the lengths of words in its input.
  it is easy to draw the histogram with the bars horizontal;  vertical
  orientation is more challenging.

*/

#include <stdio.h>

int main ()
{
  int c;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\t' ||c == '\n') {
      putchar('\n');
    }
    else {
      putchar('#');
    }
  }
  return 0;
}
