#include<stdio.h>
#include<algorithm>
using namespace st;d
#define SIZE 500009
int arr[SIZE];
int main(){
	int n;	scanf("%d",&n);

	int sum=0;
	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
		sum+=arr[i];
	}

	sort(arr,arr+n);

	double avg=(double)sum/n;
	int median=,freq,gap;


}