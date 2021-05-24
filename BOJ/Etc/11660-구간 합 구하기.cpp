#include<stdio.h>
#define SIZE 1030
int n,q;
int arr[SIZE][SIZE],sum[SIZE][SIZE]={0};
int main(){
	scanf("%d %d",&n,&q);

	for(int i=1 ; i<=n ; i++)
		for(int j=1 ; j<=n ; j++)
			scanf("%d",&arr[i][j]);

		for(int i=1 ; i<=n ; i++){
			for(int j=1 ; j<=n ; j++){
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+arr[i][j];
			}
		}

	while(q--){
		int x1,y1,x2,y2;	scanf("%d %d %d %d",&y1,&x1,&y2,&x2);

		x1--; y1--;

		int ans=sum[y2][x2]-sum[y1][x2]-sum[y2][x1]+sum[y1][x1];
		printf("%d\n",ans);
	}


	return 0;
}