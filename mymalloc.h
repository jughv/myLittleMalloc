#define malloc(s) mymalloc(s, __FILE__, __LINE__)
#define free(p) myfree(p, __FILE__, __LINE__)
#define MAXSIZE 4096
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
#include<ctype.h>
void *mymalloc(size_t sizeB, char *file, int line);
void myfree(void *p, char *file, int line);
void initiate();//initializing the memoery array


