#include<stdio.h>
int jump[1010],dp[1010];
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int n;	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &jump[i]);
		dp[i+1] = 9999;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= jump[i]; j++) {
			if (i + j > n - 1)	break;
			dp[i + j] = fMin(dp[i + j], dp[i] + 1);
		}
	}

	printf("%d\n", (dp[n-1]==9999)?-1:dp[n - 1]);

	return 0;
}
