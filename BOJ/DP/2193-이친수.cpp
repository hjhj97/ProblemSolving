#include<stdio.h>
long long dp[100];
long long f(long long x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (dp[x] != 0) //이전에 계산한 적이 있다면
		return  dp[x];

	dp[x] = f(x - 1) + f(x - 2);

	return dp[x];

}

int main() {
	int n; scanf("%d", &n);

	printf("%lld\n", f(n));

	return 0;
}
