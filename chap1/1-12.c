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
