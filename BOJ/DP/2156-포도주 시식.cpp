#include<stdio.h>
int max(int a, int b) {
	return (a >= b) ? a : b;
}

int main() {
	int n,wine[10010],dp[10010],result=0; scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &wine[i]);

	dp[0]=0, dp[1] = wine[1], dp[2] = wine[2] + wine[1];

	if (n >= 3) {
		for (int i = 3; i <= n; i++) {
			result = max(dp[i - 1], max(wine[i] + wine[i - 1] + dp[i - 3], wine[i] + dp[i - 2]));
			dp[i] = result;
		}
		printf("%d\n", result);
	}

	else if (n == 2) printf("%d\n", dp[2]);

	else if (n == 1) printf("%d\n", dp[1]);

	return 0;
}
