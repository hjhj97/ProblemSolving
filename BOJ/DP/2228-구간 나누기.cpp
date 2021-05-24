#include<stdio.h>
#define SIZE 101
int n, m, arr[SIZE], dp[SIZE][SIZE][SIZE], sum[SIZE];
int fMax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	scanf("%d %d", &n, &m);
	int ans;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= n; k++) {
				dp[i][j][k] = -(1 << 30);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		int tmp[SIZE];
		tmp[i] = arr[i];
		for (int j = i + 1; j < n; j++) {
			tmp[j] = fMax(arr[j], tmp[j - 1] + arr[j]);
		}
		int M = -(1 << 30);
		for (int j = i; j < n; j++) {
			for (int k = i; k <= j; k++) {
				M = fMax(M, tmp[k]);
			}
			dp[i][j][1] = M;
		}
	}

	for (int c = 2; c <= m; c++) {
		for (int i = 0; i < n - 2; i++) {
			for (int k = i; k < n - 2; k++) {
				for (int j = k + 2; j < n; j++) {
					dp[i][j][c] = fMax(dp[i][j][c], dp[i][k][c - 1] + dp[k + 2][j][1]);
				}

			}
		}
	}
	ans = dp[0][n - 1][m];

	printf("%d\n", ans);

	return 0;
}
