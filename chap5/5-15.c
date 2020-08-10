/**
 * Exercise 5-15: Add the option -f to fold upper and lower case together, 
 * so that case distinctions are not made during sorting; for example, 
 * a and A compare equal
 * */ 

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAXLINES 5000   
#define MAXLEN 1000        // manx # lines to be sorted
char *lineptr[MAXLINES];        // pointers to text lines


// PROTOTYPES *********************************
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
int get_line(char *s, int lim);

void q_sort(void *lineptr[], int left, int right, 
            int reverse, int (*comp)(void *, void *));
int numcmp(char *, char *);
int chrcmp(char *s, char *t);
// *********************************


// MAIN *********************************
int main(int argc, char *argv[])
{
    char c;
    int nlines;         // number of input lines read
    int numeric = 0;    // 1 if numeric sort
    int reverse = 0;    // 1 if reverse sort
    int fold = 0;       // 1 if sorting doesn't compare lower and upper case

    while (--argc > 0 && (*++argv)[0] == '-') 
        while((c = *++argv[0]))
            switch(c) {
                case 'n':
                    numeric = 1;
                    break;
                case 'r':
                    reverse = 1;
                    break;
                case 'f':
                    fold = 1;
                    break;
                default:
                    printf("%c is not an option!!\n", c);
                    return 1;
            }

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        // these qsort arguments are rediculous
        if (fold)
            q_sort((void **) lineptr, 0, nlines-1, reverse, (int (*)(void*, void*))chrcmp);
        else
            q_sort((void **) lineptr, 0, nlines-1, reverse, (int (*)(void*, void*))(numeric ? numcmp : strcmp));
    writelines(lineptr, nlines);
    return 0;
    } else {
        printf("input too big to sort\n");
        return 1;
    }
}
// ********************************* 


// QSORT ********************************* 
void q_sort(void *v[], int left, int right, int reverse, int (*comp)(void*, void*))
{
    int i, last;
    void swap(void *v[], int, int);

    if (left >= right) // do nothing if arr contains less than 2 elements
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if (reverse && (*comp)(v[i], v[left]) > 0)
            swap(v, ++last, i);
        else if (!reverse && (*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    q_sort(v, left, last-1, reverse, comp);
    q_sort(v, last+1, right, reverse, comp);
}
// ********************************* 


// NUMCMP ********************************* 
#include <stdlib.h>
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}
// ********************************* 


// SWAP ********************************* 
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
// ********************************* 


// READLINES ********************************* 
int readlines(char *lineptr[], int maxlines)
// according to the exercise, char *arr was adding for storage here
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = malloc(len + 1)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';   // delete new line
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}
// ********************************* 


// WRITELINES ********************************* 
void writelines(char *lineptr[], int nlines)
{
    int i; 
    for (i = 0; i < nlines; i++)
        printf("%s\n", *lineptr++);
}
// ********************************* 


// GETLINE ********************************* 
int get_line(char *s, int lim)
{
    int c, i;

    for (i = 0; i < lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        *s++ = c;
    if (c == '\n') {
        *s++ = c;
        ++i;
    }
    *s = '\0';
    return i;
} 
// ********************************* 

int chrcmp(char *s, char *t)
{
    for ( ; tolower(*s) == tolower(*t); s++, t++)
        if (*s == '\0')
            return 0;
    return tolower(*s) - tolower(*t);
}
