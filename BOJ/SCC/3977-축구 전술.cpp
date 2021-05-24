#include<stdio.h>
#include<stack>
#include<vector>
#include<algorithm>
#define SIZE 100000
using namespace std;
vector<int> v[SIZE];
vector<int> scc[SIZE];
vector<int> scc_adj[SIZE + 10];
stack <int> s;
int low[SIZE + 10], idx[SIZE + 10],scc_idx[SIZE+10],inD[SIZE+10];
bool visited[SIZE + 10] = { false };
int cnt = 1,scc_cnt=0,V,E;
int fMin(int a, int b) {
	return a > b ? b : a;
}
void clear() {
	for (int i = 0; i < V; i++) {
		v[i].clear();	scc[i].clear();	scc_adj[i].clear();
		low[i] = 0;	idx[i] = 0;	scc_idx[i] = 0;	inD[i] = 0;
		visited[i] = false;
		cnt = 1;	scc_cnt = 0;
	}
}
void Dfs(int cur) {
	low[cur] = idx[cur] = cnt++;
	s.push(cur);
	visited[cur] = true;

	for (int next : v[cur]) {
		if (idx[next] == 0) {
			Dfs(next);
			low[cur] = fMin(low[cur], low[next]);
		}
		else if (visited[next])
			low[cur] = fMin(low[cur], low[next]);
	}
	if (low[cur] == idx[cur]) {
		while (1) {
			int top = s.top();	s.pop();
			visited[top] = false;
			scc[scc_cnt].push_back(top);
			scc_idx[top] = scc_cnt;

			if (low[top] == idx[top])	break;
		}
		scc_cnt++;
	}
}
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		scanf("%d %d", &V, &E);
		int inD_Count = 0,index;

		for (int i = 0, a, b; i < E; i++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
		}

		for (int i = 0; i < V; i++)
			if (idx[i] == 0)	Dfs(i);

		for(int i=0 ; i<V ; i++)
			for (int next : v[i]) {
				if (scc_idx[i] == scc_idx[next])	continue;
				scc_adj[scc_idx[i]].push_back(scc_idx[next]);
				inD[scc_idx[next]]++;
			}

		for (int i = 0; i < scc_cnt; i++)
			if (inD[i] == 0) {
				index = i;	inD_Count++;
			}
		if (inD_Count != 1)	printf("Confused\n");
		else {
			sort(scc[index].begin(), scc[index].end());
			for (int i : scc[index])
				printf("%d\n", i);
		}

		clear();
		printf("\n");
	}
	return 0;
}
