#include<stdio.h>
#include<vector>
#include<algorithm>
#define SIZE 40009
using namespace std;
int n, q, max_level=20;
int par[SIZE][21], depth[SIZE], dist[SIZE][21];
vector<pair<int, int>> tree[SIZE];
void dfs(int node, int parent, int d) {
	depth[node] = depth[parent] + 1;
	par[node][0] = parent;
	dist[node][0] = d;

	for (int i = 1; i <= max_level; i++) {
		par[node][i] = par[par[node][i - 1]][i - 1];
		dist[node][i] = dist[node][i - 1] + dist[par[node][i - 1]][i - 1];
	}

	for (auto nx : tree[node]) {
		int next = nx.first, nextCost = nx.second;
		if (next != parent) dfs(next, node, nextCost);
	}

	return;
}
int LCA_Dist(int a, int b) {
	int result = 0;
	if (a != b) {
		if (depth[a] > depth[b]) swap(a, b);
		for (int i = max_level; i >= 0; i--) {
			if (depth[a] <= depth[par[b][i]]) {
				result += dist[b][i];
				b = par[b][i];
			}
		}
	}

	if (a != b) {
		for (int i = max_level; i >= 0; i--) {
			if (par[a][i] != par[b][i]) {
				result += (dist[a][i] + dist[b][i]);
				a = par[a][i];	b = par[b][i];
			}
		}
		result += (dist[a][0] + dist[b][0]);
	}
	return result;
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);

		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}
	dfs(1, 0, 0);
	scanf("%d", &q);

	while (q--) {
		int a, b;	scanf("%d %d", &a, &b);

		printf("%d\n", LCA_Dist(a, b));
	}
	return 0;
}
