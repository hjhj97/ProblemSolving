#include<stdio.h>
int num[3][100100], dp[3][100100];
int fmax(int a, int b) {
	return (a > b) ? a : b;
}
int arrmax(int i,int j) { //현재 가리키고있는 배열전까지 가장 큰 수를 반환
	if (j == 1)
		return 0;

	int max = 0;
	if (i == 1) { //윗줄일때
		if (j == 2)
			return dp[2][1];

		for (int n = j-3; n <= j - 2; n++)
			max = (max > dp[1][n]) ? max : dp[1][n];

		for (int n = j-2; n <= j - 1; n++)
			max = (max > dp[2][n]) ? max : dp[2][n];

	}
	else if (i == 2) { //아랫줄일때
		if (j == 2)
			return dp[1][1];

		for (int n = j-2; n <= j - 1; n++)
			max = (max > dp[1][n]) ? max : dp[1][n];

		for (int n = j-3; n <= j - 2; n++)
			max = (max > dp[2][n]) ? max : dp[2][n];

	}
	return max;
}
int main() {
	int t;	scanf("%d", &t);

	while (t--) {
		int n;	scanf("%d", &n);

		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++) {
				scanf("%d", &num[i][j]);
				dp[i][j] = num[i][j];
			}

		for (int j = 1; j <= n; j++)
			for (int i = 1; i <= 2; i++)
				dp[i][j] = num[i][j] + arrmax(i, j);

		int max = 0;
		for (int i = 1; i <= 2; i++)
			for (int j = 1; j <= n; j++)
				max = (max > dp[i][j]) ? max : dp[i][j];

		printf("%d\n", max);

		for(int i=1 ; i<=2 ; i++)
			for (int j = 1; j <= n; j++) {
				num[i][j] = 0;
				dp[i][j] = 0;
			}

	}

	return 0;
}
