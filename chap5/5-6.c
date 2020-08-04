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
#include <string.h>

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

void reverse(char *s)
{
    char *t = s + strlen(s) - 1;
    int c;

    while (s < t) {
        c = *s;
        *s = *t;
        *t = c;
        s++;
        t--;
    }
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
void itoa(int n, char *s)
{
    int sign;
    char *t = s;
    if ((sign = n) < 0)
        n = -n;

    do {    // generate digits in reverse order
        *s++ = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0) 
        *s++ = '-';
    *s = '\0';
    reverse(t);
}

// return index of t in s, -1 if none
// come back to this. doesn't work 100%
int strindex(char *s, char *t)
{
    int in = -1;
    int count = 0;
    // go through each character and compare
    int i = 0;
    while (*s != '\0') {
        if (*s == *t) {
            t++;
            in = i;
            count++;
        }
        i++;
        s++;
    }
    if (count == 0)
        return -1;
    return in - (count-1);
}


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
    printf("atoi: %d\n", n);

    // reverse tests
    char s[MAXLINE] = "hello";
    reverse(s);
    printf("reverse: %s\n", s);

    // itoa tests
    int num = 123;
    char numstr[MAXLINE];
    itoa(num, numstr);
    printf("itoa: %s\n", numstr);

    char *hi = "hello";
    int hindex = strindex(hi, "e");
    printf("strindex: %d\n", hindex);

    return 0;
}

