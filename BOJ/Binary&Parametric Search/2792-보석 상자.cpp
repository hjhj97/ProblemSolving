#include<stdio.h>
#define SIZE 300100
int jew[SIZE];
int main() {
	int n, m;	scanf("%d %d", &n, &m);

	for (int i = 0; i < m; i++)
		scanf("%d", &jew[i]);

	int l = 1, r = 1e+9, mid, ans;

	//lower bound search
	while (r >= l) {
		int sum = 0; //나눠줄 수 있는 아이들의 수
		mid = (l + r) / 2; //질투심 값들 중 최대값

		for (int i = 0; i < m; i++) {
			if (jew[i] % mid == 0)
				sum += (jew[i] / mid);

			else sum += (jew[i] / mid + 1);
		}

		if (sum <= n) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%d\n", ans);

	return 0;
}
