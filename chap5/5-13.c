/**
 * Exercise 5-13: Write the program tail, which prints the last 
 * n lines of its input. By default, n is 10, let us say, but
 * it can be changed by an optional argument, so that tail -n
 * prints the last n lines.
 * 
 * The program should behave rationally no matter how unreasonable 
 * the input or the value of n. Write the program so it makes the
 * best use of available storage; lines should be stored as in the
 * sorting program of Section 5.6, not in a two-dimensional array
 * of fixed size.
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 5000

int get_line(char *, int);

void tail(int n)
{
    char *lineptr[MAXLINES], line[MAXLEN];
    int len;
    char *p;
    int nlines = 0;

    while ((len = get_line(line, MAXLEN)) > 0) {
        p = malloc(len + 1);
        strcpy(p, line);
        lineptr[nlines++] = p;
    }
    int i = nlines - n;
    i = (i >= 0) ? i : 0;

    while (n > 0 && i < nlines) {
        printf("%s", lineptr[i++]);
        n--;
    }
}

int main(int argc, char **argv)
{
    int n;
    if (argc == 1)
		n = 10;
	else if (argc == 2 && (*++argv)[0] == '-') {
		n = atoi(*argv + 1);
		if (n < 1)
			n = 10;
	} else {
		printf("Usage: tail -n\n");
		return 1;
	}

    tail(n);

    return 0;
}

int get_line(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        *s++ = c;
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
} 
