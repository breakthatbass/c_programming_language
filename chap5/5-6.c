/*
 * 
 * Exercise 5-6: rewrite appropriate programs from earlier chapters and exercises
 * with pointers instead of array indexing. Good possibilities include
 * getline (chapters 1 and 4), atoi, itoa, and their variants 
 * (chapters 2, 3, and 4), reverse (chapter 3), and strindex and getop (chapter 4)
 * 
 */

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

// read a line into s, return length (pointer version)
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

// convert s to integer
int _atoi(char *s)
{
    int i, n;

    n = 0;
    for (i = 0; isdigit(*s); ++s, ++i)
        n = 10*n + (*s - '0');
    return n;
}

// convert n to characters in s



int main()
{
    /*
    char line[MAXLINE];
    int n = get_line(line, MAXLINE);
    printf("%d\n", n);
    */

   // atoi tests
   char *i = "25";
   int n = _atoi(i);
   printf("%d\n", n);

    return 0;
}

