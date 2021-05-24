#include<stdio.h>
#define INF 123456789
#define SIZE 1111
int fmin(int a, int b) {
	return (a > b) ? b : a;
}
int dp[SIZE][SIZE] = { 0 };

int main() {
	int n, m;	scanf("%d %d", &n, &m);
	int start, end;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			dp[i][j] = INF;
		}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		dp[a][b] = fmin(dp[a][b], c);
	}
	scanf("%d %d", &start, &end);

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dp[i][j] = fmin(dp[i][j], dp[i][k] + dp[k][j]);

	printf("%d", dp[start][end]);

	return 0;
}
