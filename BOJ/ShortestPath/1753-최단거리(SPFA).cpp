#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 20010
#define INF 1<<30
struct Edge {
	int to, cost;
	Edge() {}
	Edge(int _to, int _cost) {
		to = _to;
		cost = _cost;
	}
	const bool operator<(const Edge &o) const {
		return cost > o.cost;
	}
};
vector<Edge> e[SIZE];
queue<int> q;
int V, E, st;
int dist[SIZE];
int main() {
	scanf("%d %d %d", &V, &E, &st);

	for (int i = 0, a, b, c; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		e[a].push_back(Edge(b, c));
	}
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	dist[st] = 0;
	int inQ[SIZE] = { 0 };
	q.push(st);
	inQ[st] = 1;

	while (!q.empty()) {
		int cur = q.front();	q.pop();
		inQ[cur] = 0;

		for (auto &nx : e[cur]) {
			int next = nx.to;
			int nextCost = nx.cost;

			if (dist[next]>dist[cur]+nextCost) {
				dist[next] = dist[cur] + nextCost;
				if (inQ[next] == 0) {
					q.push(next);
					inQ[next] = 1;
				}
			}
		}

	}

	for (int i = 1; i <= V; i++) {
		if (dist[i] >= INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}

	return 0;
}
/*
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6
*/
