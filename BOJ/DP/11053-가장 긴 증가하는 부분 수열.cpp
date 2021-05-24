#include<stdio.h>
int main() {
	int n,max2=-1, num[1010] = {0}, dp[1010] = { 0 }; scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		scanf("%d", &num[i]);

	for (int i=1; i <= n; i++) {
		int max = 0;
		for (int j = 0; j <= i; j++) {
			if (num[i] > num[j] && dp[j] >= max)
				max = dp[j] + 1;
		}
		dp[i] = max;
	}
	for (int i = 1; i <= n; i++)
		max2 = (max2 > dp[i]) ? max2 : dp[i];

	printf("%d\n", max2);

	return 0;
}
