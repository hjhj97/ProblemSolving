#include<stdio.h>
#include<queue>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1010
#define INF 1<<30
vector<int> v[SIZE];
vector<pair<int, int>> v_p;
int V, E,M,shortest;
int cost[SIZE][SIZE],dist[SIZE];
priority_queue<int, vector<int>, greater<int>> pq;
int fMin(int a, int b) {
	return a > b ? b : a;
}
int fMax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d %d", &V, &E);

	v_p.push_back(make_pair(-1, -1));

	for (int i = 0; i < E; i++) {
		int a, b,c;	scanf("%d %d %d", &a, &b,&c);
		cost[a][b] = c;
		cost[b][a] = c;
		v[a].push_back(b);
		v[b].push_back(a);
		v_p.push_back(make_pair(a, b));
		//
	}


	for (int z = 0; z < v_p.size(); z++) {
		int first = v_p[z].first, sec = v_p[z].second;


		for (int i = 1; i <= V; i++)
			dist[i] = INF;

		bool visited[SIZE] = { false };
		dist[1] = 0;

		pq.push(1);
		while (!pq.empty()) {
			int cur = pq.top();	pq.pop();

			for (int next : v[cur]) {
				if (first == cur && sec == next) continue;
				if (first == next && sec == first) continue;
				if (!visited[next] && dist[next] > dist[cur] + cost[cur][next]) {
					pq.push(next);
					dist[next] = dist[cur] + cost[cur][next];
				}
			}
			visited[cur] = true;
		}

		if (z == 0) {
			shortest = dist[V];
			continue;
		}

		if (dist[V] == INF) {
			printf("-1\n");
			return 0;
		}
		M = fMax(dist[V], M);
	}
	printf("%d\n", M - shortest);
	return 0;
}
