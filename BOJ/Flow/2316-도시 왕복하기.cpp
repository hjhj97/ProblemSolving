#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
#define SIZE 411*2
int ST, END;
vector<int> v[SIZE];
int V, E, pre[SIZE], ans = 0;
int cap[SIZE][SIZE];
int main() {
	scanf("%d %d", &V, &E);
	ST = 1 + V, END = 2;

	for (int i = 3; i <= V; i++) {
		cap[i][i + V] = 1;
		v[i].push_back(i + V);
	}

	for (int i = 0; i < E; i++) {
		int a, b;	scanf("%d %d", &a, &b);

		int _a = a + V, _b = b + V;
		v[_a].push_back(b);
		v[b].push_back(_a);
		v[_b].push_back(a);

		cap[_a][b] = 1;
		cap[_b][a] = 1;
	}

	while (1) {
		for (int i = 1; i <= 2 * V; i++)
			pre[i] = -1;

		queue<int> q;
		q.push(ST);
		pre[ST] = ST;

		while (!q.empty()) {
			int cur = q.front();	q.pop();

			for (int next : v[cur]) {
				if (pre[next] != -1)	continue;

				if (cap[cur][next] > 0) {
					q.push(next);
					pre[next] = cur;

					if (next == END)
						break;
				}
			}
		}

		if (pre[END] == -1) break;

		for (int cur_pos = END; cur_pos != ST; cur_pos = pre[cur_pos]) {
			int pre_visit = pre[cur_pos];

			cap[pre_visit][cur_pos]--;
			cap[cur_pos][pre_visit]++;
		}
		ans++;
	}
	printf("%d\n", ans);

	return 0;
}/*
5 6
1 4
1 5
4 5
4 2
4 3
3 2
->1


6 7
1 3
3 4
4 2
1 6
6 4
3 5
5 2
->2
 */
