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
// #define IMP
// #define INF
// const int MOD=
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

	for(int i=0 ; i<=30 ; i++){
		set_i.insert(pow(2,i)-1);
	}
	while(t--){
		int a;	scanf("%d",&a);

		if(set_i.count(a)){
			vector<int> v;
			for(int i=1 ; i<=sqrt(a) ; i++){
				if(a%i==0){
					v.push_back(i);
					v.push_back(a/i);
				}
			}
			sort(v.begin(),v.end());

			printf("%d\n",v[v.size()-1-1]);
		}		
		else{

			for(auto here:set_i){
				if(here>a){
					printf("%d\n",here);
					break;
				}
			}
		}
	}

	

	return 0;
}

