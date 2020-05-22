/*
  chapter 3: exercise 3-2

  write a function 'escape(s,t)' that converts characters like newline
  and tab into visible escape sequences like \n and \t as it copies the
  string 't' to 's'. Use a switch.

  Write a function for the other direction as well, converting escape
  sequences into the real characters.
*/

#include <stdio.h>

void escape(char s[], char t[]) // t[] is original arr, s[] is array to be copied to
{
  int i, j, sym;
  for (i = j = 0; t[j] != '\0'; i++, j++)
  {
    switch (t[j])
    {
      case '\n':
        s[i++] = '\\';
        sym = 'n';
        break;
      case '\t':
        s[i++] = '\\';
        sym = 't';
        break;
      case '\v':
        s[i++] = '\\';
        sym = 'v';
        break;
      case '\b':
        s[i++] = '\\';
        sym = 'b';
        break;
      case '\r':
        s[i++] = '\\';
        sym = 'r';
        break;
      case '\f':
        s[i++] = '\\';
        sym = 'f';
        break;
      case '\a':
        s[i++] = '\\';
        sym = 'a';
        break;
      default:
        sym = t[j];
        break;
    }
    s[i] = sym;
  }
  s[i] = '\0'; // end it
}

// tests
int main()
{
  // make empty array to copy into
  char new[1000];

  char old[] = "Hello\tWorld\nHere are some invisible symbols!\r\v";
  escape(new, old);

  printf("orginal string: %s\n", old);
  printf("escaped string: %s\n", new);

  return 0;
}
