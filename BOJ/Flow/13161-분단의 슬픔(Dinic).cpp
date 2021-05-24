#include<stdio.h>
#include<queue>
#include<vector>
#include<set>
using namespace std;
#define SIZE 511
#define INF 1<<30
vector<int> v[SIZE];
vector<int> A;
vector<int> B;
set<int> s;
int cap[SIZE][SIZE], f[SIZE][SIZE], work[SIZE], level[SIZE];
int n, S, T, ans = 0;
int fMin(int a, int b) {
	return a > b ? b : a;
}
bool bfs() {
	for (int i = 0; i <= T; i++)
		level[i] = -1;

	queue<int> q;
	q.push(S);
	level[S] = 0;

	while (!q.empty()) {
		int cur = q.front();	q.pop();

		for (int next : v[cur]) {
			if (level[next] == -1 && cap[cur][next] - f[cur][next] > 0) {
				level[next] = level[cur] + 1;
				q.push(next);
			}
		}
	}

	return level[T] != -1;
}
int dfs(int cur, int flow) {
	if (cur == T) return flow;

	for (int &i = work[cur]; i < v[cur].size(); i++) {
		int next = v[cur][i];

		if (level[next] == level[cur] + 1 && cap[cur][next]-f[cur][next]>0) {
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
void find(void) {
	queue<int> q;
	q.push(S);
	bool visited[SIZE] = { false };
	visited[S] = true;

	while (!q.empty()) {
		int cur = q.front();	q.pop();
		if (cur != S)	A.push_back(cur);

		for(int next : v[cur]) {
			if (visited[next])	continue;
			if (cap[cur][next] - f[cur][next] > 0) {
				q.push(next);
				visited[next] = true;
				s.insert(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (s.count(i) == 0)
			B.push_back(i);
	}

}
int main() {
	scanf("%d", &n);
	S = 0, T = n + 1;

	for (int i = 1; i <= n; i++) {
		int area;	scanf("%d", &area);
		if (area == 1) {
			v[S].push_back(i);
			cap[S][i] = INF;
		}
		else if (area == 2) {
			v[i].push_back(T);
			cap[i][T] = INF;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &cap[i][j]);
			if(i!=j) v[i].push_back(j);
		}
	}

	while (bfs()) {
		for (int i = 0; i <= T; i++)
			work[i] = 0;

		while (1) {
			int flow = dfs(S, INF);
			if (flow == 0)	break;
			ans += flow;
		}

	}
	find();

	printf("%d\n", ans);
	for (int i : A)
		printf("%d ", i);
	printf("\n");
	for (int i : B)
		printf("%d ", i);
	printf("\n");
	return 0;
}
