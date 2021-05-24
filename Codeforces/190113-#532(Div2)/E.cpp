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
	int q;	scanf("%d",&q);

	int max_x=0,max_y=0;
	while(q--){
		char str[3];
		int x,y;
		scanf("%s %d %d",str,&x,&y);

		// printf("%c %d %d\n",str[0],x,y);
		// int max_x=0,max_y=0;

		if(str[0]=='+'){
			if(x<y) swap(x,y);
			max_x=max(max_x,x);
			max_y=max(max_y,y);
		}
		else{ //?
			if(x<y) swap(x,y);
			if(max_x<=x && max_y<=y){
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	
	return 0;
}

