#include<stdio.h>
#include<stdlib.h>
#include<time.h>
const int SIZE=100;
const int NUM_RANGE=1000;
const int LOWER_BOUND=1;

int getRandomNumber(){
	int num=((long long)rand()<<16 | rand())
			%NUM_RANGE+LOWER_BOUND;

	return num;
}

int main(){
	freopen("output.txt","w",stdout);

	srand((unsigned int) time(NULL));

	for(int i=0 ; i<SIZE ; i++){
		printf("%d\n",getRandomNumber());
	}
	return 0;
}