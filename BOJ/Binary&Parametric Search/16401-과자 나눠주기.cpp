#include<stdio.h>
#define SIZE 1000009
int arr[SIZE];
int main(){
	int m,n;	scanf("%d %d",&m,&n);

	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}

	int l=1, r=1e+9;
	int ans=-1;
	//upper bound search
	while(r>=l){
		int mid=(l+r)/2;
		int possible=0;

		for(int i=0 ; i<n ; i++){
			possible+=(arr[i]/mid);
		}

		if(possible>=m){
			l=mid+1;
			ans=mid;
		}

		else{
			r=mid-1;
		}

	}
	printf("%d\n",(ans==-1)?0:ans);
	return 0;
}
/*
10 1
10
-> 1

*/