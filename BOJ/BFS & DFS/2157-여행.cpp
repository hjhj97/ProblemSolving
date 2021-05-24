#include<stdio.h>
#include<vector>
#define SIZE 310
#define INIT -1
#define MIN -(1<<30)
using namespace std;
struct Edge {
	int to, cost;

	Edge(int _to, int _cost) {
		to = _to;
		cost = _cost;
	};
};
vector<Edge> v[SIZE];
int dp[SIZE][SIZE];
int V, m, e, ans = 0;
int fMax(int a, int b) {
	return a > b ? a : b;
}
int dfs(int cur,int cur_cost,int cur_left) {
	if (cur == V)  //목적지에 도달함
		return 0;
	if (dp[cur][cur_left] != MIN)
		return dp[cur][cur_left];

	if (v[cur].size() == 0)
		return MIN; //목적지가 아닌데 막다른 길에 도착-> 불가능한 경로

	if (cur_left >= 1) {
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].to, nextCost = v[cur][i].cost;
			int	nextResult = dfs(next, cur_cost, cur_left - 1);

			dp[cur][cur_left] = fMax(dp[cur][cur_left], nextCost + nextResult);
		}
	}
	return dp[cur][cur_left];
}
int main() {
	scanf("%d %d %d", &V, &m, &e);

	for (int i = 1; i <= V; i++)
		for (int j = 0; j <= m; j++)
			dp[i][j] = MIN;

	for (int i = 0, a, b, c; i < e; i++) {
		scanf("%d %d %d", &a, &b, &c);

		if (a < b)
			v[a].push_back(Edge(b, c));
	}

	dfs(1, 0, m - 1);

	printf("%d\n", dp[1][m-1]);

	return 0;
}
