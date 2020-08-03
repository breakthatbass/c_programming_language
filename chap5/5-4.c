/**
 * 
 * Exercise 5-4: Write the function strend(s, t), which returns 1 if the string
 * t occurs at the end of the string s, and zero otherwise.
 * 
 * */

#include <stdio.h>
#include <string.h>


int strend(char *s, char *t)
{
    // locations for first elements of strings
    char *s_first = s;
    char *t_first = t;

    // go to end of strings
    while (*s)
        s++;
    while (*t)
        t++;

    // compare each character working backwards
    while ((*s-- == *t--) && s != s_first && t != t_first)
        ;
    if (t == t_first)
        return 1;
    else
        return 0;
}

int main()
{

    char *str1 = "goodbye";
    char *str2 = "bye";

    char *str3 = "hello";
    char *str4 = "bye";

    printf("%d\n", strend(str1, str2));  // returns 1
    printf("%d\n", strend(str3, str4));  // returns 0

    return 0;
}