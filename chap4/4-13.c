/*
  write a recursive version of the function reverse(s), which reverses a string in place.
*/
#include <stdio.h>
#include <string.h>

void swap(char s[], int i, int j)
{
	char tmp = s[j];
	s[j] = s[i];
	s[i] = tmp;
}

void reverse(char s[], int l, int r)
{
    if (l >= r) {
      return;
    }
    swap(s, l, r);
    ++l, --r;
    reverse(s, l, r);
}

// tests
int main()
{
    char one[] = "hello world";
    char two[] = "It's a beautiful day today";

    printf("orignal string: %s\n", one);
    reverse(one, 0, strlen(one) - 1);
    printf("reversed string: %s\n", one);
    printf("orignal string: %s\n", two);
    reverse(two, 0, strlen(two) - 1);
    printf("reversed string: %s\n", two);

    return 0;
}
