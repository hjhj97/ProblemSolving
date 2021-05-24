#include<stdio.h>
#define SIZE 1010
int cross[SIZE][SIZE];
char sq[SIZE][SIZE];
int ans = 0;
int fMin(int a, int b) {
	return a > b ? b : a;
}
int fMin(int a, int b, int c) {
	return a > fMin(b, c) ? fMin(b, c) : a;
}
int fMax(int a, int b) {
	return a > b ? a : b;
}
int main() {
	int n, m;	scanf("%d %d ", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m + 2; j++)
			scanf("%c", &sq[i][j]);
	}


	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (sq[i][j] == '1') {
				cross[i][j] = fMin(cross[i - 1][j], cross[i][j - 1], cross[i - 1][j - 1])+1;
				ans = fMax(ans, cross[i][j]);
			}
		}
	}
	printf("%d\n", ans*ans);

	return 0;
}
/*
4 4
1111
1101
0111
1111
-> 4
*/
