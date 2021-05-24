#include<stdio.h>
#include<vector>
#include<queue>
#define SIZE 711
#define INF 1<<30
using namespace std;
vector<int> v[130];
int cap[130][130];
int flow[130][130] = { 0 };
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int E;	scanf("%d", &E);

	int totalFlow = 0;
	int S = 'A', T = 'Z';
	for (int i = 0; i < E; i++) {
		char l1, l2;
		int num;
		scanf(" %c %c %d", &l1, &l2, &num);
		cap[l1][l2] += num;
		cap[l2][l1] += num;
		v[l1].push_back(l2);
		v[l2].push_back(l1);
	}

	while (1) {
		int pre[SIZE] = { 0 };

		for (int i = 0; i < 130; i++)
			pre[i] = -1;

		queue<int> q;
		q.push(S);
		while (!q.empty()) {
			int cur = q.front();	q.pop();

			for (int next : v[cur]) {
				if (pre[next] != -1)	continue;
				if (cap[cur][next] - flow[cur][next] > 0) {
					q.push(next);
					pre[next] = cur;
					if (next == T)	break;
				}

			}
		}

		if (pre[T] == -1) //더 이상 갈 수 있는 곳이 없을때
			break;

		int min_flow = INF;
		for (int cur_pos = T; cur_pos != S; cur_pos = pre[cur_pos]) {
			int pre_visit = pre[cur_pos];
			min_flow = fMin(min_flow, cap[pre_visit][cur_pos] - flow[pre_visit][cur_pos]);
		}

		for (int cur_pos = T; cur_pos != S; cur_pos = pre[cur_pos]) {
			int pre_visit = pre[cur_pos];

			flow[pre_visit][cur_pos] += min_flow;
			flow[cur_pos][pre_visit] -= min_flow;
		}
		totalFlow += min_flow;

	}

	printf("%d\n", totalFlow);
	return 0;
}
