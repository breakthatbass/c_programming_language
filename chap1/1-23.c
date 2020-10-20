/**
 * exercise 1-23: write a program to remove all comments from a C program
 * */

#include <stdio.h>

#define IN  0
#define OUT 1

int main()
{
    int c;
    int last_c;     // keep track of the previous char
    int state;      // keep track of being in a comment or not


    while ((c = getchar()) != EOF) {
        // if in a comment, continue unless we encounter a new line
        if (state == IN)  {
            if (c != '\n') 
                continue;
            else {
                // new line detected
                putchar('\n');
                state = OUT;
            }
        }
            
        if (c == '/' && last_c == '/') {
            // in a // comment
            state = IN;
            continue;
        }
        else if (c == '*' && last_c == '/') {
            // in a /* comment
            state = IN;
            continue;
        }
        else if (c == '/') 
            last_c = c;

        else {
            putchar(c);
            last_c = c;
        }
    }
    return 0;
}