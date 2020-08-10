/**
 * exercise 5-10: Write the program expr, which evaluates a reverse 
 * Polish expression from teh command line, where each operator 
 * or operand is a separate argument.
 **/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>  
#include <ctype.h>

#define MAXOP   100     // max size of operand or operator
#define NUMBER  '0'     // signal that a number was found

int getop(char*, int, char**);
void push(double);
double pop(void);

int main(int argc, char *argv[])
{

    if (argc == 1) {
        printf("Arguments required\n");
        printf("usage: n n + -\n");
        return 1;
    }

    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s, --argc, ++argv)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push((pop()) + (pop()));
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    printf("%g\n", pop());
    return 0;
}

#define MAXVAL 100      // max depth of val stack

int sp = 0;             // next free stack position
double val[MAXVAL];     // value stack

void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("error: stack full, can't push %g\n", f);
    }
}

double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char *s, int argc, char *argv[])
{
    int c;
    char *a = *argv;

    if (argc == 0) {
        return EOF;
    }

    while ((*s = c = *a++) == ' ' || c == '\t')
        ;
    
    *++s = '\0';

    if (!isdigit(c) && c != '.')
		return c;

	if (isdigit(c))
		while (isdigit(*s++ = c = *a++))
			;


	if (c == '.')
		while (isdigit(*s++ = c = *a++))
			;

	*s = '\0';

	return NUMBER;
}
