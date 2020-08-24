/**
 * Exercise 6-3: Write a cross-referencer that prints a list of all words in
 * a document, and, for each word, a list of the line numbers on which it 
 * occurs. Remove noise words like "the," "and," and so on.
 * */

#include <stdio.h>

struct word_info {
    char *word;
    int line;
};

char *ignore[] = { "and", "the", "a", "an", "of" };

#define MAXWORD 100

// open file 

// function
// scan each line
// keep track of line count
// compare, add each word and line num to the struct array

// function comapre
// compare word to ignore words array
// if any match, don't add to struc

// function print
// print the list of words with their corresponding line numbers