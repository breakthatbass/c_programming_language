#include <stdio.h>
#include <string.h>

/*
  chapter 2: exercise 2-4

  write a function, squeeze(s1, s2), that deletes each character in s1
  that matches any character in s2
*/

void squeeze(char s1[], char s2[])
{
  int i, j, size;

  size = strlen(s1);
  // loop through each character in s1
  for (i = 0; i < strlen(s1); i++) {
    for (j = 0; j < strlen(s2); j++) {
      // at each element, check if s2 contains that same element.
      if (s1[i] == s2[j]) {
        // if yes, delete that element and move all elements back one
        for (int k = i; k < size; k++) {
          s1[k] = s1[k+1];
        }
        size--;
      }
    }
  }
}

int main()
{

  char str1[] = "hotdogs";
  char str2[] = "hamburgers";

  squeeze(str1, str2);
  printf("str1 is %s\nstr2 is %s\n", str1, str2);
  return 0;
}
