/**
 * Exercise 5-18: Make dcl recover from input errors
 * 
 * compile with:
 *      gcc 5-18.c getch.c
 * */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100
#define DTYPE_LEN 6

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

int check_type(char *s);

int gettoken(void);
int tokentype;              // type of last token
char token[MAXTOKEN];       // last token string
char name[MAXTOKEN];        // indentifier name
char datatype[MAXTOKEN];    // data type = char, int, etc.
char out[1000];             // output string

int main()
{
    while (gettoken() != EOF) {     // first token on line
        strcpy(datatype, token);    // is the datatype
        if (!check_type(datatype)) {
            printf("error: data type not recognized\n");
            return 1;
        }
        out[0] = '\0';
        dcl();
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}

int gettoken(void)
{
    int c;// getch(void);
   // void ungetch(int);
    char *p = token;

    while ((c = getch()) == ' ' || c == '\t')
        ;
    if (c == '(') {
        if ((c = getch()) == ')') {
            strcpy(token, "()");
            return tokentype = PARENS;
        } else {
            ungetch(c);
            return tokentype = '(';
        }
    } else if (c == '[') {
        for (*p++ = c; (*p++ = getch()) != ']'; )
            ;
        *p = '\0';
        return tokentype = BRACKETS;
    } else if (isalpha(c)) {
        for (*p++ = c; isalnum(c = getch()); )
            *p++ = c;
        *p = '\0';
        ungetch(c);
        return tokentype = NAME;
    } else
        return tokentype = c;
}


// dcl: parse a declarator
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*'; )   // count *'s
        ns++;
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}


// dirdcl: parse a direct declarator
void dirdcl(void)
{
    int type;

    if (tokentype == '(') {
        dcl();
        if (tokentype == ')')
            printf("error: missing )\n");
    } else if (tokentype == NAME)
        strcpy(name, token);
    else 
        printf("error: expected name of (dcl)\n");
    while ((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}

int check_type(char *s)
{
    char *types[DTYPE_LEN] = {"char", "int", "float", "double", "long", "short"};

    for (int i = 0; i < DTYPE_LEN; i++)
        if (strcmp(s, types[i]) == 0)
            return 1;
    return 0;
}