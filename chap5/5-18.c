#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "getch.h"

#define MAXTOKEN 100

enum { NAME, PARENS, BRACKETS };

void dcl(void);
void dirdcl(void);

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
        out[0] = '\0';
        dcl;
        if (tokentype != '\n')
            printf("syntax error\n");
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}