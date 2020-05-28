/******************************************

Exercise 21

Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for
detab. When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference?

note: this program is buggy.

******************************************/
#include <stdio.h>

#define TAB 4

int main()
{
  int c, i, tabs, blanks;
  tabs = blanks = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (blanks % TAB == 0) {
        tabs++;
        blanks = 0;
      }
      else {
        blanks++;
      }
    }
    else {
      while (tabs > 0) {
        putchar('\t');
        tabs--;
      }
      if (c == '\t') {
        tabs = 0;
      }
      else {
        while (blanks > 0) {
          putchar(blanks);
          blanks--;
        }
      }
      putchar(c);
    }
  }
return 0;
}
