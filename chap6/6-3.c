/**
 * Exercise 6-3: Write a cross-referencer that prints a list of all words in
 * a document, and, for each word, a list of the line numbers on which it 
 * occurs. Remove noise words like "the," "and," and so on.
 * */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAXWORD 100
#define IGN_LEN 12


struct tnode {        // tree node
    char *word; 
    int count;              // points to the text
    int line[MAXWORD];      // match found
    struct tnode *left;     // left child
    struct tnode *right;    // right child
};

struct tnode *addtree(struct tnode *, char *);
void treeprint(struct tnode *);
int getword(char *, int);
int compare(char *);

static int ln = 1;      // line number

int main()
{
    struct tnode *root;
    char word[MAXWORD];
  
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]) && compare(word) != 1)
            root = addtree(root, word);
    treeprint(root);
    return 0;
} 

// getword: get the word or character from input
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
    char *w = word;

    do {
        c = getch();
        if (c == '\n')
            ++ln;
    }

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for ( ; --lim > 0; w++)
        if (!isalnum(*w = getch() && *w != '_')) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}

struct tnode *talloc(void);
char *str_dup(char *);

// addtree: add a node with w, at or below p 
struct tnode *addtree(struct tnode *p, char *w)
{
    int cond, i;

    if (p == NULL) {       // a new word has arrived
        p = talloc();      // make a new node
        p->word = str_dup(w);
        p->count = 1;
        p->line[0] = ln;
        p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0)  { // if word is already in tree...
        p->count++;
        i = 0;
        p->line[++i] = ln;
    }
    else if (cond < 0)      // less than into left subtree
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}

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

// treeprint: in-order print of tree
void treeprint(struct tnode *p)
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
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
