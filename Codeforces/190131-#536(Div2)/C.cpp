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



int arr[300009];
int main(){
	int n;	scanf("%d",&n);

	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}

	sort(arr,arr+n);
	ll ans=0;

	for(int i=0 ; i<n/2 ; i++){
		ans+=pow(arr[i]+arr[n-i-1],2);
	}
	printf("%lld\n",ans);
	return 0;
}

