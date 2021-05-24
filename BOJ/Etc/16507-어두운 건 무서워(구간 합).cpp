#include<stdio.h>
#define SIZE 1010
int n,m,q;
int arr[SIZE][SIZE],sum[SIZE][SIZE];
int main(){
	scanf("%d %d",&n,&m);

	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=m ; j++)
			scanf("%d",&arr[i][j]);

	for(int i=1 ; i<=n ; i++){
		for(int j=1 ; j<=m ; j++){
			sum[i][j]=sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1]+arr[i][j];
		}
	}

	while(q--){
		int r1,c1,r2,c2;	scanf("%d %d %d %d",&r1,&c1,&r2,&c2);

		r1--;
		c1--;
		int ans=sum[r2][c2]-sum[r1][c2]-sum[r2][c1]+sum[r1][c1];
		printf("%d\n",ans);
	}

	return 0;
}