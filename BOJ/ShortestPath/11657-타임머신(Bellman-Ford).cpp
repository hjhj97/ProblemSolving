#include<stdio.h>
#include<vector>
#define SIZE 555
#define INF 1<<30
using namespace std;
struct Edge {
	int to, cost;
	Edge() {}
	Edge(int to, int cost) :to(to), cost(cost) {}
};
vector <Edge> v[SIZE];
int main() {
	int N, M;	scanf("%d %d", &N, &M);
	int dist[SIZE] = { 0 };
	bool cycle_check = false;

	for (int i = 2; i <= N; i++)
		dist[i] = INF;

	for (int i = 0; i < M; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		v[a].push_back(Edge(b, c));
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			for (auto &e : v[j]) {
				int to = e.to;
				int cost = e.cost;

				if (dist[j] != INF && dist[to]>dist[j] + cost) {
					dist[to] = dist[j] + cost;

					if (i == N)
						cycle_check = true;
				}
			}

	if (cycle_check)
	printf("-1\n");

	else
	for (int i = 2; i <= N; i++) {
	printf("%d\n", (dist[i] != INF) ? dist[i] : -1);
	}

	return 0;
}
