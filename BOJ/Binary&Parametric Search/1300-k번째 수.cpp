#include<stdio.h>
int fMin(int a, int b) {
	return a > b ? b : a;
}
int main() {
	int n, k, ans = 0;	scanf("%d %d", &n, &k);

	int l = 1, r = 1e+9, mid;

	//lower bound search
	while (r >= l) {
		int total = 0;
		mid = (l + r) / 2;

		for (int i = 1; i <= n; i++) {
			total += fMin(mid / i, n);
		}
		//mid는 total번째 수

		if (total >= k) {
			ans = mid;
			r = mid - 1;
		}

		else l = mid + 1;
	}
	printf("%d\n", ans);

	return 0;
}
