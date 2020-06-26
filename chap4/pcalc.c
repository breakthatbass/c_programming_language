/*
  chapter 4: exercise 4-3, 4-4, 4-5, 4-6, 4-7, 4-8, 4-9, 4-10

  given the basic framework, it's straightforward to extend the calculator.
  add the modulus (%) operator and provisions for negative numbers...

  currently working on: 4-4, duplicate
*/

#include <stdio.h>
#include <stdlib.h> 
#include <math.h>  

#define MAXOP   100     // max size of operand or operator
#define NUMBER  '0'     // signal that a number was found

int getop(char []);
void push(double);
double pop(void);
void printtop();

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '#':  // print top of stack without popping
                printtop();
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
            case '%':
                op2 = pop();
                if (op2 != 0.0) {
                    // push(((int)pop()) % ((int)op2));
                    push(fmod(pop(), op2));
                } else {
                    printf("error: zero divisor\n");
                }
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
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

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t') {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-') {
        return c;  // not a number
    }
    i = 0;

    if (c == '-') {
      if (isdigit(c = getch()) || c == '.') {
        s[++i] = c; // neg number
      } else {
        if (c == EOF) {
          ungetch(c);
        }
        return '-';
      }
    }

    if (isdigit(c)) {       // collect integer part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    if (c == '.') {         // collect fraction part
        while (isdigit(s[++i] = c = getch())) {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];      // buffer for ungetch
int bufp = 0;           // next free position in buf

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters\n");
    } else {
        buf[bufp++] = c;
    }
}

void printtop()
{
  if (sp > 0) {
    printf("top: %f\n", val[sp - 1]);
  } else {
    printf("stack empty\n");
  }
}
