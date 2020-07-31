
/* write a recursive version of itoa. that is, 
convert an integer into a string by calling a recursive routine */

#include <stdio.h>

void itoa(int n, char t[])
{
    int i, s;

    if (n < 0) {
        t[0] = '-';
        n = -n;
    }
    if (n / 10 > 0) {
        itoa(n/10, t);
    }
    i = 0;
    s = n;
    while((s = s / 10)) {
        i++;
    }
    if (t[0] == '-') {
        i++;
    }
    t[i++] = n % 10 + '0';
    t[i] = '\0';
}

int main()
{
    int num = 3245;
    int neg = -45;

    char m[5];
    char n[4];

    itoa(num, m);
    itoa(neg, n);

    printf("%s\n", m);
    printf("%s\n", n);

    return 0;
}