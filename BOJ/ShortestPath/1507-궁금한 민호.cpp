#include<stdio.h>
#define SIZE 22
#define INF 234567
int map[SIZE][SIZE];
int map2[SIZE][SIZE];
int main() {
	int n,sum=0;	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
			map2[i][j]=map[i][j];
		}

	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = i+1; j <= n; j++)
				if (k != i&&k != j) {
					if (map[i][j] > map[i][k] + map[k][j]) {
						printf("-1\n");
						return 0;
					}
					else if (map[i][j] == map[i][k] + map[k][j])
						map2[i][j] = 0;
				}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++)
			sum += map2[i][j];
	}

	printf("%d\n", sum);

	return 0;
}
