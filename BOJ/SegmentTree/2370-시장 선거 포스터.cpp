#include<stdio.h>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
#define SIZE 10009
int n,start_i,tree_size;
map<int,int> mp;
vector<int> cord;
set<int> s;
pair<int,int> post[SIZE];
int tree[SIZE*8],lazy[SIZE*8];
void propagate(int node,int cl,int cr){
	if(lazy[node]!=0){
		tree[node]=(cr-cl+1);
		if(node<start_i){
			lazy[node*2]=1;
			lazy[node*2+1]=1;
		}
		lazy[node]=0;
	}
	return;
}
int getSum(int node,int ql,int qr,int cl,int cr){
	propagate(node,cl,cr);
	if(qr<cl || cr<ql) return 0;
	if(qr >= cr && ql <= cl) return tree[node];

	int mid=(cl+cr)/2;
	return tree[node]=getSum(node*2,ql,qr,cl,mid)+getSum(node*2+1,ql,qr,mid+1,cr);
}
void update(int node,int ql,int qr,int cl,int cr){
	propagate(node,cl,cr);
	if(qr<cl || cr<ql) return;
	if(qr >= cr && ql <= cl){
		lazy[node]=1;
		propagate(node,cl,cr);
		return;
	}
	int mid=(cl+cr)/2;
	update(node*2,ql,qr,cl,mid);
	update(node*2+1,ql,qr,mid+1,cr);

	tree[node]=tree[node*2]+tree[node*2+1];
	return;
}
int main(){
	scanf("%d",&n);

	for(int i=0 ; i<n ; i++){
		int st,end;	scanf("%d %d",&st,&end);

		if(!s.count(st)){
			cord.push_back(st);
			s.insert(st);
	}

		if(!s.count(end)){
			cord.push_back(end);
			s.insert(end);
	}
		post[i]=make_pair(st,end);
	}

	sort(cord.begin(),cord.end());
	int adjusted_n=cord.size();

	for(int i=0 ; i<cord.size() ; i++){
		mp[cord[i]]=i+1;
	}

	for(start_i=1 ; start_i<adjusted_n ; start_i*=2);
	tree_size=start_i*2;
	
	int ans=0;
	for(int i=n-1 ; i>=0 ; i--){
		int st=mp[post[i].first],end=mp[post[i].second];

		if(getSum(1,st,end,1,start_i)!=end-st+1) ans++;
		
		update(1,st,end,1,start_i);	
	}

	printf("%d\n",ans);

	return 0;
}