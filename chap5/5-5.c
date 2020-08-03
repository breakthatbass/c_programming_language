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

// BUGGY
char *strncatt(char *s, char *t, int n)
{
    int i = 0;
    // go to end of t
    while (i < strlen(s))
        *s++;

    i = 0;
    while ((*s++ = *t++) && i < n)
        i++;

    *s++ = '\0';
    return s;
}

/* compare at most n characters of string s to string t;
 * return < 0 if s<t, 0 if s == t, or > 0 if s>t. */
// int strncmp(char *s, char *t, int n)


int main()
{
    char *str1 = "hello";
    char str2[MAXLEN];

    strncopy(str2, str1, 2);

    printf("strncpy: %s\n", str2);

    char h[MAXLEN] = "hello";
    char w[MAXLEN] = " world";

    printf("%d\n", strlen(h));
    
    strncatt(h, w, 2);

    printf("strncat: %s\n", w);

    return 0;
}
