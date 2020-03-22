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
