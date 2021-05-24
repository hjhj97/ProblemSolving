#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100009
#define INF 1<<30
int par[SIZE][21], depth[SIZE];
int min_dist[SIZE][21], max_dist[SIZE][21];
int n, q, max_level = 20;
int M, m;
vector<pair<int, int>> tree[SIZE];
void dfs(int node, int parent, int d) {
	depth[node] = depth[parent] + 1;
	par[node][0] = parent;
	if (node == 1) {
		max_dist[1][0] = 0;
		min_dist[1][0] = INF;
	}
	else {
		max_dist[node][0] = d;
		min_dist[node][0] = d;
	}
	for (int i = 1; i <= max_level; i++) {
		par[node][i] = par[par[node][i - 1]][i - 1];
		max_dist[node][i] = max(max_dist[node][i - 1], max_dist[par[node][i - 1]][i - 1]);
		min_dist[node][i] = min(min_dist[node][i - 1], min_dist[par[node][i - 1]][i - 1]);
	}

	for (auto nx : tree[node]) {
		int next = nx.first, nextCost = nx.second;
		if (next != parent) dfs(next, node, nextCost);
	}
	return;
}
void LCA_func(int a, int b) {
	if (depth[a] != depth[b]) {
		if (depth[a] > depth[b]) swap(a, b);

		for (int i = max_level; i >= 0; i--) {
			if (depth[a] <= depth[par[b][i]]) {
				M = max(M, max_dist[b][i]);
				m = min(m, min_dist[b][i]);
				b = par[b][i];
			}
		}
	}
	int lca = a;
	if (a != b) {
		for (int i = max_level; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				M = max(M, max(max_dist[b][i], max_dist[a][i]));
				m = min(m, min(min_dist[b][i], min_dist[a][i]));
				a = par[a][i];	b = par[b][i];
			}
		}
		lca = par[a][0];
		M = max(M, max(max_dist[b][0], max_dist[a][0]));
		m = min(m, min(min_dist[b][0], min_dist[a][0]));
	}
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}
	for (int i = 0; i < 21; i++)
		for (int j = 0; j < SIZE; j++)
			min_dist[j][i] = INF;

	dfs(1, 0, 0);
	scanf("%d", &q);
	while (q--) {
		int a, b;	scanf("%d %d", &a, &b);
		M = 0, m = INF;
		LCA_func(a, b);
		printf("%d %d\n", m, M);
	}

	return 0;
}
