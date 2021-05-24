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
// #define INF
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


int n,k;
int dmg[SIZE];
char str[SIZE];
int main(){
	scanf("%d %d",&n,&k);

	for(int i=1 ; i<=n ; i++)
		scanf("%d",&dmg[i]);
	scanf("%s",str+1);

	ll ans=0;

	int st=1;
	for(int i=1 ; i<=n ; i++){
		if(str[i]!=str[i+1]){
			sort(dmg+st,dmg+i+1,greater<int>());
			
			for(int j=st ; j<st+k && j<=i ; j++){
				ans+=dmg[j];
			}

			st=i+1;
		}
	}

	printf("%lld\n",ans);
	return 0;
}
