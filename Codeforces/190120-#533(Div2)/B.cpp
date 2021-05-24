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


char str[200009];
int main(){
	int n,k;	scanf("%d %d",&n,&k);
	scanf("%s",str);

	int ans=0;
	for(int i='a' ; i<='z' ; i++){
		int cur_level=0,cnt=0;

		for(int j=0 ; j<n ; j++){
			if(str[j]==i){
				cnt++;
			}
			else cnt=0;

			if(cnt==k){
				cur_level++,cnt=0;
			}
		}

		ans=max(cur_level,ans);
	}
	printf("%d\n",ans);

	return 0;
}

