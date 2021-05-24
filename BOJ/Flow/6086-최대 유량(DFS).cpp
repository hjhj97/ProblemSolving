#include<stdio.h>
#include<vector>
#include<queue>
#define SIZE 130
#define INF 1<<30
using namespace std;
vector<int> v[130];
int S = 'A', T = 'Z';
int cap[SIZE][SIZE];
int flow[SIZE][SIZE] = { 0 };
int visited[SIZE] = { false };
int DfsCnt = 1;
int fMin(int a, int b) {
	return a > b ? b : a;
}
int Dfs(int cur, int min_flow) {
	if (cur == T)	return min_flow;
	visited[cur] = DfsCnt;

	for (int next : v[cur]) {
		if (visited[next] == DfsCnt)	continue;
		if (cap[cur][next] - flow[cur][next] == 0)	continue;
		min_flow = fMin(min_flow, cap[cur][next] - flow[cur][next]);
		int nextDfs = Dfs(next, min_flow);

		if (nextDfs) {
			flow[cur][next] += nextDfs;
			flow[next][cur] -= nextDfs;
			return nextDfs;
		}
	}

	return 0;
}
int main() {
	int E;	scanf("%d", &E);

	for (int i = 0; i < E; i++) {
		char l1, l2;
		int num;
		scanf(" %c %c %d", &l1, &l2, &num);
		cap[l1][l2] += num;
		cap[l2][l1] += num;
		v[l1].push_back(l2);
		v[l2].push_back(l1);
	}
	int totalFlow = 0, tmp = 0;
	while (tmp = Dfs(S, INF)) {
		totalFlow += tmp;
		DfsCnt++;
	}

	printf("%d\n", totalFlow);
	return 0;
}
