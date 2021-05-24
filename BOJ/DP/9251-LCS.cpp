#include<stdio.h>
int fmax(int a, int b) {
	return (a >= b) ? a : b;
}
int dp[1111][1111] = { 0 };
int main() {
	char str1[1111], str2[1111];	scanf("%s %s", str1, str2);
	int len1 = 0, len2 = 0;

	for (int i = 0; str1[i] != 0; i++)
		len1++;

	for (int i = 0; str2[i] != 0; i++)
		len2++;

	for (int i = 1; i<=len1; i++) {

		for (int j = 1; j <= len2; j++) {
			if (str1[i-1] == str2[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;

			else
				dp[i][j] = fmax(dp[i - 1][j], dp[i][j - 1]);

		}
	}
	printf("%d\n", dp[len1][len2]);

	return 0;
}
