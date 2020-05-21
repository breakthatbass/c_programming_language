/*
  chapter 2: exercise 2-10

  rewrite the function, lower(), which converts uppercase letters
  to lower case, with a condtional expression istead of if-else.

*/
#include <stdio.h>

int lower(int c)
{
  return (c = (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c);
}

int main()
{


  printf("%c", lower('H'));
  printf("%c", lower('E'));
  printf("%c", lower('L'));
  printf("%c", lower('L'));
  printf("%c", lower('O'));
  printf("%c", lower(' '));
  printf("%c", lower('W'));
  printf("%c", lower('O'));
  printf("%c", lower('R'));
  printf("%c", lower('L'));
  printf("%c\n", lower('D'));

  return 0;
}
