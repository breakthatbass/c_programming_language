#include <stdio.h>
#define MAXLINE 1000

int myGetline(char line[], int maxline);
void reverse(char s[]);

int main()
{
  char line[MAXLINE];
  
  while (myGetline(line, MAXLINE) > 0)
  {
    reverse(line);
    printf("%s\n", line);
  }
  return 0;
}

int myGetline(char s[], int lim)
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

void reverse(char s[])
{
    int temp, i;
    int count = 0;

    i = 0;
    while(s[i] != '\n') {
        count++;
        i++;
    }
    
    i = 0;
    while (i < count) {
        temp = s[i];
        s[i] = s[count];
        s[count] = temp;
        i++;
        count--;
    }
}