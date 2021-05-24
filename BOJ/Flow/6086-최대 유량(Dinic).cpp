#include<stdio.h>
#include<vector>
#include<queue>
#define SIZE 130
#define INF 1<<30
using namespace std;
int cap[SIZE][SIZE] = { 0 }, f[SIZE][SIZE] = { 0 };
int level[SIZE] = { 0 },work[SIZE];
int S = 'A', T = 'Z';
vector<int> v[SIZE];
int ans = 0;
int fMin(int a, int b) {
	return a > b ? b : a;
}
bool bfs() {
	for (int i = S; i <= 'z'; i++)
		level[i] = -1;

	queue<int> q;
	q.push(S);
	level[S] = 0;

	while (!q.empty()) {
		int cur = q.front();	q.pop();

		for (int next : v[cur]) {
			if (cap[cur][next] - f[cur][next] > 0 && level[next]==-1) {
				level[next] = level[cur] + 1;
				q.push(next);
			}
		}
	}

	return level[T] != -1;
}
int dfs(int cur,int flow) {
	if (cur == T)	return flow;

	for (int &i = work[cur]; i < v[cur].size(); i++) {
		int next = v[cur][i];

		if (level[next] == level[cur] + 1 && cap[cur][next] - f[cur][next] > 0) {
			int min_flow = fMin(flow, cap[cur][next] - f[cur][next]);
			int c = dfs(next, min_flow);

			if (c > 0) {
				f[cur][next] += c;
				f[next][cur] -= c;
				return c;
			}
		}
	}

	return 0;
}
int main() {
	int n,ans=0;	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		char u, V;	int num;	scanf(" %c %c %d", &u, &V, &num);
		cap[u][V] += num;
		cap[V][u] += num;
		v[u].push_back(V);
		v[V].push_back(u);
	}

	while (bfs()) {
		for (int i = S; i <= 'z'; i++)
			work[i] = 0;

		while (1) {
			int flow = dfs(S, INF);
			if (flow == 0)	break;
			ans += flow;
		}

	}

	printf("%d\n", ans);
	return 0;
}
