/******************************************************************************

created by Taylor Gamache
Mar 19, 2020

exercise 1-8
write a program to count blanks, tabs, and newlines

******************************************************************************/

#include <stdio.h>

int main()
{
  int c;
  int blanks, nl, tabs = 0;

  while ((c = getchar()) != EOF)
  {
    // check for new lines
    if (c == '\n'){
      nl++;
    }
    if (c == ' ')
    {
      blanks++;
    }
    if (c == '\t')
    {
      tabs++;
    }
  }
  printf("blanks: %d\nnew lines: %d\ntabs: %d\n", blanks, nl, tabs);
}
