#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 509
#define INF 1<<30
struct Matrix{
	int r,c;
};
int a[SIZE],b[SIZE];
int dp[SIZE][SIZE]={0};
Matrix m[SIZE][SIZE],tmp[SIZE];
int main(){
	int n;	scanf("%d",&n);

	for(int i=0 ; i<SIZE ; i++)
		for(int j=i ; j<SIZE ; j++)
			if(i!=j)
				dp[i][j]=INF;

	for(int i=0 ; i<n ; i++){
		scanf("%d %d",&m[i][i].r,&m[i][i].c);
		tmp[i].r=m[i][i].r;	tmp[i].c=m[i][i].c;
	}

	for(int i=1 ; i<=n ; i++){
		for(int j=0 ; j+i<n ; j++){
			for(int k=j ; k+1 <n ; k++){
				int mul = m[j][k].r * m[j][k].c * m[k+1][j+i].c;
				m[j][j+i].r=tmp[j].r;	m[j][j+i].c=tmp[j+i].c;
				if(dp[j][j+i]>dp[j][k]+dp[k+1][j+i]+mul){
					dp[j][j+i]=dp[j][k]+dp[k+1][j+i]+mul;
					// m[j][j+i].r=m[j][k].r; m[j][j+1].c=m[k+1][j+1].c;
				}
			}
		}
	}

	// for(int i=0 ; i<n ; i++){
	// 	for(int j=i ; j<n ; j++)
	// 		printf("%d %d %d\n",i,j,dp[i][j]);
	// }
	printf("%d\n",dp[0][n-1]);
	return 0;
}