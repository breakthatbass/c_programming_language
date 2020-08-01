/**
 * Exercise 5-2: write getfloat, the floating point analog of getint.
 * 
 * buggy....
 * */


#include <stdio.h>
#include <ctype.h>

#define SIZE 20

int getch(void);
void ungetch(int);

int getfloat(float *pn)
{
    int c, sign;
    float power;

    while(isspace(c = getch()))     // skip white space
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
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
    for (*pn = 0.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
    }
    if (c == '.') {
        c = getch();
    }
    for (power = 1.0; isdigit(c); c = getch()) {
        *pn = 10.0 * *pn + (c - '0');
        power *= 10;
    }
    *pn *= sign/power;
    if (c != EOF) {
        ungetch(c);
    }
    return c;
}

int main()
{
    int n, i, getfloat(float *);
    float array[SIZE];

    for (i = 0; i < SIZE; i++) {
        array[i] = 0.0;
    }

    for (n = 0; i < SIZE && getfloat(&array[n]) != EOF; n++)
        ;

    array[++n] = '\0';
    for (i = 0; array[i] != '\0'; i++) {
        printf("%g", array[i]);
    }
    printf("\n");
    return 0;
}