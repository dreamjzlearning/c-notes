/*
    A rudimentary storage allocator.
*/

#define ALLOC_SIZE 10000 // size of available space

static char allocbuf[ALLOC_SIZE]; // storage for alloc
static char* allocp = allocbuf; // next free position

// alloc returns pointer to characters
char* alloc(int n) {
    if (allocbuf + ALLOC_SIZE - allocp >= n) { // it fits
        allocp += n;
        return allocp - n; // old p
    }

    // not enough room
    return 0;
}

// afree frees storage pointed to by p
void afree(char* p) {
    if (p >= allocbuf && p < allocbuf + ALLOC_SIZE) {
        allocp = p;
    }
}