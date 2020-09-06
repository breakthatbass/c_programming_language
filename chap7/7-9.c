/*
 * Exercise 7-9: Functions like isupper can be implemented to save
 * space or to save time. Explore both possibilities.
 */

#include <stdio.h>

// macro functions save time but apparently use more space,
// however, it's important to notice that I didn't have
// to define the data type it returns nor the data types
// of the parameters
#define is_up(s) (s >= 'A' && s <= 'Z') ? 1 : 0

// normal function format
// saves space but takes more time
// ...but not much more time in this case
int is_upper(char s)
{
    if (s >= 'A' && s <= 'Z') 
        return 1;
    else
        return 0;
}

int main()
{
    char *t = "Hello";
    char *z = "hello";

    printf("testing normal function...\n");
    printf("%s is upper? %d\n", t, is_upper(t[0]));
    printf("%s is upper? %d\n", z, is_upper(z[0]));
    
    printf("testing macro function...\n");
    printf("%s is upper? %d\n", t, is_up(t[0]));
    printf("%s is upper? %d\n", z, is_up(z[0]));
    return 0;
}
