#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"
#include <stddef.h>
#include <ctype.h>
static char memory[MAXSIZE];





void initiate(){//initializing the memoery 
    for(int i = 0; i< MAXSIZE;i++){
        memory[i] = '0';
    }
}

void myfree(void *p, char *file, int line){
    int i, size;
	
	if(p == 0){
		fprintf(stderr, "Null pointer in %s: %d", file, line);
    }

	for(i = 0; i < MAXSIZE; i ++){
		if(&memory[i] == p){
			size = memory[i];
			break;
		}
	}
	for(int n = i; n < i + size; n++){
		memory[n] = '0';
    }
	return;
}


void *mymalloc(size_t sizeB, char *file, int line){
    if(sizeB > MAXSIZE){
        fprintf(stderr, "Memory size exceeds Limit in %s:%d\n",file,line);
        return NULL;
    }
    else if(sizeB == 0){
        return NULL;
    }
    int ptr = 0;
    int blockSize = 0;
    while(blockSize<sizeB){
        if(memory[ptr] == '0'){
            blockSize++;
        }
        else{
            blockSize = 0;
        }

        if(blockSize == sizeB){
            break;
        }
        else if(ptr == MAXSIZE-1){//-1 is space for header
            return NULL;
        }
        ptr++;
    }
    int newhead = ptr - sizeB + 1;
    for(int i = newhead; i<newhead+sizeB; i++){
        memory[i] = sizeB;
    }
    fprintf(stderr,"Mymalloc called from %s:%d\n", file, line);
    return &memory[newhead];

}
