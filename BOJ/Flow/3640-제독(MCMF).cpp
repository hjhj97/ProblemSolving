#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 1011*2
#define INF 1<<30
vector<int> v[SIZE];
int cap[SIZE][SIZE], f[SIZE][SIZE], d[SIZE][SIZE];
int V, E, T, S, N;
void clear(void) {
	for (int i = 0; i <= T; i++) {
		v[i].clear();
		for (int j = 0; j <= T; j++) {
			cap[i][j] = 0;
			f[i][j] = 0;
			d[i][j] = 0;
		}
	}
	return;
}
int main() {
	while (scanf("%d %d", &V, &E) != EOF) {
		int ans = 0;
		T = 2*V+1, N = V, S = 1 + N;

		for (int i = 0; i < E; i++) {
			int a, b, c;	scanf("%d %d %d", &a, &b, &c);
			int _a = a + N, _b = b + N;
			v[_a].push_back(b);
			v[_b].push_back(a);
			v[b].push_back(_a);

			d[_a][b] = c;
			d[b][_a] = -c;

			cap[_a][b] = 1;

		}

		for (int i = 1; i <= V; i++) {
			int _i = i + N;
			v[i].push_back(_i);
			cap[i][_i] = 1;
		}

		v[V].push_back(T);
		v[T].push_back(V);
		cap[V][T] = 2;

		while (1) {
			queue<int> q;
			int pre[SIZE], dist[SIZE], inQ[SIZE] = { 0 };
			for (int i = 1; i <= T; i++) {
				pre[i] = -1; dist[i] = INF;
			}
			q.push(S);
			dist[S] = 0;
			inQ[S] = 1;

			while (!q.empty()) {
				int cur = q.front();	q.pop();
				inQ[cur] = 0;

				for (int next : v[cur]) {
					if (cap[cur][next] - f[cur][next] > 0 && dist[next] > dist[cur] + d[cur][next]) {
						pre[next] = cur;
						dist[next] = dist[cur] + d[cur][next];

						if (!inQ[next]) {
							q.push(next);
							inQ[next] = 1;
						}
					}
				}
			}
			if (pre[T] == -1)	break;

			for (int cur_pos = T; cur_pos != S; cur_pos = pre[cur_pos]) {
				int pre_visit = pre[cur_pos];
				ans += d[pre_visit][cur_pos];

				f[pre_visit][cur_pos]++;
				f[cur_pos][pre_visit]--;
			}

		}
		printf("%d\n", ans);
		clear();
	}
	return 0;
}
