/*

  chapter 1: exercise 1-22

  write a program to "fold" long input lines into two or more shorter lines
  after the last non-blank character that occurs before the n-th column of
  input. make sure you program does something intelligent with very long
  lines, and if there are no blanks or tabs before the specified column.

*/

#include <stdio.h>
#define N 20    /* column to move to next line */

int main () {

  int c, i, blanks;

  i = blanks = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ') {
      blanks++;
    }
    if (i >= N - 1)
    {
        putchar(c);
        if (c == ' ' || c == '\t') {
          putchar('\n');
          i = 0;
          blanks = 0;
        }
        else if (blanks == 0) {
          putchar('\n');
          i = 0;
        }
    }
    else {
      putchar(c);
    }
    i++;
  }
}
