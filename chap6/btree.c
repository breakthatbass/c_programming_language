 #include <stdio.h>
 #include <ctype.h>
 #include <string.h>
 #include <stdlib.h>
  
 struct tnode {        // tree node
    char *word;             // points to the text
    int count;              // number of occurances
    struct tnode *left;     // left child
    struct tnode *right;    // right child
 };
 
 #define MAXWORD 100
 
 struct tnode *addtree(struct tnode *, char *);
 void treeprint(struct tnode *);
 int getword(char *, int);
   
  
 // word frequency count
 int main()
 {
    struct tnode *root;
    char word[MAXWORD];
  
    root = NULL;
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            root = addtree(root, word);
    treeprint(root);
    return 0;
} 


 struct tnode *talloc(void);
 char *str_dup(char *);


 // addtree: add a node with w, at or below p 
 struct tnode *addtree(struct tnode *p, char *w)
 {
     int cond;

     if (p == NULL) {       // a new word has arrived
         p = talloc();     // make a new node
         p->word = str_dup(w);
         p->count = 1;
         p->left = p->right = NULL;
    } else if ((cond = strcmp(w, p->word)) == 0) // if word is already in tree...
        p->count++;
    else if (cond < 0)      // less than into left subtree
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
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
