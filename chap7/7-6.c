/* *
 * Exercise 7-6: Write a program to compare two files, printing the first
 * line where they differ.
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 500

void filecmp(FILE *fp1, FILE *fp2)
{
    char s1[MAXLINE], s2[MAXLINE];  // arrays used to store each line
    int line = 1;                   // keep track of file lines

    while ((fgets(s1, MAXLINE, fp1)) != '\0' 
            && (fgets(s2, MAXLINE, fp2)) != '\0') {
        if (strcmp(s1, s2) != 0) {
            printf("file 1, line %d: %s\n", line, s1);
            printf("file 2, line %d: %s\n", line, s2);
            exit(0);
        }
        line++;
    }
}

int main(int argc, char **argv)
{
    char *f1, *f2; 
    FILE *fp1, *fp2; 

    // requires two files
    if (argc != 3){
        fprintf(stderr, "error: requires two files for comparison\n");
        exit(1);
    }

    f1 = argv[1];   // first arg
    f2 = argv[2];   // ...

    // open them and check for errors
    fp1 = fopen(f1, "r");
    fp2 = fopen(f2, "r");
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "error: problem with file(s)\n");
        exit(2);
    }

    // compare them
    filecmp(fp1, fp2);

    fclose(fp1); 
    fclose(fp2); 

    exit(0); 
}