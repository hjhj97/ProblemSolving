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
	int n,k;	scanf("%d %d",&n,&k);

	int tabs[111];
	for(int i=0 ; i<n ; i++){
		scanf("%d",&tabs[i]);
	}

	int ans=-1;
	for(int i=0 ; i<k ; i++){
		int s=0,e=0;
		for(int j=0 ; j<n ; j++){
			if((j-i)%k==0) continue;
			if(tabs[j]==1){
				e++;
			}
			else s++;
		}
		ans=max(ans,abs(s-e));
	}
	printf("%d\n",ans);
	return 0;
}

