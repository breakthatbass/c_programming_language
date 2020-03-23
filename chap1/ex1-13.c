#include <stdio.h>

#define IN 0
#define OUT 1

int main() {

  int c, i, state, length, nc, wc[100];
  state = OUT;

  for (i = 0; i < 100; i++) {
    wc[i] = 0;
  }

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
      putchar('\n');
    }
    else
    {
      putchar('#');
    }
  }
  return 0;
}
