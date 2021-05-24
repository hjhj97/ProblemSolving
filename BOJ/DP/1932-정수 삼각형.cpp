#include<stdio.h>
int max(int a, int b) {
	return (a >= b) ? a : b;
}
int tri[555][555],dp[555][555];
int main() {
	int n,max_num=-1; scanf("%d", &n); //tri[level][왼쪽에서n번째]
	for (int i = 1; i <= n; i++) //dp[그 level]까지의 최대값
		for (int j = 1; j < i + 1; j++)
			scanf("%d", &tri[i][j]);

	  dp[1][1] = tri[1][1];

	  if (n >= 2) {
		  for (int i = 2; i <= n; i++)
			  for (int j = 1; j <= i; j++) {
				  dp[i][j] = max(dp[i - 1][j - 1] + tri[i][j], dp[i - 1][j] + tri[i][j]);

			  }
	  }
		  for (int i = 1; i <= n; i++)
			  max_num = (max_num <= dp[n][i] ? dp[n][i] : max_num);


	printf("%d\n", max_num);

	return 0;

}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
