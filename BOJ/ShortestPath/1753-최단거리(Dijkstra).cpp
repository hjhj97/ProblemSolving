#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 20010
#define INF 1<<30
struct Edge {
	int to, cost;
	Edge(){}
	Edge(int _to, int _cost) {
		to = _to;
		cost = _cost;
	}
	const bool operator<(const Edge &o) const{
		return cost > o.cost; //pq는 디폴트가 Max heap인데, 다익스트라에서는 Min heap을 필요로 하므로 <가 아닌 >를 해야함.
	}
};
vector<Edge> e[SIZE];
priority_queue<Edge> pq;
int V, E,st;
int dist[SIZE];
bool visited[SIZE] = { false };
int main() {
	scanf("%d %d %d", &V, &E,&st);

	for (int i = 0,a,b,c; i < E; i++) {
		scanf("%d %d %d", &a, &b, &c);
		e[a].push_back(Edge(b, c));
	}
	for (int i = 0; i <= V; i++) {
		dist[i] = INF;
	}

	pq.push(Edge(st, 0));

	while (!pq.empty()) {
		Edge cur_Edge = pq.top();	pq.pop();
		int cur = cur_Edge.to;
		int cur_cost = cur_Edge.cost;
		if(visited[cur]) continue; // not necessary code, but it prevent pq from visiting same node twice.

		for (auto nx : e[cur]) {
			int nextCost = cur_cost + nx.cost;
			if (dist[nx.to] > nextCost && !visited[nx.to]) {
				dist[nx.to] = nextCost;
				pq.push(Edge(nx.to, nextCost));
			}
		}
		visited[cur] = true;
	}
	dist[st] = 0;
	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			printf("INF\n");
		else printf("%d\n", dist[i]);
	}

	return 0;
}
