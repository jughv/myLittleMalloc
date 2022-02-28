#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"
#include <stddef.h>
#include <ctype.h>

#define MEMSIZE 4096

static char memory[4096];

void initiate(){//initializing the memoery 
    mainBlock->size = MAXSIZE-sizeof(struct block);
    mainBlock->free_block = 1;
    mainBlock->next = NULL;
}




void *mymalloc(size_t sizeB, char *file, int line){
    struct block *currPtr, *prevPtr;
    void *mallocResult;

    
    if(sizeB == 0){
        fprintf(stderr,"Allocation size is 0 in %s:%d", file,line);
        return NULL;
    }
    if(sizeB+sizeof(struct block)>MEMSIZE){
        fprintf(stderr,"Allocation size is overflow in %s:%d",file,line);
        return NULL;
    }
    if(sizeB<0){
        fprintf(stderr,"Negative anount of memory can't be allocated in %s:%d", file, line);
        return NULL;
    }
    if(!(mainBlock->size)){
        initiate();
        printf("Initialize mamery block\n");
    }
    currPtr = mainBlock;
    while (((currPtr->size)<sizeB)||((currPtr->free_block)==0)&&(currPtr->next!=NULL))
    {
        prevPtr = currPtr;
        currPtr = currPtr->next;
        printf("finding free block\n");
        
    }
    if((currPtr->size)==sizeB){
        currPtr->free_block = 0;
        mallocResult=(void*)(++currPtr);
        printf("Memory allocated\n");
        return mallocResult;

    }
    else if ((currPtr->size)>(sizeB+sizeof(struct block)))
    {

        struct block *temp = (void*)((void*)currPtr+sizeB+sizeof(struct block));
        temp->size = (currPtr->size)-sizeB-sizeof(struct block);
        temp->free_block = 1;
        temp->next = currPtr->next;
        currPtr->size = sizeB;
        currPtr->free_block = 0;
        currPtr->next = temp;
        mallocResult = (void*)(++currPtr);
        printf("Memory allocated");
        return mallocResult;

    }
    else{
        fprintf(stderr,"Allocation size is overflow in %s:%d",file,line);
        return NULL;
    }
    
    

    printf(stderr,"Mymalloc called from %s:%d\n", file, line);
    return NULL;
}

void myfree(void *p, char *file, int line){
}
