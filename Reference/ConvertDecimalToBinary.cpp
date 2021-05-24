#include<stdio.h>

int main(){
	int num=64,len=32; //num은 변환하려는 수, len은 변환하려는 bit의 수

	for(int i=len-1 ; i>=0 ; i--){
		printf("%d",(num>>i)&1);
		if(i%8==0) printf(" ");
	}

	return 0;
}