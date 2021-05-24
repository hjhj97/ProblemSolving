#include<stdio.h>
int dp[10010], coin[110];
int main() {
	int n, k;	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++)
		scanf("%d", &coin[i]);

	dp[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = coin[i]; j <= k; j++)
			dp[j] += dp[j - coin[i]];

	printf("%d\n", dp[k]);
	return 0;
}
