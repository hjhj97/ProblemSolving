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



char str[200009];
char *ptn[6]={"RGB","RBG","GRB","GBR","BRG","BGR"};
int main(){
	int n;	scanf("%d %s",&n,str+1);

	vector<char> result;
	int cnt[6]={0};

	int min_val=1<<30;
	for(int i=0 ; i<6 ; i++){
		int cur_cnt=0;
		for(int j=1 ; str[j] ; j++){
			if(str[j]!=ptn[i][(j-1)%3]){
				cur_cnt++;
			}
		}
		cnt[i]=cur_cnt;
		min_val=min(min_val,cnt[i]);
	}
	printf("%d\n",min_val);
	for(int i=0 ; i<6 ; i++){
		if(min_val==cnt[i]){
			for(int j=0 ; j<n ;j++){
				printf("%c",ptn[i][j%3]);
			}
			break;
		}
	}


	return 0;
}

