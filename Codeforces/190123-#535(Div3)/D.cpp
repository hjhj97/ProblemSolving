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



char str[200009],result[200009]={0};
int main(){
	int n;	scanf("%d %s",&n,str+1);

	char rgb[3]={'R','G','B'};

	int cnt=0;
	result[0]=str[1];
	for(int i=1+1 ; i<=n ; i++){
		if(str[i]==str[i-1]){
			for(int j=0 ; j<3 ; j++){
				if(rgb[j]!=str[i] && rgb[j]!=str[i+1]){
					cnt++;
					str[i]=rgb[j];
					// result[i]=rgb[j];
					break;
				}
			}
		}
	}

	printf("%d\n",cnt);
	printf("%s",str+1);
	// for(int i=1 ; i<=n ; i++){
	// 	if(!result[i]) printf("%c",str[i]);
	// 	else printf("%c",result[i]);
	// }

	return 0;
}

