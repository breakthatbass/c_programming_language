/*
  chapter 3: exercise 3-3

  write a function 'expand(s1, s2)' that expands shorthand notations like
  a-z in the string s1 into the equivalent complete list abc...xyz in s2.
  allow for letters of either case and digits, and be prepared to handle
  cases like a-b-c and a-z0-9 and -a-z. arrange that a leading or trailing
  '-' is taken literally.
*/

#include <stdio.h>

void expand(char s1[], char s2[])
{
  char c;
  int i, j;
  for (i = j = 0; (c = s1[i++]) != '\0'; )
  {
    // check next character for a '-'
    // then check char after that
    if (s1[i] == '-' && s1[i + 1] >= c)
    // if it can indeed be expanded, do it
    {
      i++;
      while (c <= s1[i])
      {
        s2[j] = c;
        j++;
        c++;
      }
    }
    else
    {
      // otherwise just copy the character
      s2[j] = c;
      j++;
    }
  }
  // mark the end of the array
  s2[j] = '\0';
}


// tests
int main()
{
  char s1[] = "a-b-c";
	char s2[1000];
	expand(s1, s2);
	printf("%s\n", s2);

	char s[] = "0-9";
	char t[1000];
	expand(s, t);
	printf("%s\n", t);

  char m[] = "0-Z";
	char b[1000];
	expand(m, b);
	printf("%s\n", b);

  char more[] = "-a-z -1-1 hello0-9-";
	char evenmore[1000];
	expand(more, evenmore);
	printf("%s\n", evenmore);

  return 0;
}
