#include <stdio.h>
#include <string.h>

/*
  chapter 2: exercise 2-5

  write a function, any(s1, s2), which returns the first location
  in the string s1 where any character from the string s2 occurs, or -1
  if s1 contains no characters from s2.
*/

int any(char s1[], char s2[])
{
  int i, j;
  int s1len = strlen(s1);
  int s2len = strlen(s2);
  // loop through s1
  for (i = 0; i < s1len; i++) {
    // loop through s2
    for (j = 0; j < s2len; j++) {
      if (s1[i] == s2[j]) {
        return i;
      }
    }
  }
  return -1;
}

int main()
{

  char *str1 = "billy";
  char *str2 = "tony";

  int check_strs = any(str1, str2); // returns 4
  printf("%d\n", check_strs);

  char *caviar = "caviar";
  char *hotdog = "hotdog";

  int food_check = any(caviar, hotdog); // returns -1
  printf("%d\n", food_check);
  return 0;
}
