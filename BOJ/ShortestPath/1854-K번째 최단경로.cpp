#include<stdio.h>
#include<queue>
#include<vector>
#define SIZE 1010
#define INF 1<<30
using namespace std;
struct Edge {
	int to, cost;

	Edge(int _to, int _cost) {
		to = _to;
		cost = _cost;
	};

	const bool operator < (const Edge &o) const {
		return cost > o.cost;
	}
};

vector<Edge> v[SIZE];
priority_queue<Edge> q;
priority_queue<int> Vpq[SIZE];
vector<int> Vcost[SIZE];
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int minD[SIZE];
	int V, e, k;	scanf("%d %d %d", &V, &e, &k);
	bool visited[SIZE] = { false };

	for (int i = 1; i <= V; i++) {
		minD[i] = INF;
	}
	for (int i = 0, a, b, c; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(Edge(b, c));
	}

	q.push(Edge(1, 0));
	Vpq[1].push(0);

	while (!q.empty()) {
		Edge cur = q.top();	q.pop();

		for (int i = 0; i < v[cur.to].size(); i++) {
			int next = v[cur.to][i].to, nextCost = v[cur.to][i].cost;

			if (Vpq[next].size() < k)
				Vpq[next].push(cur.cost + nextCost);

			else if (Vpq[next].top() > cur.cost + nextCost) {
				Vpq[next].pop();
				Vpq[next].push(cur.cost + nextCost);
			}
			else continue;

			q.push(Edge(next, cur.cost+nextCost));
		}
	}

	for (int i = 1; i <= V; i++) {
		if (Vpq[i].size() >= k)
			printf("%d\n", Vpq[i].top());

		else printf("-1\n");
	}
	return 0;
}
/*
5 10 10
1 2 2
1 3 7
1 4 5
1 5 6
2 4 2
2 3 4
3 4 6
3 5 8
5 2 4
5 4 1
*/
