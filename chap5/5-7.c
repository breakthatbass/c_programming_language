/*
 * Exercise 5-7: rewrite readlines to store lines in an array supplied by main,
 * rather than calling alloc to maintain storage.
 */

#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];    // pointers to text lines

int readlines(char *lineptr[], int nlines, char *arr);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

// helpers
int get_line(char *s, int lim);
//char *alloc(int n);
void swap(char *v[], int i, int j);


int main()
{
    int nlines;     // number of input lines read
    char storage[MAXLEN];

    if ((nlines = readlines(lineptr, MAXLINES, storage)) >= 0) {
        qsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

// input/out put functions
// read input lines
int readlines(char *lineptr[], int maxlines, char *arr)
// according to the exercise, char *arr was adding for storage here
{
    int len, nlines;
    char *p, line[MAXLEN];
    p = arr;

    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return -1;
        else {
            line[len - 1] = '\0';   // delete new line
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return nlines;
}

// print the array
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

// sort it!
void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return; // do nothing if the array is few than two elements

    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

// helper functions

// for use in readlines function
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

void swap(char *v[], int i, int j)
{
    char *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp; 
}
