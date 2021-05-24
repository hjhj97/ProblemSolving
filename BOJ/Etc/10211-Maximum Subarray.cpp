#include<stdio.h>
#define SIZE 1010
int arr[SIZE],sum[SIZE];
int fMax(int a,int b){
	return a>b?a:b;
}
int main(){
	int t;	scanf("%d",&t);

	while(t--){
		int n,ans=-(1<<30);	scanf("%d",&n);

		for(int i=1; i<=n ; i++){
			int num;	scanf("%d",&num);
			sum[i]=sum[i-1]+num;
		}

		for(int i=1 ; i<=n ; i++){
			for(int j=i ; j<=n ; j++){
				ans=fMax(ans,sum[j]-sum[i-1]);
			}
		}
		printf("%d\n",ans);
	}

	return 0;
}