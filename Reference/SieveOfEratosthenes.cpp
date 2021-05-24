#include<stdio.h>
const int MAX=20000000;
bool isPrime[MAX+10];

int main(){
    isPrime[1]=0;
    
    for(int i=2 ; i*i<=MAX ; i++){
        for(int j=i*i ; j<=MAX ; j+=i){
            isPrime[j]=0;
        }
    }

    return 0; 
}