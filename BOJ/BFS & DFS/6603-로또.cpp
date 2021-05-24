#include<stdio.h>
int k;
int num[15], arr[15];
void recur(int cur, int last) {
	if (cur == 6) {
		for (int i = 0; i < 6; i++)
			printf("%d ", num[arr[i]]);

		printf("\n");
		return;
	}

	for (int i = last + 1; i < k; i++) {
		if (6 - cur <= k - i) {
			arr[cur] = i;
			recur(cur + 1, i);
		}
	}
	return;
}
int main() {
	while (1) {
		scanf("%d", &k);

		while (k == 0)	return 0;

		for (int i = 0; i < k; i++)
			scanf("%d", &num[i]);

		recur(0, -1);
		printf("\n");
	}
}
