#include <stdio.h>
#include <stdlib.h>
//#include "mymalloc.h"

char *arr[120];// an array of pointers
int test2Time[50];
int time2; 


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
    struct timeval start;
    struct timeval end;
    
    int i;

    for(i = 0; i< 120;i++){
        gettimeofday(&start,NULL);
        arr[i] =(char*)malloc(1);
        printf("allocated: %p, size: 1", arr[i]);
    }
    for(i = 0; i<120; i++){
        free(arr[i]);
        printf("free\n");
    }
    gettimeofday(&end,NULL);
    time2 += end.tv_sec-start.tv_sec;
    
    

}

void test3(){//random allocate, random free, dont free null

}

void test4(){ //some bullshit // you plan this one out

}

void test5(){ //i think it would be calm to allocate memory in 20 part bits and then deallocate those 20 part bits similar to thee tests before just a tad different lmao

}

int main (int argc, char **argv){ //get the time per test all that is missing
    int sum2 = 0;
    for (int i = 0; i<50; i++){
        test1();
        test2();
        test3();
        test4();
        test5();
        printf("test time: %d\n", i+1);
        test2Time[i] = time2;
    }
    int j;
    for(j=0;j<50;j++){
        sum2+=test2Time[j];
    }
    printf("average time for test 2: %d\n", sum2/50);
    
    return 0;
}


