#include <stdio.h>
/* *
 * Exercise 7-7: Modify the pattern finding program of Chapter 5
 * to take its input from a set of named files or, if no files are
 * named as arguments, from the standard input.
 * */

#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

static void find_pat(FILE *, char *, int, int);
static int get_line(char *, int);

int main(int argc, char **argv)
{
    char pattern[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0;
    FILE *fp;

    while (--argc > 0 && (*++argv)[0] == '-')
        while ((c = *++argv[0]))
            switch(c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    break;
            }
    if (argc >= 1)
        strcpy(pattern, *argv);
    else {
        printf("usage: find -x -n pattern [file ...]\n");
        exit(1);
    }
        if (argc == 1) // no file, stdin instead
            find_pat(stdin, pattern, except, number);
        else 
            while (--argc > 0)  // file(s) given, this will open as many files as provided
                if ((fp = fopen(*++argv, "r")) == NULL) {
                    fprintf(stderr, "can't open file\n");
                    exit(1);
                } else {
                    find_pat(fp, pattern, except, number);
                    fclose(fp);
                }
    return 0;
}

static void find_pat(FILE *fp, char *pattern, int except, int number)
{
    char line[MAXLINE];
    long lineno;

    while (fgets(line, MAXLINE, fp) != NULL) {
        ++lineno;
        if ((strstr(line, pattern) != NULL) != except) {
            if (number)
                printf("%ld: ", lineno);
            printf("%s", line);
        }    
    }
}


static int get_line(char *line, int max)
{
    if (fgets(line, max, stdin) == NULL)
        return 0;
    else
        return strlen(line);    
}