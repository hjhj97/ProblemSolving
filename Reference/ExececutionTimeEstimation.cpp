#include<stdio.h>
#include<time.h>
clock_t start,end;
int main(){
    start=clock(); //start
 
    /*
        code here
    */

    end=clock(); //end
    printf("Time : %.3lf second\n",(double)(end-start)/CLOCKS_PER_SEC);
 
    return 0; 
}