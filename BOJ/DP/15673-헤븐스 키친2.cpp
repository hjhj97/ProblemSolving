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
#include<stack>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define SIZE 1000009
// #define MOD 1000000007
// #define IMP


priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int>> mpq;
map<int,int> mp;


int l_max[SIZE],r_max[SIZE],l_min[SIZE],r_min[SIZE],arr[SIZE];
int l_maxS[SIZE],r_maxS[SIZE],l_minS[SIZE],r_minS[SIZE];

int fabs(int a){
	return a>0?a:-a;
}
int main(){
	int n;	scanf("%d",&n);


	for(int i=1 ; i<=n ; i++){
		scanf("%d",&arr[i]);
	}

	for(int i=1 ; i<=n ; i++){
		l_max[i]=max(0,l_max[i-1]+arr[i]);
		l_maxS[i]=max(l_maxS[i-1],l_max[i]);

		l_min[i]=min(0,l_min[i-1]+arr[i]);
		l_minS[i]=min(l_minS[i-1],l_min[i]);
	}

	for(int i=n ; i>=1 ; i--){
		r_max[i]=max(0,r_max[i+1]+arr[i]);
		r_maxS[i]=max(r_maxS[i+1],r_max[i]);

		r_min[i]=min(0,r_min[i+1]+arr[i]);
		r_minS[i]=min(r_minS[i+1],r_min[i]);
	}
    
	ll ans=0;
	if(n==2) ans=(ll)arr[1]*arr[2];
	for(int i=1 ; i<=n && n!=2; i++){
		ans=max(ans,(ll)l_max[i]*r_maxS[i+1]);
		ans=max(ans,(ll)l_min[i]*r_minS[i+1]);
	}

	printf("%lld\n",ans);
	return 0;
}

