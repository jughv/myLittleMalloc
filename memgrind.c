#include <stdio.h>
#include <stdlib.h>
#include "mymalloc.h"


int main (int argc, char **argv){ //get the time per test all that is missing
    for (int i = 0; i<50; i++){
        test1();
        test2();
        test3();
        test4();
        test5();
    }
    
    return 0;
}


void test1(){ //allocate then free 120 times

}


void test2(){ //allocate 120 times then free

}

void test3(){//random allocate, random free, dont free null

}

void test4(){ //some bullshit

}

void test5(){ //some bullshit

}