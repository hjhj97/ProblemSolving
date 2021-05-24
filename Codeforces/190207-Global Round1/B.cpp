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



int arr[100009],gap[100009];
int main(){
	int n,m,k;	scanf("%d %d %d",&n,&m,&k);

	for(int i=1 ; i<=n ; i++)
		scanf("%lld",&arr[i]);


	for(int i=1 ; i<n ; i++){
		gap[i]=arr[i+1]-arr[i];
	}

	sort(gap+1,gap+n);
	int ans=0;
	for(int i=1 ; i<=n-k ; i++)
		ans+=gap[i];
	ans+=k;
	printf("%d\n",ans);

	return 0;
}

