/* *
 * Exercise 6-5: Write a function undef that will remove a name and definition
 * from the table maintained by lookup and install
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nlist {
    struct nlist *next;     // next entry in chain
    char *name;             // defined name
    char *defn;             // replacement text
};

#define HASHSIZE 101
static struct nlist *hashtab[HASHSIZE];     // pointer table


// hash: form hash value for string s
unsigned hash(char *s)  // unsigend to make sure it's not negative
{
    unsigned hashval;

    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}


// lookup: look for s in hashtab
struct nlist *lookup(char *s)
{
    struct nlist *np;

    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;  // found
    return NULL;        // not found
}


// install: put (name, defn) in hashtab
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL) {     // not in table
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else      // already in table
        free((void *) np->defn);    // free previous defn
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}


// undef: remove name and defn from hash table
void undef(char *s)
{
    struct nlist *np;
    unsigned hashval;

	if ((np = lookup(s)) != NULL) {
        hashval = hash(np->name);
	    hashtab[hashval] = NULL;

        free((void *) np->name);
        free((void *) np->defn);
        free((void *) np);
    }
}


int main()
{
	install("name", "Taylor");
	struct nlist *n = lookup("name");
	
	printf("%s\n", n->defn);
    undef("name");
    printf("%s\n", n->defn);
   
	return 0;
}

