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




int main(){
	int t;	scanf("%d",&t);

	while(t--){
		int n;	scanf("%d",&n);
		char str[333];
		scanf("%s",str);

		if(n==2){
			if(str[0]>=str[1]){
				printf("NO\n");
				continue;
			}
		}
		printf("YES\n");
		printf("2\n");
		printf("%c ",str[0]);

		for(int i=1 ; str[i] ; i++)
			printf("%c",str[i]);
		printf("\n");
	}

	

	return 0;
}

