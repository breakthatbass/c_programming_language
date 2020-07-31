/**
 * 
 * Exercise 5-1: As written, getint trats a + or - not followed by a digit as a 
 * valid representation of zero. Fix it to push such a character back onto the input
 * 
 * */

#include <stdio.h>
#include <ctype.h>
//#include "getch.h"

#define SIZE 20

int getch(void);
void ungetch(int);

int getint(int *pn)
{
    int c, sign;

    while(isspace(c = getch()))     // skip white space
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);     // not a number
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        c = getch();
        if (!isdigit(c)) {
            int sign_check = sign == 1 ? '+' : '-';
            ungetch(sign_check);
            return 0;
        }
    }
    for (*pn = 0; isdigit(c); c = getch()) {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int main()
{
    int n, i, array[SIZE], getint(int *);

    for (i = 0; i < SIZE; i++) {
        array[i] = 0;
    }

    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;

    array[++n] = '\0';
    for (i = 0; array[i] != '\0'; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
    return 0;
}