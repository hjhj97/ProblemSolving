#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
#define SIZE 100009
#define INF SIZE*5
int dp[SIZE][5][5];
int dist[5][5];
vector<int> v;
int main(){
	for(int i=1 ; i<=4 ; i++)
		dist[0][i]=2;

	dist[1][1]=1,dist[2][2]=1,dist[3][3]=1,dist[4][4]=1,
	dist[1][2]=3,dist[1][4]=3,dist[2][1]=3,dist[2][3]=3,
	dist[3][2]=3,dist[3][4]=3,dist[4][1]=3,dist[4][3]=3,
	dist[1][3]=4,dist[2][4]=4,dist[3][1]=4,dist[4][2]=4;

	v.push_back(0);
	while(1){
		int tmp;	scanf("%d",&tmp);
		if(tmp==0) break;
		v.push_back(tmp);
	}

	for(int i=0 ; i< v.size() ; i++)
		for(int j=0 ; j<=4 ; j++)
			for(int k=0 ; k<=4 ; k++)
				dp[i][j][k]=INF;

	dp[0][0][0]=0;

	for(int k=1 ; k<v.size() ; k++){
		int cur=v[k];
		for(int i=0 ; i<=4 ; i++){
			for(int j=0 ; j<=4 ; j++){
				if(cur!=j)
					dp[k][cur][j]=min(dp[k][cur][j],dp[k-1][i][j]+dist[i][cur]);

				if(cur!=i)
					dp[k][i][cur]=min(dp[k][i][cur],dp[k-1][i][j]+dist[j][cur]);
			}
		}


	}

	int ans=INF;
		for(int i=0 ; i<=4 ; i++){
			for(int j=0 ; j<=4 ; j++){
				ans=min(ans,dp[v.size()-1][i][j]);
			}
		}
	printf("%d\n",ans);

	return 0;
}