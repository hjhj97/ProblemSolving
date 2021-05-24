#include<stdio.h>
#define SIZE 1010
int n,m;
char grid[SIZE][SIZE];
bool visited[SIZE][SIZE]={false};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int check[SIZE][SIZE]={0};
int cnt=0;
bool result=false;
bool dfs(int r,int c,int cnt){
	visited[r][c]=true;
	check[r][c]=cnt;
	int next_r,next_c;

	if(grid[r][c]=='S'){
		next_r=r+1,next_c=c;
	}
	else if(grid[r][c]=='N'){
		next_r=r-1,next_c=c;
	}
	else if(grid[r][c]=='W'){
		next_r=r,next_c=c-1;
	}
	else if(grid[r][c]=='E'){
		next_r=r,next_c=c+1;
	}
	
	if(check[next_r][next_c]==cnt) return result=false;

	if(check[next_r][next_c]!=cnt && check[next_r][next_c]!=0){
		return result=true;
	}

	else{
		return dfs(next_r,next_c,cnt);
	}

}
int main(){
	scanf("%d %d",&n,&m);

	for(int i=0 ; i<n ; i++){
		scanf("%s",grid[i]);
	}

	int ans=0;

	for(int i=0 ; i<n ; i++){
		for(int j=0 ; j<m ;j++){
			if(check[i][j]==0){
				result=false;
				cnt++;
				if(!dfs(i,j,cnt)){
					ans++;
				}
			}
		}
	}

	printf("%d\n",ans);
	return 0;
}