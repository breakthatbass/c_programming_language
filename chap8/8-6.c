/**
 * exercise 8-6: the standard library function calloc(n, size) returns
 * a pointer to n objects of size size, with storage initialized to zero.
 * write calloc, by calling malloc or by modifying it.
 * 
 * compile with make calloc
 * run with ./calloc
 * */

#include "malloc.h"

void *_calloc(unsigned n, unsigned size)
{
    int bytes, i;
    char *p;    // pointer to return, first location
    char *z;    // pointer used to set the zeros

    bytes = size * n;
    p = z = _malloc(bytes);
    if (p == NULL) 
        return NULL;
    
    // initialize the zeros
    for (i = 0; i < bytes; i++)
        *z++ = 0;

    return p;
}


#include <stdio.h>
#include <string.h>

int main()
{
    char *s = _calloc(15, sizeof(char));

    strcpy(s, "hello world");

    printf("%s\n", s);

    _free(&s);
}
