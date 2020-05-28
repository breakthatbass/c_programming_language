#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  int i;

  max = 0;
  while ((len = get_line(line, MAXLINE)) > 0)
  {

    if (len > max) {
      max = len;
      copy(longest, line);
    }

    // loop backwards from end of array to get rid of trailling spaces and tabs
    for (i = len; i >= 0; i--) {
        if (line[i] == ' ' || line[i] == '\t') {
            line[i] = '\0';
        }
        else if (line[i] == '\n' || line[i] == '\0') {
            continue;
        }
        else {
            break;
        }
    }

    if (max > 0) {
      printf("length: %d\n%s", i + 1, line);
    }
  }
  return 0;
}

int get_line(char s[], int lim)
{
  int c, i;

  for (i=0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
  {
    s[i] = c;
  }

  if (c == '\n') {
    s[i] = c;
    i++;
  }

  s[i] = '\0';

  return i;
}

void copy(char to[], char from[])
{
  int i;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }

}
