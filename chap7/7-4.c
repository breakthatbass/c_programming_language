/* *
 * Exercise 7-4: Write a private version of scanf analogous to minprintf
 * from the previous section
 * */

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int c;
    FILE *fp;

    fp = fopen("test.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "error: problem with file\n");
        exit(1);
    }
    

    while ((c = getc(fp)) != EOF) {
        putc(c, stdout);
    }

    fclose(fp);
    return 0;
}
