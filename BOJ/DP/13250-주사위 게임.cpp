#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
long double dp[1000009]={0};
int main(){
	int n;	scanf("%d",&n);

	dp[1]=1;

	for(int i=2 ; i<=n ; i++){
		for(int j=1 ; j<=6 ; j++){
			if(i>j)
				dp[i]+=dp[i-j];
		}
		dp[i]/=6;
		dp[i]+=1;
	}

	 printf("%.15Lf\n",dp[n]);
	return 0;
}