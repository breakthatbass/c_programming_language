/**
 * Exercise 5-11: Modify the programs entab and detab to accept
 * a list of tab stops as arguments. Use the default tab settings
 * if there are no arguments.
 * */

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXLINE 1000

void get_line(char *s)
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\n') {
            *s++ = '\0';
            return;
        }
        *s++ = (char)c;
    }
    *s++ = '\0';
}

void entab(char *s, char *t, int tabs)
{
    int spaces = 0;
    int back;

    while (*s != '\0') {
        back = tabs;

        if (*s == ' ')
            spaces++;
        else
            spaces = 0;
        printf("spaces: %d\n", spaces);
        if (spaces == tabs) {
            while (back-- > 1)
                *t--;
            *t++ = '\t';
            spaces = 0;
        } else
            *t++ = *s++;
    }
    *t++ = '\0';
}

int main(int argc, char **argv)
{
    int tabs;

    if (argc == 1)
        tabs = 4;
    else if (argc == 2)
        tabs = atoi(*++argv);
    else
    {
        printf("usage: ./entab tabs\n");
        return 1;
    }

    char s[MAXLINE];
    char t[MAXLINE];

    get_line(s);
    entab(s, t, tabs);
    
    printf("s: %s\n", s);
    printf("t: %s\n", t);
    
  
    return 0;
}

