#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
#include<functional>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stdlib.h>
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
/****************************Default Template******************************/
// #define SIZE
// #define IMP
// #define INF
// const int MOD=
struct S{
	int a,b;

	S(){}
	S(int _a,int _b){
		a=_a;
		b=_b;
	}

	const bool operator<(const S &o) const{
		return a<o.a;
	}
};
priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int>> mpq;
map<int,int> mp;
stack<int> st;
set<int> set_i;
/****************************Default Template******************************/



char grid[555][555];
int ans=0;
// char ptn[3][3]={'x','.','x',}
void judge(int r,int c){
	if(grid[r][c]=='X'){
		if(grid[r-1][c-1]=='X' && grid[r-1][c+1]=='X'
		 && grid[r+1][c-1]=='X' && grid[r+1][c+1]=='X'){
				ans++;
		}
	}
}
int main(){
	int n;	scanf("%d",&n);

	for(int i=0 ; i< n ;i++){
		scanf("%s",grid[i]);
	}

	if(n<=2){
		printf("0\n");
		return 0;
	}
	for(int i=1 ; i<n-1 ; i++){
		for(int j=1 ; j<n-1 ; j++){
			judge(i,j);
		}
	}
	printf("%d\n",ans);

	return 0;
}

