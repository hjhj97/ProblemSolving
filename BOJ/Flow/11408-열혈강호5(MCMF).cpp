#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 411
#define INF 1<<30
vector<int> v[SIZE*2];
int n, m, ans = 0, totalCost=0,S, T;
int cap[SIZE*2][SIZE*2], f[SIZE*2][SIZE*2], d[SIZE*2][SIZE*2];
int pre[SIZE*2], dist[SIZE*2];
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	scanf("%d %d", &n, &m);
	S = 0, T = n + m + 1;

	for (int i = 1; i <= n; i++) { //사람->일 연결
		int a;	scanf("%d", &a);
		for (int j = 0; j < a; j++) {
			int to, cost;	scanf("%d %d", &to, &cost);
			v[i].push_back(to + n);
			v[to + n].push_back(i);

			d[i][to + n] = cost;
			d[to + n][i] = -cost;

			cap[i][to + n] = 1; //모든 일은 딱 한번만 하면 되므로 1.
		}
	}
	for (int i = 1; i <= n; i++) { //소스 -> 사람 연결
		v[S].push_back(i);
		v[i].push_back(S);

		cap[S][i] = 1;
	}
	for (int i = n + 1; i <= n + m; i++) { // 일 -> 싱크 연결
		v[i].push_back(T);
		v[T].push_back(i);

		cap[i][T] = 1;
	}

	while (1) {
		for (int i = 0; i < SIZE*2; i++) {
			pre[i] = -1;
			dist[i] = INF;
		}

		int inQ[SIZE * 2] = { 0 };
		queue<int> q;
		q.push(S);
		dist[S] = 0;
		inQ[S] = 0;

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
			totalCost += min_flow*d[pre_visit][cur_pos];

			f[pre_visit][cur_pos] += min_flow;
			f[cur_pos][pre_visit] -= min_flow;
		}

		ans++;

	}
	printf("%d\n%d\n", ans, totalCost);

	return 0;
}
