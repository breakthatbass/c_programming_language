/**
 * Exercise 5-11: Modify the programs entab and detab to accept
 * a list of tab stops as arguments. Use the default tab settings
 * if there are no arguments.
 * */

#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 500

void detab(char *s, int lim)
{
    int c, i;
    int tab = 5;

    while ((c = getchar()) != EOF)
    {
        // if \t then replace with ' ' for amount of spaces tab is
        if (c == '\t')
        {
            for (i = 0; i < lim; i++) {
                c = ' ';
                putchar(c);
                *s++ = c;
            }
        }
        // else just putchar() normal way
        else 
            putchar(c);
            *s++ = c;
    }
    *s = '\0';
}

int main(int argc, char *argv[])
{
    int tab, i;
    char s[MAXLINE];

    if (argc == 1) 
        tab = 5;
    else if (argc == 2)
        tab = atoi(*++argv);
    else {
        printf("usage: ./detab n...\n");
        return 1;
    }
    
    detab(s, tab);

    return 0;
}
