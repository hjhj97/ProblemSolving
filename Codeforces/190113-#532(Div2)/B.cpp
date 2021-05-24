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
#define SIZE 100009
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


int main(){
	int n,m;	scanf("%d %d",&n,&m);

	int cnt[SIZE]={0},cur=0;
	for(int i=0,tmp ; i<m ; i++){
		scanf("%d",&tmp);

		if(cnt[tmp]==0) cur++;
		cnt[tmp]++;

		if(cur==n){
			printf("1");
			for(int j=1 ; j<=n ; j++){
				cnt[j]--;
				if(cnt[j]==0) cur--;
			}
		}
		else printf("0");
	}

	return 0;
}


