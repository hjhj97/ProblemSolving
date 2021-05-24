#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 10009
struct Tree {
	int to, dist;

	Tree() {}
	Tree(int _to, int _dist) {
		to = _to;
		dist = _dist;
	}
};
int n, ans = 0, max_dist = 0, max_node;
int dist[SIZE] = { 0 };
vector<Tree> tree[SIZE];
queue<Tree> q;
bool visited[SIZE] = { false };
int fMax(int a, int b) {
	return a > b ? a : b;
}
void bfs() {
	q.push(Tree(1, 0));

	while (!q.empty()) {
		auto cur = q.front();	q.pop();
		if (tree[cur.to].size() == 1 && cur.to != 1) { //리프 노드
			if (max_dist < cur.dist) {
				max_dist = cur.dist;
				max_node = cur.to;
				continue;
			}
		}
		for (auto nx : tree[cur.to]) {
			int next = nx.to;
			int next_dist = cur.dist + nx.dist;
			if (cur.to > next) continue;//부모노드로 역행하면 안됨.

			q.push(Tree(next, next_dist));
		}
	}
}
int dfs(int cur) {
	visited[cur] = true;
	if (tree[cur].size() == 1 && cur != max_node) {//리프 노드일때
		return 0;
	}
	for (auto nx : tree[cur]) {
		int next = nx.to;
		int next_dist = nx.dist;
		if (visited[next]) continue;
		dist[cur] = fMax(dist[cur], dfs(next) + next_dist);
	}
	return dist[cur];
}
int main() {
	scanf("%d", &n);

	for (int i = 0; i < n - 1; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		tree[a].push_back(Tree(b, c));
		tree[b].push_back(Tree(a, c));
	}
	bfs();
	int ans = dfs(max_node);
	printf("%d\n", ans);
	return 0;
}
