#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
#include<map>
#define SIZE 100009
#define INF 1<<30
using namespace std;
vector<pair<int, int>> tree[SIZE];
vector<pair<int, int>> other[SIZE];
set<int> s;
map<int, int> dist[SIZE];
int V, E,level=20;
int p[SIZE],par[21][SIZE],tree_dist[21][SIZE];
int find(int a) {
	if (p[a] == -1) return a;
	return p[a]=find(p[a]);
}
void merge(int a, int b) {
	if (p[a] == p[b]) return;
	a = find(p[a]);
	b = find(p[b]);
	p[b] = a;
	return;
}
void dfs(int node,int parent) {
	par[node][0] = parent;
	tree_dist[node][0];

	for (int i = 1; i <= level; i++) {

	}
}
int LCA(int a, int b) {

}
int main() {
	scanf("%d %d", &V, &E);

	for (int i = 1; i <= V; i++) p[i] = -1;
	for (int i = 0; i < E; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);

		if (find(a) == find(b)) {
			other[a].push_back(make_pair(b, c));
			other[b].push_back(make_pair(a, c));
			continue;
		}
		if (!s.count(a)) s.insert(a);
		if (!s.count(b)) s.insert(b);
		merge(a, b);
		tree[a].push_back(make_pair(b, c));
		tree[b].push_back(make_pair(a, c));
	}

	for (int now : s) {
		int inQ[SIZE] = { 0 };
		bool visited[SIZE] = { false };
		queue<int> qu;
		for (int i = 1; i <= V; i++) {
			dist[now][i] = INF;
		}
		dist[now][now] = 0;

		qu.push(now);
		visited[now] = true;
		while (!qu.empty()) {
			int cur = qu.front();	qu.pop();
			inQ[cur] = 0;

			for (auto nx : tree[cur]) {
				int next = nx.first, nextCost = dist[now][cur] + nx.ssecond;
				if (visited[next]) continue;
				if (dist[now][next] > nextCost) {
					dist[now][next] = nextCost;

					if (!inQ[next]) {
						qu.push(next);
						inQ[next] = 1;
					}
				}
			}
			visited[cur] = true;
		}
	}

	int q;	scanf("%d", &q);

	while (q--) {
		int u, v;	scanf("%d %d", &u, &v);
	}

	return 0;
}