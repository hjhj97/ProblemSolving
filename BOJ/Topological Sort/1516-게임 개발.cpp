#include<stdio.h>
#include<queue>
#include<vector>
#define SIZE 511
using namespace std;
vector<int> v[SIZE];
queue<int> q;
int V, cost[SIZE], inD[SIZE] = { 0 }, dist[SIZE];
int fMax(int a, int b) {
	return a < b ? b : a;
}
int main() {
	scanf("%d", &V);

	for (int i = 0; i < V ; i++) {
		scanf("%d", &cost[i]);
		while (1) {
			int pre;	 scanf("%d", &pre);
			if (pre == -1)	break;
			v[pre - 1].push_back(i);
			inD[i]++;
		}
	}
	for (int i = 0; i < V; i++)
		if (inD[i] == 0) {
			q.push(i);
			dist[i] = cost[i];
		}

	while (!q.empty()) {
		int cur = q.front();	q.pop();

		for (int next : v[cur]) {
			int nextCost = dist[cur] + cost[next];
			dist[next] = fMax(dist[next], nextCost);

			if (--inD[next] == 0)
				q.push(next);
		}
	}

	for (int i = 0; i < V; i++)
		printf("%d\n", dist[i]);

	return 0;
}
