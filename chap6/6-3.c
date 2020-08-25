/**
 * Exercise 6-3: Write a cross-referencer that prints a list of all words in
 * a document, and, for each word, a list of the line numbers on which it 
 * occurs. Remove noise words like "the," "and," and so on.
 * */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct word_info {
    char *word;
    int line;
};

struct tnode {        // tree node
    char *word;             // points to the text
    int match;              // match found
    struct tnode *left;     // left child
    struct tnode *right;    // right child
 };

#define MAXWORD 100
#define IGN_LEN 5


// compare: return 1 if s is in ignore array else return 0
int compare(char *s)
{
    static char *ignore[IGN_LEN] = { "a", "an", "and", "are", "in", "is", "of", "or", "that ""the", "this", "to"};

    int i;
    for (i = 0; i < IGN_LEN; i++) 
        if (strcmp(ignore[i], s) == 0)  
            return 1;
    return 0;
}