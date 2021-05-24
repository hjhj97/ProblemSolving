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
	int arr[133];
	int n;	scanf("%d",&n);

	for(int i=0 ; i<n ; i++){
		scanf("%d",&arr[i]);
	}

	sort(arr,arr+n);
	int max_val=arr[n-1];

	for(int i=0 ; i<n ; i++){
		if(max_val%arr[i]==0){
			if(set_i.count(arr[i])==0){
				set_i.insert(arr[i]);
				arr[i]=-1;
			}
		}
	}

	int sec=0;
	for(int i=0 ; i<n ; i++){
		sec=max(sec,arr[i]);
	}
	
	printf("%d %d\n",max_val,sec);
	return 0;
}

