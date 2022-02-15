#include <stdio.h>
#include <stdlib.h>
//#include "mymalloc.h"

char *arr[120];// an array of pointers


void test1(){ //allocate then free 120 times //ill do this one
for(int i = 0;i<120;i++){//loop through 120 times
char *p = (char*)malloc(sizeof(char)); //
printf("allocated: %p, size: %lu\n", p, sizeof(p));
free(p);
printf("freed\n");
printf("memgrinded: %d\n", i+1);
}

}//end test 1


void test2(){ //allocate 120 times then free //you got this one
    
    int i;
    for(i = 0; i< 120;i++){
        arr[i] =(char*)malloc(1);
        printf("allocated: %p, size: 1", arr[i])
        free(arr[i]);
        printf("free\n");
        
        
    }
    

}

void test3(){//random allocate, random free, dont free null

}

void test4(){ //some bullshit // you plan this one out

}

void test5(){ //i think it would be calm to allocate memory in 20 part bits and then deallocate those 20 part bits similar to thee tests before just a tad different lmao

}

int main (int argc, char **argv){ //get the time per test all that is missing
    for (int i = 0; i<50; i++){
        test1();
        test2();
        test3();
        test4();
        test5();
        printf("test time: %d\n", i+1);
    }
    
    return 0;
}


