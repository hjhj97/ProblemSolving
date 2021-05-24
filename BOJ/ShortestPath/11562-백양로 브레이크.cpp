#include<stdio.h>
#include<vector>
#define SIZE 300
#define INF 300
int fmin(int a, int b) {
	return a > b ? b : a;
}
int map[SIZE][SIZE] = { 0 };
int map2[SIZE][SIZE];
int map3[SIZE][SIZE];
int main() {
	int n, m, q;	scanf("%d %d", &n, &m);


	for(int i=1 ; i<=n ; i++)
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			map[i][j] = INF;
		}


	for (int i = 0; i < m; i++) {
		int a, b, c;	scanf("%d %d %d", &a, &b, &c);
		//c가 0이면 일방통행, 1이면 양방통행
		if (c == 0) {
			map[a][b] = 0;
			map[b][a] = 1;
		}

		else if (c) {
			map[a][b] = 0;
			map[b][a] = 0;
		}
	}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) {
				map[i][j] = fmin(map[i][j], map[i][k] + map[k][j]);
			}

	scanf("%d", &q);
	for (int i = 0; i < q; i++) {
		int a, b;	scanf("%d %d",&a,&b);

		printf("%d\n", map[a][b]);
	}
	return 0;
}
