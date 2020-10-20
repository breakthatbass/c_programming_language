/*

  chapter 1: exercise 12

  write a program that prints its input one word per line

*/

#include <stdio.h>

#define IN 1
#define OUT 0

int main ()
{
  int c, state;
  state = OUT;

  while ((c = getchar()) != EOF)
  {
    if (c == ' ' || c == '\n' || c == '\t') {
			if (state == IN) {  // reached the end of word
        putchar('\n');
        state = OUT;
      }
    }
    else if (state == OUT) {
      state = IN;
      putchar(c);
    } else
      putchar(c);
  }
  return 0;
}
