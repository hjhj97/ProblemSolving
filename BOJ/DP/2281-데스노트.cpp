#include<stdio.h>
#include<algorithm>
using namespace std;
#define SIZE 1009
int n,m;
int dp[SIZE][SIZE],arr[SIZE];	
int rec(int pos,int cnt){
	if(cnt==n) return 0;

	int &ret=dp[pos][cnt];
	if(ret!=-1) return ret;

	ret=rec(arr[cnt]+1,cnt+1)+(m-pos+1)*(m-pos+1);
	if(pos+arr[cnt]<=m) 
		ret=min(ret,rec(pos+arr[cnt]+1,cnt+1));

	return ret;
}
int main(){
	scanf("%d %d",&n,&m);

	for(int i=0 ; i< n ; i++)
		scanf("%d",&arr[i]);

	for(int i=0 ; i<SIZE ; i++){
		for(int j=0 ; j<SIZE ; j++)
			dp[i][j]=-1;
	}

	int ans=rec(arr[0]+1,0+1);
	printf("%d\n",ans);

	return 0;
}