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
	int n;	scanf("%d",&n);
	int arr[1011];

	for(int i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);

	int ans=-1,min_gap=1<<30;
	for(int i=1 ; i<=100 ; i++){
		int cur_sum=0;
		for(int j=0 ; j<n ; j++){
			// int gap=abs(arr[j]-i);
			int gap=min(abs(arr[j]-(i-1)),min(abs(arr[j]-(i)),abs(arr[j]-(i+1))));
			cur_sum+=gap;
			// cur_sum+=abs(arr[j]-i);
		}
		if(min_gap>cur_sum){
			min_gap=cur_sum;
			ans=i;
		}
	}
	printf("%d %d\n",ans,min_gap);

	return 0;
}
