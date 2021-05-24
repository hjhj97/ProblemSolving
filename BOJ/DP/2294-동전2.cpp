#include<stdio.h>
#define INF 1<<30
int coin[110],dp[10010];
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int n, k;	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	for (int i = 0; i <= k; i++)
		dp[i] = INF;

	dp[0] = 0;
	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] = fMin(dp[j], dp[j - coin[i]]+1);

	printf("%d\n", (dp[k]==INF)?-1:dp[k]);

	return 0;
}
