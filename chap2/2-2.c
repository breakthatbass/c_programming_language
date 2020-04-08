/*

Exercise 2-2

for (i = 0; i < lim - 1 && (c=getchar()) != EOF; i++)

Write a loop equivelent to the for loop above without using && and ||

*/

#include <stdio.h>

enum loop = { NO, YES };
enum loop keep_going = YES;

int main ()
{
  int i = 0;
  while (keep_going == YES)
  {
    if (i >= lim -1) {
      keep_going = NO;
    }
    else if ((c = getchar() == '\n')) {
      keep_going = NO;
    }
    else {
      s[i] = c;
      i++;
    }
  }
}
