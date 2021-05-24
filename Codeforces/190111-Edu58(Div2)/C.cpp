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
	int l,r,idx;

	S(){}
	S(int _l,int _r,int _idx){
		l=_l;
		r=_r;
		idx=_idx;
	}
	const bool operator<(const S &o) const{
		return l<o.l;
	}
};
// priority_queue<int> pq;
// priority_queue<int,vector<int>,greater<int>> mpq;
// map<int,int> mp;
stack<int> st;
// set<int> set_i;
/****************************Default Template******************************/

int main(){
	int t;	scanf("%d",&t);

	while(t--){
		int n;	scanf("%d",&n);
		vector<S> v(n);
		vector<int> buf(n,2);

		for(int i=0 ; i<n ; i++){
			int a,b;	scanf("%d %d",&a,&b);
			v[i]=S(a,b,i);
		}

		sort(v.begin(),v.end());

		int max_val=v[0].r;
		buf[0]=1;

		for(int i=1 ; i<n ; i++){
			int l=v[i].l,r=v[i].r;

			if(max_val<l) break;

			max_val=max(max_val,r);
			buf[i]=1;
		}

		if(buf[n-1]==1){
			printf("-1");
		}

		else{	
			vector<int> print(n);

			for(int i=0 ; i<n ; i++)
				print[v[i].idx]=buf[i];

			for(int here:print)
				printf("%d ",here);
		}
		printf("\n");

	}

	return 0;
}

