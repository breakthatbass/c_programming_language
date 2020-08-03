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

int main()
{
    char *str1 = "hello";
    char str2[MAXLEN];

    strncopy(str2, str1, 2);

    printf("%s\n", str2);

    return 0;
}
