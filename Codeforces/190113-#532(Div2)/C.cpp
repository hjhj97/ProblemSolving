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
	int l,r,idx;

	S(){}
	S(int _l,int _r,int _idx){
		l=_l;
		r=_r;
		idx=_idx;
	}

	const bool operator<(const S &o) const{
		if(l!=o.l) return l<o.l;
		return r<o.r;
	}
};
priority_queue<int> pq;
priority_queue<int,vector<int>,greater<int>> mpq;
map<int,int> mp;
stack<int> st;
set<int> set_i;
/****************************Default Template******************************/

#define PI 3.14159265
int main(){
	double n,r;	scanf("%lf %lf",&n,&r);

	double radian=PI*(n-2)/(2*n);
	double cos_theta=cos(radian);
	double R=r*cos_theta/(1-cos_theta);


	printf("%.15lf\n",R);
	return 0;
}

