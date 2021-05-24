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


char str[SIZE];
char ans[SIZE];
int main(){
	scanf("%s",str);

	int cnt=0,idx=1;
	ans[0]=str[0];

	for(int i=1 ; str[i] ; i++){
		// printf("%c %c\n",str[i],ans[idx-1]);
		if(str[i]==ans[idx-1]){
			cnt++;
			idx-=1;
			continue;
		}

		ans[idx++]=str[i];
	}
	// printf("%d ",cnt);
	if(cnt%2) printf("Yes\n");
	else printf("No\n");
	

	return 0;
}

