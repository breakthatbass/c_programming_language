#include <stdio.h>
#define N 20    /* column to move to next line */

int main () {

  int c, i;

  i = 0;
// get input with getchar()
  while ((c = getchar()) != EOF)
  {
    if (i == N - 1)
    {
        putchar(c);
        putchar('\n');
    }
    else {
      putchar(c);
    }
    i++;
    // if i reaches N, reset to 0 to be able to fold very long lines
    if (i == N) {
      i = 0;
    }
  }
}
