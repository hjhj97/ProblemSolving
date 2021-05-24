#include<stdio.h>
char map[55][55];
int count[55][55];
bool fr[55][55] = { false };
int main() {
	int n, max = 0;	scanf("%d ", &n);

	for (int i = 0; i<n; i++)
		for (int j = 0; j < n + 1; j++) {
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'Y') {
				count[i][j] = 1;
				count[j][i] = 1;
			}
		}


	for (int k = 0; k<n; k++)
		for (int i = 0; i<n; i++)
			for (int j = 0; j < n; j++) {
				if (i == j)	continue;

				if (count[i][j] || count[i][k] == 1 && count[k][j] == 1) {
					fr[i][j] = true;	fr[j][i] = true;
				}
			}

	for (int i = 0; i < n; i++) {
		int friends = 0;
		for (int j = 0; j < n; j++)
			if (fr[i][j])	friends++;
		max = (max > friends) ? max : friends;
	}
	printf("%d\n", max);

	return 0;
}
