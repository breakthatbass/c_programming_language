/**
* Exercise 6-2: Write a program that reads a C program and prints
* in alphabetical order each group of variable names that are identical
* in the first 6 characters, but different somewhere thereafter. 
* Don't count the words within strings and comments. Make 6 a parameter
* that can be set from the command line
*
* this solution comes from The C Answer Book by Clovis Tondo
* and Scott Gimpel on pages 153, 154, & 155.
**/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

struct tnode {        // tree node
    char *word;             // points to the text
    int match;              // match found
    struct tnode *left;     // left child
    struct tnode *right;    // right child
 };

#define MAXWORD 100
#define YES     1
#define NO      0
 
struct tnode *addtree(struct tnode *, char *, int, int *);
void treeprint(struct tnode *);
int getword(char *, int);

int main(int argc, char **argv)
{
    struct tnode *root;
    char word[MAXWORD];
    int found = NO;     // YES if match was found
    int num;            // number of the first ident. chars
    
    num = (--argc && (*++argv)[0] == '-') ? atoi(argv[0] + 1) : 6;
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        // added strlen check
        // just makes sure the word in question is at least
        // as long as the amount of chars to check
        if (isalpha(word[0]) && strlen(word) >= num)
            root = addtree(root, word, num, &found);
        found = NO;
    treeprint(root);
    return 0;
} 


 struct tnode *talloc(void);
 int compare(char *, struct tnode *, int, int *);


 // addtree: add a node with w, at or below p 
 struct tnode *addtree(struct tnode *p, char *w, int num, int *found)
 {
     int cond;

     if (p == NULL) {       // a new word has arrived
         p = talloc();     // make a new node
         p->word = strdup(w);
         p->match = *found;
         p->left = p->right = NULL;
    } else if ((cond = compare(w, p, num, found)) < 0)
        p->left = addtree(p->left, w, num, found);
    else if (cond < 0)
        p->right = addtree(p->right, w, num, found);
    return p;
 }

 // compare: compare words and update p->match
 int compare(char *s, struct tnode *p, int num, int *found)
 {
     int i;
     char *t = p->word;

     for (i = 0; *s == *t; i++, s++, t++)
         if (*s == '\0')
             return 0;
    if (i >= num) {     // identical in first num chars ?
        *found = YES;
        p->match = YES;
    }
    return *s - *t;
 }


 // treeprint: in-order print of tree
 void treeprint(struct tnode *p)
 {
     if (p != NULL) {
         treeprint(p->left);
         if (p->match)
             printf("%s\n", p->word);
         treeprint(p->right);
     }
 }

 
 // talloc: make a node
 struct tnode *talloc(void)
 {
     return (struct tnode *) malloc(sizeof(struct tnode));
 }


 // strdup: make a duplicate of s
 char *str_dup(char *s)
 {
    char *p;

    p = (char *) malloc(strlen(s) + 1);  // +1 for '\0'
    if (p != NULL)
        strcpy(p, s);
    return p;
 }

// getword: get the word or character from input
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c) || c == '_' || c == '#') {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

