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
#define SIZE 200009
// #define MOD 
// #define IMP
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



ll dp[SIZE][3];
int main(){
	const ll MOD=1e9+7;

	int n,l,r;	scanf("%d %d %d",&n,&l,&r);

	int div=(r-l+1)/3;
	dp[1][0]+=div,dp[1][1]+=div,dp[1][2]+=div;
	if(l%3==r%3){
		dp[1][l%3]++;
	}
	else if(l%3==0 && r%3==1){
		dp[1][0]++;
		dp[1][1]++;
	}
	else if(l%3==1 && r%3==2){
		dp[1][1]++;
		dp[1][2]++;
	}
	else if(l%3==2 && r%3==0){
		dp[1][2]++;
		dp[1][0]++;
	}
	for(int i=2 ; i<=n ; i++){
		dp[i][0]=(dp[1][0]*dp[i-1][0])%MOD + (dp[1][1]*dp[i-1][2])%MOD + (dp[1][2]*dp[i-1][1])%MOD;
		dp[i][1]=(dp[1][0]*dp[i-1][1])%MOD + (dp[1][1]*dp[i-1][0])%MOD + (dp[1][2]*dp[i-1][2])%MOD;
		dp[i][2]=(dp[1][0]*dp[i-1][2])%MOD + (dp[1][2]*dp[i-1][0])%MOD + (dp[1][1]*dp[i-1][1])%MOD;

		dp[i][0]=dp[i][0]%MOD;
		dp[i][1]=dp[i][1]%MOD;
		dp[i][2]=dp[i][2]%MOD;
	}
	printf("%lld\n",dp[n][0]);	

	return 0;
}

