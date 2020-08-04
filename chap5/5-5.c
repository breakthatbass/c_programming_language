/*
 * 
 * Exercise 5-5: Write versions of the library functions strncpy, strncat, and strncmp,
 * which operate on at most the first n characters of their argument strings.
 * For example, strncpy(s,t,n) copies at most n characters of t to s.
 * Full descriptions are in Appendix B.
 * 
 */
#include <stdio.h>
#include <string.h>

#define MAXLEN 20

/* copy at most n characters of string t to s; return s.
 * pad with '\0's if t has fewer than n characters. */
void *strncopy(char *s, char *t, int n)
{
    int t_len = strlen(t);
    int i;

    if (t_len <= n) {
        while ((*s++ = *t++)) 
            ;
    } else {
        i = 1;
        while((*s++ = *t++) && i < n) {
            i++;
        }
        for ( ; i <= n; i++) {
            *s++ = '\0';
        }
    }
    return s;
}

/* concatinate at most n characters of string t to string s,
 * terminate s with '\0'; return s */

char *strncatt(char *s, char *t, int n)
{
    char *tmp = s;

    while (*++tmp) 
        ;

    while (n > 0 && t != '\0') {
        *tmp++ = *t++;
        n--;
    }
    
    *tmp = '\0';
    return s;
}

/* compare at most n characters of string s to string t;
 * return < 0 if s<t, 0 if s == t, or > 0 if s>t. */
// int strncmp(char *s, char *t, int n)
int strncomp(char *s, char *t, int n)
{
    for ( ; *s == *t && n > 0; s++, t++, n--)
        if (*s == '\0')
            return 0;

    if (n == 0)
        return 0;

    return *s - *t;
}


int main()
{
    // strncopy tests
    char *str1 = "hello";
    char str2[MAXLEN];
    strncopy(str2, str1, 2);
    printf("strncpy: %s\n", str2);

    // strncat tests
    char h[100] = "hello";
    char *w = " world";
    char *hw = strncatt(h, w, 3);
    printf("strncat: %s\n", hw);

    // strncmp tests
    char *cflr = "cauliflower";
    char *cldn = "cauldron";
    int test1 = strncomp(cflr, cldn, 4);
    int test2 = strncomp(cflr, cldn, 7);
    printf("strncmp: 1: %d; 2: %d\n", test1, test2);

    return 0;
}
