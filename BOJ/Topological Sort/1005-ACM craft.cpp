#include<stdio.h>
#include<queue>
#include<vector>
#define SIZE 1001
using namespace std;
int V, E;
int fMax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		int cost[SIZE] = { 0 }, dist[SIZE] = { 0 }, inD[SIZE] = { 0 };
		vector<int> v[SIZE];
		queue<int> q;
		scanf("%d %d", &V, &E);

		for (int i = 1; i <= V; i++)
			scanf("%d", &cost[i]);

		for (int i = 0, a, b; i < E; i++) {
			scanf("%d %d", &a, &b);
			v[a].push_back(b);
			inD[b]++;
		}
		int w;	scanf("%d", &w);
		for (int i = 1; i <= V; i++)
			if (inD[i] == 0) {
				q.push(i);
				dist[i] = cost[i];
			}
		while (!q.empty()) {
			int cur = q.front();	q.pop();

			for (int next : v[cur]) {
				int nextCost = dist[cur] + cost[next];
				dist[next] = fMax(dist[next], nextCost);

				if (--inD[next] == 0) {
					q.push(next);
				}
			}
		}

		printf("%d\n", dist[w]);
	}
	return 0;
}
