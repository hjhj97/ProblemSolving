#include<stdio.h>
#include<algorithm>
using namespace std;
int main() {
	int n,cost[1010][3],dp[3],tmp_dp[3]; scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 3; j++)
			scanf("%d", &cost[i][j]);

	dp[0] = cost[0][0], dp[1] = cost[0][1], dp[2] = cost[0][2];

	for (int i = 1; i < n; i++) {
		tmp_dp[0] = dp[0]; tmp_dp[1] = dp[1]; tmp_dp[2] = dp[2];
		dp[0] = min(dp[1], dp[2]) + cost[i][0];
		dp[1] = min(tmp_dp[2], tmp_dp[0]) + cost[i][1];
		dp[2] = min(tmp_dp[0], tmp_dp[1]) + cost[i][2];
	}
	int ans = min(dp[0], min(dp[1], dp[2]));
	printf("%d\n", ans);

	return 0;
}
