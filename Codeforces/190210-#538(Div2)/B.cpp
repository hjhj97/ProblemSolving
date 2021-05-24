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



int arr[SIZE],sorted[SIZE];
int main(){
	int n,m,k;	scanf("%d %d %d",&n,&m,&k);

	for(int i=1 ; i<=n ; i++){
		scanf("%d",&arr[i]);
		sorted[i]=arr[i];
	}
	sort(sorted+1,sorted+n+1,greater<int>());

	ll sum=0;
	for(int i=1 ; i<=m*k ; i++){
		mp[sorted[i]]++;
		sum+=sorted[i];
	}

	printf("%lld\n",sum);
	vector<int> v;
	for(int i=1,cnt=0 ; i<=n ; i++){
		if(mp[arr[i]]>0){
			cnt++;
			mp[arr[i]]--;
		}
		if(cnt==m){
			v.push_back(i);
			if(v.size()==k-1) break;
			cnt=0;
		}
	}
	for(int here:v) printf("%d ",here);

	return 0;
}

