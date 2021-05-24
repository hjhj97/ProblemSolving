#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100009
vector<int> tree[SIZE];
int n, q, max_level = 20;
int depth[SIZE], par[SIZE][21];
void dfs(int node, int parent) {
	depth[node] = depth[parent] + 1;
	par[node][0] = parent;

	for (int i = 1; i <= max_level; i++) {
		par[node][i] = par[par[node][i - 1]][i - 1];
	}
	for (int next : tree[node])
		if(next!=parent) dfs(next, node);
	return;
}
int LCA(int u, int v) {
	if (depth[u] != depth[v]) {
		if (depth[u] > depth[v]) swap(u, v);

		for (int i = max_level; i >= 0; i--) {
			if (depth[u] <= depth[par[v][i]])
				v = par[v][i];
		}
	}
	int lca = u;
	if (u != v) {
		for (int i = max_level; i >= 0; i--) {
			if (par[u][i] != par[v][i]) {
				u = par[u][i];	v = par[v][i];
			}
		}
		lca = par[u][0];
	}
	return lca;
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int a, b;	scanf("%d %d", &a, &b);
		tree[a].push_back(b);	tree[b].push_back(a);
	}

	scanf("%d", &q);
	dfs(1, 0);
	while (q--) {
		int a, b;	scanf("%d %d", &a, &b);
		printf("%d\n", LCA(a,b));
	}

	return 0;
}
