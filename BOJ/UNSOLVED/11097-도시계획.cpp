#include<stdio.h>
#include<vector>
#include<stack>
#define SIZE 300
using namespace std;
vector<int> v[SIZE + 10];
vector<int> scc[SIZE + 10];
vector<int> scc_adj[SIZE + 10];
vector<int> ans[SIZE + 10];
stack <int> s;
int low[SIZE + 10], idx[SIZE + 10], scc_idx[SIZE + 10];
bool visited[SIZE + 10] = { false }, route_check[SIZE + 10][SIZE + 10] = { false };
int cnt = 1, scc_cnt = 0, n;
int fMin(int a, int b) {
	return a > b ? b : a;
}
void clear() {
	for (int i = 0; i <= n; i++) {
		v[i].clear();	scc[i].clear();
		low[i] = 0;	idx[i] = 0;	scc_idx[i] = 0;
		visited[i] = false;
		cnt = 1;	scc_cnt = 0;
		for (int j = 0; j <= n; j++)
			route_check[i][j] = false;
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
			if (idx[top] == low[top])	break;
		}
		scc_cnt++;
	}
}
int main() {
	int t;	scanf("%d ", &t);

	while (t--) {
		int E = 0;
		scanf("%d ", &n);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n + 1; j++) {
				char a;	scanf("%c", &a);
				if (i == j)	continue;
				if (a == '1')	v[i].push_back(j);
			}
		}
		for (int i = 1; i <= n; i++)
			if (idx[i] == 0)	Dfs(i);


		//scc간의 route출력
		for(int i=1 ; i<=n ; i++)
			for (int next : v[i]) {
				if (scc_idx[i] == scc_idx[next])	continue;
				if (!route_check[scc_idx[i]][scc_idx[next]]) {
					scc_adj[scc_idx[i]].push_back(scc_idx[next]);
					route_check[scc_idx[i]][scc_idx[next]] = true;
					ans[i].push_back(next);
					E++;
					//printf("*%d %d\n", i, next);
				}
			}

		//scc내부에서의 route출력
		for (int i = 0; i < scc_cnt; i++)
			if(scc[i].size()>=2)
				for (int j = 0; j < scc[i].size(); j++) {
					//printf("%d %d\n", scc[i][j], scc[i][(j + 1) % scc[i].size()]);
					int a = scc[i][j], b = scc[i][(j + 1) % scc[i].size()];
					ans[a].push_back(b);
					E++;
				}
		printf("%d\n", E);

		for (int i = 1; i <= n; i++)
			for (int j : ans[i])
				printf("%d %d\n", i, j);

		clear();
	}

	return 0;
}
/*
2

3
111
011
001

4
1111
1111
0011
0011

4
1110
1110
0010
0001
*/
