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
#define SIZE 500009
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



char str[SIZE];
int main(){
	scanf("%s",str+1);

	int len=strlen(str+1),ans=-1;
	int l=1,r=len;

	for(; l<=len;l++)
		if(str[l]=='[')
			break;
	for(l++;l<=len ; l++)
		if(str[l]==':')
			break;
	for( ;r>0 ; r--)
		if(str[r]==']')
			break;
	for(r--;r>0;r--)
		if(str[r]==':')
			break;

	if(r<=l){
		ans=-1;
	}
	else{
		ans=4;
		for(int i=l ; i<=r ; i++)
			if(str[i]=='|')
				ans++;
	}

	printf("%d\n",ans);
	return 0;
}
/*
[:[|]:]
->
*/

