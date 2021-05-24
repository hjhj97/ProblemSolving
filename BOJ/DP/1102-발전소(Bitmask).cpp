#include<stdio.h>
#define INF 1<<10
int dp[1 << 17], dist[20][20];
int n, ans,p;
int fMin(int a, int b) {
	return a > b ? b : a;
}
int dfs(int cnt, int visited) {
	if (cnt >= p) {
		return 0;
	}

	if (dp[visited] != -1)
		return dp[visited];

	dp[visited] = INF;

	for (int from = 1; from <= n; from++) {
		if (visited & (1 << from)) {
			for (int to = 1; to <= n; to++) {
				if (from == to) continue;
				if (visited & (1 << to)) continue;
				int next_visited = visited | (1 << to);

				dp[visited] = fMin(dp[visited], dfs(cnt + 1, next_visited)+dist[from][to]);
			}
		}
	}

	return dp[visited];
}
int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d ", &dist[i][j]);
		}

	for (int j = 0; j <= (1 << n+1); j++)
		dp[j] = -1;

	int init = 0, init_cnt = 0;
	for (int i = 1; i <= n + 1; i++) {
		char a; scanf("%c", &a);
		if (a == 'Y') {
			init |= (1 << i);
			init_cnt++;
		}
	}
	scanf("%d", &p);

	if (init_cnt == 0 && p!=0)
		ans = -1;
	else ans = dfs(init_cnt, init);

	printf("%d\n", ans);

	return 0;
}
