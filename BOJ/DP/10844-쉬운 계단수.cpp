#include<stdio.h>
int main() {
	int n; int dp[10][110];  long long sum = 0; scanf("%d", &n);
	for (int i = 1; i <= 9; i++)
		dp[i][0] = 1;

	dp[0][0] = 0;
	//dp->dp[끝자리의 숫자][자릿수]
	//n자리 계단의 경우의 수는 dp[][n-1]인덱스를 모두 더한 값이다
	for (int j = 1; j < n; j++)
		for (int i = 1; i <= 8; i++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i + 1][j - 1])%1000000000;
			dp[0][j] = dp[1][j - 1]%1000000000;
			dp[9][j] = dp[8][j - 1]%1000000000;
		}

	for (int i = 0; i <= 9; i++)
		sum += dp[i][n - 1];

	printf("%lld\n", sum%1000000000);

	return 0;

}
