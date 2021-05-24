#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 111*2
#define INF 1<<30
vector<int> v[SIZE];
int n, m,ans=0;
int S, T;
int cap[SIZE][SIZE], f[SIZE][SIZE], d[SIZE][SIZE];
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	scanf("%d %d", &n, &m);
	S = 0, T = n + m + 1;

	for (int i = 1; i <= n; i++) {
		int a;	scanf("%d", &a);
		cap[m + i][T] = a;

		v[m + i].push_back(T);
		v[T].push_back(m + i);
	}

	for (int i = 1; i <= m; i++) {
		int a;	scanf("%d", &a);
		cap[S][i] = a;

		v[S].push_back(i);
		v[i].push_back(S);
	}

	for (int i = 1; i <= m; i++) { //서점 -> 사람 연결
		for (int j = 1; j <= n; j++) {
			int cost;	scanf("%d", &cost);
			d[i][m + j] = cost;
			d[m + j][i] = -cost;
			cap[i][m + j] = INF; //서점 -> 사람에게 줄 수 있는 책의 수는 충분하므로 INF로 가정.

			v[i].push_back(m + j);
			v[m + j].push_back(i);
		}

	}

	while (1) {
		int pre[SIZE], dist[SIZE], inQ[SIZE] = { 0 };
		queue<int> q;
		for (int i = S; i <= T; i++) {
			pre[i] = -1; dist[i] = INF;
		}
		dist[S] = 0;
		q.push(S);
		inQ[S] = 1;

		while (!q.empty()) {
			int cur = q.front();	q.pop();
			inQ[cur] = 0;

			for (int next : v[cur]) {
				if (cap[cur][next] - f[cur][next] > 0 && dist[next] > dist[cur] + d[cur][next]) {
					dist[next] = dist[cur] + d[cur][next];
					pre[next] = cur;

					if (!inQ[next]) {
						inQ[next] = 1;
						q.push(next);
					}
				}
			}
		}
		if (pre[T] == -1)	break;

		int min_flow = INF;
		for (int cur_pos = T; cur_pos != S; cur_pos = pre[cur_pos]) {
			int pre_visit = pre[cur_pos];

			min_flow = fMin(min_flow, cap[pre_visit][cur_pos] - f[pre_visit][cur_pos]);
		}

		for (int cur_pos = T; cur_pos != S; cur_pos = pre[cur_pos]) {
			int pre_visit = pre[cur_pos];

			ans += min_flow*d[pre_visit][cur_pos];
			f[pre_visit][cur_pos] += min_flow;
			f[cur_pos][pre_visit] -= min_flow;
		}

	}
	printf("%d\n", ans);

	return 0;
}
