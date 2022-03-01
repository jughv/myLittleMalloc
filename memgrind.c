#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"
#include <time.h>
#include <sys/time.h>
char* arr[120];


double total1Time = 0;
double total2Time = 0;
double total3Time = 0;


struct timeval start, end;




void test1(){ //allocate then free 120 times //ill do this one
    for(int i = 0; i<50; i++){
        initiate();
        gettimeofday(&start,NULL);
        for(int j = 0;j<120;j++){//loop through 120 times
            char *p = (char*)malloc(sizeof(char)); //
            free(p);
        gettimeofday(&end, NULL);
        total1Time +=((end.tv_usec-start.tv_usec)/1000000.0);
        printf("time :%f\n", total1Time);
    }
}

}//end test 1


void test2(){ //allocate 120 times then free //you got this one
int i, j, k;
for(i = 0;i<50;i++){
    
    initiate();
    gettimeofday(&start,NULL);
    for(j = 0; j< 120;j++){

        arr[i] =(char*)malloc(1);
    }
    for(k = 0; k<120; k++){
        free(arr[i]);
    }
    gettimeofday(&end,NULL);
    total2Time +=((end.tv_usec-start.tv_usec)/1000000.0);
    printf("time :%f\n",total2Time);
} 

}

void test3(){//random allocate, random free, dont free null
    for(int i = 0; i<50; i++){
        initiate();
        gettimeofday(&start, NULL);
        char* arr1[120];
        int countFree = 0;
        int countMalloc = 0;
        int randomNum = 0;
        while(countMalloc <120){
            randomNum = rand()%2;
            if(randomNum == 0){
                arr1[countMalloc] =malloc(1);
                countMalloc++;

            }
            else{
                if(countMalloc>countFree){
                    free(arr1[countFree]);
                    countFree++;
                }
            }

        }
        while(countFree!=countMalloc){
            free(arr1[countFree]);
            countFree++;
        }
        gettimeofday(&end,NULL);
        total3Time+= ((end.tv_usec-start.tv_usec)/1000000.0);
        printf("time :%f\n",total3Time);
    }

}

void test4(){ //some bullshit // you plan this one out

}

void test5(){ //i think it would be calm to allocate memory in 20 part bits and then deallocate those 20 part bits similar to thee tests before just a tad different lmao

}
int main (int argc, char **argv){ //get the time per test all that is missing
    test1();
   printf("the average time of test1 is: %f\n", total1Time/50);
    test2();
    printf("the average time of test2 is: %f\n", total2Time/50);
    test3();
    printf("the average time of test3 is: %f\n", total3Time/50);

    
    return 0;
}


