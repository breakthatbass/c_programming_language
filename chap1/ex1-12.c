#include <stdio.h>

#define IN 1
#define OUT 2

int main()
{
  int c, state;
  state = OUT;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      putchar('\n');
    }
    else
    {
      puthar(c);
    }
  }

}
