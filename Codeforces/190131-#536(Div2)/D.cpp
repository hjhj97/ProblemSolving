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
#define SIZE 100009
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



int V,E;
vector<int> edge[SIZE];
vector<int> ans;
bool visited[SIZE]={0};
// void dfs(int node){
// 	ans.push_back(node);
// 	visited[node]=true;
// 	for(int next:edge[node]){
// 		if(!visited[next]){
// 			dfs(next);
// 		}
// 	}
// 	return;
// }
void bfs(void){

	// queue<int> q;
	mpq.push(1);
	// q.push(1);
	while(!mpq.empty()){
		int top=mpq.top();	mpq.pop();
		ans.push_back(top);
		// printf("%d\n",top);
		visited[top]=true;
		int min_node=SIZE+100;

		for(int next:edge[top]){
			if(!visited[next]){
				mpq.push(next);
				visited[next]=true;
			}
		}
	}

}
int main(){
	scanf("%d %d",&V,&E);

	for(int i=0 ; i<E ; i++){
		int u,v;	scanf("%d %d",&u,&v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}

	for(int i=1 ; i<=V ; i++){
		unique(edge[i].begin(),edge[i].end());
		sort(edge[i].begin(),edge[i].end());
	}

	bfs();
	for(int here:ans)
		printf("%d ",here);

	return 0;
}
