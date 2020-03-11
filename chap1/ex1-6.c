/*
  Exercise 1-7
  Write a program to print the value of EOF
*/

#include <stdio.h>

int main()
{
  int c;

  while ((c = getchar()) != EOF)
    if (EOF == 1 || EOF == 0)
    {
      printf("EOF = 1 or 0\n");
    }
    else
    {
      putchar(c);
    }
}
