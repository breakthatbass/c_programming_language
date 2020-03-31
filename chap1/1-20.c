/**************************

Exercise 1-20

Write a program detab that replaces tabs in the input with the proper number
of blanks to space to the next tab stop. Assume a fixed set of tab stops, say,
every n columns. Should n be a variable or symbolic parameter?

**************************/

#include <stdio.h>

int main () {

  int c, i;
  int tab = 3;

// get input with getchar()
  while ((c = getchar()) != EOF)
  {
    // if \t then replace with ' ' for amount of spaces tab is
    if (c == '\t')
    {
      for (i = 0; i < tab; i++) {
        putchar(' ');
      }
    }
    // else just putchar() normal way
    else {
      putchar(c);
    }
  }
}
