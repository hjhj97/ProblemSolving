#include<stdio.h>
#include<vector>
#include<queue>
#define SIZE 10010
using namespace std;
struct Edge {
	int to, cost;
	Edge() {}
	Edge(int _to, int _cost) {
		to = _to;
		cost = _cost;
	}

};
int V, E;
int inD[SIZE], dist[SIZE];
vector<Edge> v[SIZE];
vector<Edge> rev[SIZE];
int fMax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d %d", &V, &E);

	for (int i = 0, a, b, c; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(Edge(b, c));
		rev[b].push_back(Edge(a, c));
		inD[b]++;
	}
	int st, end;	scanf("%d %d", &st, &end);

	queue<int> q;
	q.push(st);

	while (!q.empty()) {
		int cur = q.front();	q.pop();

		for (auto nx : v[cur]) {
			int next = nx.to;
			int nextCost = dist[cur] + nx.cost;
			dist[next] = fMax(dist[next], nextCost);

			if (--inD[next] == 0)
				q.push(next);
		}
	}
	int ans1 = dist[end], ans2 = 0;
	bool visited[SIZE] = { false };
	queue<int> rq;
	rq.push(end);

	while (!rq.empty()) {
		int cur = rq.front();	rq.pop();
		for (auto nx : rev[cur]) {
			int next = nx.to;
			int nextCost = nx.cost;
			if (dist[cur] - nextCost == dist[next]) {
				ans2++;
				if (!visited[next]) {
					rq.push(next);
				}
				visited[next] = true;
			}
		}
	}

	printf("%d\n%d\n", ans1, ans2);
	return 0;
}
