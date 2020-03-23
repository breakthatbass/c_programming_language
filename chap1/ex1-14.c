#include <stdio.h>

int main()
{
    int letters[26];
    int c, i, j;

    for (i = 0; i <= 26; i++)
    {
        letters[i] = 0;
    }

    while((c = getchar()) != EOF)
    {
        if (c >= 'a' && c <= 'z')
        {
            letters[c - 'a']++;
        }
    }
    for (i = 0; i <= 26; i++)
    {
        printf("%c: ", 'a' + i);
        for (j = 0; j < letters[i]; j++)
        {
            putchar('#');
        }
        putchar('\n');
    }
}