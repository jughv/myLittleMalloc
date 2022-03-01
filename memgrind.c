#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"
#include <time.h>
#include <sys/time.h>
char* arr[120];


double total1Time = 0;
double total2Time = 0;
double total3Time = 0;
double total4Time = 0;
double total5Time = 0;


struct timeval start, end;




void test1(){ //allocate then free 120 times //ill do this one
    for(int i = 0; i<50; i++){
        initiate();
        gettimeofday(&start,NULL);
        for(int j = 0;j<120;j++){//loop through 120 times
            char *p = (char*)malloc(sizeof(char)); //
            free(p);
        gettimeofday(&end, NULL);
        total1Time +=(end.tv_sec - start.tv_sec)+((end.tv_usec - start.tv_usec)/1000000.0);
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
    total2Time +=(end.tv_sec - start.tv_sec)+((end.tv_usec - start.tv_usec)/1000000.0);
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
        total3Time+= (end.tv_sec - start.tv_sec)+((end.tv_usec - start.tv_usec)/1000000.0);
        printf("time :%f\n",total3Time);
    }

}

 void test4(){ 
    for (int x = 0; x<50;x++){ // loop through this 50 times
        int randomValue = rand()%1000+100; // gets a random value
        char *currentArray[randomValue]; //populates an array of that size
        initiate();

        gettimeofday(&start,NULL); // gets the time of the day 
        //int totalTime = 0; //total time for the method to run

        for (int i = 0;i<randomValue; i++){
            //int randi = rand(); // gets a random number
            //while(randi >= randomValue){ //makes sure we stay within the bounds
             //  randi = randi/2;
            //}
            for (int j = 0; j<randomValue;j++){ //populate the array that random number of times
            currentArray[j] = malloc(1);
            }
            for (int j = randomValue; j<=0;j--){ //free the array that random number of times
                //currentArray[randi] = free();
                free(currentArray[j]);
            }    

            gettimeofday(&end,NULL); //gets the time of this iteration
            total4Time += (end.tv_sec - start.tv_sec)+((end.tv_usec - start.tv_usec)/1000000.0); // timer increases
        }
        //int avgTime = total4Time/randomValue; //gets the avg of the total time
    }

}


void test5(){ //i think it would be calm to allocate memory in 20 part bits and then deallocate those 20 part bits a random number of times
    
    for (int x = 0; x<50;x++){ // loop through this 50 times
        initiate();
        gettimeofday(&start,NULL); // gets the beginning time
        for (int i = 0; i < 1000; i++){ //do this a random amount of times
            for (int j = 0; j<20; j++){
                arr[j] = malloc(1); //allocate 20 times
            }
            for (int j = 0; j<20; j++){ //free 20 times
                free(arr[j]);
            }
        }

        gettimeofday(&end,NULL); //gets the time of this iteration
        total5Time += (end.tv_sec - start.tv_sec)+((end.tv_usec - start.tv_usec)/1000000.0); // timer increases
        
    }


}


int main (int argc, char **argv){ //get the time per test all that is missing
    test1();
  
    test2();
    
    test3();
    test4();
    
    test5();
    printf("the average time of test1 is: %f\n", total1Time/50);
    printf("the average time of test2 is: %f\n", total2Time/50);
    printf("the average time of test3 is: %f\n", total3Time/50);
    printf("the average time of test4 is: %f\n", total4Time/50);//since we used a random number so the time for every test cases are
    printf("the average time of test5 is: %f\n", total5Time/50);
    
    return 0;
}


