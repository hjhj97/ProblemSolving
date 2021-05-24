#include<stdio.h>
int dp[100000] = { 0,1,2,4, };
int f(int x) {
	if (dp[x] != 0)
		return dp[x];

	return dp[x] = f(x - 1) + f(x - 2) + f(x - 3);

}
int main() {
	int t; scanf("%d", &t);
	while (t--) {
		int x;  scanf("%d", &x);
		printf("%d\n", f(x));
	}
	return 0;
}
