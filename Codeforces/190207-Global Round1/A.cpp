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



int arr[100009];
int main(){
	int b,k;	scanf("%d %d",&b,&k);

	for(int i=1 ; i<=k ; i++)
		scanf("%d",&arr[i]);

	int ans=0;
	if(b%2){

		for(int i=1 ; i<=k ; i++){
			ans+=(arr[i]%2);
		}
	}
	else{
		if(arr[k]%2) ans=1;
	}
	
	printf("%s",(ans%2)?"odd":"even");
	return 0;
}

