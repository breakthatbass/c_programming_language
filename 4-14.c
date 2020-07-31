/**
 * 
 * Exercise 4-14: define a macro swap(t,x,y) that interchanges two arguments of type t
 * 
 * */

#include <stdio.h>

#define swap(t,x,y) {t tmp = x; x = y; y = tmp; }

int main()
{
    int m = 5;
    int n = 2;
    swap(int, m, n);

    printf("%d, %d\n", m, n);

    return 0;
}