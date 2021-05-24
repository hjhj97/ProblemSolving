#include<stdio.h>
#include<queue>
#include<vector>
#define	SIZE 510
#define INF 1<<30
using namespace std;
struct Edge {
	int to, cost;

	Edge(int _to, int _cost) {
		to = _to;
		cost = _cost;
	};

	const bool operator <(const Edge&o) const {
		return cost > o.cost;
	}
};
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	while (1) {
		int V, e;	scanf("%d %d", &V, &e);
		if (V == 0 && e == 0)
			break;

		bool visited[SIZE] = { false }, visited2[SIZE] = { false };
		int minD[SIZE];
		int minD2[SIZE];
		vector <Edge> v[SIZE];
		priority_queue<Edge> pq;
		queue<int> q;

		for (int i = 0; i < V; i++) {
			minD[i] = INF;	minD2[i] = INF;
			v[i].push_back(Edge(i, 0));
		}
		int start, end;	scanf("%d %d", &start, &end);

		for (int i = 0, a, b, c; i < e; i++) {
			scanf("%d %d %d", &a, &b, &c);
			v[a].push_back(Edge(b, c));
		}

		pq.push(Edge(start, 0));

		while (!pq.empty()) {
			Edge cur = pq.top();	pq.pop();
			if (visited[cur.to])	continue;

			for (int i = 0; i < v[cur.to].size(); i++) {
				int next = v[cur.to][i].to;
				minD[next] = fMin(minD[next], cur.cost + v[cur.to][i].cost);

				pq.push(Edge(next, minD[next]));
			}
			visited[cur.to] = true;
		}
		q.push(end);
		while (!q.empty()) {
			int cur = q.front(); q.pop();

			for (int i = 0; i < V; i++) {
				for (int j = 0; j < v[i].size(); j++)
					if (v[i][j].to == cur)
						if (minD[cur] == minD[i] + v[i][j].cost && v[i][j].cost != -1) {
							v[i][j].cost = -1;
							q.push(i);
						}
			}
		}
		pq.push(Edge(start, 0));

		while (!pq.empty()) {
			Edge cur = pq.top();	pq.pop();
			if (visited2[cur.to])	continue;

			for (int i = 0; i < v[cur.to].size(); i++) {
				int next = v[cur.to][i].to;
				if (v[cur.to][i].cost == -1)	continue;

				minD2[next] = fMin(minD2[next], cur.cost + v[cur.to][i].cost);
				pq.push(Edge(next, minD2[next]));
			}
			visited2[cur.to] = true;
		}
		printf("%d\n", (minD2[end] == INF) ? -1 : minD2[end]);
	}
}
