/**
 * 
 * Exercise 5-3: write a pointer version of the function strcat that we showed in chapter 2.
 * strcat(s, t) copies the string t to the end of s.
 * 
 * */

#include <stdio.h>
#include <stdlib.h>

void stcat(char *s, char *t)
{
    int i, j;

    i = j = 0;
    while(*(s+i) != '\0') {   // find end of s
        i++;
    }
    while (( (*(s+(i++)) = *(t+(j++)) )) != '\0') {     // copy
        ;
    }
}

int main()
{
    
    char str1[20] = "hello";
    char *str2 = "world";

    stcat(str1, str2);

    printf("%s\n", str1);
    
    return 0; 
}

