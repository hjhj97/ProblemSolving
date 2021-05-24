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

char str[1010];
int main(){
	scanf("%s",str);
	int len=strlen(str);

	int ver=1,hor=1;
	for(int i=0 ; i<len ; i++){
		if(str[i]=='0'){ //vertical
			printf("%d %d\n",1,ver);
			ver=ver%4+1;
		}
		else{ //'1',horiz
			printf("%d %d\n",3,hor);
			hor=(hor==1)?3:1;
		}
	}


	return 0;
}

