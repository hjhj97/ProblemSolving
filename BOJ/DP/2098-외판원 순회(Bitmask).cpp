#include<stdio.h>
#define SIZE 16
#define INF 123456789
int n, start=0;
int dist[SIZE][SIZE], dp[SIZE][1<<SIZE];
//dp[cur][visited]=cost -> 현재위치가(cur)이고 지금까지 visited방문했을때, 남은 점들을 모두 방문하여 시작점으로 돌아가는 최소비용=cost
int fmin(int a, int b) {
	return a > b ? b : a;
}
int path(int cur, int visited) {
	if (visited == (1 << n) - 1) //모든 지점을 다 방문했을때
		return (dist[cur][start]) ? dist[cur][start] : INF;

	if (dp[cur][visited] != -1)
		return dp[cur][visited];

	dp[cur][visited] = INF;

	for (int i = 0; i < n; i++) {
		int next = i;
		int next_visited = visited | (1 << next);
		if (dist[cur][next] == 0) //next로 가는 길이 없다면
			continue;
		if (visited&(1 << next)) //next가 이미 방문한 곳이라면
			continue;

		dp[cur][visited] = fmin(dp[cur][visited], path(next,next_visited) + dist[cur][next]);
	}

	return dp[cur][visited];
}
int main() {
	scanf("%d", &n);

	for(int i=0 ; i<n ; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &dist[i][j]);

	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < (1<<SIZE)-1; j++)
			dp[i][j] = -1;

	printf("%d\n",path(0, 1));

	return 0;
}
