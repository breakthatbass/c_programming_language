/* *
 * Exercise 7-2: Write a program that will print arbitrary input
 * in a sensible way. As a minimum, it should print non-graphic 
 * characters in octal or hexidecimal according to local custom,
 * and break long text lines.
 * */

#include <stdio.h>
#include <ctype.h>

int main()
{
    int c;

    while ((c = getchar()) != EOF)
        if (iscntrl(c) || c == ' ') {
            printf(" \\%03o ", c);

            if (c == '\n') 
                putchar('\n');
        } else
            putchar(c);
    return 0;
}
