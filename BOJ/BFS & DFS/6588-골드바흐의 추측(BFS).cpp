#include<stdio.h>
#define SIZE 1000009
bool prime[SIZE];
int main(){
	for(int i=0 ; i<SIZE ; i++)
		prime[i]=true;

	for(int i=2 ; i<SIZE ; i++){
		for(int j=2 ; i*j<SIZE ; j++)
			prime[i*j]=false;
	}
	prime[1]=false;

	while(1){
		int n;	scanf("%d",&n);

		if(n==0) return 0;

		for(int i=3 ; i<n; i+=2){
			if(prime[i] && prime[n-i]){
				printf("%d = %d + %d\n",n,i,n-i);
				break;
			}
			if(i==n-1) printf("Goldbach's conjecture is wrong.\n");
		}

	}
}