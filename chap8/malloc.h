#include <stdio.h>          // for NULL

#define NALLOC 1024         // minimum #units to request

#define MAXBYTES 10000      // for exercise 8.7

typedef long Align;         // for alignment to long boundary

union header {
    struct {                // block header
        union header *ptr;  // next block if on free list
        unsigned size;      // size of this block
    } s;
    Align x;                // force alignment of blocks
};

typedef union header Header;

static Header base;         // empty list to get started
static Header *freep = NULL; // start of free list

void *_malloc(unsigned);
void _free(void *);
Header *morecore(unsigned);



