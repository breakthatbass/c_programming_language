/******************************************

Exercise 21

Write a program entab that replaces strings of blanks by the minimum number
of tabs and blanks to achieve the same spacing. Use the same tab stops as for
detab. When either a tab or a single blank would suffice to reach a tab stop,
which should be given preference?

******************************************/
#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline);
void entab(char s[]);

int main()
{

  char line[MAXLINE];

  while (myGetline(line, MAXLINE) > 0)
  {
    entab(line);
    printf("%s\n", line);
  }
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

void entab(char s[])
{
  int len, i, p, c, max;

  int tab = 3;
  int space = 1;
  int space_count = 0;
  int tab_count = 0;

  i = 0;
  while ((to[i] = from[i]) != '\0') {
    i++;
  }

  for (p = 1; (c = getchar()) != EOF; p++)
  {
    if (line[i] == ' ') {
      space_count++;
    }
    if (line[i] == '\t') {
      tab_count++;
    }

}
