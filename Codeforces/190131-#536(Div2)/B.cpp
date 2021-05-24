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
// #define IMP
// #define INF
// const int MOD=
struct S{
	int idx,size,cost;

	// S(){}
	// S(int _a,int _b){
	// 	a=_a;
	// 	b=_b;
	// }

	const bool operator<(const S &o) const{
		return cost<o.cost;
	}
};
priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int>> mpq;
map<int,int> mp;
stack<int> st;
set<int> set_i;
/****************************Default Template******************************/

S arr[SIZE],orig[SIZE];
// int size[SIZE],cost[SIZE];
int main(){
	int n,m;	scanf("%d %d",&n,&m);

	for(int i=1 ; i<=n ; i++){
		scanf("%d",&arr[i].size);
		arr[i].idx=i;
	}
	for(int i=1 ; i<=n ; i++){
		scanf("%d",&arr[i].cost);
		orig[i]=arr[i];
	}

	sort(arr+1,arr+n+1);

	queue<int> order;

	for(int i=1 ; i<=n ; i++){
		order.push(arr[i].idx);
		// printf("%d ",arr[i].idx);
	}

	while(m--){
		int t,d;	scanf("%d %d",&t,&d);
		ll total=0;

		ll take=min(d,orig[t].size);
		total += take*orig[t].cost;
		orig[t].size-=take;

		// if(take==d){
		// 	printf("%lld\n",total);
		// 	continue;
		// }
		int remain=d-take;
		bool check=false;
		while(remain){
			if(order.empty()){
				total=0;
				check=true;
				break;
			}
			while(orig[order.front()].size==0){
				order.pop();

				if(order.empty()){
					// printf("0!\n");
					total=0;
					check=true;
					break;
				}
			}

			if(check) {
				break;
			}
			int cur=order.front();
			// printf("cur : %d remain : %d\n",cur,remain);

			ll take2=min(remain,orig[cur].size);
			total+=take2*orig[cur].cost;
			orig[cur].size-=take2;

			remain-=take2;
		}
		printf("%lld\n",total);

	}
	return 0;
}

